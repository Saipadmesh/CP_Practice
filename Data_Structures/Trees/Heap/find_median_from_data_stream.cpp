#include <queue>
using namespace std;
// Use max heap to represent elements before the assumed middle element, and min heap for elements to the right. The difference between the size of the two heaps should be <=1. If it is not, balance by shifting the top element from the higher sized heap to lower sized one.
class MedianFinder
{
public:
    bool even;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder()
    {
        even = true;
        left = priority_queue<int>();
        right = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num)
    {
        if ((left.empty() && right.empty()) || left.top() >= num)
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }

        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (double)(left.top() + right.top()) / 2;
        }
        else if (left.size() > right.size())
        {
            return left.top();
        }
        else
        {
            return right.top();
        }
    }
};