#include <bits/stdc++.h>
using namespace std;

float interpolate(int x, int x1, int x2, float y1, float y2)
{
    float y;
    y = y1 + ((y2 - y1) * (x - x1) / (x2 - x1));
    return y;
}
string findPrice(vector<int> items, vector<float> prices, int n)
{
    int minIndex = -1, maxIndex = -1, minq = INT_MIN, maxq = INT_MAX, sminIndex = -1, smaxIndex = -1;
    for (int i = 0; i < items.size(); i++)
    {
        if (prices[i] <= 0)
        {
            continue;
        }
        if (items[i] == n)
        {
            return to_string(round(prices[i] * 100.0) / 100.0);
        }
        if (items[i] < n)
        {
            if (minq < items[i])
            {
                sminIndex = minIndex;
                minq = items[i];
                minIndex = i;
                continue;
            }
        }
        else
        {
            if (maxq > items[i])
            {
                smaxIndex = maxIndex;
                maxq = items[i];
                maxIndex = i;
                continue;
            }
        }
    }
    float y;

    if (minq == INT_MIN)
    {
        y = interpolate(n, items[smaxIndex], maxq, prices[smaxIndex], prices[maxIndex]);
    }
    else if (maxq == INT_MAX)
    {
        y = interpolate(n, items[sminIndex], minq, prices[sminIndex], prices[minIndex]);
    }
    else
    {
        y = interpolate(n, minq, maxq, prices[minIndex], prices[maxIndex]);
    }
    y = round(y * 100.0) / 100.0;
    return to_string(y);
}

