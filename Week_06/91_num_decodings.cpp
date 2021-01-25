#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.size()+1);
        dp[0]=1;dp[1]=1;
        for (int i =1; i < s.size(); i++) {
            //1.s[i]为0的情况
            if (s[i] == '0') {
                //s[i - 1]等于1或2的情况
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i+1] = dp[i-1];  //由于s[1]指第二个下标，对应为dp[2],所以dp的下标要比s大1，故为dp[i+1]
                }else {
                    return 0;
                }
            //2.s[i]不为0的情况
            } else {
                //s[i-1]s[i]两位数要小于26的情况
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    dp[i+1] = dp[i]+dp[i-1];
                //其他情况
                }else{
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp[s.size()];
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：s = "226"
        输出：3
        解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
    */
    string str = "226";

    Solution solution;
    int num = solution.numDecodings(str);
    printf("num = %d \n", num);

    return 0;
}