#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {       
        if (stones.size()==1)return stones[0];
        sort(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int y = stones[stones.size() - 1];
            stones.pop_back();
            int x = stones[stones.size() - 1];
            stones.pop_back();
            if (x < y) {
                stones.push_back(y - x);
                sort(stones.begin(), stones.end());
            }
        }
        if (stones.size() == 1)return stones[0];
        else return 0;
    }
};
int main() {
    Solution sol;
    vector<int>nums = { 7,6,7,6,9 };
    cout << sol.lastStoneWeight(nums);
    return 0;
}