import sys

def tsp_dp(graph):
    """Solve the Travelling Salesman Problem using Dynamic Programming with Bitmasking."""
    
    n = len(graph)
    ALL_VISITED = (1 << n) - 1  # Bitmask when all cities are visited
    
    # dp[mask][i] = minimum cost to visit all cities in 'mask', ending at city 'i'
    dp = [[None] * n for _ in range(1 << n)]

    def visit(mask, pos):
        """Recursive helper function for visiting cities."""
        
        # If all cities have been visited, return to the starting city (0)
        if mask == ALL_VISITED:
            return graph[pos][0]
        
        # Return the stored result if already computed
        if dp[mask][pos] is not None:
            return dp[mask][pos]
        
        min_cost = sys.maxsize
        
        # Try to go to every unvisited city next
        for city in range(n):
            if mask & (1 << city) == 0:  # If 'city' not yet visited
                cost = graph[pos][city] + visit(mask | (1 << city), city)
                min_cost = min(min_cost, cost)
        
        # Store result in dp table
        dp[mask][pos] = min_cost
        return min_cost

    # Start from city 0 with only city 0 visited (mask = 1)
    return visit(1, 0)


# Example Run
if __name__ == "__main__":
    print("=== TRAVELLING SALESMAN PROBLEM USING DP + BITMASKING ===")

    # Distance matrix for 4 cities
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    min_cost = tsp_dp(graph)
    print("\nMinimum cost of TSP tour:", min_cost)
