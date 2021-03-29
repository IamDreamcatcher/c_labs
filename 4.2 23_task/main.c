#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count(char word[]) {
    int digit_ans = 0, word_ans = 0;

    int i, flag = 0;
    int length = strlen(word);
    for (i = 0; i < length; i++) {

        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            flag = 1;    
        } else {
            word_ans += flag;
            flag = 0;
            if (word[i] >= '0' && word[i] <= '9') {
                digit_ans += word[i] - '0';
            } else {
                printf("Incorrect text");
                return -1;
            }
        }
    }
    word_ans += flag; 

    return word_ans - digit_ans;
}
int main() {
    char word[10000];
    FILE *f = fopen("input.txt", "r");
    int ans = 0;
    while (fscanf(f, "%s", word) != EOF) {
        ans += count(word); 
    }
    
    if (ans == 0) {
        printf("They are equal");
    } else {
        printf("They are not equal");    
    }
    getchar();
    return 0;
}
