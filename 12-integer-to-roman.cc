#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string rst ="";
        for (auto p : elem_table){
            while(num/p.second.second > 0){
                roman_cnt[p.second.first]++;
                num -= p.second.second;
            }
        }
        for (auto r : elem_table){
            // cout << r.second.first << ": " << roman_cnt[r.second.first] << endl;
            if(roman_cnt[r.second.first] < 4)
                for(int i = 0; i < roman_cnt[r.second.first]; ++i){
                    rst += r.second.first;
                }
            else if(roman_cnt[r.second.first] == 4){
                if(roman_cnt[elem_table[r.first-1].first] > 0){
                    rst.erase(rst.size()-1);
                    rst += r.second.first;
                    rst += elem_table[r.first-2].first;
                }
                else{
                    rst += r.second.first;
                    rst += elem_table[r.first-1].first;
                }
            }
        }
        return rst;
    }
private:
    map<int, pair<const string, int>> elem_table{
        {0, {"M", 1000}},
        {1, {"D", 500}},
        {2, {"C", 100}},
        {3, {"L", 50}},
        {4, {"X", 10}},
        {5, {"V", 5}},
        {6, {"I", 1}}
    };    
    map<const string, int> roman_cnt{
        {"M", 0},
        {"D", 0},
        {"C", 0},
        {"L", 0},
        {"X", 0},
        {"V", 0},
        {"I", 0}
    };
    // set<const string> elem{"M", "D", "C", "L", "X", "V", "I"}
};