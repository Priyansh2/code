class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        mod = 10**9 +7
        ans = 0
        for i in range(22):
            power = 2**i
            d = {}
            res = 0
            for x in deliciousness:
                if power -x in d:
                    res = (res + d[power-x]) %mod
                d[x] =d.get(x,0) + 1
            ans= (ans + res)%mod
        return ans       