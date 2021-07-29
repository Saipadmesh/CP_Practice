#include <cmath>
#include <iostream>
using namespace std;
// The problem is: Given two numbers say a and b, mark the multiples of 2 and 5
// between a and b using less than O(|b – a|) space and output each of the
// multiples.

// Simple solution:
// Initialize an array of size (b-a), add a in the beginning and b in the end.
// If an index passes the criteria, mark as 1, otherwise mark as 0.

// Bit manipulation technique can be applied to problems mapping binary values
// in arrays. Each integer is represented in 32 bits. We can use those 32 bits
// instead of indexes that each have 32 bits.

// Important points
// 1. If divisor is of the form 2^n, instead of doing a%b, we can do a & (b-1)
// 2. If you need to divide a number by a divisor of form 2^n, instead of doing
// a/b, we can do a >> n

void decToBinary(int n) {
  // array to store binary number
  int binaryNum[32];

  // counter for binary array
  int i = 0;
  while (n > 0) {

    // storing remainder in binary array
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }

  // printing binary array in reverse order
  for (int j = i - 1; j >= 0; j--)
    cout << binaryNum[j];
}

bool checkBit(int arr[], int index) {
  return arr[index >> 5] & (1 << (index & 31));
}

void setBit(int arr[], int index) {
  cout << "Before setBit: ";
  decToBinary(arr[index >> 5]);
  cout << endl;
  arr[index >> 5] |= (1 << (index & 31));
  cout << "index>>5: " << (index >> 5);
  decToBinary(index >> 5);
  cout << endl;
  cout << "After setBit: ";
  decToBinary(arr[index >> 5]);
  cout << endl;
}

int main() {
  int a, b;
  cout << "Enter two integers: ";
  cin >> a >> b;
  // find the difference, divide by 32,and ceil it.
  int size = ceil(abs(b - a) / 32);
  int *arr = new int[size];
  cout << "Size: " << size << endl;
  for (int i = a; i <= b; i++) {
    if (i % 2 == 0 || i % 5 == 0) {
      cout << "for " << i << endl;
      setBit(arr, i - a);
    }
  }
  cout << "Numbers divisible by 2 and 5 are: ";
  for (int i = a; i <= b; i++) {
    if (checkBit(arr, i - a)) {
      cout << i << " ";
    }
  }
  cout << endl;
}
