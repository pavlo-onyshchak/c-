#include"BinaryFunctions.h"

bool isOdd(int number)
{
    auto mask = 0b0001;
    return number & mask;
}

int addOne(int number)
{
    auto mask = 1;
    while (number & mask)
    {
        number ^= mask;
        mask <<= 1;
    }
    number ^= mask;
    return number;
}

int countOfBinaryUnits(int number)
{
    const auto mask = 1;
    auto counter = 0;
    while (number)
    {
        if (number & mask)
        {
            counter++;
        }
        number >>= 1;
    }
    return counter;
}

long long setBits(long long number,int count_of_bits)

{
    for (int i = 0; i < count_of_bits; i++)
    {
        if (isOdd(i))
        {
            number &= ~(1ll << i);
        }
        else {
            number |= (1ll << i);
        }
    }
    return number;
}
