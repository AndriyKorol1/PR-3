#include <stdio.h>

// Функція для обчислення кількості допустимих чисел довжиною р
int countNumbers(int p) {
    if (p == 1) return 2; // Якщо довжина 1, то можливі два числа: 5 і 9

    // Масиви для зберігання кількості чисел
    int dp5[p+1], dp55[p+1], dp9[p+1], dp99[p+1];


    dp5[1] = 1;
    dp55[1] = 0;
    dp9[1] = 1;
    dp99[1] = 0;

    for (int i = 2; i <= p; i++) {
        dp5[i] = dp9[i-1] + dp99[i-1];
        dp55[i] = dp5[i-1];
        dp9[i] = dp5[i-1] + dp55[i-1];
        dp99[i] = dp9[i-1];
    }


    return dp5[p] + dp55[p] + dp9[p] + dp99[p];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int p;
    printf("Введіть кількість розрядів p: ");
    scanf("%d", &p);

    if (p > 30) {
        printf("Кількість розрядів повинна бути не більше 30.\n");
        return 1;
    }

    int result = countNumbers(p);
    printf("Кількість чисел довжиною %d розрядів: %d\n", p, result);

    return 0;
}
