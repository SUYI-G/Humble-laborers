//150. 逆波兰表达式求值
//根据 逆波兰表示法，求表达式的值。
//有效的算符包括  + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string a : tokens) {
            if (a == "+" || a == "-" || a == "*" || a == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (a == "+") st.push(num2 + num1);
                else if (a == "-") st.push(num2 - num1);
                else if (a == "*") st.push(num2 * num1);
                else if (a == "/") st.push(num2 / num1);
            }else {
                st.push(stoi(a));   //stoi()把数字字符串转换成int输出
            }
        }
        int result = st.top();
        st.pop();    //不弹出最后一个元素也可以
        return result;
    }
};

class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0;i < tokens.size();i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                else if (tokens[i] == "-") st.push(num2 - num1);
                else if (tokens[i] == "*") st.push(num2 * num1);
                else if (tokens[i] == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoi(tokens[i]));   //stoi()把数字字符串转换成int输出
            }
        }
        int result = st.top();
        st.pop();    //不弹出最后一个元素也可以
        return result;
    }
};