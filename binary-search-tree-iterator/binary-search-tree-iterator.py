
import queue,copy
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class BSTIterator:
    """
    @param: root: The root of binary tree.
    """
    def __init__(self, root):
        #public
        self._st = queue.LifoQueue()
        while root != None:
            self._st.put(root)
            root = root.left

    """
    @return: True if there has next node, or false
    """
    def hasNext(self, ):
        return not self._st.empty()

    """
    @return: return next node
    """
    def next(self, ):
        if not self.hasNext():return None

        ret = self._st.get()
        out = ret
        #jump to right child;
        #in order to find min at O(1), 
        #we need to push all left child into stack;
        #Caution: this are will cause time limit problem;
        if ret.right != None: 
            ret = ret.right
            while ret != None:
                self._st.put(ret)
                ret = ret.left
        return out

    def test(self):
        a = [1,2,3,4,5]
        b = a[2]
        c = b
        print(a,b,c)
        b = a[3]
        print(a, b, c)


if __name__ == "__main__":
    print(BSTIterator(TreeNode(-1)).next())
    print(BSTIterator(TreeNode(-1)).test())
