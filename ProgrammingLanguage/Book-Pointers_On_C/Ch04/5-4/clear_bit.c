#define MAXSIZE 32
void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_number = (bit_number - 1) % MAXSIZE;
    bit_array[MAXSIZE - bit_number - 1] = '0';
}