#include <iostream>

using namespace std;
void BinaryMultiply(int *, int *, int *, int, int, int);

int main()
{

    int *multplicand, *multiplier, *result;
    int multiplicandSize, multiplierSize, resultSize;

    cout << "Enter the size of the Multiplicand: ";
    cin >> multiplicandSize;

    cout << "Enter the size of the Multiplier: ";
    cin >> multiplierSize;

    resultSize = multiplicandSize + multiplierSize;

    multplicand = new int[multiplicandSize];
    multiplier = new int[multiplierSize];
    result = new int[resultSize];

    cout << "Enter the Multiplicand: ";
    for (int i = 0; i < multiplicandSize; i++)
    {
        cin >> multplicand[i];
    }

    cout << "Enter the Multiplier: ";
    for (int i = 0; i < multiplierSize; i++)
    {
        cin >> multiplier[i];
    }

    BinaryMultiply(multplicand, multiplier, result, multiplicandSize, multiplierSize, resultSize);

    cout << "Product: ";
    for (int i = 0; i < resultSize; i++)
    {
        cout << result[i];
    }
    cout << endl;

    return 0;
}

/**
 * The BinaryMultiply function performs binary multiplication on two arrays of integers and stores the
 * result in another array.
 * 
 * @param multiplicand An array representing the binary digits of the multiplicand.
 * @param multiplier An array representing the binary representation of the multiplier. Each element of
 * the array can be either 0 or 1.
 * @param result The `result` parameter is an array that will store the result of the binary
 * multiplication.
 * @param multiplicandSize The size of the array `multiplicand`, which represents the number being
 * multiplied.
 * @param multiplierSize The parameter `multiplierSize` represents the size of the array `multiplier`.
 * It indicates the number of elements in the `multiplier` array.
 * @param resultSize The parameter `resultSize` represents the size of the `result` array. It indicates
 * the number of bits required to store the result of the binary multiplication.
 */
void BinaryMultiply(int *multiplicand, int *multiplier, int *result, int multiplicandSize, int multiplierSize, int resultSize)
{
    int rawSum, carry = 0;
    for (int i = 0; i < resultSize; i++)
    {
        result[i] = 0;
    }

    for (int i = multiplierSize - 1; i >= 0; i--)
    {
        if (multiplier[i] == 1)
        {
            for (int j = multiplicandSize - 1; j >= 0; j--)
            {
                rawSum = multiplicand[j] + result[i + j + 1] + carry;
                result[i + j + 1] = rawSum % 2;
                carry = rawSum / 2;
            }
        }
    }
}
