import itertools


def solve_cryptoarithmetic(puzzle):
    # Get unique characters from the puzzle
    chars = set()
    for word in puzzle:
        chars.update(word)

    chars = list(chars)
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digits = range(10)

    # Generate all possible digit assignments
    for perm in itertools.permutations(digits, len(chars)):
        mapping = dict(zip(chars, perm))

        # Check if the assignment satisfies the puzzle
        if is_solution(puzzle, mapping):
            # Print the solution
            print_solution(puzzle, mapping)
            return True

    # No solution found
    return False

def is_solution(puzzle, mapping):
    # Convert words to numbers based on the digit mapping
    numbers = []
    for word in puzzle:
        number = 0
        for char in word:
            number = number * 10 + mapping[char]
        numbers.append(number)

    # Check if the sum condition holds
    return sum(numbers[:-1]) == numbers[-1]

def print_solution(puzzle, mapping):
    # Print the puzzle solution
    for word in puzzle:
        for char in word:
            print(mapping[char], end=" ")
        print()

# Example puzzle: SEND + MORE = MONEY
puzzle = ["SEND", "MORE", "MONEY"]

print("Cryptoarithmetic puzzle solution:")
if not solve_cryptoarithmetic(puzzle):
    print("No solution found.")
