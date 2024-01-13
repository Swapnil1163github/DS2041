#include <iostream>
#include <string>
#include <limits>

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

// Function to get user input for adding a product
Product getUserInputForProduct() {
    string productName;
    int quantity;

    cout << "Choose a product name from the list (Laptop, Notebook, Headphones): ";
    getline(cin, productName);

    // Other attributes are predefined based on the selected product name
    string category = "Electronics";
    int price;

    if (productName == "Laptop") {
        price = 89999;
    } else if (productName == "Notebook") {
        price = 250;
    } else if (productName == "Headphones") {
        price = 4999;
    } else {
        cout << "Invalid product name. Using default values.\n";
        price = 0;
    }

    cout << "Enter product quantity: ";
    cin >> quantity;

    // Consume the newline character left in the stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Product(productName, category, price, quantity);
}

int main() {
    // Create an instance of the Inventory class
    Inventory inventory;

    // Prompt the user to add products to the inventory
    char addMore;
    do {
        Product newProduct = getUserInputForProduct();
        inventory.addProduct(newProduct);

        cout << "Do you want to add another product? (y/n): ";
        cin >> addMore;

        // Consume the newline character left in the stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (addMore == 'y' || addMore == 'Y');

    // Display all products in the inventory
    inventory.displayAllProducts();

    // Display the total price of all inventories
    cout << "Total Price of All Inventories: RS " << inventory.calculateTotalPrice() << endl;

    return 0;
}
