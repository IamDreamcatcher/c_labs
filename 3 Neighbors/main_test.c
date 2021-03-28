#include "main.h"
#include <assert.h>

void test_solve() {
    int** a = dynamic_array_alloc(3, 3);
    solve(a, 3, 3);
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i - 1 >= 0) {
                assert(a[i][j] != a[i - 1][j]);
            }
            if (i + 1 < 3) {
                assert(a[i][j] != a[i + 1][j]);
            }
            if (j - 1 >= 0) {
                assert(a[i][j] != a[i][j - 1]);
            }
            if (j + 1 < 3) {
                assert(a[i][j] != a[i][j + 1]);
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                assert(a[i][j] != a[i - 1][j - 1]);
            }
            if (i + 1 < 3 && j + 1 < 3) {
                assert(a[i][j] != a[i + 1][j + 1]);
            }
            if (i - 1 >= 0 && j + 1 < 3) {
                assert(a[i][j] != a[i - 1][j + 1]);
            }
            if (i + 1 < 3 && j - 1 >= 0) {
                assert(a[i][j] != a[i + 1][j - 1]);
            }
        }
    }
}

#undef main
int main() {
    test_solve();
}
