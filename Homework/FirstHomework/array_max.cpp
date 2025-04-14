#include <cstdio>
#include <cstring>

// �ִ��� ã�� �Լ�
int findArrayMax(int score[], int n)
{
    int tmp = score[0];
    for (int i = 1; i < n; i++) {
        if (score[i] > tmp) {
            tmp = score[i];
        }
    }
    return tmp;
}

// �迭�� ���ڿ��� ��ȯ�ϴ� �Լ�
void arrayToString(int arr[], int n, char* buffer, size_t bufferSize)
{
    buffer[0] = '\0'; // ���ڿ� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        char numStr[12];
        sprintf_s(numStr, sizeof(numStr), "%d", arr[i]);              // ������ ���
        strcat_s(buffer, bufferSize, numStr);                         // ������ �����̱�
        if (i < n - 1) {
            strcat_s(buffer, bufferSize, ", ");                       // �޸� �߰�
        }
    }
}

int main()
{
    int arr1[] = { 3, 7, 2, 9, 10, 5 };
    int arr2[] = { -10, -5, -3 };
    int arr3[] = { 100, 200, 300, 50, 400 };
    int arr4[] = { 0, 0, -2, 0 };
    int arr5[] = { 10000 };

    // ��� ���
    printf("%-30s   %s\n", "Numbers", "Max");
    printf("------------------------------   -----\n");

    char buffer[100];

    arrayToString(arr1, sizeof(arr1) / sizeof(int), buffer, sizeof(buffer));
    printf("%-30s   %d\n", buffer, findArrayMax(arr1, sizeof(arr1) / sizeof(int)));

    arrayToString(arr2, sizeof(arr2) / sizeof(int), buffer, sizeof(buffer));
    printf("%-30s   %d\n", buffer, findArrayMax(arr2, sizeof(arr2) / sizeof(int)));

    arrayToString(arr3, sizeof(arr3) / sizeof(int), buffer, sizeof(buffer));
    printf("%-30s   %d\n", buffer, findArrayMax(arr3, sizeof(arr3) / sizeof(int)));

    arrayToString(arr4, sizeof(arr4) / sizeof(int), buffer, sizeof(buffer));
    printf("%-30s   %d\n", buffer, findArrayMax(arr4, sizeof(arr4) / sizeof(int)));

    arrayToString(arr5, sizeof(arr5) / sizeof(int), buffer, sizeof(buffer));
    printf("%-30s   %d\n", buffer, findArrayMax(arr5, sizeof(arr5) / sizeof(int)));

    return 0;
}
