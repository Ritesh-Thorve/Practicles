import numpy as np
from statistics import mode, StatisticsError

def descriptive_stats(arr):
    arr_np = np.array(arr)
    mean_val = np.mean(arr_np)
    std_val = np.std(arr_np)
    min_val = np.min(arr_np)
    max_val = np.max(arr_np)
    median_val = np.median(arr_np)

    try:
        mode_val = mode(arr_np)
    except StatisticsError:
        mode_val = "No unique mode"  # occurs when data is multimodal

    print(f"Array: {arr_np}")
    print(f"Mean: {mean_val}")
    print(f"Standard Deviation: {std_val}")
    print(f"Median: {median_val}")
    print(f"Mode: {mode_val}")
    print(f"Minimum: {min_val}")
    print(f"Maximum: {max_val}")


if __name__ == "__main__":
    # Example array
    data = [1, 2, 2, 3, 4, 5, 5, 5, 6, 7]
    descriptive_stats(data)
