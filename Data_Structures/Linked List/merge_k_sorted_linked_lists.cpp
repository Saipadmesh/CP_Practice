#include <iostream>
#include <vector>
#include <queue>
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
struct CompareLL
{

    bool operator()(ListNode const *l1, ListNode const *l2)
    {
        return l1->val > l2->val;
    }
};

// Merging function
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // Use a priority queue to get the minimum each time, then add it to the final list and add the next element in the popped list back to the queue
    ListNode *head = nullptr, *temp1, *temp2;
    int k = lists.size();
    if (k == 0)
    {
        return nullptr;
    }
    priority_queue<ListNode *, vector<ListNode *>, CompareLL> pq;
    for (int i = 0; i < k; i++)
    {
        // cout << "pushing " << lists[i]->val << endl;
        if (lists[i])
        {
            pq.push(lists[i]);
        }
    }
    while (pq.size() != 0)
    {
        temp2 = pq.top();
        // cout << "temp2 val: " << temp2->val << endl;
        if (head == nullptr)
        {
            head = temp2;
            temp1 = temp2;
        }
        else
        {
            temp1->next = temp2;
            if (temp1->next)
            {
                temp1 = temp1->next;
            }
        }
        pq.pop();
        if (temp2 && temp2->next)
        {
            pq.push(temp2->next);
        }
    }
    return head;
}

int main()
{
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    vector<ListNode *> linked_lists;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode *l1 = arrayToList(arr1, n1);
    ListNode *l2 = arrayToList(arr2, n2);
    linked_lists.push_back(l1);
    linked_lists.push_back(l2);
    ListNode *head = mergeKLists(linked_lists);
    cout << "Final list:\n";
    display(head);
    cout << endl;
}