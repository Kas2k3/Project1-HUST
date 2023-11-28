#include <bits/stdc++.h>
using namespace std;

bool isCorrectExpression(string s) {
    stack<char> st;

    for (char c : s) {
		//Neu gap mo ngoac thi push vao stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
			//Neu gap dau dong ngoac va stack rong thi tra ve false 
            if (st.empty()) {
                return false;
			//Neu stack khong rong thi pop dau tren cung ra khoi stack
            } else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isCorrectExpression(s)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
