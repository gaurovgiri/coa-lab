#include <iostream>

using namespace std;


/**
 * The function BinaryMultiply takes two binary numbers as input and returns their product as a binary
 * number.
 * 
 * @param multplicand An array representing the first binary number.
 * @param multiplier The parameter `multiplier` represents the second binary number that you want to
 * multiply with `multplicand`.
 * @param multiplicandSizeThe size of the first binary number (multplicand).
 * @param multiplierSize The parameter "multiplierSize" represents the size of the second binary number, "multiplier".
 * @param resultSize The parameter `resultSize` represents the size of the resulting binary array after
 * multiplying `multplicand` and `multiplier`.
 * 
 * @return a pointer to an integer array.
 */
int *BinaryMultiply(int *multplicand, int *multiplier, int multiplicandSize, int multiplierSize, int resultSize)
{
    int *result = new int[resultSize];
    int carry = 0, weight = 1, raw_sum;
    
    for (int i = 0; i < resultSize; i++)
    {
        result[i] = 0;
    }

    for (int i = multiplicandSize-1; i >= 0; i--)
    {
        for (int j = multiplierSize-1; j >= 0; j--)
        {
            raw_sum = multplicand[i] * multiplier[j] + result[i+j+1] + carry;
            result[i+j+1] = raw_sum % 2;
            carry = raw_sum / 2;
        }
        result[i] = carry;
        carry = 0;
    }

    return result;
}


int main()
{
    int multiplicandSize, multiplierSize, resultSize;
    int *multplicand, *multiplier, *result;

    cout << "Enter the size of the Multiplicand: ";
    cin >> multiplicandSize;

    cout << "Enter the size of the Multiplier: ";
    cin >> multiplierSize;

    resultSize = multiplicandSize+ multiplierSize;

    multplicand = new int[multiplicandSize];
    multiplier = new int[multiplierSize];

    cout << "Multiplicand: ";
    for (int bit_pos = multiplicandSize-1; bit_pos >= 0; bit_pos--)
    {
    
        cin >> multplicand[bit_pos];
    }

    cout << "Multiplier: ";
    for (int bit_pos = multiplierSize-1; bit_pos >= 0; bit_pos--)
    {
        cin >> multiplier[bit_pos];
    }

    result = BinaryMultiply(multplicand, multiplier, multiplicandSize, multiplierSize,resultSize);

    cout << "Result: ";
    for (int bit_pos = 0; bit_pos < resultSize; bit_pos++)
    {
        cout << result[bit_pos];
    }
    cout << endl;

    return 0;
}

