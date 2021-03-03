#include <stdio.h>
#include <math.h>

double scanf_double() {
    double x;
    char ch;
    while (scanf("%lf%c", &x, &ch) != 2 || ch != '\n' || x < 0 || x > 10000000) {
        printf("Enter correct number\n");
        while (getchar() != '\n') {
        }
    }
    return x;
}

int right_answer(double angle, double left_answer, double eps) {
    if (angle <= eps) {
        return 0;
    }
    int n_answer = 1;
    int fact = 2;
    double denominator = 1;
    double numerator = angle;
    double current_answer = angle;

    while (fabs(current_answer - left_answer) >= eps) {
        numerator *= angle * angle;
        denominator *= fact * (fact + 1);
        fact += 2;
        double value = numerator / denominator;
        if (n_answer % 2 == 0) {
            current_answer += value;
        } else {
            current_answer -= value;
        }
        n_answer++;
    }
    return n_answer;
}
int main() {
    printf("Enter eps:\n");
    double eps = scanf_double();
    printf("Enter the angle in radians:\n");
    double angle = scanf_double();
    
    double left_answer = sin(angle);
    int answer = right_answer(angle, left_answer, eps);

    printf("n = %d\n", answer);
    printf("Finish, press enter to exit");
    getchar();
    return 0;
}
