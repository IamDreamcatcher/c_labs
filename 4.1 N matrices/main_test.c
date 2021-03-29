#include "main.h"
#include <assert.h>

void test_is_palindrome() {
    assert(is_palindrome("1234") == false);
    assert(is_palindrome("1221") == true);
    assert(is_palindrome("1212") == false);
    assert(is_palindrome("11311") == true);
}

#undef main
int main() {
    test_is_palindrome();
}
