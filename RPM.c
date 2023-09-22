#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING_LENGTH 100

// TODO: Move to Header file 
void welcome_message();

int main(int argc, char** argv)
{
    if (argc != 1) {
        char error_message[MAX_STRING_LENGTH] = "Called with too many arguments!\n";
        fprintf(stderr, "%s", error_message);
        exit(-1);
    }

    welcome_message();

    char operator;
    double x, y;
    int calc_case = 0;  
    do {
        // 1: Addition
        // 2: Subtraction
        // 3: Multiplication
        // 4: Division
        bool operator_checker = false;
        do {
            scanf("%c", &operator);
            switch (operator) {
                case '+': 
                    // printf("Addition selected\n");
                    operator_checker = true; 
                    calc_case = 1;
                    break;
                case '-': 
                    // printf("Subtraction selected\n");
                    operator_checker = true; 
                    calc_case = 2;
                    break;
                case '*': 
                    // printf("Multiplication selected\n");
                    operator_checker = true; 
                    calc_case = 3;
                    break;
                case '/': 
                    // printf("Division selected\n");
                    operator_checker = true;
                    calc_case = 4;
                    break;
                case 'q':
                    exit(1); 
                    break;
                default: 
                    printf("Invaild Input. Try again or press q to quit!\n"); 
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
            }
        } while(!operator_checker);

        // printf("Now enter in the numbers you want to calculate!\n");
        scanf("%lf", &x);
        scanf("%lf", &y);
        
        switch (calc_case) {
            case 1: printf("Result: %.2lf\n", x+y); break;
            case 2: printf("Result: %.2lf\n", x-y); break;
            case 3: printf("Result: %.2lf\n", x*y); break;
            case 4: printf("Result: %.2lf\n", x/y); break;
            default:
                fprintf(stderr, "There seems to have been a calc error!\n");
                exit(-2);
        }

        operator_checker = false; // reset operator_checker
        calc_case = 0; // reset calc_case
        while (getchar() != '\n'); // Clear the input buffer
    } while (true);

    return 0;    
}

// TODO: Move to seperate file 
void welcome_message()
{
    printf("This is the powerfull RPM-Calculator!\nInput in Reverse Polish Notation or Press q to quit\n");
}
