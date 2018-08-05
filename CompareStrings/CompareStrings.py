class Solution:
    """
    @param A: A string
    @param B: A string
    @return: if string A contains all of the characters in B return true else return false
    """
    def compareStrings(self, A, B):
        if 0==len(B):
            return True
        if 0==len(A):
            return False
        dica, dicb = {}, {}
        for i in range(len(A)):
            if A[i] not in dica.keys():
                dica[A[i]] = 1
            else:
                dica[A[i]] += 1
        for i in range(len(B)):
            if B[i] not in dicb.keys():
                dicb[B[i]] = 1
            else:
                dicb[B[i]] += 1

        for i in range(len(B)):
            if B[i] not in dica.keys():
                return False
            if dicb[B[i]] > dica[B[i]]:
                return False
            if i == len(B)-1:
                return True



if __name__ == "__main__":
    print(Solution().compareStrings('ABCDEFG','ACC'))