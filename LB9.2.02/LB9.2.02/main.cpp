#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_DIVISOR 2  // ������� ���������� ��� ���������� ������� ��������

// ������� ��� ��������, �� � ������ ������ (��� ������������ <ctype.h>)
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// ������� ��� ��������, �� � ������ ������ (��� ������������ <ctype.h>)
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// ������� ��� ��������� �� ��������� �������
void buildMatrix(int rows, int cols);

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);  // �������� ����� �� �����������

    int rows = 0, cols = 0;
    int foundDigit = 0, foundAlpha = 0;

    // ���� ��� ����������� ������� ����������� ��������� �� ������� ���������� �������
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_digit(input[i]) && input[i] != '0' && !foundDigit) {
            rows = input[i] - '0';  // ��������� ������� ����� �� ����� ����� �����
            foundDigit = 1;         // ������������ ���������, �� ����� ��������
        }
        else if (is_alpha(input[i]) && !foundAlpha) {
            cols = (input[i] / ROW_DIVISOR);  // ��������� ������� �������� �� ����� ASCII-���� �����
            foundAlpha = 1;                   // ������������ ���������, �� ����� ��������
        }
        if (foundDigit && foundAlpha) break;  // �������� � �����, ���� ������ �������� �������
    }

    // �������� �� �������� ��������� ������� ��� ������� ����� �� ��������
    if (rows > 0 && cols > 0) {
        printf("Matrix dimensions: %d x %d\n", rows, cols);
        buildMatrix(rows, cols);  // ������ ������� ��� �������� �������
    }
    else {
        printf("Invalid input for matrix creation.\n");
    }

    return 0;
}

// ������� ��� �������� �� ��������� �������
void buildMatrix(int rows, int cols) {
    // �������� �������� ���'�� ��� 2D ������
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    int num = 1;  // ��������� �������� ��� ���������� �������

    // ���������� ������� ����������� �������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = num++;
            printf("%2d ", matrix[i][j]);  // ��������� �������� � �������������
        }
        printf("\n");
    }

    // ��������� ������� ���'��
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

//3abc5def ��������