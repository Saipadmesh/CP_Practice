// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.
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
// Use a carry variable. Traverse through both lists, add values and divide by
// 10 for the new carry value. Update the ans list with units digit of the sum.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ans = new ListNode(0);
  // Pointers for both linked lists
  ListNode *p = l1;
  ListNode *q = l2;
  ListNode *curr = ans;
  // Carry value to next node
  int carry = 0;
  // Traverse until both lists become null.
  while (p != NULL || q != NULL) {
    int x = (p != NULL) ? p->val : 0;
    int y = (q != NULL) ? q->val : 0;
    int sum = x + y + carry;
    // Get the tens digit
    carry = sum / 10;
    // Get the units digit
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
    // If the pointers are not null, move them
    if (p != NULL) {
      p = p->next;
    }
    if (q != NULL) {
      q = q->next;
    }
  }
  // After loop ends, if the carry value is greater than 0, append it to the end
  // of the list
  if (carry > 0) {
    curr->next = new ListNode(carry);
  }

  return ans->next;
}

int main() {
  int arr[] = {1, 2, 3}, arr1[] = {1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  ListNode *head = arrayToList(arr, n);
  ListNode *head1 = arrayToList(arr1, n1);
  ListNode *ans = addTwoNumbers(head, head1);
  display(ans);
}