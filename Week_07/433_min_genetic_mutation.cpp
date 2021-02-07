#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (dict.find(end) == dict.end()) return -1;
        queue<string> que_help;
        que_help.push(start);
        vector<char> letter = {'A', 'C', 'G', 'T'};
        int ladder = 1;
        while (!que_help.empty()) {
            int n = que_help.size();
            for (int i = 0; i < n; i++) {
                string word = que_help.front();
                que_help.pop();
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < letter.size(); k++) {
                        word[j] = letter[k];
                        if (word == end) return ladder;
                        if (dict.find(word) != dict.end()) {
                            que_help.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return -1;
    }
};


int main(int argc, char** argv)
{
    printf("hello world \n");

    /*
        start: "AAAAACCC"
        end:   "AACCCCCC"
        bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
    */
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};

    Solution solution;
    int num = solution.minMutation(start, end, bank);
    printf("num = %d \n", num);

    return 0;
}