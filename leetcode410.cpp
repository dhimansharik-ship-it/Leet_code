class Solution {
public:
    bool isPossible(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long sum = 0;

        for (int x : nums) {
            if (sum + x <= maxSum) {
                sum += x;
            } else {
                parts++;
                sum = x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;

        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};