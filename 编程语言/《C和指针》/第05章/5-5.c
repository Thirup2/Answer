int store_bit_field(int original_value,
                    int value_to_store,
                    unsigned starting_bit,
                    unsigned ending_bit)
{
    int mask = 0;
    int i = 1;
    int j = 0;
    // 步骤1
    for (i <<= ending_bit; j <= starting_bit - ending_bit; i <<= 1, ++j) {
        mask |= i;
    }
    // 步骤2
    original_value &= ~mask;
    // 步骤3
    value_to_store <<= ending_bit;
    // 步骤4
    value_to_store &= mask;
    // 步骤5
    value_to_store |= original_value;

    return value_to_store;
}