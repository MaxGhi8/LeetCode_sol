class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        max_ = abs(nums[0] - nums[-1])
        for i in range(len(nums) - 1):
            diff = abs(nums[i] - nums[i + 1])
            if diff > max_:
                max_ = diff

        return max_
