#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

struct Product{
    char name[50];
    float price;
    int id;
};

struct Order{
    char address[100];
    int product_id;
};

Product products[MAX_PRODUCTS];
Order orders[MAX_ORDERS];
int products_count = 0;
int orders_count = 0;

void addProduct(char name[], float price, int id) {
    if (products_count < MAX_PRODUCTS) {
        strcpy(products[products_count].name, name);
        products[products_count].price = price;
        products[products_count].id = id;
        products_count++;

        for (int i = 0; i < orders_count; i++) {
            if (orders[i].product_id == id) {
                printf("Client %s ordered %s\n", orders[i].address, name);
                for (int j = i; j < orders_count - 1; j++) {
                    orders[j] = orders[j + 1];
                }
                orders_count--;
            }
        }
    } else {
        printf("Error: Maximum number of products reached!\n");
    }
}

void processOrder(char address[], int product_id) {
    int found = 0;
    for (int i = 0; i < products_count; i++) {
        if (products[i].id == product_id) {
            printf("Client %s ordered %s\n", address, products[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        strcpy(orders[orders_count].address, address);
        orders[orders_count].product_id = product_id;
        orders_count++;
    }
}

int zad2() {
    char command[10];
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0) {
            break;
        }

        if (strcmp(command, "Product") == 0) {
            char name[50];
            float price;
            int id;
            scanf("%s", name);
            scanf("%f", &price);
            scanf("%d", &id);
            addProduct(name, price, id);
        } else if (strcmp(command, "Order") == 0) {
            char address[100];
            int product_id;
            scanf("%s", address);
            scanf("%d", &product_id);
            processOrder(address, product_id);
        }
    }

    return 0;
}
