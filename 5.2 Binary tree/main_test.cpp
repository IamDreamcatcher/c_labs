#include "main.h"
#include "tree.h"
#include <assert.h>
#include <list>

void test_solve() {
    tree* bin_tree = new tree();
    std::list <int> input_list = {-1, 2, 3, 4};
    for (int x: input_list) {
        bin_tree -> insert(x);
    }
    std::vector <int> vec;
    std::vector <int> ans{2, 3, 4};
    solve(bin_tree);
    bin_tree -> to_vector(vec);
    assert(vec == ans);
    bin_tree -> insert(-4);
    bin_tree -> insert(5);
    bin_tree -> insert(-1);
    ans.push_back(5);
    solve(bin_tree);
    vec.clear();
    bin_tree -> to_vector(vec);
    assert(vec == ans);

    delete bin_tree;
}

#undef main
int main() {
    test_solve();
}
