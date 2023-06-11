#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX 100

struct Stack {
    int data[MAX];
};

struct Queue {
    int data[MAX];
};

class Calculator {
private:
    Stack stack;
    Queue postfix;
    int tail;
    int tos;

    int convert(char symbol);
    void evaluatePostfix();

public:
    Calculator();
    void run();
};

#endif  // CALCULATOR_H
