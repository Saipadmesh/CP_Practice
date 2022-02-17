#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

// implementation using hash map which is implemented using red black tree, like
// set. Insertion takes O(nlogn) and not O(1).
bool containsDuplicate(vector<int> &nums) {
  map<int, int> hashMap;
  for (int i = 0; i < nums.size(); i++) {
    if (hashMap.find(nums[i]) != hashMap.end()) {
      return true;
    }
    hashMap[nums[i]] = 1;
  }
  return false;
}
// Using unordered set is faster than using set according to leetcode because it
// is implemented using a hash table, whereas set is implemented using trees, so
// insertion takes more time.
bool containsDuplicate_set(vector<int> &nums) {
  unordered_set<int> orderSet;
  for (int i = 0; i < nums.size(); i++) {
    orderSet.insert(nums[i]);
  }
  if (orderSet.size() != nums.size()) {
    return true;
  }
  return false;
}
