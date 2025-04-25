string isBalanced(string s){
    stack<char> stk;
    int n = s.length();

    for (int i = 0; i < n; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push(s[i]);
        else{
            if (stk.empty()) return "NO";

            if ((s[i] == ')' && stk.top() != '(') || (s[i] == '}' && stk.top() != '{') || (s[i] == ']' && stk.top()
                != '['))
                return "NO";

            stk.pop();
        }
    }
    return (stk.empty() ? "YES" : "NO");
}