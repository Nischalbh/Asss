#include <stdio.h>

// Structure to store product information
struct Product {
    char name[50];
    float price;
};

// Function to calculate total amount including taxes
float calculateTotalAmount(float subtotal) {
    float taxRate = 0.07; // 7% tax rate
    float tax = subtotal * taxRate;
    return subtotal + tax;
}

int main() {
    struct Product product;
    float subtotal = 0.0;
    
    // Adding product information
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    
    // Calculating subtotal
    subtotal += product.price;
    
    // Displaying total amount including taxes
    float totalAmount = calculateTotalAmount(subtotal);
    printf("Total amount (including taxes): $%.2f\n", totalAmount);
    
    // Cash payment process
    float cashPayment;
    printf("Enter cash amount: $");
    scanf("%f", &cashPayment);
    
    // Calculating change to be returned
    float change = cashPayment - totalAmount;
    printf("Change to be returned: $%.2f\n", change);
    
    // Generating receipt
    printf("\n--- Receipt ---\n");
    printf("Product: %s\n", product.name);
    printf("Price: $%.2f\n", product.price);
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", totalAmount - subtotal);
    printf("Grand Total: $%.2f\n", totalAmount);
    
    return 0;
}