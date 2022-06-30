#include <stack>
#include <string>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (auto letter : s)
    {
        if (letter == '{' || letter == '[' || letter == '(')
        {
            st.push(letter);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char recent = st.top();
            if ((letter == '}' && recent != '{') || (letter == ']' && recent != '[') || (letter == ')' && recent != '('))
            {
                return false;
            }
            st.pop();
        }
    }
    return (st.empty());
}