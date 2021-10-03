#include <iostream>
#include <stack>
using namespace std;

bool RedundantBraces(string &str)
{
    stack<char> st;

    for (auto &ch : str)
    {

        if (ch == ')')
        {
            char top = st.top();
            st.pop();
            bool flag = true;

            while (top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }

            if (flag == true)
                return true;
        }
        else
            st.push(ch); 
    }
    return false;
}

void CheckRedundancy(string &str)
{
    bool ans = RedundantBraces(str);
    if (ans == true)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    string str = "((a-b)-c*d)";
    CheckRedundancy(str);
    str = "(a*((b+c)))";
    CheckRedundancy(str);
    return 0;
}

/*
Program to Check Redundant brackets in an expression
----------------------------------------------------

Input - ((a-b)-c*d),
        (a*((b+c)))

Output - False,
         True

Time complexity - O(n) 
Auxiliary space - O(n)

*/