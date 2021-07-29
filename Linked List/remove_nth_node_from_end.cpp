#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n) {
  struct ListNode *main_ptr = head;
  struct ListNode *ref_ptr = head;
  int i;
  for (i = 0; i < n; i++) {
    if (ref_ptr == NULL) {
      cout << n << " is greater than length of list";
      break;
    }
    ref_ptr = ref_ptr->next;
  }
  if (ref_ptr == nullptr) {
    return main_ptr->next;
  }
  while (ref_ptr->next) {
    ref_ptr = ref_ptr->next;
    main_ptr = main_ptr->next;
  }
  ListNode *temp_ptr = main_ptr->next;
  main_ptr->next = main_ptr->next->next;
  delete temp_ptr;
  return head;
}
int main() {}