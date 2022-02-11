#include <iostream>
using namespace std;
// Can be done in two ways. Converting into cyclic linked list has not been done
// yet.
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

int getLength(ListNode *head) {
  int n = 0;
  ListNode *curnode = head;
  while (curnode) {
    n++;
    curnode = curnode->next;
  }
  return n;
}

ListNode *rotateRight(ListNode *head, int k) {
  if (head == NULL || k == 0) {
    return head;
  }
  if (head->next == NULL) {
    return head;
  }
  // get the length of the linked list
  int n = getLength(head);
  // The value of k can be greater than n, and the algorithm should still work.
  // So we take the remainder k%n and subtract it from n to get the length we
  // should not rotate.
  int length_to_not_rotate = n - (k % n);
  ListNode *curnode = head;
  int i = 1;
  // Traverse the list till the point from which we need to rotate.
  while (i < length_to_not_rotate && length_to_not_rotate != n) {
    curnode = curnode->next;
    i++;
  }
  if (length_to_not_rotate != n || i != 1) {

    ListNode *node = curnode->next;

    while (node->next != NULL) {
      node = node->next;
    }
    node->next = head;
    head = curnode->next;
    curnode->next = NULL;
  }
  return head;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  ListNode *l1 = arrayToList(arr1, n1);
  int k = 18;
  ListNode *head = rotateRight(l1, k);
  cout << "Final list: ";
  display(head);
  cout << endl;
}