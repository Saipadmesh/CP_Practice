#include <bits/stdc++.h>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

// Overload operator < as specified
// bool operator<(Box& b)

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)
class Box {
private:
  int l, b, h;

public:
  Box() { l = b = h = 0; }
  Box(int len, int bdth, int hght) {
    l = len;
    b = bdth;
    h = hght;
  }
  Box(const Box &b1) {
    l = b1.l;
    b = b1.b;
    h = b1.h;
  }

  int get_length() { return l; }
  int get_breadth() { return b; }
  int get_height() { return h; }

  long long CalculateVolume() { return (long long)l * b * h; }

  bool operator<(Box b1) {
    return (l < b1.l || ((l == b1.l) && (b < b1.b)) ||
            ((l == b1.l) && (b == b1.b) && (h == b1.h)));
  }

  friend std::ostream &operator<<(std::ostream &os, const Box &b1) {
    os << (b1.l) << " " << b1.b << " " << b1.h;
    return os;
  }
};
