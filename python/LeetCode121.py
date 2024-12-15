class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        Min, Max, profit = prices[0], None, 0
        for cost in prices:
            if cost < Min:
                Min = cost
                Max = None
            elif Max is None or cost > Max:
                Max = cost
                profit = max(Max - Min, profit)

        return profit
