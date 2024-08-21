# Given an array of strings strs, group the anagrams together. You can return the answer in any order.

# An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

# Example 1:

# Input: strs = ["eat","tea","tan","ate","nat","bat"]
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
# Example 2:

# Input: strs = [""]
# Output: [[""]]
# Example 3:

# Input: strs = ["a"]
# Output: [["a"]]
 

# Constraints:

# 1 <= strs.length <= 104
# 0 <= strs[i].length <= 100
# strs[i] consists of lowercase English letters.

def checkIfAnagram(str1, str2):
    letters = {}
    if len(str1) != len(str2):
        return False
    for l in str1:
        if l in letters.keys():
            letters[l] += 1
        else:
            letters[l] = 1
    for l in str2:
        if l not in letters.keys():
            return False
        if letters[l] == 0:
            return False
        letters[l] -= 1
    return True

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        solution = []
        anagrams = {}
        for str in strs:
            anagramFound = False
            for key in anagrams.keys():
                if checkIfAnagram(key, str):
                    anagrams[key].append(str)
                    anagramFound = True
                    break
            if not anagramFound:
                anagrams[str] = []

        print(anagrams)
        for key, values in anagrams.items():
            solution.append([key] + values)
        return solution
