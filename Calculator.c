//Simple C program for a simple calculator
#include <stdio.h>
#include<math.h>

int main() {
    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero is not allowed.");
            break;
            case('^'):
            printf("%.2lf ^ %.2lf = %.2lf", num1,num2, pow(num1,num2));
        default:
            printf("Error! Invalid operator for this calculator");
    }

    return 0;
}
