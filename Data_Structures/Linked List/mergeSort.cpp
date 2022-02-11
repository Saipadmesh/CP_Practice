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
// Function to find the middle of the linked list
node *findMiddle(node *head) {
  // Use two pointers, one which skips alternate elements, and one that doesn't.
  // Run a loop till the fast one reaches the end of the list. The value of the
  // slow pointer will be the middle.
  node *fast = head;
  node *slow = head;
  if (head != NULL) {
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  } else {
    return head;
  }
}

node *merge(node *left, node *right) {
  // This pointer is for moving through the merged linked list
  node *merged = NULL;
  // this variable is for pointing to the head of the new sorted linked list
  node *mergedHead = NULL;
  // Pointers for both of the linked lists
  node *currLeft = left;
  node *currRight = right;
  // Select the first node of the merged linked list based on which of the two
  // is smaller.
  if (left->data < right->data) {
    merged = mergedHead = left;
    currLeft = currLeft->next;
  } else {
    merged = mergedHead = right;
    currRight = currRight->next;
  }

  while (currLeft != NULL && currRight != NULL) {
    // compare the values of the two pointers and add the smaller one to the
    // final list.
    if (currLeft->data <= currRight->data) {
      merged->next = currLeft;
      currLeft = currLeft->next;
    } else {
      merged->next = currRight;
      currRight = currRight->next;
    }
    merged = merged->next;
  }
  // If one of the lists is not empty yet, simply add it to the end of the
  // merged list.
  merged->next = (currLeft != NULL) ? currLeft : currRight;
  // Return the head of the merged list
  return mergedHead;
}

node *mergeSort(node *head) {
  if (head == nullptr || head->next == nullptr) {
    // We need to stop at the tail node
    return head;
  }
  // Find the middle of the current linked list
  node *mid = findMiddle(head);
  node *rightHead = mid->next;
  // Detach the two linked lists
  mid->next = NULL;
  // recursive call for both those linked lists
  node *left = mergeSort(head);
  node *right = mergeSort(rightHead);
  return merge(left, right);
}

int main() {
  int arr[] = {1, 4, 5, 2, 3, 6, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  node *head = arrayToList(arr, n);
  cout << "Original list:\n";
  display(head);
  cout << endl;
  node *ans = mergeSort(head);
  cout << "Final list:\n";
  display(ans);
  cout << endl;
}