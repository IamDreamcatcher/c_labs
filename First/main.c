#include "main.h"
#include <stdio.h>

int is_decreasing(int number) {
    int last = -1;
    while (number > 0) {
        if (number % 10 <= last) {
            return 0;
        }
        last = number % 10;
        number /= 10;
    }
    return 1;
}

int is_increasing(int number) {
    int last = 10;
    while (number > 0) {
        if (number % 10 >= last) {
            return 0;
        }
        last = number % 10;
        number /= 10;
    }
    return 1;
}
int get_input() {
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 1 || x > 1000000) {
        printf("Enter correct n\n");
        while (getchar() != '\n') {
        }
    }
    return x;
}
int main() {
    int n;
    printf("Enter n: ");
    n = get_input();
    int number;
    for (number = 1; number <= n; number++) {
        if (is_increasing(number) || is_decreasing(number)) {
            printf("%d\n", number);
        }
    }
    printf("Finish, press any key\n");
    getchar();
    return 0;
}
