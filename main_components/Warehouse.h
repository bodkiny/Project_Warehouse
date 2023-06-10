#ifndef PROJECT_WAREHOUSE_WAREHOUSE_H
#define PROJECT_WAREHOUSE_WAREHOUSE_H

#include <string>
#include <map>
#include "Product.h"
#include "Order.h"
#include "../interfaces/IProductRepository.h"
#include "../interfaces/IOrderRepository.h"

class Warehouse {
private:
    IProductRepository& productRepository;
    IOrderRepository& orderRepository;

public:
    Warehouse(IProductRepository &productRepository, IOrderRepository &orderRepository)
    : productRepository(productRepository), orderRepository(orderRepository)
    {}

    void addProduct(const Product& product) {
        productRepository.addProduct(product);
    }
    void removeProduct(const std::string& productId) {
        productRepository.removeProduct(productId);
    }
    std::optional<Product> getProduct(const std::string& productId) const {
        return productRepository.getProduct(productId);
    }
    std::map<std::string, Product>& getAllProducts() const {
        return productRepository.getAllProducts();
    }

    void addOrder(const Order& order) {
        orderRepository.addOrder(order);
    }
    void removeOrder(const std::string& orderId) {
        orderRepository.removeOrder(orderId);
    }
    std::optional<Order> getOrder(const std::string& orderId) const {
        return orderRepository.getOrder(orderId);
    }
    std::map<std::string, Order>& getAllOrders() const {
        return orderRepository.getAllOrders();
    }
};


#endif
