#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int num = 0;
        int n = s.size();
        //遍历回文中心点
        for(int i=0;i<n;i++)
        {
            //j=0,中心是一个点，j=1,中心是两个点
            for(int j=0;j<=1;j++)
            {
                int l = i;
                int r = i+j;
                while(l>=0 && r<n && s[l--]==s[r++])num++;
            }
        }
        return num;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入："aaa"
        输出：6
        解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
    */
    string str = "aaa";

    Solution solution;
    int num = solution.countSubstrings(str);
    printf("num = %d \n", num);

    return 0;
}