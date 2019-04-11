// version for Huawei test, including []{}() three kinds of brackets, and reverse output.

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
stack<char> stk;

int main(){
    string num = "0123456789";
    // string s = "fjasdff2(a)ss";
    string s;
    cin >> s;
    // cout << s;
    do{
        auto sl = s.size();
        auto n = s.find_first_of(num);
        string news = "";
        if(n < s.size()){
            news += s.substr(0,n);
            string len = "";
            len += s[n];
            ++n;
            while(isdigit(s[n])){
                len += s[n++];
                // cout << len << endl;
            }
            stk.push(s[n]);
            ++n;
            string subs = "";
            while(!stk.empty()){
                if(s[n] == '(' || s[n] == '[' || s[n] == '{'){
                    stk.push(s[n]);
                    subs += s[n];
                }
                else if(s[n] == ')' || s[n] == ']' || s[n] == '}'){
                    stk.pop();
                    if(!stk.empty())
                        subs += s[n];
                }
                else
                    subs += s[n];
                ++n;
            }
            // cout << subs << endl;
            int length = stoi(len);
            while(length-- > 0){
                news += subs;
            }
            news += s.substr(n, sl-n);
        }else{
            news = s;
        }
        s = news;
    }while(s.find_first_of(num) < s.size());
    reverse(s.begin(), s.end()); // version for leetcode 394, comment this and replace next line with "return s;" works.
    cout << s;
}