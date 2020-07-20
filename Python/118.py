from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        i = 1
        while nowRows > 0:
            tmp = []
            if i == 1:
                tmp.add(1)
            else if i==2:
                tmp.add(1)
                tmp.add(1)
            else:
                tmp.add(1)
                last = res[-1]
                for j in range(len(last)-1):
                    tmp.add(last[j]+last[j+1])
                tmp.add(1)
            res.add(tmp)
            i += 1
            numRows -= 1
        return res

