from collections import deque

def is_valid_state(state, jug1_capacity, jug2_capacity):
    """Check if the given state is valid (within jug limits)."""
    x, y = state
    return 0 <= x <= jug1_capacity and 0 <= y <= jug2_capacity


def bfs_water_jug(jug1_capacity, jug2_capacity, target):
    """Solve the Water Jug Problem using Breadth-First Search (BFS)."""
    
    visited = set()  # To keep track of visited states
    queue = deque()  # Queue will store tuples: (jug1, jug2, path)
    
    # Start from (0, 0)
    queue.append((0, 0, []))
    
    while queue:
        jug1, jug2, path = queue.popleft()

        # Skip already visited states
        if (jug1, jug2) in visited:
            continue
        
        visited.add((jug1, jug2))  # Mark as visited
        current_path = path + [(jug1, jug2)]  # Record current state
        
        # Check if goal is achieved
        if jug1 == target or jug2 == target:
            print("\n🎯 Target achieved!")
            print("Sequence of steps (Jug1, Jug2):")
            for step in current_path:
                print(step)
            return True
        
        # Generate all possible next states (actions)
        next_states = [
            (jug1_capacity, jug2),  # Fill Jug1
            (jug1, jug2_capacity),  # Fill Jug2
            (0, jug2),              # Empty Jug1
            (jug1, 0),              # Empty Jug2
            
            # Pour Jug1 → Jug2
            (jug1 - min(jug1, jug2_capacity - jug2),
             jug2 + min(jug1, jug2_capacity - jug2)),
            
            # Pour Jug2 → Jug1
            (jug1 + min(jug2, jug1_capacity - jug1),
             jug2 - min(jug2, jug1_capacity - jug1))
        ]
        
        # Enqueue valid and unvisited states
        for state in next_states:
            if is_valid_state(state, jug1_capacity, jug2_capacity) and state not in visited:
                queue.append((state[0], state[1], current_path))
    
    print("\n❌ Target cannot be reached with given jug capacities.")
    return False


# Example Run
if __name__ == "__main__":
    print("=== WATER JUG PROBLEM USING BFS ===")
    jug1_capacity = int(input("Enter capacity of Jug 1: "))
    jug2_capacity = int(input("Enter capacity of Jug 2: "))
    target = int(input("Enter target amount (Z): "))

    print(f"\nFinding solution for Jug1={jug1_capacity}, Jug2={jug2_capacity}, Target={target}...\n")
    bfs_water_jug(jug1_capacity, jug2_capacity, target)
