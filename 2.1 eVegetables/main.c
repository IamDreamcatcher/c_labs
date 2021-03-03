#include <stdio.h>

void show_inf() {
    printf("Name - eVegetables\n");
    printf("License number - 10101\n");
    printf("Phone - +375298549386\n");
    printf("Website - eVegetables.com\n");
}

void add_to_backet(int number, double amount, double* backet) {
    backet[number] += amount;
}

void show_backet(double* backet) {
    printf("Potatoes: %lf kg, %lf p.\n", backet[0], backet[0] * 500);
    printf("Carrots: %lf kg, %lf p.\n", backet[1], backet[1] * 1000);
    printf("Beets: %lf kg, %lf p.\n", backet[2], backet[2] * 700);
}

double show_cost(double* backet) {
    show_backet(backet);
    printf("Delivering price: 15000 p.\n");
    double total_cost = backet[0] * 500 + backet[1]  * 1000 + backet[2] * 700;
    
    if (50 - (backet[0] + backet[1] + backet[2]) < 0) {
        printf("Discount: 30%%\n");
        total_cost = total_cost / 100 * 70;
    } else if (25 - (backet[0] + backet[1] + backet[2]) < 0) {
        printf("Discount: 20%%\n");
        total_cost = total_cost / 100 * 80;
    } else if (10 - (backet[0] + backet[1] + backet[2]) < 0) {
        printf("Discount: 10%%\n");
        total_cost = total_cost / 100 * 90;
    } else {
        printf("Discount: 0%%\n");
    }
    return total_cost + 15000;
}
int get_request() {
    int request;
    char ch;
    while (scanf("%d%c", &request, &ch) != 2 || ch != '\n' || request < 1 || request > 7) {
        printf("Enter correct request\n");
        while (getchar() != '\n') {
        }
    }
    return request;
}
double get_amount() {
    double amount;
    char ch;
    while (scanf("%lf%c", &amount, &ch) != 2 || ch != '\n' || 
           amount < 1 || amount > 10000000) {
        printf("Enter correct amount\n");
        while (getchar() != '\n') {
        }
    }
    return amount;
}

int main() {
    double backet[3] = {0, 0, 0};
    for(;;) {
        printf("Enter 1 to order potatoes\n");
        printf("Enter 2 to order carrots\n");
        printf("Enter 3 to order beets\n");
        printf("Enter 4 to show backet\n");
        printf("Enter 5 to checkout\n");
        printf("Enter 6 to show info\n");
        printf("Enter 7 to exit\n");

        printf("Enter request:");
        int request = get_request();
        if (request <=3) {
            printf("Enter amount:"); 
            double amount = get_amount();
            add_to_backet(request - 1, amount, backet);
        }
        if (request == 4) {
            show_backet(backet);
        }
        if (request == 5) {
            double cost = show_cost(backet);
            printf("Total cost: %lf\n", cost);
        }
        if (request == 6) {
            show_inf();
        }
        if (request == 7) {
            break;
        }
    }
    printf("Finish, press enter to exit");
    getchar();
    return 0;
}
