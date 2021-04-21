#include "main.h"
#include <assert.h>
#include <vector>

void test_solve() {
    
    std::vector<int> my_vector = convert("20");    
    assert(solve("20", "10") == my_vector);
    my_vector = convert("31610054640417607788145206291543662493274686990");
    assert(solve("557940830126698960967415390", "56654851076662550441") == my_vector);
    my_vector = convert("6469693230");
    assert(solve("30030", "30808063") == my_vector);
    
}

#undef main
int main() {
    test_solve();
}
