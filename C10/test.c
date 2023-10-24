#include <stdio.h>

// Функция, которой передается двумерный массив
void processArray(int n, int m, int arr[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Введите количество строк: ");
    scanf("%d", &rows);

    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    int myArray[rows][cols];

    // Инициализируем массив
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            myArray[i][j] = i * cols + j + 1;
        }
    }

    // Вызываем функцию и передаем массив, указывая его размеры
    processArray(rows, cols, myArray);

    return 0;
}
