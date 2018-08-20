import copy,gc

class Solution:
    def kSumII(self, A, k, targer):
        ret = []
        if len(A) < 1:
            return ret

        nums = []
        if k == 1:
            for i in A:
                if i == targer:
                    nums.append(targer)
                    ret.append(nums)
            return ret
        else:
            while len(A) > 1:
                tmp = A[0]
                del(A[0])
                A1 = copy.copy(A)
                tmpout = self.kSumII(A1, k-1, targer-tmp)
                for i in tmpout:
                    if len(i) != 0:
                        i.append(tmp)
                        ret.append(i)
            return ret


if __name__ == '__main__':
    print(Solution().kSumII([1,4,7,10,12,15,16,18,21,23,24,25,26,29], 5, 113))
