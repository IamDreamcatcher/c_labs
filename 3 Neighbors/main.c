#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 1 || x > 1000000) {
        printf("Enter correct int\n");
        while (getchar() != '\n') {
        }
    }
    return x;
}

int** dynamic_array_alloc(int n, int m)
{
    int** a;
    if ( !(a = (int**) malloc(n * sizeof(int*))) ) {
        printf("Error: can't allocate memory");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++) {
        if ( !(a[i] = (int*) malloc(m * sizeof(int))) ) {
            printf("Error: can't allocate memory");
            exit(1);
        }
    }
    return a;
}

void dynamic_array_free(int **a, int n)
{
    for(int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

void solve(int** a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 1 + (j % 2) * 2 + i % 2;
        }
    }
}
int main() {
    int n, i, j, m;
    int** a;
    printf("Enter n: ");
    n = get_int();
    printf("Enter m: ");
    m = get_int();   
    a = dynamic_array_alloc(n, m);
    solve(a, n, m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }
    dynamic_array_free(a, n);
    getchar();
    return 0;
}