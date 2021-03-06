#include <exception>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
stack<ListNode *> s;

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
    cout << root->val << " ";
    root = root->next;
  }
}

ListNode *arrayToList(int arr[], int n) {
  ListNode *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

ListNode *swapPairs(ListNode *head) {
  if (head == NULL) {
    return nullptr;
  }
  int i = 1;
  ListNode *node = head;
  while (node->next != nullptr) {

    if (i % 2 == 0) {
      if (i == 2) {
        head = node;
      }
      ListNode *temp = node;
      node = node->next;
      // cout << node->val << endl;
      temp->next = s.top();

      cout << temp->next->val << endl;
      s.pop();
      temp->next->next = node->next;
      /*cout << "temp value: " << temp->val
           << "\ntemp->next->next value:" << temp->next->next->val << endl;*/
    } else {
      ListNode *temp = node;
      node = node->next;
      temp->next = nullptr;
      // cout << temp->val << endl;
      s.push(temp);
    }
    cout << "Head Val in iteration " << i << " is " << head->val << endl;
    i++;
  }
  cout << "Head Val after everything is over: " << head->val << endl;
  while (!s.empty()) {
    node->next = s.top();
    s.pop();
    cout << "Remaining node: " << node->next->val;
  }

  return head;
}

ListNode *swapPairs1(ListNode *head) {
  if (head == NULL || head->next == nullptr) {
    return head;
  }
  int i = 1;
  ListNode *prev = head;
  ListNode *curr = head->next;
  head = curr;
  while (true) {
    ListNode *next = curr->next;
    curr->next = prev;
    if (next == nullptr || next->next == nullptr) {
      prev->next = next;
      break;
    }
    prev->next = next->next;
    prev = next;
    curr = prev->next;
  }
  cout << "Head val in func = " << head->val << endl;

  return head;
}

// Easiest implementation using recursion
ListNode *swapPairs2(ListNode *head) {
  ListNode *prev = head;
  ListNode *curr = prev->next;
  ListNode *next = curr->next;
  // swap first and second elements
  prev->next = next;
  curr->next = prev;
  // change head
  head = curr;
  // if the next node is not null and if the length is not odd, do a recursive
  // call
  if (next != nullptr && next->next != nullptr) {
    prev->next = swapPairs2(next);
  }
  return head;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  ListNode *head = arrayToList(arr, n);
  ListNode *ans = swapPairs2(head);
  cout << "Final list:\n";
  display(ans);
  cout << endl;
}