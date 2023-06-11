#ifndef PROJECT_WAREHOUSE_CONSOLEPRODUCTGENERATOR_H
#define PROJECT_WAREHOUSE_CONSOLEPRODUCTGENERATOR_H

#include <iostream>
#include "../interfaces/IProductGenerator.h"

class ConsoleProductGenerator : public IProductGenerator{
public:
    Product generateProduct() override {
        std::string productId;
        std::string productName;
        double price;
        int quantity;


        std::cout << "=== Adding a product ===\n";
        std::cout << "Enter the product ID: ";
        std::cin >> productId;
        std::cout << "Enter the name of the product: ";
        std::cin >> productName;
        std::cout << "Enter the price of the product: ";
        std::cin >> price;
        std::cout << "Enter the quantity of the product: ";
        std::cin >> quantity;

        return Product(productId, productName, price, quantity);
    }
};


#endif
