#include <stdio.h>
#define MAX_ITEMS 20

char food[MAX_ITEMS][30] = {
    "Burger",
    "Pizza",
    "Sandwich",
    "French Fries",
    "Cold Drink"
};

int price[MAX_ITEMS] = {120, 250, 100, 90, 60};
int quantity[MAX_ITEMS] = {0};

int foodCount = 5;
int orderConfirmed = 0;
void viewMenu();
void placeOrder();
void viewOrder();
void generateBill(char customerName[], int orderNumber);
void adminMenu();
void saveMenu();
void loadMenu();
int getOrderNumber();
void saveOrderNumber(int orderNumber);
void resetOrder();


int main()
{
    int choice;
    int orderNumber;
    char customerName[50];
    loadMenu();
    orderNumber = getOrderNumber();

    printf("\n========================================\n");
    printf("      SMART CANTEEN BILLING SYSTEM\n");
    printf("========================================\n");
    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", customerName);

    printf("Your Order Number is: %d\n", orderNumber);
    do
    {
        printf("\n========== MAIN MENU ==========\n");

        printf("1. View Food Menu\n");
        printf("2. Place Order\n");
        printf("3. View Current Order\n");
        printf("4. Generate Bill\n");
        printf("5. Admin Menu\n");
        printf("6. New Customer\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                viewMenu();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                viewOrder();
                break;
            case 4:
                generateBill(customerName, orderNumber);
                break;
            case 5:
                adminMenu();
                break;
            case 6:

                if(orderConfirmed == 1)
                {
                    resetOrder();
                    orderNumber++;
                    saveOrderNumber(orderNumber);
                    printf("\nEnter New Customer Name: ");
                    scanf(" %[^\n]", customerName);

                    printf("Your Order Number is: %d\n",
                           orderNumber);
                }
                else
                {
                    printf("\nCurrent order has not been completed yet!\n");
                    printf("Please confirm and generate the bill, ");
                    printf("or cancel the current order first.\n");
                }

                break;
            case 7:

                printf("\nThank you for visiting Smart Canteen!\n");
                break;
            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 7);


    return 0;
}

void viewMenu()
{
    int i;

    printf("\n========== FOOD MENU ==========\n");

    printf("%-5s %-20s %-10s\n",
           "No.", "Food Item", "Price");

    printf("--------------------------------------\n");


    for(i = 0; i < foodCount; i++)
    {
        printf("%-5d %-20s Rs. %d\n",
               i + 1,
               food[i],
               price[i]);
    }
    printf("--------------------------------------\n");
}
void placeOrder()
{
    int item;
    int qty;
    int choice;
    int newQuantity;
    int i;
    int found;
    char confirm;

    if(orderConfirmed == 1)
    {
        printf("\nYour order has already been confirmed!\n");
        printf("Confirmed order cannot be changed or cancelled.\n");

        return;
    }

    viewMenu();
    printf("\nEnter item number: ");
    scanf("%d", &item);

    if(item < 1 || item > foodCount)
    {
        printf("\nInvalid item number!\n");

        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);
    if(qty <= 0)
    {
        printf("\nInvalid quantity!\n");

        return;
    }
    quantity[item - 1] += qty;
    printf("\nItem added successfully!\n");
    do
    {
        viewOrder();
        printf("\n========== ORDER OPTIONS ==========\n");
        printf("1. Add Another Item\n");
        printf("2. Change Quantity\n");
        printf("3. Remove Item\n");
        printf("4. Confirm Order\n");
        printf("5. Cancel Order\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:

                viewMenu();
                printf("\nEnter item number: ");
                scanf("%d", &item);
                if(item >= 1 && item <= foodCount)
                {
                    printf("Enter quantity: ");
                    scanf("%d", &qty);
                    if(qty > 0)
                    {
                        quantity[item - 1] += qty;
                        printf("\nItem added successfully!\n");
                    }
                    else
                    {
                        printf("\nInvalid quantity!\n");
                    }
                }
                else
                {
                    printf("\nInvalid item number!\n");
                }
                break;
            case 2:
                printf("\nEnter item number: ");
                scanf("%d", &item);
                if(item >= 1 && item <= foodCount)
                {
                    if(quantity[item - 1] > 0)
                    {
                        printf("Enter new quantity: ");
                        scanf("%d", &newQuantity);
                        if(newQuantity > 0)
                        {
                            quantity[item - 1] = newQuantity;
                            printf("\nQuantity changed successfully!\n");
                        }
                        else
                        {
                            printf("\nInvalid quantity!\n");
                        }
                    }
                    else
                    {
                        printf("\nYou have not ordered this item!\n");
                    }
                }
                else
                {
                    printf("\nInvalid item number!\n");
                }
                break;
            case 3:
                printf("\nEnter item number to remove: ");
                scanf("%d", &item);
                if(item >= 1 && item <= foodCount)
                {
                    if(quantity[item - 1] > 0)
                    {
                        quantity[item - 1] = 0;

                        printf("\nItem removed successfully!\n");
                    }
                    else
                    {
                        printf("\nYou have not ordered this item!\n");
                    }
                }
                else
                {
                    printf("\nInvalid item number!\n");
                }

                break;
            case 4:
                found = 0;
                for(i = 0; i < foodCount; i++)
                {
                    if(quantity[i] > 0)
                    {
                        found = 1;

                        break;
                    }
                }
                if(found == 0)
                {
                    printf("\nYour order is empty!\n");
                    printf("Please add an item or cancel the order.\n");
                    break;
                }
                printf("\nDo you want to confirm your order? (Y/N): ");
                scanf(" %c", &confirm);
                if(confirm == 'Y' || confirm == 'y')
                {
                    orderConfirmed = 1;
                    printf("\nOrder confirmed successfully!\n");

                    printf("Order can no longer be changed ");
                    printf("or cancelled.\n");
                    return;
                }
                else
                {
                    printf("\nOrder not confirmed.\n");

                    printf("You can still change or ");
                    printf("cancel your order.\n");
                }

                break;
            case 5:

                for(i = 0; i < foodCount; i++)
                {
                    quantity[i] = 0;
                }
                printf("\nOrder cancelled successfully!\n");

                printf("Returning to Main Menu...\n");
                return;
            default:

                printf("\nInvalid choice! Please try again.\n");
        }


    } while(1);
}
void viewOrder()
{
    int i;
    int found = 0;
    printf("\n========== CURRENT ORDER ==========\n");
    printf("%-20s %-8s %-10s\n",
           "Item",
           "Qty",
           "Amount");
    printf("----------------------------------------\n");
    for(i = 0; i < foodCount; i++)
    {
        if(quantity[i] > 0)
        {
            printf("%-20s %-8d Rs. %d\n",
                   food[i],
                   quantity[i],
                   price[i] * quantity[i]);
            found = 1;
        }
    }
    if(found == 0)
    {
        printf("No items ordered yet.\n");
    }
    printf("----------------------------------------\n");
    if(orderConfirmed == 1)
    {
        printf("Status: ORDER CONFIRMED\n");
    }
    else
    {
        printf("Status: NOT CONFIRMED\n");
    }
}
void generateBill(char customerName[], int orderNumber)
{
    int i;
    float subtotal = 0;
    float discount = 0;
    float finalAmount;
    FILE *fp;
    if(orderConfirmed == 0)
    {
        printf("\nPlease confirm your order ");
        printf("before generating the bill!\n");

        return;
    }
    for(i = 0; i < foodCount; i++)
    {
        if(quantity[i] > 0)
        {
            subtotal =
                subtotal +
                (price[i] * quantity[i]);
        }
    }
    if(subtotal > 1000)
    {
        discount = subtotal * 0.10;
    }
    finalAmount = subtotal - discount;
    printf("\n========================================\n");
    printf("               FINAL BILL\n");
    printf("========================================\n");
    printf("Order Number  : %d\n",
           orderNumber);
    printf("Customer Name : %s\n",
           customerName);
    printf("----------------------------------------\n");
    printf("%-18s %-5s %-7s %-8s\n",
           "Item",
           "Qty",
           "Price",
           "Amount");
    printf("----------------------------------------\n");
    for(i = 0; i < foodCount; i++)
    {
        if(quantity[i] > 0)
        {
            printf("%-18s %-5d %-7d Rs. %d\n",
                   food[i],
                   quantity[i],
                   price[i],
                   price[i] * quantity[i]);
        }
    }
    printf("----------------------------------------\n");
    printf("Subtotal       : Rs. %.2f\n",
           subtotal);
    printf("Discount       : Rs. %.2f\n",
           discount);
    printf("----------------------------------------\n");
    printf("Final Amount   : Rs. %.2f\n",
           finalAmount);
    printf("========================================\n");
    printf("          Thank you for visiting!\n");
    printf("========================================\n");
    fp = fopen("receipts.txt", "a");
    if(fp == NULL)
    {
        printf("\nUnable to save receipt!\n");

        return;
    }
    fprintf(fp,
            "\n========================================\n");

    fprintf(fp,
            "               FINAL BILL\n");
    fprintf(fp,
            "========================================\n");
    fprintf(fp,
            "Order Number  : %d\n",
            orderNumber);
    fprintf(fp,
            "Customer Name : %s\n",
            customerName);
    fprintf(fp,
            "----------------------------------------\n");
    fprintf(fp,
            "%-18s %-5s %-7s %-8s\n",
            "Item",
            "Qty",
            "Price",
            "Amount");
    fprintf(fp,
            "----------------------------------------\n");
    for(i = 0; i < foodCount; i++)
    {
        if(quantity[i] > 0)
        {
            fprintf(fp,
                    "%-18s %-5d %-7d Rs. %d\n",
                    food[i],
                    quantity[i],
                    price[i],
                    price[i] * quantity[i]);
        }
    }
    fprintf(fp,
            "----------------------------------------\n");
    fprintf(fp,
            "Subtotal       : Rs. %.2f\n",
            subtotal);
    fprintf(fp,
            "Discount       : Rs. %.2f\n",
            discount);
    fprintf(fp,
            "----------------------------------------\n");
    fprintf(fp,
            "Final Amount   : Rs. %.2f\n",
            finalAmount);
    fprintf(fp,
            "========================================\n\n");
    fclose(fp);
    printf("\nReceipt saved successfully!\n");
}
void adminMenu()
{
    int choice;
    int item;
    int newPrice;
    int i;
    int j;
    do
    {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. View Food Menu\n");
        printf("2. Add New Food Item\n");
        printf("3. Remove Food Item\n");
        printf("4. Change Food Item Price\n");
        printf("5. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                viewMenu();
                break;
            case 2:
                if(foodCount < MAX_ITEMS)
                {
                    printf("\nEnter new food name: ");
                    scanf(" %[^\n]",
                          food[foodCount]);
                    printf("Enter price: ");
                    scanf("%d",
                          &price[foodCount]);
                    if(price[foodCount] > 0)
                    {
                        quantity[foodCount] = 0;
                        foodCount++;
                        saveMenu();
                        printf("\nFood item added successfully!\n");
                    }
                    else
                    {
                        printf("\nInvalid price!\n");
                    }
                }
                else
                {
                    printf("\nMenu is full!\n");
                }
                break;
            case 3:
                viewMenu();
                printf("\nEnter item number to remove: ");
                scanf("%d", &item);
                if(item >= 1 &&
                   item <= foodCount)
                {
                    for(i = item - 1;
                        i < foodCount - 1;
                        i++)
                    {
                        for(j = 0;
                            j < 30;
                            j++)
                        {
                            food[i][j] =
                                food[i + 1][j];
                        }
                        price[i] =
                            price[i + 1];
                        quantity[i] =
                            quantity[i + 1];
                    }
                    foodCount--;
                    saveMenu();
                    printf("\nFood item removed successfully!\n");
                }
                else
                {
                    printf("\nInvalid item number!\n");
                }
                break;
            case 4:
                viewMenu();
                printf("\nEnter item number: ");
                scanf("%d", &item);
                if(item >= 1 &&
                   item <= foodCount)
                {
                    printf("Current Price: Rs. %d\n",
                           price[item - 1]);
                    printf("Enter new price: ");

                    scanf("%d", &newPrice);
                    if(newPrice > 0)
                    {
                        price[item - 1] =
                            newPrice;
                        saveMenu();
                        printf("\nPrice changed successfully!\n");
                    }
                    else
                    {
                        printf("\nInvalid price!\n");
                    }
                }
                else
                {
                    printf("\nInvalid item number!\n");
                }
                break;
            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 5);
}
void saveMenu()
{
    FILE *fp;
    int i;
    fp = fopen("menu.txt", "w");
    if(fp == NULL)
    {
        printf("\nError saving menu!\n");
        return;
    }
    fprintf(fp, "%d\n", foodCount);
    for(i = 0; i < foodCount; i++)
    {
        fprintf(fp,
                "%s\n",
                food[i]);
        fprintf(fp,
                "%d\n",
                price[i]);
    }
    fclose(fp);
}
void loadMenu()
{
    FILE *fp;
    int i;
    fp = fopen("menu.txt", "r");
    if(fp == NULL)
    {
        return;
    }
    fscanf(fp,
           "%d\n",
           &foodCount);
    if(foodCount < 1 ||
       foodCount > MAX_ITEMS)
    {
        foodCount = 5;
        fclose(fp);
        return;
    }
    for(i = 0;
        i < foodCount;
        i++)
    {
        fscanf(fp,
               " %[^\n]",
               food[i]);
        fscanf(fp,
               "%d\n",
               &price[i]);
        quantity[i] = 0;
    }
    fclose(fp);
}
int getOrderNumber()
{
    FILE *fp;
    int orderNumber = 1001;
    fp = fopen("order_number.txt", "r");
    if(fp != NULL)
    {
        fscanf(fp,
               "%d",
               &orderNumber);
        fclose(fp);
    }
    else
    {
        saveOrderNumber(orderNumber);
    }
    return orderNumber;
}
void saveOrderNumber(int orderNumber)
{
    FILE *fp;
    fp = fopen("order_number.txt", "w");
    if(fp == NULL)
    {
        printf("\nError saving order number!\n");
        return;
    }
    fprintf(fp,
            "%d",
            orderNumber);
    fclose(fp);
}
void resetOrder()
{
    int i;
    for(i = 0;
        i < MAX_ITEMS;
        i++)
    {
        quantity[i] = 0;
    }
    orderConfirmed = 0;
}
