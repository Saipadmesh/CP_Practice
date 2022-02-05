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
node *findMiddle(node *head) {
  // cout << "Inside findMiddle fn" << endl;
  node *fast = head;
  node *slow = head;
  if (head != NULL) {
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      // cout << "Slow val: " << slow->data << endl;
      slow = slow->next;
    }
    return slow;
  } else {
    return head;
  }
  // cout << "Returning from findMiddle fn" << endl;
}

node *merge(node *left, node *right) {
  // cout << "Inside merge" << endl;
  node *merged = NULL;
  node *mergedHead = NULL;
  node *currLeft = left;
  node *currRight = right;
  if (left->data < right->data) {
    merged = mergedHead = left;
    currLeft = currLeft->next;
  } else {
    merged = mergedHead = right;
    currRight = currRight->next;
  }

  while (currLeft != NULL && currRight != NULL) {
    // cout << "Inside while loop" << endl;
    if (currLeft->data <= currRight->data) {
      merged->next = currLeft;
      currLeft = currLeft->next;
    } else {
      merged->next = currRight;
      currRight = currRight->next;
    }
    merged = merged->next;
  }
  merged->next = (currLeft != NULL) ? currLeft : currRight;

  return mergedHead;
}

node *mergeSort(node *head) {
  if (head == nullptr || head->next == nullptr) {
    // cout << "Returned from mergeSort function" << endl;
    return head;
  }
  // cout << "Did not return from mergeSort function" << endl;
  node *mid = findMiddle(head);
  // cout << "Mid val: " << mid->data << endl;
  node *rightHead = mid->next;
  mid->next = NULL;
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