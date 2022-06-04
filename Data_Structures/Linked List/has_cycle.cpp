#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to define linked list node
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to insert a new node at the end of the linked list
void insert(ListNode **root, int item)
{
  ListNode *temp = new ListNode;
  ListNode *ptr;
  temp->val = item;
  temp->next = NULL;

  if (*root == NULL)
    *root = temp;
  else
  {
    ptr = *root;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}
// Helper function to print linked list
void display(ListNode *root)
{
  while (root != NULL)
  {
    cout << root->val << " ";
    root = root->next;
  }
}

bool hasCycle(ListNode *head)
{
  // Use two pointers, one that moves twice the speed. If they meet, there is a cycle
  if (head == nullptr)
  {
    return false;
  }

  ListNode *slow = head;
  ListNode *fast = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow)
    {
      return true;
    }
  }
  return false;
}