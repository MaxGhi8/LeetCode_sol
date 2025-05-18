#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1000000007;
        
        // Base case with only one column
        if (n == 1) {
            return (3 * (1 << (m-1))) % MOD;
        }
        
        // For small m, we can use integers to represent colorings
        // Each color takes 2 bits: 00=empty, 01=red, 10=green, 11=blue
        // So m cells take 2*m bits, max state is (1 << (2*m))
        
        // Generate all valid colorings for a single column
        std::vector<int> validColorings;
        generateValidColorings(m, 0, 0, validColorings);
        
        // DP array: dp[i] = count of valid colorings ending with state i
        std::unordered_map<int, int> dp;
        for (int coloring : validColorings) {
            dp[coloring] = 1;
        }
        
        // Precompute valid transitions between colorings
        std::unordered_map<int, std::vector<int>> validTransitions;
        for (int coloring1 : validColorings) {
            validTransitions[coloring1] = std::vector<int>();
            for (int coloring2 : validColorings) {
                if (canTransition(coloring1, coloring2, m)) {
                    validTransitions[coloring1].push_back(coloring2);
                }
            }
        }
        
        // DP on columns
        for (int i = 1; i < n; i++) {
            std::unordered_map<int, int> nextDp;
            
            for (const auto& [state, count] : dp) {
                for (int nextState : validTransitions[state]) {
                    nextDp[nextState] = (nextDp[nextState] + static_cast<int>(count)) % MOD;
                }
            }
            
            dp = std::move(nextDp);
        }
        
        // Sum up all possibilities
        int total = 0;
        for (const auto& [_, count] : dp) {a
            total = (total + count) % MOD;
        }
        
        return total;
    }

private:
    // Check if coloring2 can follow coloring1 (no adjacent cells have same color)
    bool canTransition(int coloring1, int coloring2, int m) {
        for (int i = 0; i < m; i++) {
            // Extract color (2 bits) from each coloring
            int color1 = (coloring1 >> (2*i)) & 3;
            int color2 = (coloring2 >> (2*i)) & 3;
            
            if (color1 == color2) {
                return false;
            }
        }
        return true;
    }
    
    // Generate all valid colorings recursively
    void generateValidColorings(int m, int pos, int current, std::vector<int>& result) {
        if (pos == m) {
            result.push_back(current);
            return;
        }
        
        // 1=red, 2=green, 3=blue (in 2-bit representation)
        for (int color = 1; color <= 3; color++) {
            // Check if this color conflicts with the previous cell
            if (pos > 0) {
                int prevColor = (current >> (2*(pos-1))) & 3;
                if (prevColor == color) {
                    continue;
                }
            }
            
            // Add this color to the current state
            int nextState = current | (color << (2*pos));
            generateValidColorings(m, pos+1, nextState, result);
        }
    }
};