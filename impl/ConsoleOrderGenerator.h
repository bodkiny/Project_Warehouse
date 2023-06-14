#ifndef PROJECT_WAREHOUSE_CONSOLEORDERGENERATOR_H
#define PROJECT_WAREHOUSE_CONSOLEORDERGENERATOR_H

#include "../interfaces/IOrderGenerator.h"

class ConsoleOrderGenerator : public IOrderGenerator{
public:
    Order generateOrder(std::map<std::string, Product>& productsInStock) override {
        std::string customerName;

        std::cout << "=== Creating an order ===\n";
        std::cout << "Enter customer name: ";
        std::getline(std::cin, customerName);

        std::vector<Product> orderedProducts;
        orderGeneratorHelper(productsInStock, orderedProducts);

        return Order(orderedProducts, customerName);
    }



private:
    void orderGeneratorHelper(std::map<std::string, Product> &productsInStock,
                              std::vector<Product> &orderedProducts) {
        char continueAdding;

        do {
            system("cls");
            std::cout << "=== Adding products to the order ===\n";
            std::cout << "\nAvailable products in stock:" << std::endl;
            displayAvailableProducts(productsInStock);

            std::string productId;
            int quantity;

            std::cout << "Enter the product ID to add to your order: ";
            std::cin >> productId;
            std::cout << "Enter product quantity: ";
            std::cin >> quantity;

            auto productIt = productsInStock.find(productId);
            if (productIt != productsInStock.end()) {
                Product& product = productIt->second;

                if (quantity <= product.getQuantity()) {
                    product.decreaseQuantity(quantity);
                    orderedProducts.emplace_back(product.getProductId(), product.getName(), product.getPrice(), quantity);
                } else {
                    std::cout << "Not enough products in stock!" << std::endl;
                }
            } else {
                std::cout << "Product with the specified ID was not found!" << std::endl;
            }

            std::cout << "\nWould you like to add more items to your order? (y/n): ";
            std::cin >> continueAdding;
        } while (continueAdding == 'y' || continueAdding == 'Y');
    }

    void displayAvailableProducts(const std::map<std::string, Product>& products) {
        for (const auto& pair : products) {
            const Product& product = pair.second;
            std::cout << "ID: " << product.getProductId() << ", Name: " << product.getName()
                      << ", Price: " << product.getPrice() << ", Available quantity: " << product.getQuantity() << std::endl;
        }
    }
};


#endif