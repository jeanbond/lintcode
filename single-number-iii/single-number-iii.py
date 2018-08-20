class Solution:
    '''
    Important comment: 2018.08.05 xuwei at home for h3c working;
    xor and or not are the most important operation in computer world, filled again;
    please add comment at soon;
    '''
    def singleNumberIII(self, A):
        ret = []
        a, b, xor, loc = 0, 0, 0, 0

        #xor all data;
        for i in A:
            xor ^= i
        #find the first diff location;
        for i in range(32):
            if (xor>>i)&1 == 1:loc = i
        ## oper two sets in diffrent way;
        for i in A:
            ks = (i >> loc)&1
            if ks == 1: a ^= i
            else:
                b ^= i

        #add two element into answer;
        ret.append(a);ret.append(b)
        return ret
                
if __name__ == "__main__":
    #
    print(Solution().singleNumberIII([4,12]))