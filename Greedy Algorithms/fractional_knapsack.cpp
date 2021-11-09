#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Item {
public:
  int id;
  int weight;
  int benefit;
  Item(int i, int w, int b) {
    id = i;
    weight = w;
    benefit = b;
  }

  void print(int w) {
    cout << "ID: " << this->id << "\nWeight: " << w << "\nBenefit"
         << this->benefit;
  }
};

bool cmp(Item a, Item b) {
  double r1 = (double)a.benefit / (double)a.weight;
  double r2 = (double)b.benefit / (double)b.weight;
  return r1 > r2;
}

bool cmp1(Item a, Item b) { return a.weight > b.weight; }

bool cmp2(Item a, Item b) { return a.benefit > b.benefit; }

void fractional_knapsack(vector<Item> items, int maxWeight, int type) {

  int currWeight = 0;
  double finalBenefit = 0.0;
  if (type == 0) {
    sort(items.begin(), items.end(), cmp);
  } else if (type == 1) {
    sort(items.begin(), items.end(), cmp1);
  } else if (type == 2) {
    sort(items.begin(), items.end(), cmp2);
  }
  for (auto it = items.begin(); it != items.end(); it++) {
    int w;
    if (it->weight <= maxWeight - currWeight) {
      w = it->weight;
      currWeight += w;
      finalBenefit += it->benefit;

    } else {
      w = maxWeight - currWeight;
      currWeight += w;
      finalBenefit += it->benefit * ((double)w / (double)it->weight);
    }
    it->print(w);
  }
  cout << "Final benefit value is " << finalBenefit << endl;
}
int main() {
  int maxWeight = 25;
  int n;
  cout << "Enter number of elements" << endl;
  cin >> n;
  cout << endl;
  vector<Item> items;
  for (int i = 0; i < n; i++) {
    int w, b, id;
    cout << "Enter ID" << endl;
    cin >> id;
    cout << "Enter weight" << endl;
    cin >> w;
    cout << "Enter benefit" << endl;
    cin >> b;
    Item *item = new Item(id, w, b);
    items.push_back(*item);
  }
  cout << "\n\n";
  fractional_knapsack(items, maxWeight, 0);
}