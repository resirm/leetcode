#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto max = nums.rbegin();
        for(auto idx = nums.rbegin(); idx != nums.rend(); ++idx){
            if(*idx < *max){
                bool found = false;
                for(auto i = max; i != nums.rbegin(); --i){
                    if(*idx < *i){
                        continue;
                    }else{
                        ++i;
                        std::swap(*i,*idx);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    auto i = nums.rbegin();
                    if(*idx >= *i){
                        ++i;  
                    }
                    std::swap(*i,*idx);
                }
                reverse(nums.rbegin(), idx);
                break;
            }else{
                max = idx;
                if(idx == nums.rend()-1){
                    reverse(nums.rbegin(), nums.rend());
                }
            }
        }
    }
};