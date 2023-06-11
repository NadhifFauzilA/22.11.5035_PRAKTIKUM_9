#include "Calculator.h"
#include <iostream>
#include <conio.h>

Calculator::Calculator() {
    tail = -1;
    tos = -1;
}

int Calculator::convert(char symbol) {
    switch (symbol) {
        case '/':
            return -1;
        case '*':
            return -2;
        case '-':
            return -4;
        case '+':
            return -5;
        default:
            return -7;
    }
}

void Calculator::evaluatePostfix() {
    for (int i = 0; i <= tail; i++) {
        if (postfix.data[i] >= 0) {
            tos++;
            stack.data[tos] = postfix.data[i];
        } else {
            switch (postfix.data[i]) {
                case -1:
                    stack.data[tos - 1] = stack.data[tos - 1] / stack.data[tos];
                    tos--;
                    break;
                case -2:
                    stack.data[tos - 1] = stack.data[tos - 1] * stack.data[tos];
                    tos--;
                    break;
                case -4:
                    stack.data[tos - 1] = stack.data[tos - 1] - stack.data[tos];
                    tos--;
                    break;
                case -5:
                    stack.data[tos - 1] = stack.data[tos - 1] + stack.data[tos];
                    tos--;
                    break;
            }
        }
    }

    std::cout << stack.data[tos];
}

void Calculator::run() {
    char symbol;
    int number;

    while (true) {
        tail++;
        std::cin >> postfix.data[tail];
        std::cin >> symbol;
        number = convert(symbol);
        if (number == -7) {
            break;
        }

        if (tos == -1) {
            tos++;
            stack.data[tos] = number;
        } else {
            int n = tos + 1;
            for (int i = 0; i <= n; i++) {
                if (tos == -1) {
                    tos++;
                    stack.data[tos] = number;
                    break;
                } else {
                    if ((number - 1) <= stack.data[tos]) {
                        tail++;
                        postfix.data[tail] = stack.data[tos];
                        tos--;
                    } else {
                        tos++;
                        stack.data[tos] = number;
                        break;
                    }
                }
            }
        }
    }

    int n = tos;
    for (int i = 0; i <= n; i++) {
        tail++;
        postfix.data[tail] = stack.data[tos];
        tos--;
    }

    std::cout << "\n";
    evaluatePostfix();

    getch();
}
