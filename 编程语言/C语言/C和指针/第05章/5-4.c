void set_bit(char bit_array[], unsigned bit_number)
{
    if (!bit_array[bit_number - 1]) {
        bit_array[bit_number - 1] = 1;
    }
}
void clear_bit(char bit_array[], unsigned bit_number)
{
    if (bit_array[bit_number - 1]) {
        bit_array[bit_number - 1] = 0;
    }
}
void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    if (!value) {
        clear_bit(bit_array, bit_number);
    } else {
        set_bit(bit_array, bit_number);
    }
}
int test_bit(char bit_array[], unsigned bit_number)
{
    if (bit_array[bit_number - 1]) {
        return 1;
    } else {
        return 0;
    }
}