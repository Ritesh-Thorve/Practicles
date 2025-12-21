def is_armstrong(number):
    """Check if a three-digit number is an Armstrong number."""
    
    # Extract digits
    hundreds = number // 100
    tens = (number // 10) % 10
    units = number % 10

    # Calculate sum of cubes of digits
    sum_of_cubes = hundreds**3 + tens**3 + units**3

    # Return True if Armstrong condition is met
    return sum_of_cubes == number


# Input a three-digit number
num = int(input("Enter a three-digit number: "))

# Check and display result
if 100 <= num <= 999:
    if is_armstrong(num):
        print(f"{num} is an Armstrong number.")
    else:
        print(f"{num} is not an Armstrong number.")
else:
    print("Please enter a valid three-digit number.")
