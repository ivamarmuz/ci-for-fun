#include <stdio.h>

void printBits(int);
int reverseBits(int);

enum {BITS_COUNT = sizeof(int) * 8 - 1};

int main()
{
    int number;

    printf("Enter your number: ");
    scanf("%d", &number);
    printBits(number);
    printBits(reverseBits(number));

    return 0;
}

void printBits(int numb)
{
    int c, i = 1 << BITS_COUNT;

    printf("%d = ", numb);

    for (c = 0; c <= BITS_COUNT; c++) {
        numb & i ? printf("1") : printf("0");
        numb <<= 1;
        if((c + 1) % 8 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

int reverseBits(int numb)
{
    int c, result = 0;

    for (c = 0; c <= BITS_COUNT; ++c) {
        result |= ((numb >> c) & 1) << (BITS_COUNT - c);
    }

    return result;
}