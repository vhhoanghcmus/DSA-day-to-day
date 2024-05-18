#include <bits/stdc++.h>
#include <stack>
using namespace std;


int pop(stack<char>& stack) {
    const int c = stack.top();
    stack.pop();
    return c;
  }

  bool isValid(string s) {
    stack<char> stack;

    for (const char c : s)
      if (c == '(')
        stack.push(')');
      else if (c == '{')
        stack.push('}');
      else if (c == '[')
        stack.push(']');
      else if (stack.empty() || pop(stack) != c)
        return false;

    return stack.empty();
  }

  
string isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
 
    if (S == P) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main() {
    string S = "{[[]]}";
    if(isValid(S)) {
        cout << " This is a Parentheses" << endl;
    } else {
        cout << " This is not Parentheses" << endl;
    }

    string str = "madam";
    cout << isPalindrome(str);
}
