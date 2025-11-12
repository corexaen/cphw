#include <stdio.h>
#include <stdbool.h>

bool is_wonderful(char* text) {
    bool letters[256] = {false,};
    while(*text) {
        if(letters[*text]) {
            return false;
        }
        letters[*text] = true;
        text++;
    }
    bool has_lower = false;
    bool has_upper = false;
    for(int i = 'a'; i <= 'z'; i++) {
        if(letters[i]) {
            has_lower = true;
            break;
        }
    }
    for(int i = 'A'; i <= 'Z'; i++) {
        if(letters[i]) {
            has_upper = true;
            break;
        }
    }
    if(!has_lower || !has_upper) {
        return false;
    }
    return true;
}

int main() {
    char string[101] = "";
    scanf("%s", string);
    if(is_wonderful(string)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}