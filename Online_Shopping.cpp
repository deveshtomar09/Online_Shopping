#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A struct to represent a product
struct Product {
    int id;
    string name;
    double price;
};

// A struct to represent a shopping cart
struct Cart {
    vector<Product> items;
    double totalPrice;
};

// A function to display a list of products
void displayProducts(vector<Product>& products) {
    cout << "==========================" << endl;
    cout << "      PRODUCT LIST        " << endl;
    cout << "==========================" << endl;

    for (int i = 0; i < products.size(); i++) {
        cout << products[i].id << " - " << products[i].name << " - $" << products[i].price << endl;
    }
}

// A function to add a product to the cart
void addToCart(Cart& cart, Product& product) {
    cart.items.push_back(product);
    cart.totalPrice += product.price;
}

// A function to display the shopping cart
void displayCart(Cart& cart) {
    cout << "==========================" << endl;
    cout << "         SHOPPING CART     " << endl;
    cout << "==========================" << endl;

    for (int i = 0; i < cart.items.size(); i++) {
        cout << cart.items[i].name << " - $" << cart.items[i].price << endl;
    }

    cout << "--------------------------" << endl;
    cout << "TOTAL: $" << cart.totalPrice << endl;
}

// The main function
int main() {
    // Create some sample products
    vector<Product> products = {
        { 1, "Product A", 10.99 },
        { 2, "Product B", 15.99 },
        { 3, "Product C", 7.99 }
    };

    // Create an empty shopping cart
    Cart cart = { {}, 0 };

    // Display the product list
    displayProducts(products);

    // Prompt the user to select a product
    int selection;
    cout << "Enter a product ID to add to your cart (or 0 to checkout): ";
    cin >> selection;

    while (selection != 0) {
        // Check if the selection is valid
        if (selection < 1 || selection > products.size()) {
            cout << "Invalid selection. Please try again." << endl;
        } else {
            // Add the selected product to the cart
            Product product = products[selection - 1];
            addToCart(cart, product);
            cout << product.name << " added to your cart." << endl;
        }

        // Display the updated cart and prompt the user for another selection
        displayCart(cart);
        cout << "Enter a product ID to add to your cart (or 0 to checkout): ";
        cin >> selection;
    }

    // Display the final cart and checkout message
    displayCart(cart);
    cout << "Thank you for shopping with us!" << endl;

    return 0;
}

