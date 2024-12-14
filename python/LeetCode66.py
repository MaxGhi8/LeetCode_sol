class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for idx in range(len(digits) - 1, -1, -1):
            if digits[idx] + 1 < 10:
                digits[idx] += 1
                break
            else:
                digits[idx] = 0

            if idx == 0:
                digits = [1] + digits

        return digits
