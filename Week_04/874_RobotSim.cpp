#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
//using set
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direx[] = {0,1,0,-1};
        int direy[] = {1,0,-1,0};
        int curx=0,cury=0;
        int curdire = 0;
        int comLen = commands.size();
        int ans = 0;
        set<pair<int, int>> obstacleSet;        //我没想到 set 直接支持 pair<int,int>, 遗憾 !
        for(int i=0; i<obstacles.size(); ++i)
            obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));

        for(int i=0;i<comLen;i++){
            switch (commands[i])
            {
            case -1:
                curdire = (curdire + 1)%4;
                break;
            case -2:
                curdire = (curdire + 3)%4;
                break;
            default:
                for (int j=0; j<commands[i]; ++j) {
                    //尝试走一步
                    int try_x = curx + direx[curdire];
                    int try_y = cury + direy[curdire];
                    //如果是障碍物
                    if (obstacleSet.find(make_pair(try_x, try_y)) != obstacleSet.end()) {
                        break;
                    }
                    //如果不是障碍物
                    curx = try_x;
                    cury = try_y;
                    ans = max(ans, curx*curx+cury*cury);
                }
                break;
            }
        }
        return ans;
    }
};

#if 0
//using unordered_set
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }

        return ans;
    }

private:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
#endif


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
        输出: 65
        解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
    */
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    // vector<vector<int>> obstacles = {{2,4},{1,3},{2,8}};

    Solution solution;
    int ans = solution.robotSim(commands, obstacles);
    printf("ans = %d \n", ans);

    return 0;
}