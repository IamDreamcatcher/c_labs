#include "main.h"
#include <math.h>
#include <assert.h>

#define eps 0.01

void test_show_cost() {
    double first_backet[3] = {2.0, 3.2 , 4.1};
    assert(fabs(show_cost(first_backet) - 22070) < eps);
    double second_backet[3] = {4.3, 5.2 , 7.9};
    assert(fabs(show_cost(second_backet) - 26592) < eps);
    double third_backet[3] = {10.3, 6.6 , 20.9};
    assert(fabs(show_cost(third_backet) - 36104) < eps);
    double fourth_backet[3] = {52.3, 10.11, 66.6};
    assert(fabs(show_cost(fourth_backet) - 73016) < eps);
}

#undef main
int main() {
    test_show_cost();
}
