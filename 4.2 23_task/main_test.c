#include "main.h"
#include <assert.h>

void test_count() {
    assert(count("aaaa1") == 0);
    assert(count("aaaaa13") == -3);
    assert(count("aaa") == 1);
}

#undef main
int main() {
    test_count();
}
