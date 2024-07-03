// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]


// Naive Approach -- TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int last;
        while(k--) {
            last = nums[n-1];
            for(int i=n-1; i>0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = last;
        }
    }
};


// O(N) Approach -- Accepted
// This approach has space complexity O(N) as well
// We can try to make it O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return;
        }
        while (k > n) {
            k = k-n;
        }
        if ((n-k) <= 0) {
            return;
        }
        int arr[n-k], i;
        for(i=0; i<n-k; i++) {
            arr[i] = nums[i];
        }

        for(i=0; i<k; i++) {
            nums[i] = nums[n-k+i];
        }

        int j = 0;
        for(i; i<n; i++) {
            nums[i] = arr[j++];
        }
    }
};