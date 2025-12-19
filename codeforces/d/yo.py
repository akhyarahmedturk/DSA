# Input sequence
arr = ["f","s","f","s","f","f","f","f","f","s","f","s"]
n = len(arr)

results = []

def backtrack(index, levels):
    """
    index: current statement index
    levels: list of current indentation levels of open 'f's
    """
    if index == n:
        # store the result as a list of (statement, level)
        results.append(levels[:])
        return

    if arr[index] == "s":
        # 's' can be placed at any open level (0..len(levels))
        for l in range(len(levels)+1):
            levels.append(l)
            backtrack(index+1, levels)
            levels.pop()
    else:  # 'f'
        # 'f' must increase indentation by 1 for next statement
        levels.append(len(levels))  # current level
        backtrack(index+1, levels)
        levels.pop()

# Run backtracking
backtrack(0, [])

# Print all results
for r in results:
    for idx, lvl in enumerate(r):
        print("    "*lvl + arr[idx])
    print("-"*20)

print("Total valid indentations:", len(results))
