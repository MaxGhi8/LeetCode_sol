class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if m == 0:
            a = -n
        else:
            a = -n-1
        b = -1
        for i in range(1,  n+m+1):
            if b < -n:
                break
            elif a < -m-n:
                if b == -1:
                    nums1[:m] = nums2
                else:
                    nums1[:len(nums2[:b+1])] = nums2[:b+1]
                break
            elif nums2[b] >= nums1[a]:
                nums1[-i] = nums2[b]
                b -= 1
            else:
                nums1[-i] = nums1[a]
                a -= 1