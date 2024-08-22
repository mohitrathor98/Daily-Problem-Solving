# Write an algorithm to determine if a number n is happy.

# A happy number is a number defined by the following process:

# Starting with any positive integer, replace the number by the sum of the squares of its digits.
# Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
# Those numbers for which this process ends in 1 are happy.
# Return true if n is a happy number, and false if not.

# A number will not be a Happy Number when it makes a loop in its sequence that is it touches a number in sequence which already been touched. 

# Example 1:

# Input: n = 19
# Output: true
# Explanation:
# 12 + 92 = 82
# 82 + 22 = 68
# 62 + 82 = 100
# 12 + 02 + 02 = 1
# Example 2:

# Input: n = 2
# Output: false

class Solution:
    def isHappy(self, n: int) -> bool:
        touched = {}
        while True:
            sum = 0
            temp = n
            while temp//10 > 0:
                digit = temp%10
                sum += digit*digit
                temp = temp//10
            sum += temp*temp
            n = sum
            if n == 1:
                return True
            if n in touched.keys():
                return False
            touched[n] = 1
        