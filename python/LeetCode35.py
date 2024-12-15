class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.helper(nums, target, 0)

    def helper(self, nums, target, index):
        if len(nums) == 0:
            return index
        else:
            mid = len(nums) // 2
            if nums[mid] == target:
                return index + mid
            elif nums[mid] > target:
                return self.helper(nums[:mid], target, index)
            else:
                return self.helper(nums[mid + 1 :], target, index + mid + 1)
