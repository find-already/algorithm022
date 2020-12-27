#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <map>

using namespace std;

/*
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //将数字插入 map
        int max_freq = 1;
        map<int, int> freq_map;
        for (auto ele : nums) {
            auto iter = freq_map.find(ele);
            if (iter == freq_map.end()) {
                freq_map.insert(make_pair(ele, 1));
            } else {
                if (iter->second + 1 > max_freq) {
                    max_freq = iter->second + 1;
                }
                freq_map[ele] = iter->second + 1;
            }
        }
        //桶排序
        vector<vector<int> > aaa(max_freq);
        for (auto ele : freq_map) {
            aaa[ele.second - 1].push_back(ele.first);
        }
#if 0
        //测试
        for (int i=0; i<aaa.size(); ++i) {
            for (auto mmm : aaa[i]) {
                printf("value %d's freq is %d ", mmm, i+1);
            }
            printf("\n");
        }
#endif
        //输出结果
        vector<int> ret;
        for (int i=aaa.size()-1; i>=0; --i) {
            for (auto mmm : aaa[i]) {
                ret.push_back(mmm);
                if (ret.size() == k)
                    return ret;
            }
        }

        return ret;
    }
};

int main(int argc, char** argv)
{
    printf("hello world \n");

    Solution solution;

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ret = solution.topKFrequent(nums, k);
    for (auto i : ret) {
        printf("i = %d \n", i);
    }
    return 0;
}