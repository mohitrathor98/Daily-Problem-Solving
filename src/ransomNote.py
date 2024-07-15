# Given two strings ransomNote and magazine, return true if ransomNote can be 
#constructed by using the letters from magazine and false otherwise.
# Each letter in magazine can only be used once in ransomNote.

# Example 1:
# Input: ransomNote = "a", magazine = "b"
# Output: false
# Example 2:

# Input: ransomNote = "aa", magazine = "ab"
# Output: false
# Example 3:

# Input: ransomNote = "aa", magazine = "aab"
# Output: true

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_letters = {}
        for s in magazine:
            if s in mag_letters.keys():
                mag_letters[s] += 1
            else:
                mag_letters[s] = 1
        
        for s in ransomNote:
            if s not in mag_letters.keys():
                return False
            if mag_letters[s] == 0:
                return False
            else:
                mag_letters[s] -= 1
        return True