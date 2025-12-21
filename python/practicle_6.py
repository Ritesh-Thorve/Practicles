import os
# Input: directory path
directory = input("Enter the directory path: ")
try:
    # Get list of files (excluding subdirectories)
    files = [os.path.join(directory, f) for f in os.listdir(directory)
             if os.path.isfile(os.path.join(directory, f))]

    # Sort files by creation time
    sorted_files = sorted(files, key=os.path.getctime)

    # Output
    print("\nFiles sorted by creation date:")
    for file in sorted_files:
        print(file)

except FileNotFoundError:
    print("The specified directory does not exist.")
except PermissionError:
    print("You do not have permission to access this directory.")
