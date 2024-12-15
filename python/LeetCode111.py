# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        ## With this solution I have to check for the entire tree
        # if not root:
        #     return 0
        # elif not root.left:
        #     return 1 + self.minDepth(root.right)
        # elif not root.right:
        #     return 1 + self.minDepth(root.left)
        # else:
        #     return 1 + min(self.minDepth(root.left), self.minDepth(root.right))

        ## This solution stop at the first leaf ecounter
        if not root:
            return 0  # If the tree is empty, return depth 0

        queue = deque(
            [(root, 1)]
        )  # Initialize the queue with the root node and depth 1

        while queue:
            node, depth = queue.popleft()

            # If it's a leaf node, return the current depth
            if not node.left and not node.right:
                return depth

            # Add left and right children to the queue, if they exist
            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))
