#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>

using namespace std;

/*
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/
class Solution {
public:
    /*
    输入: n = 10
    输出: 12
    解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
    */
    int nthUglyNumber(int n) {
        //优先队列: 小堆
        int answer=1;
        priority_queue <int, vector<int>, greater<int> > q;
        for (int i=1;i<n;++i)
        {
            //插入数字: 上次的最小数*质因子
            q.push(answer*2);
            q.push(answer*3);
            q.push(answer*5);
            //堆顶是最小的数, 出顶
            answer = q.top();
            q.pop();
            //去掉重复数据: 感觉有点慢 ?
            while (!q.empty() && answer==q.top()) {
                q.pop();
            }
        }
        return answer;
    }
};

int main(int argc, char** argv)
{
    printf("hello world \n");

    Solution solution;

    int k = 2;
    auto ret = solution.nthUglyNumber(10);
    printf("i = %d \n", ret);
    return 0;
}