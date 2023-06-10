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
    std::string orderId;
    std::vector<Product> products;
    std::string customerName;
    std::chrono::system_clock::time_point orderDate;

    std::chrono::system_clock::time_point getCurrentDateTime() const {
        return std::chrono::system_clock::now();
    }

public:
    Order(const std::string &orderId, const std::vector<Product> &products, const std::string &customerName) : orderId(
            orderId), products(products), customerName(customerName), orderDate(getCurrentDateTime())
            {}

    Order() = default;

    const std::string &getOrderId() const { return orderId; }

    const std::vector<Product> &getProducts() const { return products; }

    const std::string &getCustomerName() const { return customerName; }

    const std::chrono::system_clock::time_point& getOrderDate() const { return orderDate; }

    void showProducts(){
        for (const auto &item: products){
            std::cout << item << std::endl;
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
};


#endif
