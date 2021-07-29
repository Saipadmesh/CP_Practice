#include <iostream>
using namespace std;

int main() {
  unsigned int a = 9, b = 5; // 9:00000000000000000000000000001001, 5:00000101
  unsigned int c = a | b;    // 1101
  cout << "a OR b: " << c << endl;
  c = a & b; // 0001
  cout << "a AND b: " << c << endl;
  c = a ^ b; // 1100
  cout << "a XOR b: " << c << endl;
  c = a << b; // 100100000
  cout << "a LEFT SHIFT b: " << c << endl;
  c = a >> 3;
  cout << "a RIGHT SHIFT b: " << c << endl;
  c = ~a;
  cout << "NOT a: " << c << endl;
}