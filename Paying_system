#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int units;
    float price;
    char status[10];
    float invoice_total;
} Customer;

void print_customer(Customer c) {
    printf("Name: %s\n", c.name);
    printf("Units: %d\n", c.units);
    printf("Price: %.2f\n", c.price);
    printf("Status: %s\n", c.status);
    printf("Invoice Total: $%.2f\n", c.invoice_total);
    printf("\n");
}

float generate_invoice_total(int units, float price) {
    float rand_multiplier = (float)rand() / RAND_MAX; // generate random float between 0 and 1
    return units * price * (1.0 + rand_multiplier); // multiply invoice by random multiplier between 1 and 2
}

Customer create_customer(char name[], int units, float price, char status[]) {
    Customer c;
    strcpy(c.name, name);
    c.units = units;
    c.price = price;
    strcpy(c.status, status);
    c.invoice_total = generate_invoice_total(units, price);
    return c;
}

void print_all_customers(Customer customers[], int num_customers) {
    printf("All Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        print_customer(customers[i]);
    }
}

void print_delinquent_customers(Customer customers[], int num_customers) {
    printf("Delinquent Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].status, "delinquent") == 0) {
            print_customer(customers[i]);
        }
    }
}

void print_paid_customers_greater_than(Customer customers[], int num_customers, float invoice_total) {
    printf("Paid Customers with Invoice Greater than $%.2f:\n", invoice_total);
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].status, "paid") == 0 && customers[i].invoice_total > invoice_total) {
            print_customer(customers[i]);
        }
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    int num_customers = 3;
    Customer customers[num_customers];
    
    // initialize customers
    customers[0] = create_customer("John Doe", 10, 2.50, "delinquent");
    customers[1] = create_customer("Jane Smith", 20, 1.75, "late");
    customers[2] = create_customer("Bob Johnson", 30, 1.50, "paid");
    
    // print all customers
    print_all_customers(customers, num_customers);
    
    // print delinquent customers
    print_delinquent_customers(customers, num_customers);
    
    // print paid customers with invoice greater than $50
    print_paid_customers_greater_than(customers, num_customers, 50.0);
    
    // add new customer
    num_customers++;
    Customer new_customer = create_customer("Sally Brown", 15, 2.00, "paid");
    customers[num_customers - 1] = new_customer;
    
    // print all customers again
    print_all_customers(customers, num_customers);
    
    return 0;
}