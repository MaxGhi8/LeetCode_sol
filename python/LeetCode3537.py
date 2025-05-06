class Solution:
    def specialGrid(self, N: int) -> List[List[int]]:
        size = 2**N
        grid = [[0 for _ in range(size)] for _ in range(size)]
        self._fill_grid(grid, 0, 0, size, 0)
        return grid
        
    def _fill_grid(self, grid: list[list[int]], row: int, col: int, size: int, start_num: int) -> None:
        
        if size == 1:
            grid[row][col] = start_num
            return
        
        half_size = size//2
        
        
        self._fill_grid(grid, row, col + half_size, half_size, start_num)
        self._fill_grid(grid, row + half_size, col + half_size, half_size, start_num + half_size**2)
        self._fill_grid(grid, row + half_size, col, half_size, start_num + 2*half_size**2)
        self._fill_grid(grid, row, col, half_size, start_num + 3*half_size**2)
        
        