#define MAXSIZE 32
void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    bit_number = (bit_number - 1) % MAXSIZE;
    if (value == 0) {
        bit_array[MAXSIZE - bit_number - 1] = '0';
    } else {
        bit_array[MAXSIZE - bit_number - 1] = '1';
    }
}