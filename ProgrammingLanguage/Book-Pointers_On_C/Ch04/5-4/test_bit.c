#define MAXSIZE 32
int test_bit(char bit_array[], unsigned bit_number)
{
    bit_number = (bit_number - 1) % MAXSIZE;
    if (bit_array[MAXSIZE - bit_number - 1] == '0') {
        return 0;
    } else {
        return 1;
    }
}