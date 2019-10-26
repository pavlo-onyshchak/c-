#include"BinaryFunctions.h"

bool isOdd(int& number)
{
    auto mask = 0b0001;
    return number & mask;
}

int addOne(int& number)
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

int countOfBinaryUnits(int& number)
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

long long setBits(long long& number, int count_of_bits)
{
    for (int i = 0; i < count_of_bits; i++)
    {
        if (isOdd(i))
        {
            number &= ~(1ll << i);
        }
        else 
        {
            number |= (1ll << i);
        }
    }
    return number;
}

int sumOfTwoElem(int& first, int& second)
{
    const auto bitsNumber = 32;
    auto sum = 0;
    auto mask = 1;
    auto carry = 0;
    for (int i = 0; i < bitsNumber; i++)
    {
        if (first & (mask<<i) && second & (mask<<i))
        {
            sum &= ~(mask<<i);
            carry = 1;
        }
        else if (!(first & (mask << i)) && second & (mask << i))
        {
            if (carry == 1)
            {
                sum &= (mask << i);
            }
            else
            {
                sum |= (mask << i);
                carry = 0;
            }
        }
        else if (first & (mask << i) && !(second & (mask << i)))
        {
            if (carry == 1)
            {
                sum &= (mask << i);
            }
            else
            {
                sum |= (mask << i);
                carry = 0;
            }
        }
        else
        {
            if (carry == 1)
            {
                sum |= (mask << i);
                carry = 0;
            }
            else
            {
                sum &= ~(mask << i);
                carry = 0;
            }
        }
    }
    return sum;
}
