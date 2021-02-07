#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;
        }
        return ans;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：intervals = [[1,4],[4,5]]
        输出：[[1,5]]
        解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
    */
    vector<vector<int>> interval = {
        {1,4},
        {4,5}
    };

    Solution solution;
    vector<vector<int>> ret = solution.merge(interval);
    for (auto i : ret) {
        printf("[%d, %d] \n", i[0], i[1]);
    }

    return 0;
}