to_uppercase = lambda s: s.upper()

# Lambda to check if string starts with a specific character
starts_with = lambda s, ch: s.startswith(ch)

# Input
text = input("Enter a string: ")
char = input("Enter the character to check start: ")

# Output
print("Uppercase String:", to_uppercase(text))

if starts_with(text, char):
    print(f"The string starts with '{char}'.")
else:
    print(f"The string does NOT start with '{char}'.")
