#include "main.h"
#include <assert.h>
#include <vector>

void test_solve() {
    std::vector<int> my_vector = convert("10");
    assert(solve("20", "10") == my_vector);
}

#undef main
int main() {
    test_solve();
}
