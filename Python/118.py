from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        i = 1
        while numRows > 0:
            tmp = []
            if i == 1:
                tmp.append(1)
            elif i==2:
                tmp.append(1)
                tmp.append(1)
            else:
                tmp.append(1)
                last = res[-1]
                for j in range(len(last)-1):
                    tmp.append(last[j]+last[j+1])
                tmp.append(1)
            res.append(tmp)
            i += 1
            numRows -= 1
        return res

