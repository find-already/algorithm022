#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        //回文串起始位置
        int start = 0;
        //回文串最大长度
        int max = 1;
        //定义二维动态数组
        vector<vector<int>>  dp(len,vector<int>(len));
        //初始化状态
        for(int i=0;i<len;i++) {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        //l表示检索的子串长度，等于3表示先检索长度为3的子串
        for(int l=3;l<=len;l++)         {
            for(int i=0;i+l-1<len;i++) {
                //终止字符位置
                int j=l+i-1;
                //状态转移
                if(s[i]==s[j]&&dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        //获取最长回文子串
        return s.substr(start,max);
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：s = "babad"
        输出："bab"
        解释："aba" 同样是符合题意的答案
    */
    string s = "babad";

    Solution solution;
    printf("原始串 = %s \n", s.c_str());
    string s_new = solution.longestPalindrome(s);
    printf("回文串 = %s \n", s_new.c_str());

    return 0;
}