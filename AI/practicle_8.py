def is_safe(board, row, col):
    """Check if a queen can be placed at board[row][col]."""
    # Check this column on previous rows
    for i in range(row):
        if board[i] == col:
            return False

    # Check upper-left diagonal
    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    # Check upper-right diagonal
    for i, j in zip(range(row - 1, -1, -1), range(col + 1, 8)):
        if board[i] == j:
            return False

    return True


def solve_8_queens(row, board, solutions):
    """Recursively attempt to place queens row by row."""
    if row == 8:
        # Found a valid solution (copy the board)
        solutions.append(board[:])
        return

    for col in range(8):
        if is_safe(board, row, col):
            board[row] = col
            solve_8_queens(row + 1, board, solutions)


def print_board(board):
    """Print the board in chess-like format."""
    for r in range(8):
        row = ["Q" if board[r] == c else "." for c in range(8)]
        print(" ".join(row))
    print()


# Run the solver
solutions = []
solve_8_queens(0, [None] * 8, solutions)

print(f"Total number of solutions: {len(solutions)}\n")

# Print all solutions (remove this loop if you only want the count)
for i, sol in enumerate(solutions, 1):
    print(f"Solution {i}:")
    print_board(sol)
