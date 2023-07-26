#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void Eratosthenes(char *prime, unsigned int size, unsigned int base);
void ShowPrime(char *prime, unsigned int size, unsigned int base);
bool IsItNotPrime(unsigned num);

/* 自行确保下标不会越界 */
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入1-2个数作为范围！\n");
        return -1;
    }
    unsigned int min;
    unsigned int max;
    if (argc < 3) {
        min = 0;
        max = (unsigned int) atoi(argv[1]);
    } else {
        min = (unsigned int) atoi(argv[1]);
        max = (unsigned int) atoi(argv[2]);
        if (min < max) {
            int temp = min;
            min = max;
            max = temp;
        }
    }
    unsigned size = max - min + 1;
    char *prime;
    prime = (char *) malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        set_bit(prime, i);
    }
    Eratosthenes(prime, size, min);
    ShowPrime(prime, size, min);
    free(prime);

    return 0;
}
void Eratosthenes(char *prime, unsigned int size, unsigned int base)
{
    for (int i = 0; i < size; i++) {
        if (i + base == 0) {
            clear_bit(prime, i);
        } else if (i + base == 1) {
            clear_bit(prime, i);
        } else if (test_bit(prime, i)) {
            if (IsItNotPrime(base + i)) {
                int j = 1;
                while ((i + base) * j - base <= size + base) {
                    clear_bit(prime, (i + base) * j++ - base);
                }
            }
        }
    }
}
void ShowPrime(char *prime, unsigned int size, unsigned int base)
{
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (test_bit(prime, i)) {
            printf("%-10u ", i + base);
            cnt++;
            if (cnt % 5 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");
}
bool IsItNotPrime(unsigned num)
{
    for (int i = num - 1; i > 1; i--) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}
void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '1';
}
void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '0';
}
int test_bit(char bit_array[], unsigned bit_number)
{
    if (bit_array[bit_number] == '0') {
        return 0;
    }
    return 1;
}