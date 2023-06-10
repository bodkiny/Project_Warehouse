#ifndef PROJECT_WAREHOUSE_WAREHOUSE_H
#define PROJECT_WAREHOUSE_WAREHOUSE_H

#include <string>
#include <map>
#include "Product.h"
#include "Order.h"

class Warehouse {
private:
    std::map<std::string, Product> products;
    std::map<std::string, Order> orders;

public:
    Warehouse(const std::map<std::string, Product> &products, const std::map<std::string, Order> &orders)
    : products(products), orders(orders)
    {}

    Warehouse() = default;

    const std::map<std::string, Product> &getProducts() const { return products; }
    void setProducts(const std::map<std::string, Product> &products) { Warehouse::products = products; }

    const std::map<std::string, Order> &getOrders() const { return orders; }
    void setOrders(const std::map<std::string, Order> &orders) { Warehouse::orders = orders; }

    void addProduct(const Product& product) { products[product.getProductId()] = product; }
    void removeProduct(const std::string& productId) { products.erase(productId); }
    const Product& getProduct(const std::string& productId) const { return products.at(productId); }

    void addOrder(const Order& order) { orders[order.getOrderId()] = order; }
    void removeOrder(const std::string& orderId) { orders.erase(orderId); }
    const Order& getOrder(const std::string& orderId) const { return orders.at(orderId); }
};


#endif
