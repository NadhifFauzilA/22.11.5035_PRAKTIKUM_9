#include "Calculator.h"
#include <iostream>

int main() {
    char choice;

    do {
        system("cls");
        std::cout <<"==================== Kalkulator Postfix ==============================\n";
        std::cout << "Masukan angka , Masukan operasi + - * / diakhiri dengan = tanpa spasi \n";
        std::cout << "Input : ";

        Calculator calculator;
        calculator.run();
        std::cout << "\nApakah ingin menghitung lagi (Y/N) : ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
