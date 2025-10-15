#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct __Node {
    char data;
    struct __Node* next;
} Node;
typedef struct __Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;
Queue CreateQueue() {
    Queue q;
    q.front = (Node*)malloc(sizeof(Node));
    q.front->next = NULL;
    q.rear = q.front;
    q.size = 0;
    return q;
}
void inq(Queue* q, char c) {
    q->rear->data = c;
    q->rear->next = (Node*)malloc(sizeof(Node));
    q->rear->next->next = NULL;
    q->rear = q->rear->next;
    q->size++;
}
void deleteq(Queue* q) {
    while(q->front != q->rear) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
    free(q->front);
}
void qtos(Queue q, char* str) {
    Node* curr = q.front;
    while(curr != q.rear) {
        *str++ = curr->data;
        curr = curr->next;
    }
    *str = '\0';
}
void stoq(Queue* q, char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        inq(q, str[i]);
    }
}
void filterq(Queue* q, bool (*filter)(char)) {
    Node* curr = q->front;
    Node* prev = NULL;
    while(curr != q->rear) {
        if(!filter(curr->data)) {                   // 필터 조건에 맞지 않으면
            if(prev == NULL) {                      // 맨 앞 노드인 경우
                q->front = curr->next;              // front를 다음 노드로 변경
                free(curr);
                curr = q->front;
            } else {                                // 중간 노드인 경우
                prev->next = curr->next;            // 이전 노드의 next를 현재 노드의 next로 변경
                free(curr);
                curr = prev->next;
            }
            q->size--;
        } else {                                    // 필터 조건에 맞으면
            prev = curr;
            curr = curr->next;
        }
    }
    q->rear = prev ? prev->next : q->front;
}
bool is_2(char c) {
    return c == '2';
}
int main() {
    Queue q = CreateQueue();
    char input[101] = "";
    scanf("%100s", input);
    stoq(&q, input);                                        // 문자열을 기준으로 queue생성
    filterq(&q, is_2);                                      // '2'를 제외한 모든 숫자를 물리적으로 제거
    char* str = (char*)malloc((q.size + 1) * sizeof(char));
    memset(str, 0, (q.size + 1) * sizeof(char));
    qtos(q, str);                                           // 남겨진 2를 연결하여 새로운 문자열 생성
    printf("%s\n", str);
    free(str);
    deleteq(&q);
    return 0;
}
