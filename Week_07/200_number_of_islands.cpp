#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    void is_land(vector<vector<char>>& grid, int row, int column){
        if(row<grid.size()&&column<grid[row].size()&&grid[row][column]=='1')
            grid[row][column] = '0';
        else
            return;
        is_land(grid,row+1,column);
        is_land(grid,row-1,column);
        is_land(grid,row,column+1);
        is_land(grid,row,column-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int row = 0;
        for(vector<char> &temp:grid){
            int column = 0;
            for(char &temp_c : temp){
                if(temp_c=='0') {column++;continue;}
                is_land(grid,row,column);
                cnt++;
                column++;
            }
            row++;
        }
        return cnt;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入：grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        输出：3
    */
    vector<vector<char>> grid =
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution solution;
    int cnt = solution.numIslands(grid);
    printf("cnt = %d \n", cnt);

    return 0;
}