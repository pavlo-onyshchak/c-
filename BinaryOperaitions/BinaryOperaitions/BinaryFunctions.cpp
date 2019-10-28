#include"BinaryFunctions.h"

bool isOdd(const int& number)
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

int sumOfTwoElem(const int& first,const int& second)
{
    const auto bitsNumber = sizeof(int) * 8;
    auto sum = 0;
    auto mask = 1;
    auto carry = 0;
    for (int i = 0; i < bitsNumber; i++)
    {
        if (first & (mask<<i) && second & (mask<<i))
        {
            if (carry == 1)
            {
                sum |= (mask << i);
            }
            else
            {
                sum &= ~(mask << i);
                carry = 1;
            }
        }
        else if (!(first & (mask << i)) && second & (mask << i))
        {
            if (carry == 1)
            {
                sum &= ~(mask << i);
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
                sum &= ~(mask << i);
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

bool testSumOfTwoElem()
{
    auto actual = 0;
    actual = sumOfTwoElem(15, 15);//1111 + 1111
    auto expected = 15 + 15;
    if (actual != expected)
    {
        throw "15 + 15 is not equal 30";
    }

    actual = sumOfTwoElem(5, 10);// 0101 + 1010
    expected = 5 + 10;
    if (actual != expected)
    {
        throw "5 + 10 is not equal 15";
    }

    actual = sumOfTwoElem(15, 0);// 1111 + 0000
    expected = 15 + 0;
    if (actual != expected)
    {
        throw "15 + 0 is not equal 15";
    }

    actual = sumOfTwoElem(-5, 10);
    expected = -5 + 10;
    if (actual != expected)
    {
        throw "-5 + 10 is not equal 5";
    }
   
    actual = sumOfTwoElem(-15, -15);
    expected = -15 - 15;
    if (actual != expected)
    {
        throw "-15 -15 is not equal -39";
    }
    return true;   
}
