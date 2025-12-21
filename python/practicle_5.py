# Accept input from the user
values = input("Enter comma-separated numbers: ")

# Split the string into a list
list_values = values.split(",")

# Convert the list to a tuple
tuple_values = tuple(list_values)

# Display the results
print("List:", list_values)
print("Tuple:", tuple_values)
