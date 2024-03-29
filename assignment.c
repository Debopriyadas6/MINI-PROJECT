#include <stdio.h>
#include <time.h>

#define MAX 4500

char result[MAX], temp_1[MAX], temp_2[MAX];

void addition()
{
    int carry = 0;
    for (int i = MAX - 1; i >= 0; i--)
    {
        int digit = (temp_1[i] - '0') + (temp_2[i] - '0') + carry;
        result[i] = (digit % 10) + '0';
        carry = digit / 10;
    }
}

void fibonacci(int N)
{
    if (N == 1 || N == 0)
    {
        printf("%d", N);
        return;
    }
    for (int i = 2; i <= N; i++)
    {
        addition();
        for (int i = 0; i < MAX; i++)
        {
            temp_1[i] = temp_2[i];
            temp_2[i] = result[i];
        }
    }
    int firstDigit = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (firstDigit == 0 && result[i] == '0')
        {
            continue;
        }

        if (firstDigit == 0 && result[i] != '0')
        {
            firstDigit = 1;
        }
        printf("%c", result[i]);
    }
}

int main()
{
    int N;
    printf("Enter the index of the fibonacci number to be found :\n");
    scanf("%d", &N);

    for (int i = 0; i < MAX; i++)
    {
        temp_1[i] = '0';
        temp_2[i] = '0';
        result[i] = '0';
    }
    temp_2[MAX - 1] = '1';

    printf("The %dth fibonacci number is : \n", N);
    fibonacci(N);
    printf("\n");

    return 0;
}