#include <iostream>
#include <math.h>
using namespace std;

#define MAXN 10000
#define SQRSIZE 100

int arr[MAXN];      // original array
int block[SQRSIZE]; // decomposed array
int block_sz;       // block size

void update(int idx, int val) {
  int blockNumber = idx / block_sz;
  block[blockNumber] += val - arr[idx];
  arr[idx] = val;
}