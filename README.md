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
• Allow the admin to add a new food item with its price.
• Allow the admin to remove an existing food item.
• Allow the admin to increase, decrease, or otherwise change the price of an existing food item.
• Save the updated food menu in menu.txt and reload it when the program starts.
• Accept the customer name and assign a unique order number so customers with the same name can be
distinguished.
• Allow the customer to select an item number and enter its quantity, and add multiple items to one order.
• Display the current order with item name, quantity, and amount.
• Allow quantity changes and item removal before order confirmation.
• Allow the customer to cancel the complete order before confirmation.
• Lock the order after confirmation so it cannot be changed, removed, or cancelled.
• Calculate the subtotal and apply a 10% discount when the subtotal exceeds Rs. 1000.
• Display the final bill with order number, customer name, item details, subtotal, discount, and final payable
amount.
• Save every generated receipt in receipts.txt using append mode.
• Maintain the order number using order_number.txt so it continues across program runs.
• Support a New Customer option that clears the previous order and assigns the next order number.
• Handle invalid menu choices, item numbers, quantities, and prices.

Algorithm / Pseudocode

1. Start the program.
2. Load the saved food menu from menu.txt. If the file does not exist, use the default menu.
3. Read the current order number from order_number.txt; use 1001 for the first order if no file exists.
4. Ask the customer to enter their name and display the assigned order number.
5. Display the Main Menu: View Food Menu, Place Order, View Current Order, Generate Bill, Admin Menu, New
Customer, Exit.
6. If View Food Menu is selected, display all current food items and prices using foodCount.
7. If Place Order is selected, accept an item number and quantity and add it to the current order.
8. Show order options: Add Another Item, Change Quantity, Remove Item, Confirm Order, or Cancel Order.
9. If Confirm Order is selected, ensure the order is not empty, ask for Y/N confirmation, and lock the order after
successful confirmation.
10. If Cancel Order is selected before confirmation, set all ordered quantities to zero and return to the Main Menu.
11. If Generate Bill is selected, require a confirmed order, calculate subtotal, apply 10% discount when subtotal >
Rs. 1000, calculate final amount, display the bill, and append it to receipts.txt.
12. If Admin Menu is selected, allow View Menu, Add Food Item, Remove Food Item, Change Price, or Back. Save
every successful menu modification to menu.txt.
13. If New Customer is selected after completing the current order, clear quantities, unlock the order, increment
and save the order number, and accept the new customer name.
14. Repeat until Exit is selected.
15. Stop the program.
    
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
|
+-- Place Order -> Item + Quantity
| |
| +-- Add / Change / Remove / Cancel
| |
| +-- Confirm -> Lock Order
|
+-- View Current Order
|
+-- Generate Bill -> Subtotal
| |
| +-- Subtotal > 1000? -> 10% Discount
| |
| +-- Final Amount -> Display Bill
| -> Save receipts.txt
|
+-- Admin Menu
| +-- Add Item
| +-- Remove Item
| +-- Change Price
| +-- Save menu.txt
|
+-- New Customer -> Reset Order -> Next Order Number
|
+-- Exit
|
End

C Programming Concepts Used

1. Variables and Data Types
2. One-Dimensional and Two-Dimensional Arrays
3. Strings
4. Functions and Function Prototypes
5. Loops (for and do-while)
6. Conditional Statements
7. Switch Case
8. Operators
9. Input/Output
10. Input Validation
11. Global Variables
12. File Handling (FILE pointer, fopen, fprintf, fscanf, fclose)
13. Dynamic menu control using foodCount
14. Flag variables for order confirmation


Instructions to Compile and Execute the Program

1. Save the complete C source code as smart_canteen.c.
2. Open it in VS Code, Code::Blocks, Dev-C++, or another C environment.
3. Compile with: gcc smart_canteen.c -o smart_canteen
4. Run with: ./smart_canteen
5. Enter the customer name. The program displays a unique order number.
6. Use the Main Menu to view the menu, place/view an order, generate a bill, access Admin Menu, start a New
Customer, or exit.
7. While ordering, enter an item number and quantity. Add more items or change/remove them as required.
8. Confirm the order when final. After confirmation, it cannot be changed or cancelled.
9. Generate Bill to display the bill and save it in receipts.txt.
10. Use Admin Menu to add/remove food items or change prices. Changes are saved in menu.txt.
11. order_number.txt stores the current order number so numbering continues after restarting the program.


Expected Output
A menu-driven canteen system that displays a dynamic food menu, accepts and manages customer orders, locks
confirmed orders, produces an itemized bill containing a unique order number, customer name, quantities, prices,
item-wise amounts, subtotal, discount, and final payable amount, and saves the receipt. Admin menu changes
remain available after restarting the program.

Sample Test Case 1 - Customer Order Without Discount

Customer Name: Vanshika
Order Number: 1001
Place Order:
Item Number: 1
Quantity: 3
Add Another Item: 2
Quantity: 2
Add Another Item: 4
Quantity: 1
Current Order:
Burger 3 Rs. 360
Pizza 2 Rs. 500
French Fries 1 Rs. 90
Confirm Order: Y
Subtotal : Rs. 950.00
Discount : Rs. 0.00
Final Amount : Rs. 950.00
Sample Test Case 2 - With Discount

Example:

Subtotal : Rs. 1200.00
Discount (10%) : Rs. 120.00
Final Amount : Rs. 1080.00
Sample Test Case 3 - Admin Adds a Food Item
Admin Menu -> Add New Food Item
Food Name: Momos
Price: 150
Food item added successfully!
Updated Menu:
1. Burger Rs. 120
2. Pizza Rs. 250
3. Sandwich Rs. 100
4. French Fries Rs. 90
5. Cold Drink Rs. 60
6. Momos Rs. 150
The updated menu is saved in menu.txt and remains
available when the program is restarted.

Sample Test Case 4 - Same Customer Name

Customer 1:
Name: Vanshika
Order Number: 1001
New Customer:
Name: Vanshika
Order Number: 1002
The unique order numbers distinguish the two orders
even though the customer names are the same.

Sample Output
========================================
SMART CANTEEN BILLING SYSTEM
========================================
Enter Customer Name: Vanshika
Your Order Number is: 1001
========== MAIN MENU ==========
1. View Food Menu
2. Place Order
3. View Current Order
4. Generate Bill
5. Admin Menu
6. New Customer
7. Exit
========== FINAL BILL ==========
Order Number : 1001
Customer Name : Vanshika
----------------------------------------
Item Qty Price Amount
----------------------------------------
Burger 3 120 Rs. 360
Pizza 2 250 Rs. 500
French Fries 1 90 Rs. 90
----------------------------------------
Subtotal : Rs. 950.00
Discount : Rs. 0.00
----------------------------------------
Final Amount : Rs. 950.00
========================================
Thank you for visiting!
========================================
Receipt saved successfully!

Files Used by the Program
• menu.txt - stores the latest food names and prices. It is read when the program starts and rewritten after
successful Admin changes.
• receipts.txt - stores generated bills in append mode so previous receipts are preserved.
• order_number.txt - stores the current order number so unique numbering continues between program runs.

Conclusion

The Smart Canteen Billing System is a menu-driven C program for managing customer orders and canteen menu
data. Customers can select multiple food items, enter quantities, view and modify their current order before
confirmation, cancel an unconfirmed order, and generate an itemized bill after confirmation. Confirmed orders are
locked to prevent later modification or cancellation. Each order receives a unique order number, allowing
customers with the same name to be distinguished. The Admin Menu allows food items to be added or removed
and prices to be changed. File handling is used to preserve menu changes, generated receipts, and order numbers
across program runs. The program demonstrates arrays, strings, functions, loops, conditional statements, switch
case, input validation, operators, and file handling in a practical C application.
