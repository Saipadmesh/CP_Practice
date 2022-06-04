#include <iostream>
#include <stack>
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
// Helper function to convert an array to linked list
ListNode *arrayToList(int arr[], int n)
{
    ListNode *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
    return root;
}

// Merging function
void reorderList(ListNode *head)
{
    stack<ListNode *> s;
    ListNode *fast = head;
    ListNode *slow = head;
    if (head != NULL)
    {
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp = slow;
        slow = slow->next;
        temp->next = nullptr;

        while (slow)
        {
            s.push(slow);
            slow = slow->next;
        }

        temp = head;
        ListNode *temp1;
        while (!s.empty())
        {
            temp1 = temp->next;
            temp->next = s.top();
            s.pop();
            temp->next->next = temp1;
            temp = temp1;
        }
        if (temp)
        {

            temp->next = nullptr;
        }
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode *head = arrayToList(arr1, n1);
    reorderList(head);
    cout << "Final list:\n";
    display(head);
    cout << endl;
}