// Given an integer array nums sorted in non-decreasing order,
// remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, 
// you need to do the following things:

// 1. Change the array nums such that the first k elements of nums contain 
// the unique elements in the order they were present in nums initially. 
// The remaining elements of nums are not important as well as the size of nums.

// 2. Return k

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int size = nums.size();
        if (size == 0) {
            return k;
        }

        int ele = nums[k++];
        //int distinct[size];
        //distinct[k++] = ele;
        for (int i=1; i< size; i++){
            if (ele != nums[i]) {
                ele = nums[i];
                //distinct[k++] = ele;
                nums[k++] = ele;
            }
        }
        return k;
    }
};

