"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

import queue

class Solution:
    ret = []
    """
    @param root: A Tree
    @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
    """
    def zigzagLevelOrder(self, root):
        # write your code here
        if root == None:return self.ret
        tmp, reverseFlag = [], True

        q = queue.Queue()
        q.put(root)
        while not q.empty():
            tmp.clear()
            size = q.qsize()
            reverseFlag = not reverseFlag
            for i in range(size):
                ts = q.get()
                tmp.append(ts.val)
                if ts.left != None: q.put(ts.left)
                if ts.right != None: q.put(ts.right)
            if reverseFlag: tmp.reverse()
            self.ret.append(list(tmp))
        return self.ret


if __name__ == "__main__":
    print('shit')
