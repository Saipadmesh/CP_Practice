#include <iostream>
using namespace std;

// Struct to define linked list node
struct node {
  int val;
  node *next;
  node() : val(0), next(nullptr) {}
  node(int x) : val(x), next(nullptr) {}
  node(int x, node *next) : val(x), next(next) {}
};

// Helper function to insert a new node at the end of the linked list
void insert(node **root, int item) {
  node *temp = new node;
  node *ptr;
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
void display(node *root) {
  while (root != NULL) {
    cout << root->val << " ";
    root = root->next;
  }
}
// Helper function to convert an array to linked list
node *arrayToList(int arr[], int n) {
  node *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

// Recursive function which reverses in groups
node *reverse_in_groups(node *head, int k) {
  // Use three pointers for traversing the list.
  node *curr = head->next;
  node *prev = head;
  node *next;
  // Detach prevNode from list
  prev->next = nullptr;
  int i = k;
  while (curr != nullptr && i > 1) {
    // Point to the next node
    next = curr->next;
    // Reverse the connection
    curr->next = prev;
    // Move to the next node
    prev = curr;
    curr = next;
    i--;
  }
  // If curr isn't null,the list isn't empty yet, and the function needs to be
  // called again for the next set of list elements.
  if (curr != nullptr) {
    head->next = reverse_in_groups(curr, k);
  }
  return prev;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  node *head = arrayToList(arr, n);
  cout << "Initial list: ";
  display(head);
  cout << endl;
  int k = 3;
  node *ans = reverse_in_groups(head, k);
  cout << "Final list: ";
  display(ans);
  cout << endl;
}