# EMPLOYEE class with various operations

class Employee:
    total_employees = 0
    male_count = 0
    female_count = 0

    def __init__(self, name, designation, gender, doj, salary):
        self.name = name
        self.designation = designation
        self.gender = gender
        self.doj = doj
        self.salary = salary

        # Updating class-level counters
        Employee.total_employees += 1
        if gender.lower() == 'male':
            Employee.male_count += 1
        elif gender.lower() == 'female':
            Employee.female_count += 1

    def display(self):
        print(
            f"Name: {self.name}, Designation: {self.designation}, "
            f"Gender: {self.gender}, Date of Joining: {self.doj}, Salary: ₹{self.salary}"
        )


# List to store employee objects
employee_list = []

# Input section
n = int(input("Enter number of employees: "))
for i in range(n):
    print(f"\nEnter details for Employee {i + 1}:")
    name = input("Name: ")
    designation = input("Designation: ")
    gender = input("Gender (Male/Female): ")
    doj = input("Date of Joining (DD-MM-YYYY): ")
    salary = float(input("Salary: "))

    emp = Employee(name, designation, gender, doj, salary)
    employee_list.append(emp)

# Output section
print("\n--- All Employee Records ---")
for emp in employee_list:
    emp.display()

print("\n--- Summary Report ---")
print(f"Total Employees: {Employee.total_employees}")
print(f"Male Employees: {Employee.male_count}")
print(f"Female Employees: {Employee.female_count}")

print("\nEmployees with salary more than ₹10,000:")
for emp in employee_list:
    if emp.salary > 10000:
        emp.display()

print("\nEmployees with designation 'Asst Manager':")
for emp in employee_list:
    if emp.designation.lower() == 'asst manager':
        emp.display()
