#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_names(char* names, int N) {
    memset(names, 0, N * 11 * sizeof(char));
    for (int i = 0; i < N; i++) {
        scanf("%10s", names + (i * 11));
    }
}

static inline int is_name_in_list(const char* name, int X, char* names) {
    return strcmp(names + ((X - 1) * 11), name);
}

int main() {
    int N;
    scanf("%d", &N);
    char* names = (char*)malloc(N * 11 * sizeof(char));
    input_names(names, N);
    int X;
    char name[11] = {0,};
    scanf("%d\n%10s", &X, name);
    if(is_name_in_list(name, X, names) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(names);
    return 0;
}