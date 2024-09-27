import math
import pickle


class Grid:
    def __init__(self, size=None):
        if size is None:
            size = 9
        self.grid_size = size
        self.box_size = int(math.sqrt(size))
        self.grid = [[0] * size for _ in range(size)]

    def print_grid(self):
        for row in self.grid:
            print(" ".join(str(num) if num != 0 else "." for num in row))
        print(" ")  # 空行隔开

    def get_row(self, row):
        return self.grid[row]

    def get_col(self, col):
        return [self.grid[r][col] for r in range(len(self.grid))]

    def get_box(self, row, col):
        start_row = row - row % self.box_size
        start_col = col - col % self.box_size
        box = []
        for i in range(self.box_size):
            tempbox = []
            for j in range(self.box_size):
                tempbox.append(self.grid[start_row + i][start_col + j])
            box.append(tempbox)
        return box

    def getValue(self, row, col):
        return self.grid[row][col]

    def setValue(self, row, col, value):
        self.grid[row][col] = value


class Sudoku(Grid):
    def __init__(self, size=None):
        super().__init__(size)

    def parse(self, input_str):
        gs = (int)(math.sqrt(len(input_str)))
        bs = (int)(math.sqrt(gs))
        self.grid_size = gs
        self.box_size = bs
        self.grid = [[0] * gs for _ in range(gs)]

        for i in range(gs):
            for j in range(gs):
                self.grid[i][j] = (int)(input_str[i * gs + j])

    def getInference(self, row, col):
        if row == self.grid_size - 1 and col == self.grid_size:
            self.print_grid()
            return
        if col == self.grid_size:
            row = row + 1
            col = 0
        if self.grid[row][col] == 0:
            for digit in range(1, 10):
                if self.isValid(row, col, digit):
                    self.setValue(row, col, digit)
                    self.getInference(row, col + 1)
                    self.setValue(row, col, 0)
        else:
            self.getInference(row, col + 1)

    def isValid(self, row, col, num):
        # 检查行重复
        temprow = self.get_row(row)
        for i in range(self.grid_size):
            if temprow[i] == num:
                return False

        # 检查列重复
        tempcol = self.get_col(col)
        for i in range(self.grid_size):
            if tempcol[i] == num:
                return False

        # 检查box重复
        tempbox = self.get_box(row, col)
        for i in range(self.box_size):
            for j in range(self.box_size):
                if tempbox[i][j] == num:
                    return False

        return True


def SaveObject(obj, filename):  # 序列化
    with open(filename, "wb") as f:
        pickle.dump(obj, f)


def LoadObject(filename):  # 反序列化
    with open(filename, "rb") as f:
        obj = pickle.load(f)
    return obj


def test_SaveLoad(obj, filename):  # 测试函数
    SaveObject(obj, filename)
    test_sudoku = LoadObject(filename)
    print("sudoku grid_size is:", test_sudoku.grid_size)
    test_sudoku.print_grid()
    test_sudoku.getInference(0, 0)


if __name__ == "__main__":
    sudoku_str = "000840009010209008008000500000036090600000001090750000005000800400508060100064000"
    sudoku = Sudoku()
    sudoku.parse(sudoku_str)
    test_SaveLoad(sudoku, "sudoku.pkl")
    # sudoku.print_grid()
    # sudoku.getInference(0, 0)
