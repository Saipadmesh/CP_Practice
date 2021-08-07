#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  // Complete the code.
  char c;
  int a;
  long b;
  float d;
  double e;
  scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << fixed << setprecision(3) << d << endl;
  cout << fixed << setprecision(9) << e << endl;

  return 0;
}