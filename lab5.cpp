#include <iostream>

using namespace std;

int add(int[], int[], int);
void get_twos_complement(int[], int);
void shift_left(int[], int[], int);

int main()
{
    int n;
    cout << "GAURAV GIRI (KAN077BCT034)" << endl;
    cout << "Enter the number of bits: ";
    cin >> n;

    int count = n;
    int *Q = new int[n];       // Dividend
    int *M = new int[n + 1];   // Divisor
    int *M2s = new int[n + 1]; // Divisor's Two's Complement for Subtraction
    int *A = new int[n + 1];   // Remainder

    // Initializing MSB's to 0
    M[0] = 0;
    A[0] = 0;
    M2s[0] = 0;

    // Input Dividend and Divisor
    cout << "Enter the Dividend: ";
    for (int i = 0; i < n; i++)
        cin >> Q[i];

    cout << "Enter the Divisor: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> M[i];
        M2s[i] = M[i];
        A[i] = 0;
    }

    // Get Two's Complement of Divisor
    get_twos_complement(M2s, n + 1);

    // Perform Division
    for (int i = count; i > 0; i--)
    {
        if (A[0] == 1) // if A is negative
        {
            shift_left(A, Q, n);
            add(A, M, n + 1); // A = A + M
        }
        else
        {
            shift_left(A, Q, n);
            add(A, M2s, n + 1); // A = A + (-M)
        }

        if (A[0] == 1) // if A is negative
        {
            Q[n - 1] = 0; // q0 <- 0
        }
        else
        {
            Q[n - 1] = 1; // q0 <- 1
        }
    }

    if (A[0] == 1) // if A is negative
    {
        add(A, M, n + 1); // A = A + M
    }

    // Display Results
    cout << "Remainder: ";
    for (int i = 0; i <= n; i++)
    {
        cout << A[i];
    }
    cout << endl;

    cout << "Quotient: ";
    for (int i = 0; i < n; i++)
    {
        cout << Q[i];
    }
    cout << endl;

    return 0;
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
    one[n - 1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        one[i] = 0;
    }

    add(a, one, n);
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
