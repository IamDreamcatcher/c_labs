#include "main.h"
#include <assert.h>
#include <vector>

void test_solve() {
    std::vector<int> my_vector = convert("10");    
    assert(solve("20", "10") == my_vector);
    my_vector = convert("1");
    assert(solve("557940830126698960967415390", "56654851076662550441") == my_vector);
    my_vector = convert("143");
    assert(solve("30030", "30808063") == my_vector);
    
}

#undef main
int main() {
    test_solve();
}
