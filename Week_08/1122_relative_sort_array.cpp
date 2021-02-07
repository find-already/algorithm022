#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int freq[1001] = {0};
        for(auto num :arr1) freq[num]++;
        for(int i =0;i<arr2.size();i++){
            while(freq[arr2[i]]){
                result.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
        for(int i =0;i<1001;i++){
            while(freq[i]){
                result.push_back(i);
                freq[i]--;
            }
        }
        return result;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
        输出：[2,2,2,1,4,3,3,9,6,7,19]
    */
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    Solution solution;
    vector<int> result = solution.relativeSortArray(arr1, arr2);
    for (auto i : result) {
        printf("%d, ", i);
    }
    printf("\n");

    return 0;
}