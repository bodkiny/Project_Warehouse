#ifndef PROJECT_WAREHOUSE_COMMANDLINEUI_H
#define PROJECT_WAREHOUSE_COMMANDLINEUI_H

#include "../interfaces/IUI.h"

class CommandLineUI : public IUI{
public:
    void displayMenu() override {
        std::cout << "=== Warehouse Menu ===" << std::endl;
        std::cout << "1. Browse products" << std::endl;
        std::cout << "2. Browse orders" << std::endl;
        std::cout << "3. Browse exact order" << std::endl;//+++++++++
        std::cout << "4. Add product" << std::endl;
        std::cout << "5. Delete product" << std::endl;
        std::cout << "6. Add order" << std::endl;
        std::cout << "7. Delete order" << std::endl;
        std::cout << "8. Generate sales report" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Select the option: ";
    }

    void displayProducts(std::map<std::string, Product> &products) override {
        std::cout << "=== Products ===" << std::endl;
        if(!products.empty()) {
            for (const auto &pair: products) {
                const Product &product = pair.second;
                std::cout << "ID: " << product.getProductId() << ", Name: " << product.getName() << ", Quantity: "
                          << product.getQuantity() << std::endl;
            }
        }else{
            std::cout << "The stock is empty!" << std::endl;
        }
        std::cout << std::endl;
    }

    void displayOrders(const std::map<std::string, Order> &orders) override {
        std::cout << "=== Orders ===" << std::endl;
        if(!orders.empty()) {
            for (const auto &pair: orders) {
                const Order &order = pair.second;
                std::cout << "ID: " << order.getOrderId() << ", Customer: " << order.getCustomerName()
                          << ", Order Date: " << order.getOrderDateStringValue() << std::endl;
            }
        }else{
            std::cout << "The order list is empty!" << std::endl;
        }
        std::cout << std::endl;
    }

    void displayExactOrder(const std::optional<Order>& orderOpt) override {
        if (!orderOpt) {
            std::cout << "Order not found." << std::endl;
            return;
        }

        const Order& order = orderOpt.value();

        std::cout << "=== Order#" << order.getOrderId() << " ===" << std::endl;
        std::cout << "Client: " << order.getCustomerName() << std::endl;
        std::cout << "Order date: " << order.getOrderDateStringValue() << std::endl;
        std::cout << "\nProduct list:" << std::endl;
        order.showProducts();
    }

    void displayMessage(const std::string &message) override {
        std::cout << message << std::endl;
    }

    std::string getInput() override {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    ~CommandLineUI() override = default;
};


#endif
