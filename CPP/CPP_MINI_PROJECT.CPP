#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;  // Maximum number of products in the inventory

// Product class to represent each item in inventory
class Product {
public:
    string name;
    string category;
    int price;  // Represent price in whole Rupees
    int quantity;

    // Default constructor
    Product() : name(""), category(""), price(0), quantity(0) {}

    Product(string n, string cat, int p, int q)
        : name(n), category(cat), price(p), quantity(q) {}
};

// Inventory class to manage products
class Inventory {
private:
    Product products[MAX_PRODUCTS];  // Array to store products
    int numProducts;  // Number of products currently in the inventory

public:
    // Constructor to initialize the number of products
    Inventory() : numProducts(0) {}

    // Function to add a new product to the inventory
    void addProduct(Product product) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts++] = product;
        } else {
            cout << "Error: Maximum number of products reached.\n";
        }
    }

    // Function to display product information
    void displayProductInfo(const Product& product) {
        cout << "Name: " << product.name << "\nCategory: " << product.category
             << "\nPrice: RS " << product.price << "\nQuantity: " << product.quantity << "\n\n";
    }

    // Function to display all products in the inventory
    void displayAllProducts() {
        cout << "Inventory:\n";
        for (int i = 0; i < numProducts; ++i) {
            displayProductInfo(products[i]);
        }
    }

    // Function to calculate the total price of all inventories
    int calculateTotalPrice() {
        int totalPrice = 0;
        for (int i = 0; i < numProducts; ++i) {
            totalPrice += products[i].price * products[i].quantity;
        }
        return totalPrice;
    }
};

int main() {
    // Create an instance of the Inventory class
    Inventory inventory;

    // Add some sample products to the inventory
    inventory.addProduct(Product("Laptop", "Electronics", 89999, 10));
    inventory.addProduct(Product("Notebook", "Stationery", 250, 100));
    inventory.addProduct(Product("Headphones", "Electronics", 4999, 20));

    // Display all products in the inventory
    inventory.displayAllProducts();

    // Display the total price of all inventories
    cout << "Total Price of All Inventories: RS " << inventory.calculateTotalPrice() << endl;

    return 0;
}
