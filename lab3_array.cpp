#include <iostream>

using namespace std;

/**
 * The function `multiplyBinary` performs binary multiplication on two arrays of binary digits and
 * stores the result in another array.
 * 
 * @param multiplicand An array representing the binary digits of the multiplicand. The size of the
 * array is given by size1.
 * @param size1 The parameter `size1` represents the size of the `multiplicand` array.
 * @param multiplier The `multiplier` parameter is an array of integers representing a binary number.
 * Each element in the array can be either 0 or 1.
 * @param size2 The parameter `size2` represents the size of the `multiplier` array.
 * @param result The `result` parameter is an array that will store the result of the binary
 * multiplication.
 */
void multiplyBinary(int multiplicand[], int size1, int multiplier[], int size2, int result[]) {
    int sizeResult = size1 + size2;

    // Initialize the result array with zeros
    for (int i = 0; i < sizeResult; ++i) {
        result[i] = 0;
    }

    // Perform binary multiplication
    for (int i = size1 - 1; i >= 0; --i) {
        for (int j = size2 - 1; j >= 0; --j) {
            int product = multiplicand[i] * multiplier[j];

            // Add the product to the result array
            result[i + j + 1] += product;
            result[i + j] += result[i + j + 1] / 2; // Add carry to next bit
            result[i + j + 1] %= 2; // Remove carry from current bit
        }
    }
}

int main() {
    int size1, size2;

    // Read the size of the multiplicand
cout << "Enter the size of the multiplicand: ";
    cin >> size1;

    // Read the size of the multiplier
    cout << "Enter the size of the multiplier: ";
    cin >> size2;

    // Read the multiplicand
    int multiplicand[size1];
    cout << "Enter the multiplicand: ";
    for (int i = 0; i < size1; ++i) {
        cin >> multiplicand[i];
    }

    // Read the multiplier
    int multiplier[size2];
    cout << "Enter the multiplier: \t";
    for (int i = 0; i < size2; ++i) {
        cin >> multiplier[i];
    }

    // Calculate the size of the result array
    int sizeResult = size1 + size2;

    // Initialize the result array
    int result[sizeResult];

    // Multiply the binary numbers
    multiplyBinary(multiplicand, size1, multiplier, size2, result);

    // Display the product array
    cout << "Product array: ";
    for (int i = 0; i < sizeResult; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
