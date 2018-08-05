import math
class BitMask:
    '''
    Author: xuwei x17133 At 2018/08/02
    dsc:
        1.use binary mask solve 'mice drink poison' problem.
        2.show one posibility on detail.
        3.use self.lensi to control output length.
        4.use shift move(replacement) left/right to replace multiplication/division.
        5.use a special func to convering bianry to string for outputing.
    '''
    
    lensi = 12
    def calcuAnimalCnt(self, poisonCnt):
        ''' find minum count for poison test;
            if u need detailed process, try to use the 'showCalcuProcess' to show all '''
        if poisonCnt < 1:return 0
        bottleCnt = int(math.ceil(math.log2(poisonCnt)))
        return bottleCnt
    
    def showCalcuProcess(self, poisonCnt):
        '''Caution: this function is used to show one possibility, 
            no which one is important, ideas and method are the important;
            when u need to answer such question, try to understand this func; '''
        '''Suppose: node 5 is poison '''
        antCnt = int(math.ceil(math.log2(poisonCnt)))
        p1 = [1]; p2 = []
        for i in range(1, antCnt):
            #make condition mask by shift move(left or right) are all fine;
            p1.append((1<<i) | p1[i-1])
        for i in range(0,(len(p1)+1)//2):
            for j in range((len(p1))//2,len(p1),1):
                #make bitmask by xor operation; 
                #try to find binard output;               
                p2.append(p1[i] ^ p1[j])
                print(self.itob(p2[-1]))
        ot = p2[0]
        for item in p2:
            #make outer flag by and operation;
            # result is a single flag;
            ot = item & ot
        return math.log2(ot) if ot != 0 else 0

    def itob(self, ins):
        '''translate int to binary by bin method;
            notes: care the output's length and alignment by format or print's control character;
        '''
        r1 = bin(ins)
        lensi = self.lensi
        ret = ''
        if len(r1) <= lensi:
            #[0-1]:output '0b';
            #[2-12]:detail binary output;
            ret = r1[0:2]+'0'*(lensi-len(r1))+r1[2:]
        return ret


if __name__ == '__main__':
    print(BitMask().calcuAnimalCnt(1000))
    BitMask().showCalcuProcess(1000)
    #print(BitMask().itob(10))