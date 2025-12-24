import pandas as pd
import matplotlib.pyplot as plt

def vehicle_sales_analysis(file_path):
    # Read dataset (assuming column name is 'sale_date')
    df = pd.read_csv(file_path, parse_dates=['sale_date'])

    # Show top ten sales records
    print("Top 10 Vehicle Sales Records:")
    print(df.head(10))

    # Accept vehicle model from user
    model = input("\nEnter vehicle model to plot (exact match): ")

    # Filter by model (assuming column name is 'model')
    df_model = df[df['model'] == model]

    if df_model.empty:
        print(f"No records found for vehicle model '{model}'.")
        return

    # Sort by sale date
    df_model = df_model.sort_values(by='sale_date')

    # Plot sale date vs selling price
    plt.figure(figsize=(10, 5))
    plt.plot(df_model['sale_date'], df_model['selling_price'], marker='o')
    plt.title(f"Sale Date vs Selling Price for Model: {model}")
    plt.xlabel("Sale Date")
    plt.ylabel("Selling Price (₹ or USD etc.)")
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    file_path = 'vehicle_sales.csv'  # adjust path if needed
    vehicle_sales_analysis(file_path)
