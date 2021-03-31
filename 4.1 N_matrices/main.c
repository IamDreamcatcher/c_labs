#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int get_int() {
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 1 || x > 1000) {
        printf("Enter correct int\n");
        while (getchar() != '\n') {
        }
    }
    return x;
}

bool is_palindrome(char word[]) {
    int length = strlen(word);
    int left = 0, right = length - 1;
    while (right > left) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    int number_of_matrices;
    printf("Enter number of matrices: ");
    number_of_matrices = get_int();
    while (number_of_matrices > 0) {
        number_of_matrices--;
        int n, m, i, j, k;
        printf("Enter n: ");
        n = get_int();
        printf("Enter m: ");
        m = get_int();

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                char word[1000];
                if (scanf("%s", word) != 1 || word[0] == 0) {
                    printf("Word isn't valid\n");
                    return 0;
                }
    
                if (is_palindrome(word)) {
                    printf("----- ");
                } else {
                    printf("%s ", word);
                }
            }
            printf("\n");
        }

    }

    getchar();
    return 0;
}