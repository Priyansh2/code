class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        queue = deque()
        for i in range(1,10):
            queue.append(str(i))
        d = 1
        while d<=n-1:
            l = len(queue)
            for x  in range(l):
                number = queue.popleft()
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
        return queue    