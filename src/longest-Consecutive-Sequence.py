# https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

# You must write an algorithm that runs in O(n) time.

 

# Example 1:

# Input: nums = [100,4,200,1,3,2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
# Example 2:

# Input: nums = [0,3,7,2,5,8,4,6,0,1]
# Output: 9

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # O(NlogN)
        # nums = sorted(nums)
        # sequence = {}
        # for num in nums:
        #     if num+1 in sequence.keys():
        #         sequence[num] = sequence[num+1] + 1
        #     elif num-1 in sequence.keys():
        #         sequence[num] = sequence[num-1] + 1
        #     else:
        #         sequence[num] = 1
        # return max(sequence.values())
        s = set()
        ans = 0

        # Hash all the array elements
        for ele in nums:
            s.add(ele)

        # check each possible sequence from the start
         # then update optimal length
        for i in range(len(nums)):

            # if current element is the starting
            # element of a sequence
            if (nums[i]-1) not in s:

                # Then check for next elements in the
                # sequence
                j = nums[i]
                while(j in s):
                    j += 1

                # update  optimal length if this length
                # is more
                ans = max(ans, j-nums[i])
        return ans