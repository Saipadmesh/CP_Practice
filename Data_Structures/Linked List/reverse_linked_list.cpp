#include <iostream>
using namespace std;

// Struct to define linked list node
struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};

// Helper function to insert a new node at the end of the linked list
void insert(node **root, int item)
{
    node *temp = new node;
    node *ptr;
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
void display(node *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }
}
// Helper function to convert an array to linked list
node *arrayToList(int arr[], int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
    return root;
}

// Recursive function which reverses in groups
node *reverse(node *head)
{
    // Use three pointers for traversing the list.
    node *curr = head;
    node *prev = nullptr;
    node *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        // int outputval = (curr->next) ? curr->next->val : -1;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    node *head = arrayToList(arr, n);
    cout << "Initial list: ";
    display(head);
    cout << "\n";
    int k = 3;
    node *ans = reverse(head);
    cout << "Final list: ";
    display(ans);
    cout << endl;
}