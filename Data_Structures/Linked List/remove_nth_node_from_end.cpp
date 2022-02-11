#include <iostream>
using namespace std;
// Struct to define linked list node
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to insert a new node at the end of the linked list
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
}
// Helper function to convert an array to linked list
ListNode *arrayToList(int arr[], int n) {
  ListNode *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
  // node which traverses list till nth element from the end
  struct ListNode *main_ptr = head;
  // node which traverses list and is used as reference for the mainPtr to find
  // the right element
  struct ListNode *ref_ptr = head;
  int i;
  for (i = 0; i < n; i++) {
    // RefPtr can only be null if n is greater than length.
    if (ref_ptr == NULL) {
      cout << n << " is greater than length of list";
      break;
    }
    // Move refPtr till position n.
    ref_ptr = ref_ptr->next;
  }
  // After the loop, if the refPtr is null, it has reached the end of the
  // list, and it means that nth element from end is the head. So head is
  // removed.
  if (ref_ptr == nullptr) {
    return main_ptr->next;
  }
  // From it's current position, refPtr moves to the end of the list. If we move
  // the mainPtr from the head, we get to the nth element from the end.
  while (ref_ptr->next) {
    ref_ptr = ref_ptr->next;
    main_ptr = main_ptr->next;
  }
  // mainPtr.next is the element which needs to be deleted.
  ListNode *temp_ptr = main_ptr->next;
  main_ptr->next = main_ptr->next->next;
  delete temp_ptr;
  return head;
}
int main() {
  int arr[] = {1, 4, 5, 2, 3, 6, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  ListNode *head = arrayToList(arr, n);
  cout << "Original list: ";
  display(head);
  cout << endl;
  ListNode *ans = removeNthFromEnd(head, 8);
  cout << "After removal: ";
  display(ans);
  cout << endl;
}