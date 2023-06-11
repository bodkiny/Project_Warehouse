#ifndef PROJECT_WAREHOUSE_ORDER_H
#define PROJECT_WAREHOUSE_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include "Product.h"

class Order {
private:
    static int orderCounter;
    std::string orderId;
    std::vector<Product> products;
    std::string customerName;
    std::chrono::system_clock::time_point orderDate;

    std::chrono::system_clock::time_point getCurrentDateTime() const {
        return std::chrono::system_clock::now();
    }

public:
    Order(const std::vector<Product> &products, const std::string &customerName) : products(products), customerName(customerName), orderDate(getCurrentDateTime()){
                orderId = std::to_string(orderCounter);
                orderCounter++;
            }

    Order() = default;

    const std::string &getOrderId() const { return orderId; }

    const std::vector<Product> &getProducts() const { return products; }

    const std::string &getCustomerName() const { return customerName; }

    const std::chrono::system_clock::time_point& getOrderDate() const { return orderDate; }

    std::string getOrderDateStringValue() const {
        std::time_t time = std::chrono::system_clock::to_time_t(orderDate);
        std::tm* timeinfo = std::localtime(&time);

        std::ostringstream oss;
        oss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");

        return oss.str();
    }

    void showProducts() const{
        if (products.empty()) {
            std::cout << "The order contains no products." << std::endl;
        }else{
            int i = 1;
            for (const auto &item: products){
                std::cout << "Product#" << i << std::endl;
                std::cout << item << std::endl;
                i++;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "Order Information:" << std::endl;
        os << "Customer Name: " << order.getCustomerName() << std::endl;

        std::time_t orderTime = std::chrono::system_clock::to_time_t(order.getOrderDate());
        os << "Order Date: " << std::put_time(std::localtime(&orderTime), "%Y-%m-%d %H:%M:%S") << std::endl;

        os << "Products:\n";
        for (int i = 0; i < order.products.size(); ++i) {
            os << "Item#" << i + 1 << std::endl;
            os << order.products[i] << std::endl;
        }

        return os;
    }

    std::string toString() const {
        std::ostringstream oss;
        std::time_t orderTime = std::chrono::system_clock::to_time_t(orderDate);
        oss << "Order ID: " << orderId << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Order Date: " << std::put_time(std::localtime(&orderTime), "%Y-%m-%d %H:%M:%S") << "\n";

        std::cout << "Do you want to view ordered products? (press \"y\" or \"n\"): ";
        char option;
        std::cin >> option;
        if(option == 'y'){
            oss << "Products:\n";
            for (int i = 0; i < products.size(); ++i) {
                oss << "Item#" << i + 1 << std::endl;
                oss << products[i] << std::endl;
            }
        }

        return oss.str();
    }
};

int Order::orderCounter = 0;


#endif
