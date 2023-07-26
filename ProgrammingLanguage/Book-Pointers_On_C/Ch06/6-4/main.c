#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void Eratosthenes(bool *prime, unsigned int size, unsigned int base);
void ShowPrime(bool *prime, unsigned int size, unsigned int base);
bool IsItNotPrime(unsigned num);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入1-2个参数作为界限！\n");
        return -1;
    }
    unsigned int max;
    unsigned int min;
    if (argc < 3) {
        min = 0;
        max = (unsigned int) atoi(argv[1]);
    } else {
        min = (unsigned int) atoi(argv[1]);
        max = (unsigned int) atoi(argv[2]);
        if (min > max) {
            int temp = min;
            min = max;
            max = temp;
        }
    }
    unsigned int size = max - min + 1;
    bool *prime;
    prime = (bool *) malloc(size * sizeof(bool));
    for (int i = 0; i < size; i++) {
        prime[i] = true;
    }
    Eratosthenes(prime, size, min);
    ShowPrime(prime, size, min);
    free(prime);

    return 0;
}
void Eratosthenes(bool *prime, unsigned int size, unsigned int base)
{
    for (int i = 0; i < size; i++) {
        if (i + base == 0) {
            prime[i] = false;
        } else if (i + base == 1) {
            prime[i] = false;
        } else if (prime[i] == true) {
            if (IsItNotPrime(base + i)) {
                int j = 1;
                while ((i + base) * j - base <= size + base) {
                    prime[(i + base) * j++ - base] = false;
                }
            }
        }
    }
}
void ShowPrime(bool *prime, unsigned int size, unsigned int base)
{
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (prime[i]) {
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