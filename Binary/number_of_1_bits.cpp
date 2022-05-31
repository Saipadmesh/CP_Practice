#include <iostream>
using namespace std;
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        int val = n % 2;
        if (val == 1)
        {
            count++;
        }
        n = n / 2;
    }
    return count;
}

int main()
{
    cout << hammingWeight(9) << endl;
}