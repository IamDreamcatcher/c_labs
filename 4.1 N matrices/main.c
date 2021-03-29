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

bool is_palindrome(char string[]) {
    bool palindrome = true;
    int length = strlen(string); 
    int left = 0, right = length - 1;
    while (right > left) {
        if (string[left] != string[right]) {
            palindrome = false;
            break;
        }
        left++;
        right--;
    }    
    return palindrome;
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
                char string[1000];
                scanf("%s", string);
                bool palindrome = is_palindrome(string);
    
                if (palindrome) {
                    printf("----- ");
                }
                else {
                    printf("%s ", string);
                }
            }
            printf("\n");
        }

    }
    getchar();
    return 0;
}
