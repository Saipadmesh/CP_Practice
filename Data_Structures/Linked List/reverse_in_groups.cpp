#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *next;

  node(int x) {
    data = x;
    next = NULL;
  }

} * head;

void insert(node **root, int item) {
  node *temp = new node(item);
  node *ptr;
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

void display(node *root) {
  while (root != NULL) {
    cout << root->data << " ";
    root = root->next;
  }
}

node *arrayToList(int arr[], int n) {
  node *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

node *reverse_in_groups(node *head, int k) {
  node *curr = head->next;
  node *prev = head;
  node *next;

  prev->next = nullptr;
  bool first = false;
  int i = k;
  while (curr != nullptr && i > 1) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    i--;
  }
  if (curr != nullptr) {
    head->next = reverse_in_groups(curr, k);
  }
  return prev;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  node *head = arrayToList(arr, n);
  int k = 3;
  node *ans = reverse_in_groups(head, k);
  cout << "Final list:\n";
  display(ans);
  cout << endl;
}