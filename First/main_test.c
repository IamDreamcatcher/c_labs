#include "main.h"
#include <assert.h>

void test_is_increasing() {
   // assert(is_increasing(123) == 1);
    assert(is_increasing(123) == 123);
    assert(is_increasing(122) == 0);
}

void test_is_decreasing() {
    assert(is_decreasing(321) == 1);
    assert(is_decreasing(122) == 0);
}

#undef main
int main() {
    test_is_increasing();
    test_is_decreasing();
}
