#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countMonotonicPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(51, 0));
        
        for (int j = 0; j <= nums[0]; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; ++i) {
            vector<int> prefixSum(51, 0);
            for (int j = 0; j <= nums[i - 1]; ++j) {
                prefixSum[j] = dp[i - 1][j];
                if (j > 0) {
                    prefixSum[j] = (prefixSum[j] + prefixSum[j - 1]) % MOD;
                }
            }
            for (int j = 0; j <= nums[i]; ++j) {
                dp[i][j] = prefixSum[j];
            }
        }

        int result = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            result = (result + dp[n - 1][j]) % MOD;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 2};
    cout << "Count for [2, 3, 2]: " << sol.countMonotonicPairs(nums1) << endl;

    vector<int> nums2 = {5, 5, 5, 5};
    cout << "Count for [5, 5, 5, 5]: " << sol.countMonotonicPairs(nums2) << endl;

    return 0;
}