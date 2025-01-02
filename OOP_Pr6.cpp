/*write a program for sorting and seraching
user defined records such as item records , name, cost, quantity and id
using vector container*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Item {
public:
string name;
int quantity;
int cost;
int code;
// Overload the == operator for comparison
bool operator==(const Item& i1) const {
return code == i1.code;
}
// Overload the < operator for sorting
bool operator<(const Item& i1) const {
return code < i1.code;
}
};
vector<Item> o1;
void print(const Item& i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item& i1, const Item& i2) {
return i1.cost < i2.cost;
}
int main() {
int ch;
do {
cout << "\n* * * * * Menu * * * * *";
cout << "\n1. Insert";
cout << "\n2. Display";
cout << "\n3. Search";
cout << "\n4. Sort";
cout << "\n5. Delete";
cout << "\n6. Exit";
cout << "\nEnter your choice: ";
cin >> ch;
switch (ch) {
case 1:
insert();
break;
case 2:
display();
break;
case 3:
search();
break;
case 4:
sort(o1.begin(), o1.end(), compare);
cout << "\n\nSorted on Cost:";
display();
break;
case 5:
dlt();
break;
case 6:
cout << "Exiting the program. Thank you!";
break;
default:
cout << "Invalid choice! Please try again.";
}
} while (ch != 6);
return 0;
}
void insert() {
Item i1;
cout << "\nEnter Item Name: ";
cin >> ws; // Clear input buffer
getline(cin, i1.name);
cout << "Enter Item Quantity: ";
cin >> i1.quantity;
cout << "Enter Item Cost: ";
cin >> i1.cost;
cout << "Enter Item Code: ";
cin >> i1.code;
o1.push_back(i1);
}
void display() {
if (o1.empty()) {
cout << "\nNo items to display!";
return;
}
for_each(o1.begin(), o1.end(), print);
}
void print(const Item& i1) {
cout << "\nItem Name: " << i1.name;
cout << "\nItem Quantity: " << i1.quantity;
cout << "\nItem Cost: " << i1.cost;
cout << "\nItem Code: " << i1.code;
cout << "\n";
}
void search() {
if (o1.empty()) {
cout << "\nThe list is empty!";
return;
}
int searchCode;
cout << "\nEnter Item Code to search: ";
cin >> searchCode;
auto it = find_if(o1.begin(), o1.end(), [searchCode](const Item& item) {
return item.code == searchCode;
});
if (it == o1.end()) {
cout << "\nItem not found!";
} else {
cout << "\nItem found:";
print(*it);
}
}
void dlt() {
if (o1.empty()) {
cout << "\nThe list is empty!";
return;
}
int deleteCode;
cout << "\nEnter Item Code to delete: ";
cin >> deleteCode;
auto it = find_if(o1.begin(), o1.end(), [deleteCode](const Item& item) {
return item.code == deleteCode;
});
if (it == o1.end()) {
cout << "\nItem not found!";
} else {
o1.erase(it);
cout << "\nItem deleted successfully!";
}
}
