#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_ind = 0;
        for(auto ind = 0; ind < s.size(); ++ind){
            while(t_ind < t.size()){
                if(s[ind] == t[t_ind]){
                    ++t_ind;
                    break;
                }
                ++t_ind;
            }
            if(t_ind >= t.size() && s[ind] != t[t_ind-1]){
                return false;
            }
        }
        return true;
    }
};