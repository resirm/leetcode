#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max = sum;
        if(nums.size() == 1)
            return max;
        for(auto ind = 1; ind < nums.size(); ++ind){
            sum = sum > 0 ? nums[ind]+sum : nums[ind];
            max = sum > max ? sum : max;
        }
        return max;
    }
};