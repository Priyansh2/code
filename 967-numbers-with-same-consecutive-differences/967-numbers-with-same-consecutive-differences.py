class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        queue = [str(i) for i in range(1,10)]
        d = 1
        while len(queue)!=0:
            length = len(queue)
            for i in range(length):
                number = queue.pop(0)
                candidate1 = int(number[-1]) + k
                candidate2 = int(number[-1]) - k
                if k==0:
                    queue.append(number + str(candidate1))
                    continue    
                if candidate1 <=9:
                    queue.append(number + str(candidate1))
                if candidate2 >=0:
                    queue.append(number + str(candidate2))
            d+=1
            if d==n:
                break
        return queue    