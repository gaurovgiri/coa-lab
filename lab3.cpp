#include <iostream>

using namespace std;

long long add(long long, long long);

int main()
{
    int multiplicand, multiplier, lsb;
    int weight = 1;
    long long partial_sum = 0;
    

    cout << "Enter the multiplicand: ";
    cin >> multiplicand;

    cout << "Enter the multiplier: ";
    cin >> multiplier;

    while (multiplier != 0)
    {
        lsb = multiplier % 10;
        if (lsb)
            partial_sum = add(partial_sum, static_cast<long long>(weight * multiplicand));
       
        multiplier /= 10;
        weight *= 10;
    }

    cout << "The output is : " << partial_sum << endl;

    return 0;
}

long long add(long long binary_1, long long binary_2)
{
    int carry = 0;
    long long sum = 0, weight = 1, raw_sum;

    while (binary_1 != 0 || binary_2 != 0)
    {
        raw_sum = binary_1 % 10 + binary_2 % 10 + carry;
        sum += (raw_sum % 2) * weight;
        carry = raw_sum / 2;
        weight *= 10;
        binary_1 /= 10;
        binary_2 /= 10;
    }

    sum = sum + static_cast<long long>(carry * weight);
    return sum;

}