#include "tree.h"
#include <stdio.h>
#include <list>
#include <vector>

using namespace std;

int get_int() {
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n') {
        printf("Enter correct int\n");
        while (getchar() != '\n') {
        }
    }
    return x;
}

std::list <int> get_list(int size) {
    std::list <int> input;
    while (size > 0) {
        size--;
        input.push_back(get_int());
    }
    return input;
}

void solve(tree* bin_tree) {
    bin_tree -> remove_negative_numbers();
}

int main() {
    tree* bin_tree = new tree();
    printf("Write size of list\n");
    int n = get_int();
    printf("Write list in a column\n");
    std::list <int> input_list = get_list(n);
    for (int x: input_list) {
        bin_tree -> insert(x);
    }
    solve(bin_tree);
    std::vector <int> vec;
    bin_tree -> to_vector(vec);
    for (size_t i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    delete bin_tree;
    
    return 0;
}