#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return rst;
        int num = 1;
        for(auto& c : digits){
            num *= dig[c].size();
        }
        rst = vector<string>(num, "");
        int idx = 0;
        int subnum = num;
        while(idx < digits.size()){
            int beg = 0;
            while(beg < num){
                subadd(dig[digits[idx]], beg, subnum);
                beg += subnum;
            }
            subnum /= dig[digits[idx]].size();
            ++idx;
        }
        return rst;
    }
    void subadd(const vector<char> &v, int beg, int n){
        for(int i = 0; i < n; ++i){
            rst[beg+i] += v[i*v.size()/n];
            cout << rst[beg+i] << ", ";
        }
    }
private:
    vector<char> v2{'a','b','c'};
    vector<char> v3{'d','e','f'};
    vector<char> v4{'g','h','i'};
    vector<char> v5{'j','k','l'};
    vector<char> v6{'m','n','o'};
    vector<char> v7{'p','q','r','s'};
    vector<char> v8{'t','u','v'};
    vector<char> v9{'w','x','y','z'};
    map<char, vector<char>>dig{
        {'2', v2},
        {'3', v3},
        {'4', v4},
        {'5', v5},
        {'6', v6},
        {'7', v7},
        {'8', v8},
        {'9', v9}
    };
    vector<string> rst;
};