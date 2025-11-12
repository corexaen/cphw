#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Name {
    char first[11];
    char last[11];
} Name;

bool is_can_make_unique_nickname(Name* names, int n) {
    for(int i = 0; i < n; i++) {
        bool first_duplicate = false;
        bool last_duplicate = false;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(strcmp(names[i].first, names[j].first) == 0 ||
               strcmp(names[i].first, names[j].last) == 0) {
                first_duplicate = true;
            }
            if(strcmp(names[i].last, names[j].first) == 0 ||
               strcmp(names[i].last, names[j].last) == 0) {
                last_duplicate = true;
            }
        }
        if(first_duplicate && last_duplicate) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    Name* names = (Name*)malloc(n * sizeof(Name));
    for(int i = 0; i < n; i++) {
        scanf(" %s %s", names[i].first, names[i].last);
    }
    if(is_can_make_unique_nickname(names, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(names);
    return 0;
}