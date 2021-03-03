#include "main.h"
#include <math.h>
#include <assert.h>

#define eps 0.01

void test_right_answer_should_return_answer() {
    double first_left_answer = sin(1);
    int first_answer = right_answer(1, first_left_answer, eps);
    assert(first_answer == 2);
    double second_left_answer = sin(3.5);
    int second_answer = right_answer(3.5, second_left_answer, eps);
    assert(second_answer == 6);
    double third_left_answer = sin(0.523599);
    int third_answer = right_answer(0.523599, third_left_answer, eps);
    assert(third_answer == 2);
    double fourth_left_answer = sin(13);
    int fourth_answer = right_answer(13, fourth_left_answer, eps);
    assert(fourth_answer == 19);
}

#undef main
int main() {
    test_right_answer_should_return_answer();
}
