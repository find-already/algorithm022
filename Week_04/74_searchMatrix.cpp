#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
//using 二分查找
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int left = 0, right = matrix.size()*matrix[0].size() - 1;
        int n = matrix[0].size();
        while(left <= right) {
            int mid = left + ((right - left)>>1);   //>>即是 /2
            if(matrix[mid/n][mid%n] > target) {
                right = mid-1;
            } else if(matrix[mid/n][mid%n] < target) {
                left = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};

#if 0
public boolean searchMatrix(int[][] matrix, int target) {
    if(matrix.length==0 || matrix[0].length == 0) return false;
    int rowIndex = findRow(matrix, target);
    if(rowIndex == -1)return false;
    return findTarget(matrix[rowIndex], target);
}
//在matrix第一列上进行二分查找，定位到行号
private int findRow(int[][] matrix, int target) {
    int low = 0, high = matrix.length, mid;
    int first;
    while (low < high) {
        mid = (low + high) >> 1;
        first = matrix[mid][0];
        if (first > target) {
            high = mid;
        } else if(first == target) {
            return mid;
        } else {
            low = mid + 1;
        }
    }
    return low - 1;
}
//在row上进行二分查找
private boolean findTarget(int[] row, int target) {
    int low = 0, high = row.length-1, mid;
    while(low <= high) {
        mid = (low+high)>>1;
        if(row[mid] == target) {
            return true;
        } else if(row[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
#endif


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        输出：true
    */
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;

    Solution solution;
    bool found = solution.searchMatrix(matrix, target);
    printf("found = %d \n", found);

    return 0;
}