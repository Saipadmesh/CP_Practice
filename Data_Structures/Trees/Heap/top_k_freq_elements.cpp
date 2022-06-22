#include <vector>
#include <map>
#include <queue>
using namespace std;
// Use map to count frequencies and use a max heap to sort the values and get the k frequent elements
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m;
    for (auto num : nums)
    {
        if (m.find(num) == m.end())
        {
            m[num] = 0;
        }
        m[num] += 1;
    }
    priority_queue<pair<int, int>> pq;
    for (auto elem : m)
    {
        pq.push(make_pair(elem.second, elem.first));
    }

    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}