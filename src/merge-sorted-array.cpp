// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if second array is empty
        if (n==0) {
            return;
        }
        // if first array only contains zeroes
        if (m == 0) {
            for (int i =0; i<n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }


        int j = 0;
        m = nums1.size();
        
        // Array may contain zero in between as well
        // so find out where everything ends
        // Eg, -1 0 1 2 3 0 0 0
        int start_of_zeroes = 0;
        for (int i=m-1; i >= 0; i--) {
            if (nums1[i] != 0) {
                start_of_zeroes = i+1;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (j >= n) {
                return;
            }
            if (i == start_of_zeroes) {
                // if we are at position where
                // nums1 contains only zeroes at index >= i
                break;
            }

            if (nums1[i] > nums2[j]) {
                // insert nums2 at i and
                // shift the elements of nums1
                int temp = nums1[i];
                nums1[i] = nums2[j];
                
                int k = i + 1;
                while ( k < m) {
                    int temp2 = nums1[k];
                    nums1[k] = temp;
                    temp = temp2;
                    if (k == start_of_zeroes) {
                        break;
                    }
                    k++;
                }

                start_of_zeroes += 1;
                j++;
            }
        }

        // insert all the elements on nums2 when 
        // only zeroes are remaining in nums1
        while ( j < n ) {
            nums1[start_of_zeroes] = nums2[j];
            j++;
            start_of_zeroes++;
        }
    }
};