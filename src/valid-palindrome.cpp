// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. 
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:=
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

class Solution {
public:
    bool isAlpha(int ascii) {
        if (ascii >= 65 && ascii <= 90) {
            return true;
        }
        if (ascii >= 97 && ascii <= 122) {
            return true;
        }
        if (ascii >=48 && ascii <= 57) {
            return true;
        }
        return false;
    }

    int toLower(char c) {
        int ascii = int(c);
        if (ascii >= 65 && ascii <= 90 ) {
            return char(ascii+32);
        }
        return char(ascii);
    }

    bool isPalindrome(string s) {
    
        int size = s.size();
        if (size == 1) {
            return true;
        }

        int i = 0, j = 0;
        while(i < size){
            if (isAlpha(s[i])) {
                s[j++] = toLower(s[i]);
            } 
            i++;
        }
        
        int start = 0; int end = j-1;
        while(start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};