#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
    {
        val = x;
        next = nullptr;
    }
};

void append(ListNode **root, int item)
{
    ListNode *temp = new ListNode(item);
    ListNode *ptr;

    if (!*root)
        *root = temp;
    else
    {
        ptr = *root;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(ListNode *root)
{
    while (root)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << "\n";
}

bool search(ListNode *root, int item)
{
    while (root)
    {
        if (root->val == item)
        {
            return true;
        }
        root = root->next;
    }
    return false;
}

int main()
{
    ListNode *head = new ListNode(1);
    append(&head, 2);
    append(&head, 3);
    display(head);
    cout << search(head, 2)
         << "\n";
    cout << search(head, 4) << endl;
}