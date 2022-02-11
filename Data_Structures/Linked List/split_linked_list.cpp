// Given the head of a singly linked list and an integer k, split the linked
// list into k consecutive linked list parts. The length of each part should be
// as equal as possible: no two parts should have a size differing by more than
// one. This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list, and parts
// occurring earlier should always have a size greater than or equal to parts
// occurring later.
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insert(ListNode **root, int item) {
  ListNode *temp = new ListNode;
  ListNode *ptr;
  temp->val = item;
  temp->next = NULL;

  if (*root == NULL)
    *root = temp;
  else {
    ptr = *root;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

void display(ListNode *root) {
  while (root != NULL) {
    cout << root->val << ",";
    root = root->next;
  }
}

void print_Vector(vector<ListNode *> ans) {
  cout << "[";
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {
    cout << "[ ";
    display(*ip);
    cout << "]";
  }
  cout << "]" << endl;
}

ListNode *arrayToList(int arr[], int n) {
  ListNode *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

int getLength(ListNode *head) {
  int n = 0;
  ListNode *curnode = head;
  while (curnode) {
    n++;
    curnode = curnode->next;
  }
  return n;
}
// Function to split the list into approx. equal parts
vector<ListNode *> splitListToParts(ListNode *head, int k) {
  // Get the length of the linked list
  int n = getLength(head);
  vector<ListNode *> ans;
  // If k is greater than size of list, some of the arrays will be null, and
  // individual elements are put in individual arrays
  if (n < k) {
    ListNode *curr = head;
    while (k--) {
      // Init to null.
      ListNode *temp = NULL;
      // if the list is not empty, detach it and push it to the vector
      if (curr) {
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;
      }
      ans.push_back(temp);
    }
    return ans;
  }
  // Find the width and remainder. The remainder should be filled up first.
  int width = n / k, r = n % k;
  ListNode *curr = head;
  while (k--) {
    ListNode *temp = head;
    for (int i = 1; i < width; i++) {
      curr = curr->next;
    }
    // The split should be approx equal size, so all of the remainder is not
    // added to the first list itself.
    if (r > 0) {
      curr = curr->next;
      r--;
    }
    // Detach the list, and move the head to the right split to continue
    // splitting.
    head = curr->next;
    ans.push_back(temp);
    temp = curr;
    curr = curr->next;
    temp->next = NULL;
  }

  return ans;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  ListNode *head = arrayToList(arr, n);
  vector<ListNode *> ans = splitListToParts(head, 11);
  print_Vector(ans);
}
