//case_study:2
#include <iostream>
#include <string>
using namespace std;
struct Contact {
string name;
string phone;
string email;
Contact* next;
};
void addContact(Contact*& head, const string& name,

const string& phone, const string& email) {
Contact* newNode = new Contact{name, phone, email, nullptr};
if (head == nullptr) {
head = newNode;
return;
}
Contact* temp = head;
while (temp->next != nullptr) {
temp = temp->next;
}
temp->next = newNode;
}
void displayContacts(Contact* head) {
if (head == nullptr) {
cout << "No contacts found.\n";
return;
}
cout << "\n--- Contact List ---\n";
Contact* temp = head;
while (temp != nullptr) {
cout << "Name : " << temp->name << "\n";
cout << "Phone: " << temp->phone << "\n";
cout << "Email: " << temp->email << "\n";
cout << "----------------------\n";
temp = temp->next;
}
}

Contact* searchContact(Contact* head, const string& keyName) {
Contact* temp = head;
while (temp != nullptr) {
if (temp->name == keyName)
return temp;
temp = temp->next;
}
return nullptr;
}
bool updateContact(Contact* head, const string& keyName,
const string& newPhone, const string& newEmail) {
Contact* result = searchContact(head, keyName);
if (result == nullptr) return false;
result->phone = newPhone;
result->email = newEmail;
return true;
}
bool deleteContact(Contact*& head, const string& keyName) {
if (head == nullptr) return false;
if (head->name == keyName) {
Contact* toDelete = head;
head = head->next;
delete toDelete;
return true;
}
Contact* prev = head;
Contact* curr = head->next;

while (curr != nullptr && curr->name != keyName) {
prev = curr;
curr = curr->next;
}
if (curr == nullptr) return false;

prev->next = curr->next;
delete curr;
return true;
}
int main() {
Contact* head = nullptr;
int choice;
string name, phone, email;
do {
cout << "\n===== Contact Management System =====\n";
cout << "1. Add Contact\n";
cout << "2. Display All Contacts\n";
cout << "3. Search Contact by Name\n";
cout << "4. Update Contact by Name\n";
cout << "5. Delete Contact by Name\n";
cout << "6. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
cin.ignore(); // clear newline from buffer
switch (choice) {
case 1:

cout << "Enter name : ";
getline(cin, name);
cout << "Enter phone: ";
getline(cin, phone);
cout << "Enter email: ";
getline(cin, email);
addContact(head, name, phone, email);
cout << "Contact added successfully.\n";
break;
case 2:
displayContacts(head);
break;
case 3:
cout << "Enter name to search: ";
getline(cin, name);
if (Contact* c = searchContact(head, name)) {
cout << "Contact found:\n";
cout << "Name : " << c->name << "\n";
cout << "Phone: " << c->phone << "\n";
cout << "Email: " << c->email << "\n";
} else {
cout << "Contact not found.\n";
}
break;
case 4:
cout << "Enter name to update: ";
getline(cin, name);

cout << "Enter new phone: ";
getline(cin, phone);
cout << "Enter new email: ";
getline(cin, email);
if (updateContact(head, name, phone, email)) {
cout << "Contact updated successfully.\n";
} else {
cout << "Contact not found.\n";
}
break;
case 5:
cout << "Enter name to delete: ";
getline(cin, name);
if (deleteContact(head, name)) {
cout << "Contact deleted successfully.\n";
} else {
cout << "Contact not found.\n";
}
break;
case 6:
cout << "Exiting program.\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
}
} while (choice != 6);
return 0;

}