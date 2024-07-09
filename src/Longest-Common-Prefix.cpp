// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 // Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        string smallest = strs[0];
        for (int i=1; i<size; i++) {
            if (smallest.size() > strs[i].size()) {
                smallest = strs[i];
            }
        }

        int j = 0;
        string result = "";
        while (j != smallest.size()) {
            char ch = smallest[j];
    
            for (int i=0; i<size; i++) {
                if (strs[i][j] != ch) {
                    return result;
                }
            }
            result += ch;        
            j++;
        }
        return result;
    }
};