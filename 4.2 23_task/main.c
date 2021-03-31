#include <stdio.h>
#include <stdlib.h>
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
                exit(-1);
            }
        }
    }
    word_ans += flag; 

    return word_ans - digit_ans;
}
int main() {
    char word[10000];
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Input file is invalid");
        exit(-1);
    }

    int ans = 0;
    for(;;) {
        int resuslt = fscanf(file, "%s", word);     
        if (resuslt == EOF) {
            break;
        }
        if (resuslt != 1 || word[0] == 0) {
            printf("Word isn't valid\n");
            return 0;
        }       
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

