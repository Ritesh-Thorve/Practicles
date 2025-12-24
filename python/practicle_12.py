import numpy as np
import matplotlib.pyplot as plt
def simple_plot():
    # Create data using NumPy arrays
    x = np.linspace(0, 10, 50)  # 50 points between 0 and 10
    y = np.sin(x)             # sine curve
    y2 = np.cos(x)            # cosine curve
    # Manipulate data
    y_shifted = y + 0.5       # shift sine curve upward
    y2_scaled = 2 * y2       # scale cosine curve
    # Plotting
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, label='sin(x)', color='blue', marker='o')
    plt.plot(x, y2, label='cos(x)', color='red', linestyle='--')
    plt.plot(x, y_shifted, label='sin(x) + 0.5', color='green')
    plt.plot(x, y2_scaled, label='2 * cos(x)', color='purple')
    # Labels and customization
    plt.title("Simple Trigonometric Plots using NumPy and Matplotlib")
    plt.xlabel("x values")
    plt.ylabel("Function values")
    plt.legend()
    plt.grid(True)
    plt.show()
if __name__ == "__main__":
    simple_plot()
