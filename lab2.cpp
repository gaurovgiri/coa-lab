#include <iostream>

using namespace std;

int add(int *, int *, int *, int);
int sub(int *, int *, int *, int);
int *getTwosComplement(int *, int);

int main()
{
    int n, *b1, *b2, *sum, bit_pos, carry;

    cout << "Enter the total bit size: ";
    cin >> n;

    b1 = new int[n];
    b2 = new int[n];
    sum = new int[n];

    cout << "B1: ";
    for (bit_pos = 0; bit_pos < n; bit_pos++)
    {
        cin >> b1[bit_pos];
    }

    cout << "B2: ";

    for (bit_pos = 0; bit_pos < n; bit_pos++)
    {
        cin >> b2[bit_pos];
    }

    cout << "------------------------" << endl;

    carry = add(b1, b2, sum, n);

    cout << "SUM: ";
    cout << carry;

    for (bit_pos = 0; bit_pos < n; bit_pos++)
        cout << sum[bit_pos];
    cout << endl;



    cout << "SUB: ";
    carry = sub(b1, b2, sum, n);

    if (carry == 0)
    {
        cout << "-";
        int *result  = new int[n];
        result = getTwosComplement(sum, n);
        for (bit_pos = 0; bit_pos < n; bit_pos++)
            cout << result[bit_pos];
    }

    else{
        cout << "+";
        for (bit_pos = 0; bit_pos < n; bit_pos++)
            cout << sum[bit_pos];
    }


    cout << endl;

    return 0;
}

int add(int *b1, int *b2, int *sum, int n)
{
    int carry = 0;

    for (int bit_pos = n - 1; bit_pos >= 0; bit_pos--)
    {
        sum[bit_pos] = (b1[bit_pos] + b2[bit_pos] + carry) % 2;
        carry = (b1[bit_pos] + b2[bit_pos] + carry) / 2;
    }
    return carry;
}

int *getTwosComplement(int *bin, int n)
{
    int *onesComplement = new int[n];
    int *twosComplement = new int[n];
    int *one = new int[n];

    for (int i = 0; i < n - 1; i++)
        one[i] = 0;

    one[n - 1] = 1;

    for (int i = 0; i < n; i++)
        onesComplement[i] = (bin[i] + 1) % 2;


    add(onesComplement, one, twosComplement, n);
    return twosComplement;
}

int sub(int *b1, int *b2, int *diff, int n)
{
    int carry = 0;
    int *twosComplement = getTwosComplement(b2, n);
    carry = add(b1, twosComplement, diff, n);
    return carry;
}
