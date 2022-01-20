#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>

using namespace std;

// Stickler the thief wants to loot money from a society having n houses in a
// single line. He is a weird person and follows a certain rule when looting the
// houses. According to the rule, he will never loot two consecutive houses. At
// the same time, he wants to maximize the amount he loots. The thief knows
// which house has what amount of money but is unable to come up with an optimal
// looting strategy. He asks for your help to find the maximum money he can get
// if he strictly follows the rule. Each house has a[i] amount of money present
// in it.

int maxSum(int numbers[], int size) {
  int val1 = numbers[0];
  if (size == 1) {
    return val1;
  }

  int val2 = max(numbers[0], numbers[1]);
  if (size == 2) {
    return val2;
  }
  int sum;
  for (int i = 2; i < size; i++) {
    sum = max(numbers[i] + val1, val2);
    val1 = val2;
    val2 = sum;
  }
  return sum;
}

int main() {
  int num[] = {5, 5, 10, 100, 10, 5};
  int length = sizeof(num) / sizeof(num[0]);
  int sum = maxSum(num, length);
  cout << sum << endl;
}
