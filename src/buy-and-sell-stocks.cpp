// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a
// different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 
// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Python Solution -- Easy, neat but with TLE
// class Solution:
//     def maxProfit(self, prices: List[int]) -> int:
//         profit = 0
//         for i in range(len(prices)-1):
//             max_val = max(prices[i+1:])
//             diff = max_val - prices[i]
//             if diff > profit:
//                 profit = diff
//         return profit

// Similar code in c++ -- way faster than python code but has TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
    
        int size = prices.size();
        for(int i=0; i<size-1; i++) {
            for (int j=i+1; j<size; j++) {
                int diff = prices[j] - prices[i];
                if (diff > max_profit) {
                    max_profit = diff;
                }
            }
        }

        return max_profit;
    }
};

// O(N) -- Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        int size = prices.size();
        int min = prices[0];
        for(int i=1; i<size; i++) {
            if (min > prices[i]) {
                // finding minimum price till day[i]
                min = prices[i];
            }
            if (max_profit < (prices[i] - min)) {
                // if we substract minimum price till this day
                // with the price of day i, 
                // we get profit for day i.
                max_profit = (prices[i]-min);
            }
        }
        return max_profit;
    }
};
