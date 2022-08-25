class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        n = str(n)
        sum = 0
        prod = 1
        for i in n:
            sum+=int(i)
            prod*=int(i)
        return prod - sum    