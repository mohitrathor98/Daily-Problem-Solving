// Given a roman numeral, convert it to an integer.
// Example 1:
// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int num = 0;
        int size = s.size();
        for (int i=0; i<size; i++) {
            if((i<size-1) && (roman[s[i]] < roman[s[i+1]])) {
                num += (roman[s[i+1]] - roman[s[i]]);
                i++;
               cout<<num<<endl;
            } else {
                num += roman[s[i]];
                cout<<num<<endl;
            }
        }
        
        // if (roman[s[size-2]] < roman[s[size-1]]) {
        //     num += (roman[s[size-1]] - roman[s[size-2]]);
        // } else {
        //     num += roman[s[size-1]];
        //     cout<<num<<endl;
        // }
        return num;
    }
};