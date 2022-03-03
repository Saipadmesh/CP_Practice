// Return the head of the linked list after swapping the values of the kth node
// from the beginning and the kth node from the end (the list is 1-indexed).

#include <cstddef>
#include <iostream>
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

// Helper function to print linked list
void display(ListNode *root) {
  while (root != NULL) {
    cout << root->val << " ";
    root = root->next;
  }
  cout << endl;
}
// Helper function to convert an array to linked list
ListNode *arrayToList(int arr[], int n) {
  ListNode *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

ListNode *swapNodes(ListNode *head, int k) {
  ListNode *start, *end;
  start = head;
  int n = 0;
  while (start != NULL) {
    n++;
    start = start->next;
  }
  if (n == 1)
    return head;
  int k1 = n - k + 1;
  if (k == k1) {
    return head;
  }
  start = head;
  for (int i = 1; i < k; i++) {
    start = start->next;
  }
  end = head;
  for (int i = 1; i < k1; i++) {
    end = end->next;
  }

  int temp;
  temp = start->val;
  start->val = end->val;
  end->val = temp;
  return head;
}

int main() {
  int arr[] = {100, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  ListNode *head = arrayToList(arr, n);
  int k = 2;
  ListNode *ans = swapNodes(head, k);
  display(ans);
}