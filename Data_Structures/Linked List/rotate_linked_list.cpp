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
// answer which is not optimized
ListNode *rotateRight(ListNode *head, int k) {
  if (head == NULL || k == 0) {
    return head;
  }
  if (head->next == NULL) {
    return head;
  }
  int n = getLength(head);
  int length_to_not_rotate = n - (k % n);
  ListNode *curnode = head;
  int i = 1;
  while (i < length_to_not_rotate && length_to_not_rotate != n) {
    curnode = curnode->next;
    i++;
  }
  if (length_to_not_rotate != n || i != 1) {

    ListNode *node = curnode->next;

    // curnode->next = NULL;
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
  int arr1[] = {1, 2};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  ListNode *l1 = arrayToList(arr1, n1);
  int k = 2;
  ListNode *head = rotateRight(l1, k);
  cout << "Final list:\n";
  display(head);
  cout << endl;
}