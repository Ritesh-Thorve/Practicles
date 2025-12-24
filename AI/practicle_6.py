from collections import deque

# State representation:
# (monkey_position, box_position, monkey_on_box, banana_position, has_banana)

def get_next_states(state):
    monkey, box, on_box, banana, has = state
    next_states = []

    # If banana already taken, no more actions
    if has:
        return next_states

    positions = ["door", "window", "middle"]

    # 1. Monkey moves
    for pos in positions:
        if pos != monkey:
            next_states.append((pos, box, on_box, banana, has))

    # 2. Monkey pushes box (only if monkey and box are at same position
    # and monkey is not on box)
    if monkey == box and not on_box:
        for pos in positions:
            if pos != box:
                next_states.append((pos, pos, on_box, banana, has))

    # 3. Monkey climbs box
    if monkey == box and not on_box:
        next_states.append((monkey, box, True, banana, has))

    # 4. Monkey climbs down
    if on_box:
        next_states.append((monkey, box, False, banana, has))

    # 5. Monkey grabs banana (only if on box and box under banana)
    if on_box and box == banana:
        next_states.append((monkey, box, on_box, banana, True))

    return next_states


def bfs(start_state):
    queue = deque([(start_state, [])])
    visited = set()

    while queue:
        state, path = queue.popleft()

        if state in visited:
            continue
        visited.add(state)

        monkey, box, on_box, banana, has_banana = state

        # Goal check
        if has_banana:
            return path + ["Monkey grabs banana!"]

        # Expand next states
        for next_state in get_next_states(state):
            action_desc = f"State changed: {state} → {next_state}"
            queue.append((next_state, path + [action_desc]))

    return None


# Initial state:
# Monkey at door, box at window, banana at middle
start = ("door", "window", False, "middle", False)

solution = bfs(start)

print("\n--- SOLUTION STEPS ---")
if solution:
    for step in solution:
        print(step)
else:
    print("No solution found.")
