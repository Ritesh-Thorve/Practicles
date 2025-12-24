class BankAccount:
    def __init__(self, account_no, name, account_type, balance=0):
        self.account_no = account_no
        self.name = name
        self.account_type = account_type
        self.balance = balance
    # Deposit money
    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"₹{amount} deposited successfully.")
        else:
            print("Invalid deposit amount.")
    def withdraw(self, amount):
        if amount > 0:
            if amount <= self.balance:
                self.balance -= amount
                print(f"₹{amount} withdrawn successfully.")
            else:
                print("Insufficient balance.")
        else:
            print("Invalid withdrawal amount.")
    # Check balance
    def check_balance(self):
        print(f"Current Balance: ₹{self.balance}")
    # Display account information
    def display_account_info(self):
        print("\n--- Account Information ---")
        print(f"Account Number : {self.account_no}")
        print(f"Name           : {self.name}")
        print(f"Account Type   : {self.account_type}")
        print(f"Balance        : ₹{self.balance}")
        print("---------------------------")
# Creating an account
acc_no = input("Enter Account Number: ")
name = input("Enter Name: ")
acc_type = input("Enter Account Type (Savings/Current): ")
balance = float(input("Enter Initial Balance: "))
# Create BankAccount object
account = BankAccount(acc_no, name, acc_type, balance)
# Menu-driven banking operations
while True:
    print("\n----- Banking Menu -----")
    print("1. Deposit Money")
    print("2. Withdraw Money")
    print("3. Check Balance")
    print("4. Display Account Info")
    print("5. Exit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        amount = float(input("Enter amount to deposit: "))
        account.deposit(amount)
    elif choice == 2:
        amount = float(input("Enter amount to withdraw: "))
        account.withdraw(amount)
    elif choice == 3:
        account.check_balance()
    elif choice == 4:
        account.display_account_info()
    elif choice == 5:
        print("Thank you for using the banking application!")
        break
    else:
        print("Invalid choice! Please try again.")
