class Solution:
    def countCollisions(self, directions: str) -> int:
        count = 0
        leftOver =directions.lstrip("L").rstrip("R") 
        for i in leftOver:
            if i!="S":
                count+=1
        return count        
            
        