

// Given an integer array nums and an integer val, 
// remove all occurrences of val in nums in-place. 
// The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are 
// not equal to val be k, to get accepted, 
// you need to do the following things:

// 1. Change the array nums such that the first k 
// elements of nums contain the elements which are 
// not equal to val. The remaining elements of nums 
// are not important as well as the size of nums.

// 2. Return k.

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, 
// with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, 
// with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.

// My Accepted solution
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Calculate value of k -- values not equal to val
        int size_of_array = nums.size();
        if ((!size_of_array)){
            return size_of_array;
        }
        // distinct values can also be duplicate -- need to handle that
        int distinct[size_of_array];
        int size_of_distinct = 0; //k
        for(int i=0; i<size_of_array; i++) {
            if (nums[i] != val) {
                distinct[size_of_distinct] = nums[i];
                size_of_distinct++;
            }
        }
        cout<<size_of_distinct<<endl;
        // traverse from 0 to k and put the distinct elements
        // where val is present
        // All the distinct element should be available between
        // 0 to k
        for(int i=0; i<size_of_distinct; i++) {
            nums[i] = distinct[i];
        }
        return size_of_distinct;
    }
};

// BEST Solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};