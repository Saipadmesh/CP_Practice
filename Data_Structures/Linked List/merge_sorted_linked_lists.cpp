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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *head;
  if (l1 && l2) {
    if (l1->val > l2->val) {
      head = l2;
      l2 = l2->next;
    } else {
      head = l1;
      l1 = l1->next;
    }
  } else if (l1) {
    head = l1;
    l1 = l1->next;
  } else if (l2) {
    head = l2;
    l2 = l2->next;
  } else {
    return NULL;
  }
  ListNode *curr = head;

  while (l1 && l2) {
    if (l1->val <= l2->val) {
      curr->next = l1;
      l1 = l1->next;
    } else if (l2->val < l1->val) {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }

  while (l1) {
    curr->next = l1;
    l1 = l1->next;
    curr = curr->next;
  }

  while (l2) {

    curr->next = l2;
    l2 = l2->next;
    curr = curr->next;
  }
  return head;
}

int main() {
  int arr1[] = {1, 2, 4};
  int arr2[] = {1, 3, 4};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  ListNode *l1 = arrayToList(arr1, n1);
  ListNode *l2 = arrayToList(arr2, n2);
  ListNode *head = mergeTwoLists(l1, l2);
  cout << "Final list:\n";
  display(head);
  cout << endl;
}