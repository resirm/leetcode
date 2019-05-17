#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return rst;
        sort(nums.begin(), nums.end());
        if(nums.front() > 0 || nums.back() < 0)
            return rst;
        for(int i = 0; i < nums.size(); ++i){
            elem_idx.insert({nums[i], i});
        }
        
        //test
        // for(auto c:nums){
        //     auto ret = elem_idx.find(c);
        //     cout << "test: " << c << ", " << ret->first << ", " << ret->second << ", ";
        // }
        
        last_i = nums[0]-1;
        for(int i = 0; i < nums.size() && nums[i] <= 0; ++i){
            // if(checked.find(nums[i]) != checked.end())
            //     continue;
            if(last_i == nums[i])
                continue;
            else
                last_i = nums[i];
            int tgt = -nums[i];
            // set<int> checked_j;
            int last_j;
            if(i+1 < nums.size())
                last_j = nums[i+1]-1;
            for(int j = i+1; j < nums.size(); ++j){
                // if(checked_j.find(nums[j]) != checked_j.end())
                //     continue;
                if(last_j == nums[j])
                    continue;
                else
                    last_j = nums[j];
                // nums[i]+nums[j] > 0 and -(nums[i]+nums[j]) < nums[j]
                if(nums[i] + 2*nums[j] > 0){
                    // checked.insert(nums[i]);
                    break;
                }
                auto ret = elem_idx.find(tgt - nums[j]);
                if(ret == elem_idx.end())
                    continue;
                if(ret->second <= j){ // 这里其实有问题，unordered_multimap有多个重复key的话，leetcode编译器(g++ 8.2, c++17)返回的是的多个重复key的<key,val>的最后一个，所以我的代码通过了。本地g++(?不确定真的是g++还是clang++的拷贝改名)和clang++返回的都是第一个的，所以应该再判断ret的下一个是不是也是同样值，或者ret的key是不是大于一个才行。
                    // cout << "continue!" << ret->second << ", " << j << ", ";
                    continue;
                }
                else{
                    cout << ret->second << ", " << j;
                    // found one matched.
                    // vector<int> tmp {nums[i], nums[j], ret->first};
                    // sort(tmp.begin(), tmp.end());
                    // dedup.insert(tmp);
                    rst.push_back({nums[i], nums[j], ret->first});
                }
                // checked_j.insert(nums[j]);
            }
            // checked.insert(nums[i]);
        }
        
        // for(int i = 0; i < nums.size(); ++i){
        //     for(int j = i+1; j < nums.size(); ++j){
        //         for(int k = j+1; k < nums.size(); ++k){
        //             if (nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int> tmp{nums[i], nums[j], nums[k]};
        //                 auto ret = dedup.insert(tmp);
        //                 if (ret.second == true)
        //                     rst.push_back(tmp);
        //             }
        //         }
        //     }
        // }
        
        // return vector<vector<int>>(dedup.begin(), dedup.end());
        return rst;
    }
    
private:
    unordered_multimap<int, int> elem_idx; // map<value, idx>
    vector<vector<int>> rst;
    // set<vector<int>> dedup;
    // set<int> checked;
    int last_i;
};