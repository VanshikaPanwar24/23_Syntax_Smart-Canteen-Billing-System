# 23_Syntax_Smart-Canteen-Billing-System 


Batch: 23

Member 1: Vanshika Panwar
Member 2: Devanshi Rawal
Member 3: Tavish Mathur

Problem Statement

Develop a menu-driven Smart Canteen Billing System in C that allows customers to view a dynamic food menu,
place and manage orders, confirm an order, generate an itemized bill with a unique order number, and save
receipts using file handling. The system also provides an Admin Menu to add or remove food items and change
their prices, with menu changes saved permanently.

Objectives and Features

• Display a dynamic food menu containing food item names and prices.
• Allow the admin to add a new food item, remove an existing food item, and change item prices.
• Save the updated food menu in menu.txt and reload it when the program starts.
• Accept the customer name and assign a unique order number.
• Allow customers to select an item number, enter quantity, and add multiple items.
• Display the current order with item name, quantity, and amount.
• Allow add/change/remove/cancel operations before confirmation.
• Lock the order after confirmation so it cannot be changed or cancelled.
• Calculate subtotal and apply a 10% discount when subtotal exceeds Rs. 1000.
• Display the final bill with order number, customer name, item details, subtotal, discount, and final amount.
• Save generated receipts in receipts.txt using append mode.
• Maintain order numbering using order_number.txt.
• Support a New Customer option with a fresh order and next order number.
• Handle invalid menu choices, item numbers, quantities, and prices.

Algorithm / Pseudocode

1. Start the program.
2. Load the saved food menu from menu.txt; use the default menu if the file does not exist.
3. Read the current order number from order_number.txt.
4. Enter customer name and display the unique order number.
5. Display Main Menu: View Food Menu, Place Order, View Current Order, Generate Bill, Admin Menu, New
Customer, Exit.
6. Place Order: select item number and quantity, then allow Add Another Item, Change Quantity, Remove Item,
Confirm Order, or Cancel Order.
7. Before confirmation the order can be modified or cancelled. After confirmation it is locked.
8. Generate Bill: calculate subtotal, apply 10% discount if subtotal > Rs. 1000, calculate final amount, display the
bill, and append it to receipts.txt.
9. Admin Menu: view menu, add food item, remove food item, or change food price; save successful changes to
menu.txt.
10. New Customer: reset the previous order, increment/save the order number, and enter the new customer name.
11. Repeat until Exit is selected.
12. Stop the program.

Flowchart

Start
|
Load menu.txt and order_number.txt
|
Enter Customer Name -> Assign Order Number
|
Display Main Menu
|
+-- View Food Menu
+-- Place Order -> Item + Quantity
| +-- Add / Change / Remove / Cancel
| +-- Confirm -> Lock Order
+-- View Current Order
+-- Generate Bill -> Subtotal -> Discount -> Final Amount
| -> Save receipts.txt
+-- Admin Menu -> Add / Remove / Change Price -> Save menu.txt
+-- New Customer -> Reset -> Next Order Number
+-- Exit
|
End


C Programming Concepts Used


1. Variables and Data Types
2. One-Dimensional and Two-Dimensional Arrays
3. Strings
4. Functions and Function Prototypes
5. Loops
6. Conditional Statements
7. Switch Case
8. Operators
9. Input/Output
10. Input Validation
11. Global Variables
12. File Handling: FILE pointer, fopen(), fprintf(), fscanf(), fclose()
13. Dynamic menu control using foodCount
14. Flag variable for order confirmation
Instructions to Compile and Execute the Program
1. Save the complete source code as smart_canteen.c.
2. Compile using: gcc smart_canteen.c -o smart_canteen
3. Run using: ./smart_canteen
4. Enter the customer name and note the assigned order number.
5. Use the Main Menu to view the menu, place/view an order, generate a bill, use Admin Menu, start a New
Customer, or exit.
6. Enter item number and quantity while ordering. Modify or cancel before confirmation if required.
7. After confirmation, the order cannot be changed or cancelled.
8. Generate the bill to display it and save it in receipts.txt.
9. Admin changes are saved in menu.txt.
10. order_number.txt maintains unique order numbering across program runs.

Expected Output

A dynamic menu-driven canteen billing system that creates uniquely numbered customer orders, supports
pre-confirmation order management, locks confirmed orders, generates itemized bills, saves multiple receipts, and
permanently stores Admin menu changes.

Sample Test Case - Without Discount

Customer Name: Devanshi
Order Number: 1001
Item Number: 1
Quantity: 1
Confirm Order: Y
Burger: 1 x Rs. 120 = Rs. 120
Subtotal : Rs. 120.00
Discount : Rs. 0.00
Final Amount : Rs. 120.00
Sample Test Case - With Discount
Subtotal : Rs. 1200.00
Discount (10%) : Rs. 120.00
Final Amount : Rs. 1080.00
File Handling - receipts.txt Output
The receipt file is opened in append mode, so every generated bill is added to the file without deleting the previous
receipts. The following output demonstrates multiple receipts stored in the same file:

========================================
FINAL BILL
========================================
Customer Name : vanshika
----------------------------------------
Item Qty Price Amount
----------------------------------------
Burger 2 120 Rs. 240
----------------------------------------
Subtotal : Rs. 240.00
Discount : Rs. 0.00
----------------------------------------
Final Amount : Rs. 240.00
========================================



========================================
FINAL BILL
========================================
Order Number : 1001
Customer Name : devanshi
----------------------------------------
Item Qty Price Amount
----------------------------------------
Burger 1 120 Rs. 120
----------------------------------------
Subtotal : Rs. 120.00
Discount : Rs. 0.00
----------------------------------------
Final Amount : Rs. 120.00
========================================

Note: The first receipt above was generated before the unique order-number feature was added. Receipts
generated by the final program include the Order Number, as shown in the second receipt.

Admin Menu Example

========== ADMIN MENU ==========
1. View Food Menu
2. Add New Food Item
3. Remove Food Item
4. Change Food Item Price
5. Back to Main Menu

Example:

Add New Food Item
Food Name: Momos
Price: 150
Food item added successfully!
The updated menu is saved in menu.txt and remains
available after restarting the program.

Files Used by the Program

• menu.txt - stores the latest food names and prices.
• receipts.txt - stores all generated bills in append mode.
• order_number.txt - stores the current order number so numbering continues between program runs.


Conclusion

The Smart Canteen Billing System is a menu-driven C application that manages customer orders and canteen
menu data. Customers can select multiple items, enter quantities, modify or cancel an order before confirmation,
and generate a final bill after confirmation. Confirmed orders are locked. Each final order is identified using a
unique order number, which distinguishes customers even when their names are the same. The Admin Menu
allows food items to be added or removed and prices to be changed. File handling preserves the updated menu,
generated receipts, and order numbers across program runs. The project demonstrates arrays, strings, functions,
loops, conditional statements, switch case, operators, input/output, validation, and file handling
