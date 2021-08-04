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

vector<ListNode *> splitListToParts(ListNode *head, int k) {
  int n = getLength(head);
  vector<ListNode *> ans;
  if (n < k) {
    ListNode *curr = head;
    while (k--) {
      ListNode *temp = NULL;
      if (curr) {
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;
      }
      ans.push_back(temp);
    }
    return ans;
  }
  int width = n / k, r = n % k;
  ListNode *curr = head;
  while (k--) {
    ListNode *temp = head;
    for (int i = 1; i < width; i++) {
      curr = curr->next;
    }
    if (r > 0) {
      curr = curr->next;
      r--;
    }
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
  vector<ListNode *> ans = splitListToParts(head, 3);
  print_Vector(ans);
}
