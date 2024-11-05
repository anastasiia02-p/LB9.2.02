#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_DIVISOR 2  // Задайте коефіцієнт для обчислення кількості стовпців

// Функція для перевірки, чи є символ цифрою (без використання <ctype.h>)
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Функція для перевірки, чи є символ буквою (без використання <ctype.h>)
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Функція для створення та виведення матриці
void buildMatrix(int rows, int cols);

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);  // Отримуємо рядок від користувача

    int rows = 0, cols = 0;
    int foundDigit = 0, foundAlpha = 0;

    // Цикл для знаходження першого ненульового цифрового та першого буквенного символів
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_digit(input[i]) && input[i] != '0' && !foundDigit) {
            rows = input[i] - '0';  // Визначаємо кількість рядків на основі першої цифри
            foundDigit = 1;         // Встановлюємо прапорець, що цифра знайдена
        }
        else if (is_alpha(input[i]) && !foundAlpha) {
            cols = (input[i] / ROW_DIVISOR);  // Визначаємо кількість стовпців на основі ASCII-коду букви
            foundAlpha = 1;                   // Встановлюємо прапорець, що літера знайдена
        }
        if (foundDigit && foundAlpha) break;  // Виходимо з циклу, коли обидва значення знайдені
    }

    // Перевірка на наявність коректних значень для кількості рядків та стовпців
    if (rows > 0 && cols > 0) {
        printf("Matrix dimensions: %d x %d\n", rows, cols);
        buildMatrix(rows, cols);  // Виклик функції для побудови матриці
    }
    else {
        printf("Invalid input for matrix creation.\n");
    }

    return 0;
}

// Функція для побудови та виведення матриці
void buildMatrix(int rows, int cols) {
    // Динамічне виділення пам'яті для 2D масиву
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    int num = 1;  // Початкове значення для заповнення матриці

    // Заповнення матриці послідовними числами
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = num++;
            printf("%2d ", matrix[i][j]);  // Виведення значення з форматуванням
        }
        printf("\n");
    }

    // Звільнення виділеної пам'яті
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

//3abc5def перевірка