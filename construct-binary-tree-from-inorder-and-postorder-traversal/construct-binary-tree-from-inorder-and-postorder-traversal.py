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

class Solution:
    """
    @param inorder: A list of integers that inorder traversal of a tree
    @param postorder: A list of integers that postorder traversal of a tree
    @return: Root of a tree
    """
    def buildTree(self, inorder, postorder):
        #坑点：判断的时候注意有子树为空的时候，判断的时候不能两个序列只要有空的就返回，应该只判断后序队列，
        #就如同先序+中序的时候，只需要一个先序的判断就可以了，如果同时判断，就有不必要的问题；切记；
        if len(postorder) == 0 : return None
        prelen, latlen = len(inorder), len(postorder)
        root = TreeNode(postorder[latlen-1])
        i = inorder.index(root.val)
        root.left = self.buildTree(inorder[:i], postorder[:i])
        root.right = self.buildTree(inorder[i+1:], postorder[i:-1])
        return root

if __name__ == '__main__':
    Solution().buildTree([2,1,3],[2,3,1])
    print([0,1,2,3,4,5][:-1]) #python中间使用[]中括号控制位置的时候，切记，一定是前闭后开；；；
