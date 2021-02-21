#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        //每2k个字符是一个小单元
        for (int start = 0; start < len; start += 2 * k) {
            int i = start;
            //剩余字符数目小于k的情况
            int j = std::min(start + k - 1, len - 1);
            //反转[i,j]区间内的字符
            while (i < j) {
                std::swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入: s = "abcdefg", k = 2
        输出: "bacdfeg"
    */
    string str = "abcdefg";
    int k = 2;

    Solution solution;
    printf("old str = %s \n", str.c_str());
    string str_new = solution.reverseStr(str, k);
    printf("new str = %s \n", str_new.c_str());

    return 0;
}