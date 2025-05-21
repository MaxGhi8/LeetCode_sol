class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # O(n+m) space solution
        # n = len(matrix)
        # m = len(matrix[0])
        # cols = set()
        # rows = set()

        # for i in range(n):
        #     for j in range(m):
        #         if matrix[i][j] == 0:
        #             rows.add(i)
        #             cols.add(j)

        # for i in rows:
        #     for j in range(m):
        #         matrix[i][j] = 0

        # for j in cols:
        #     for i in range(n):
        #         matrix[i][j] = 0

        # O(1) space solution
        n = len(matrix)
        m = len(matrix[0])

        flag_row = 0
        flag_col = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    if i == 0:
                        flag_row = 1
                    if j == 0:
                        flag_col = 1
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, n):
            for j in range(1, m):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0

        if flag_row == 1:
            for j in range(m):
                matrix[0][j] = 0

        if flag_col == 1:
            for i in range(n):
                matrix[i][0] = 0
