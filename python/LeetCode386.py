class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        # Compute number of digits
        ans = [1]
        num = 1
        n_digits = 1
        for i in range(1, 6):
            if n / (10**i) >= 1:
                n_digits += 1
                num *= 10
                ans.append(num)
            else:
                break

        flag = 0
        # at every iteration I add a number
        for _ in range(n - n_digits):
            if flag > 0:
                flag -= 1
                num *= 10

            else:
                num += 1

                if num > n:
                    if num % 10 == 0:
                        num = num // 10
                    else:
                        num = num // 10 + 1

                while num % 10 == 0:
                    flag += 1
                    num = num // 10

            ans.append(num)

        return ans
