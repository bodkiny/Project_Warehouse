#ifndef PROJECT_WAREHOUSE_WAREHOUSE_H
#define PROJECT_WAREHOUSE_WAREHOUSE_H

#include <string>
#include <map>
#include <limits>
#include "Product.h"
#include "Order.h"
#include "../interfaces/IProductRepository.h"
#include "../interfaces/IOrderRepository.h"
#include "../interfaces/IUI.h"
#include "../interfaces/IProductGenerator.h"
#include "../interfaces/IOrderGenerator.h"

class Warehouse {
private:
    IProductRepository& productRepository;
    IOrderRepository& orderRepository;
    IUI& ui;
    IProductGenerator& productGenerator;
    IOrderGenerator& orderGenerator;

public:
    Warehouse(IProductRepository &productRepository, IOrderRepository &orderRepository, IUI &ui,
              IProductGenerator& productGenerator, IOrderGenerator& orderGenerator)
    : productRepository(productRepository), orderRepository(orderRepository), ui(ui),
    productGenerator(productGenerator), orderGenerator(orderGenerator)
    {}

    void addProductToStock(const Product& product) {
        productRepository.addProduct(product);
    }
    void removeProductFromStock() {
        std::cout << "=== Removing product ===\n";
        std::map<std::string, Product>& allProducts = productRepository.getAllProducts();

        std::cout << "Specify the product ID to remove: ";
        std::string productIdToRemove = ui.getInput();

        //Check if there is a product with the specified ID
        auto productIt = allProducts.find(productIdToRemove);
        if (productIt == allProducts.end()) {
            std::cout << "Product with ID " << productIdToRemove << " not found.\n" << std::endl;
            return;
        }

        std::cout << "\nAre you sure you want to delete the product with the ID " << productIdToRemove << "? (y/n): ";
        std::string choice = ui.getInput();

        if (choice == "y") {
            productRepository.removeProduct(productIdToRemove);
            std::cout << "\nProduct with ID " << productIdToRemove << " successfully deleted.\n" << std::endl;
        } else {
            std::cout << "\nProduct deletion has been canceled.\n" << std::endl;
        }
    }
    std::optional<Product> getProduct(const std::string& productId) const {
        return productRepository.getProduct(productId);
    }
    std::map<std::string, Product>& getAllProductsInStock() const {
        return productRepository.getAllProducts();
    }

    void addOrder(const Order& order) {
        orderRepository.addOrder(order);
    }

    void removeOrder() {
        std::cout << "=== Removing order ===\n";
        std::map<std::string, Order>& allOrders = orderRepository.getAllOrders();

        std::cout << "Specify the order ID to remove: ";
        std::string orderIdToRemove = ui.getInput();

        // Check if there is an order with the specified ID
        auto orderIt = allOrders.find(orderIdToRemove);
        if (orderIt == allOrders.end()) {
            std::cout << "Order with ID " << orderIdToRemove << " not found.\n" << std::endl;
            return;
        }

        std::cout << "\nAre you sure you want to delete the order with the ID " << orderIdToRemove << "? (y/n): ";
        std::string choice = ui.getInput();

        if (choice == "y") {
            orderRepository.removeOrder(orderIdToRemove);
            std::cout << "\nOrder with ID " << orderIdToRemove << " successfully deleted.\n" << std::endl;
        } else {
            std::cout << "\nThe deletion of the order has been cancelled.\n" << std::endl;
        }
    }
    std::optional<Order> getOrder(const std::string& orderId) const {
        return orderRepository.getOrder(orderId);
    }
    std::map<std::string, Order>& getAllOrders() const {
        return orderRepository.getAllOrders();
    }

    Product generateProduct() const {
        return productGenerator.generateProduct();
    }

    Order generateOrder(std::map<std::string, Product>& productsInStock){
        return orderGenerator.generateOrder(productsInStock);
    }

    void processUserInput(){
        bool exit = false;

        while (!exit) {
            system("cls");
            // Menu display
            ui.displayMenu();

            // Getting user input
            std::string userInput = ui.getInput();

            // Processing user input
            switch (userInput[0]) {
                case '1': {
                    // Display product list
                    std::map<std::string, Product> products = getAllProductsInStock();
                    system("cls");
                    ui.displayProducts(products);
                    std::cout << "\n";
                    system("pause");
                    break;
                }
                case '2': {
                    // Display orders list
                    std::map<std::string, Order> orders = getAllOrders();
                    system("cls");
                    ui.displayOrders(orders);
                    std::cout << "\n";
                    system("pause");
                    break;
                }
                case '3': {
                    // Display the exact order
                    system("cls");
                    std::cout << "Specify the order ID: ";
                    std::string input = ui.getInput();
                    system("cls");
                    std::optional<Order> order = getOrder(input);
                    ui.displayExactOrder(order);
                    system("pause");
                    break;
                }
                case '4': {
                    system("cls");
                    Product createdProduct = generateProduct();
                    addProductToStock(createdProduct);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                case '5': {
                    system("cls");
                    removeProductFromStock();
                    system("pause");
                    break;
                }
                case '6': {
                    system("cls");
                    Order createdOrder = generateOrder(getAllProductsInStock());
                    addOrder(createdOrder);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                case '7': {
                    system("cls");
                    removeOrder();
                    system("pause");
                    break;
                }
                case '8': {
                    // TODO Genarating a sales report
                    // generateSalesReport();
                    break;
                }
                case '9': {
                    // Exit
                    exit = true;
                    break;
                }
                default: {
                    // Invalid input
                    system("cls");
                    ui.displayMessage("Invalid input. Try again.");
                    std::cout << "\n";
                    system("pause");
                    break;
                }
            }
        }
    }
};


#endif
