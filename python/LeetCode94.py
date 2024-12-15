# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ## recursive solution
        # if root is None:
        #     return []
        # return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

        ## iterative solution
        left = []
        final_list = []

        while root or left:
            while root:  # go all left
                left.append(root)
                root = root.left

            root = left.pop()  # takes the last left entries
            final_list.append(root.val)

            root = root.right

        return final_list
