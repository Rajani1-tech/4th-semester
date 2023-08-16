def is_safe(board, row, col):
    # Check if it's safe to place a queen at the given position
    # Check row and column
    for i in range(len(board)):
        if board[row][i] == 1 or board[i][col] == 1:
            return False

    # Check diagonals
    for i in range(len(board)):
        for j in range(len(board)):
            if (i + j == row + col) or (i - j == row - col):
                if board[i][j] == 1:
                    return False

    return True

def solve_queen_problem(board, col):
    # Base case: If all queens are placed, return True
    if col >= len(board):
        return True

    # Try placing a queen in each row of the current column
    for i in range(len(board)):
        if is_safe(board, i, col):
            # Place the queen at (i, col)
            board[i][col] = 1

            # Recur to place the rest of the queens
            if solve_queen_problem(board, col + 1):
                return True

            # If placing the queen leads to an invalid solution, backtrack
            board[i][col] = 0

    # If no solution is found, return False
    return False

def print_solution(board):
    # Print the board configuration
    for row in board:
        for cell in row:
            print(cell, end=" ")
        print()

# Create an 8x8 chessboard
board = [[0] * 8 for _ in range(8)]

# Solve the 8-Queen problem
if solve_queen_problem(board, 0):
    print("Solution:")
    print_solution(board)
else:
    print("No solution found.")
