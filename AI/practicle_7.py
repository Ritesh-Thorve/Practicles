import math

# Alpha-Beta Pruning Implementation
def alpha_beta(node, depth, alpha, beta, maximizing_player, game_tree):
    # Base case: leaf or depth limit
    if depth == 0 or not isinstance(game_tree[node], list):
        return game_tree[node]

    if maximizing_player:
        max_eval = -math.inf
        for child in game_tree[node]:
            eval_value = alpha_beta(
                child, depth - 1, alpha, beta, False, game_tree
            )
            max_eval = max(max_eval, eval_value)
            alpha = max(alpha, eval_value)

            # Pruning
            if beta <= alpha:
                break
        return max_eval

    else:  # Minimizing player
        min_eval = math.inf
        for child in game_tree[node]:
            eval_value = alpha_beta(
                child, depth - 1, alpha, beta, True, game_tree
            )
            min_eval = min(min_eval, eval_value)
            beta = min(beta, eval_value)

            # Pruning
            if beta <= alpha:
                break
        return min_eval


# Example Game Tree (A simple fixed tree)
game_tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': 3,
    'E': 5,
    'F': 6,
    'G': 9
}

# Run Alpha-Beta
best_value = alpha_beta(
    'A', depth=3, alpha=-math.inf, beta=math.inf,
    maximizing_player=True, game_tree=game_tree
)

print("Best value for root node A:", best_value)
