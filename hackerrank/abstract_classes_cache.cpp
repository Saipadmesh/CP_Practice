#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

void printLinkedList(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->value << ",";
    temp = temp->next;
  }
  cout << endl;
}

class Cache {

protected:
  map<int, Node *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node *tail;                     // double linked list tail pointer
  Node *head;                     // double linked list head pointer
  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache {
public:
  LRUCache(int capacity) {
    cp = capacity;
    head = nullptr;
    tail = nullptr;
  }
  void set(int index, int value) {
    if (mp.find(index) != mp.end()) {
      mp[index]->value = value;
    } else {

      mp[index] = new Node(nullptr, head, index, value);

      if (head != nullptr) {

        head->prev = mp[index];
      }
      head = mp[index];

      if (tail == nullptr) {
        tail = head;
      }

      if (mp.size() > cp) {
        mp.erase(tail->key);
        tail = tail->prev;
        delete tail->next;

        tail->next = nullptr;
      }
    }
  }

  int get(int index) {
    if (mp.find(index) == mp.end()) {
      return -1;
    } else {
      if (mp[index] != head) {
        if (mp[index] != tail) {
          mp[index]->next->prev = mp[index]->prev;
          mp[index]->prev->next = mp[index]->next;
          mp[index]->prev = nullptr;

        } else {
          mp[index]->prev->next = nullptr;
          tail = mp[index]->prev;
          mp[index]->prev = nullptr;
        }
        mp[index]->next = head;
        head->prev = mp[index];
        head = mp[index];
      }

      // printLinkedList(head);
      return mp[index]->value;
    }
  }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
