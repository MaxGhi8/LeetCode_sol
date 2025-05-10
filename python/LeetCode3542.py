from typing import List
# Monotonic stack approach
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        st = []
        ans = 0

        for num in nums:
            while len(st) > 0 and num < st[-1]:
                st.pop()

            if len(st) == 0 or num > st[-1]:
                if num == 0:
                    continue
                ans += 1
                st.append(num)

        return ans

# Brute force approach
class Solution:
    def minOperations(self, nums: List[int]) -> int:

        if min(nums) == 0:
            As = self.split_(nums)
        else:
            As = [nums]
        
        total = 0
        while len(As) > 0:
            total += 1
            tmp = As[-1]
            As = As[:-1]
            for el in self.split_(tmp):
                As.append(el)
        
        return total
            
                
                
    def split_(self, Bs):
        As = []
        min_value = min(Bs)
        j = 0
        
        for i in range(len(Bs)):
            if Bs[i] == min_value:
                sub_list = Bs[j:i]
                j = i + 1
                if len(sub_list) > 0:
                    As.append(sub_list)
        
        try:
            sub_list = Bs[j:]
        except:
            sub_list = []
        if len(sub_list) > 0:
                    As.append(sub_list)
        
        return As
            
        