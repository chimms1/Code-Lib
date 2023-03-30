class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        i = 0
        answer = []
        while i <= numRows:
            if i==1:
                answer.append([1])
            if i==2:
                answer.append([1,1])
            if i>2:
                latestline = answer[len(answer)-1]
                temp = []
                temp.append(1)
                for j in range(len(latestline)-1):
                    temp.append(latestline[j]+latestline[j+1])
                temp.append(1)
                answer.append(temp)
            i += 1
        return answer

print(Solution().generate(5))
