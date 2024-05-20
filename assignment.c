#include <stdio.h>

// Structure to store product information
struct Product {
    char name[50];
    float price;
};

int main() {
    struct Product products[100];
    int count = 0;
    
    // Adding product information
    printf("product details:\n");
    while(count < 100)
    {
        printf(" product name: ");
        scanf(" %s", products[count].name); // prevent buffer overflow
        printf(" product price: ");
        scanf(" %f", &products[count].price);
        count++;
        char choice;
        printf("Another product? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
    
    // Calculating subtotal
    float totalAmount ;
    for (int i = 0; i < count; i++) {
        totalAmount += products[i].price;
    }

    float taxRate = 0.07;
    float taxAmount = totalAmount * taxRate;
    float grandTotal = totalAmount + taxAmount;

    // Cash payment process
    float cashPayment;
    printf("cash amount:");
    scanf("%f", &cashPayment);
    
    // Calculating change to be returned
    float change = cashPayment - grandTotal; // use grandTotal instead of totalAmount
    printf(" returned: %.2f\n", change);
    
    // Generating receipt
    printf("\n--- Receipt ---\n");
    for (int i = 0; i < count; i++) {
        printf("Product: %s\n", products[i].name);
        printf("Price: $%.2f\n", products[i].price);
    }
    printf("Subtotal: $%.2f\n", totalAmount);
    printf("Tax: $%.2f\n", taxAmount);
    printf("Grand Total: $%.2f\n", grandTotal);
    
    return 0;
}
