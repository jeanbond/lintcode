'''
Topic:the base heap data struct oper
Attention:
    some methed use 0 location to store data, it will affect child-parent calculation formula;
    when 0 store data: parent formula->(child-1)/2 , child formula->(parent * 2)+1 and (parent * 2)+2;
    when 0 dose not store data: parent formula->child/2 , child formula->parent*2 and (parent*2)+1;
'''
class Heap:
    '''Tips: do not use 0 loc to store data'''
    data = []
    heapMaxSize = 0
    rootDataIdx = 1 #root index;
    def __init__(self, maxSize):
        self.heapMaxSize = maxSize
        self.data.clear()
    
    def buildHeap(self, inputList):
        self.data[self.rootDataIdx:] = inputList
        return self.refine()
    
    def refine(self):
        childIdx = len(self.data) - 1
        self.shiftUp(childIdx)     

    ''' Core Code Area start ... '''
    def shiftUp(self, childIdx):
        parentIdx = self.getParentIdx(childIdx)
        if parentIdx == -1: return -1
        for i  in range(parentIdx, 0, -1):
            if self.data[i] > self.data[self.findMinChildIdx(i)]:
                minChildidx = self.findMinChildIdx(i)                
                self.data[i], self.data[minChildidx] = self.data[minChildidx], self.data[i]
                self.shiftDown(minChildidx)
        
    def shiftDown(self, parentIdx):
        if parentIdx < self.rootDataIdx:return -1
        childMinIdx = self.findMinChildIdx(parentIdx)
        if childMinIdx == -1:return 
        if self.data[parentIdx] > self.data[childMinIdx]:
            self.data[parentIdx], self.data[childMinIdx] = self.data[childMinIdx], self.data[parentIdx]
            self.shiftDown(childMinIdx)        
    ''' Core Code Area end ... '''

    def insert(self, el):
        '''Notes: self.data[0] is a empty location, this location is useful but not store any data;'''
        if self.full():
            return None
        if el in self.data:
            print("Insert element has been in Heap!")
            return -1
        self.data.append(el)
        self.refine()
        return 0
    
    def delete(self):
        #we can just remove the root element;
        if self.empty():print('The heap is empty when removeing data...')
        self.data[self.rootDataIdx] = self.data[len(self.data)-1]
        del self.data[len(self.data)-1]
        self.refine()
        return 

    def compare(self, A, B):
        return A > B

    def show(self):
        print(self.data[self.rootDataIdx:])
    
    def getParentIdx(self, childIdx):
        return childIdx >> 1 if (childIdx >> 1) >= self.rootDataIdx else -1
    
    def getChildIdx(self, parentIdx):
        '''return[leftChildIdx, rightChildIdx]'''
        ret = []
        #return [int(parentIdx * 2), int((parentIdx*2)+1)] 
        if int(parentIdx << 1) < len(self.data):
            ret.append(int(parentIdx << 1))
        if int((parentIdx << 1)+1) < len(self.data):
            ret.append(int((parentIdx*2)+1))
        return ret

    def findMaxChildIdx(self, parentIdx):
        if parentIdx >= len(self.data):
            print('findMaxChildIdx input parent idx:%s error!' %parentIdx)
            return None
        childList = self.getChildIdx(parentIdx)
        if len(childList) <= 0: return -1 #not find any child idx
        if len(childList) == 1: return childList[0]
        return childList[0] if self.data[childList[0]] > self.data[childList[1]] else childList[1]
    
    def findMinChildIdx(self, parentIdx):
        if parentIdx >= len(self.data):
            print('findMaxChildIdx input parent idx:%s error!' %parentIdx)
            return None
        childList = self.getChildIdx(parentIdx)
        if len(childList) <= 0: return -1 #not find any child idx
        if len(childList) == 1: return childList[0]
        return childList[0] if self.data[childList[0]] < self.data[childList[1]] else childList[1]


    def full(self):
        return True if self.heapMaxSize < len(self.data) else False;
    
    def empty(self):
        return True if len(self.data)<=1 else False;
            
    def test(self):
        #return -1 if 0 else print('ss')
        b = 0
        a = b if b > 0 else  99
        print(a)

if __name__ == '__main__':
    s = Heap(255)
    #s.buildHeap([-1,3,32,5,6,7,9,11,34,23])  #test ok
    s.show()
    s.test()
    #insert and delete test pass;
    s.insert(1);s.show()
    s.insert(2);s.show()
    s.insert(7);s.show()
    s.insert(4);s.show()
    s.insert(6);s.show()
    s.insert(9);s.show()
    s.insert(11);s.show()
    s.insert(21);s.show()
    s.insert(34);s.show()
    s.insert(3);s.show()
    s.insert(45);s.show()
    s.delete();s.show()
