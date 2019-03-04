#include <iostream>
#include <map>
#include <deque>

std::map<char, int> index;
std::deque<char> unique;
int beg = 1, cur = 1, maxlen = 0, curlen = 0;

int lengthOfLongestSubstring(const std::string s) {
    for(auto c : s){
        if(index[c] > 0){
            maxlen = curlen > maxlen ? curlen : maxlen;
            beg = index[c]+1;
            for(auto cc : unique){
                if(cc != c){
                    index[cc] = 0;
                    unique.pop_front();
                }else{
                    unique.pop_front();
                    unique.push_back(c);
                    break;
                }
            }
            curlen = cur-beg+1;
            index[c] = cur++;
        }else{
            index[c] = cur++;
            unique.push_back(c);
            ++curlen;
        }
    }
    return maxlen;
}

int main(){
    std::string s = "pwwkew";
    std::cout << lengthOfLongestSubstring(s) << std::endl;
}

/* reference solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int left=-1;
        vector<int> last_index(128,-1);
        for(int i = 0,len = s.size();i < len; ++i){
            left = max(left,last_index[s[i]]);
            last_index[s[i]] = i;
            max_size=max(max_size, i-left);
        }
        return max_size;
    }
};
*/