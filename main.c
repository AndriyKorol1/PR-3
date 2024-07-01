#include <stdio.h>

// ������� ��� ���������� ������� ���������� ����� �������� �
int countNumbers(int p) {
    if (p == 1) return 2; // ���� ������� 1, �� ������ ��� �����: 5 � 9

    // ������ ��� ��������� ������� �����
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
    printf("������ ������� ������� p: ");
    scanf("%d", &p);

    if (p > 30) {
        printf("ʳ������ ������� ������� ���� �� ����� 30.\n");
        return 1;
    }

    int result = countNumbers(p);
    printf("ʳ������ ����� �������� %d �������: %d\n", p, result);

    return 0;
}
