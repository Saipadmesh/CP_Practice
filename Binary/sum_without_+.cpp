#include <iostream>
using namespace std;
int sum(int a, int b)
{
    while (b != 0)
    {
        unsigned carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    cout << sum(-12, -8) << endl;
}