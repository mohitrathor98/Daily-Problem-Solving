// Given two strings needle and haystack, return the index of the first occurrence of needle 
// in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_size = needle.size();
        int h_size = haystack.size();
        if (n_size > h_size) {
            return -1;
        }
        int i = 0, j = 0, match_index = 0;
        while(j < n_size && i<h_size) {
            if(needle[j++] != haystack[i++]) {
                match_index += 1;
                i = match_index;
                j = 0;
            }
        }
        if (n_size > (h_size-match_index)) {
            return -1;
        }
        return match_index;
    }
};

// Python Code: -- efficient than above
// class Solution:
//     def strStr(self, haystack: str, needle: str) -> int:
//         n = len(needle)
//         h = len(haystack)
//         i = 0
//         if needle == haystack:
//             return 0
//         while ((h-i) >= n):
//             if haystack[i:i+n] == needle:
//                 return i
//             i += 1
//         return -1 
        