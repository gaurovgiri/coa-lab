#include <iostream>

using namespace std;

int add(int[], int[], int);
void get_twos_complement(int[], int);
void shift_left(int[], int[], int);

int main()
{
    int number_of_bits;
    cout << "Enter the number of bits: ";
    cin >> number_of_bits;

    int *divisor = new int[number_of_bits + 1];
    int *twos_complement_of_divisor = new int[number_of_bits + 1];
    int *dividend = new int[number_of_bits];
    int *remainder = new int[number_of_bits + 1];

    cout << "Enter the dividend: ";
    for (int i = 0; i < number_of_bits; i++)
    {
        cin >> dividend[i];
    }

    cout << "Enter the divisor: ";
    divisor[0] = twos_complement_of_divisor[0] = 0;
    for (int i = 1; i <= number_of_bits; i++)
    {
        cin >> divisor[i];
        twos_complement_of_divisor[i] = divisor[i];
    }

    for (int i = 0; i <= number_of_bits; i++)
    {
        remainder[i] = 0;
    }

    get_twos_complement(twos_complement_of_divisor, number_of_bits + 1);

    for (int i = number_of_bits; i > 0; i--)
    {
        shift_left(remainder, dividend, number_of_bits);
        add(remainder, twos_complement_of_divisor, number_of_bits + 1);

        if (remainder[0] == 1)
        {
            dividend[number_of_bits - 1] = 0; // q0 <- 0
            add(remainder, divisor, number_of_bits + 1);
        }
        else
        {
            dividend[number_of_bits - 1] = 1; // q0 <- 1
        }
    }

    cout << endl
         << "Remainder: ";
    for (int i = 0; i <= number_of_bits; i++)
    {
        cout << remainder[i];
    }

    cout << endl
         << "Quotient: ";
    for (int i = 0; i < number_of_bits; i++)
    {
        cout << dividend[i];
    }
}

/**
 * The function takes two arrays of integers and adds them together, returning the carry value.
 * 
 * @param a An array of integers representing the first binary number.
 * @param b The parameter "b" is an array of integers.
 * @param n The number of elements in the arrays a[] and b[].
 * 
 * @return the carry value after adding the two arrays.
 */
int add(int a[], int b[], int n)
{
    int carry = 0;
    int temp;
    for (int i = n - 1; i >= 0; i--)
    {
        temp = a[i];
        a[i] = (a[i] + b[i] + carry) % 2;
        carry = (temp + b[i] + carry) / 2;
    }
    return carry;
}

/**
 * The function `get_twos_complement` takes an array of integers and converts it to its two's
 * complement representation.
 * 
 * @param a An array of integers representing a binary number in two's complement form.
 * @param n The parameter `n` represents the size of the array `a[]`.
 */
void get_twos_complement(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }

    int *one = new int[n];
    one[n-1] =1;
    for(int i=0; i< n-1 ; i++){
        one[i] =0;
    }

    add(a,one, n);
}

/**
 * The function "shift_left" shifts the elements of array "a" and array "q" to the left by one
 * position.
 * 
 * @param a An array of integers that represents the elements to be shifted.
 * @param q An array of integers representing the elements to be shifted.
 * @param n The parameter `n` represents the size of the arrays `a` and `q`.
 */
void shift_left(int a[], int q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    a[n] = q[0];

    for (int i = 0; i < n - 1; i++)
    {
        q[i] = q[i + 1];
    }
}
