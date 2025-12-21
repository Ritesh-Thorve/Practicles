def tower_of_hanoi(n, source, auxiliary, destination):
    """
    Recursive function to solve the Tower of Hanoi puzzle.
    Parameters:
    n (int): Number of disks
    source (str): The peg from which disks are moved
    auxiliary (str): The peg used as helper
    destination (str): The peg to which disks are moved
    """
    # Base case: if there is only one disk
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return
    
    # Step 1: Move top n-1 disks from source to auxiliary
    tower_of_hanoi(n - 1, source, destination, auxiliary)
    
    # Step 2: Move the largest disk from source to destination
    print(f"Move disk {n} from {source} to {destination}")
    
    # Step 3: Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n - 1, auxiliary, source, destination)

# -------- Main program --------
n = int(input("Enter number of disks: "))
print("\nSequence of moves:")
tower_of_hanoi(n, 'A', 'B', 'C')
