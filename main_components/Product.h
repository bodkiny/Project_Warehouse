#ifndef PROJECT_WAREHOUSE_PRODUCT_H
#define PROJECT_WAREHOUSE_PRODUCT_H


#include <string>
#include <iostream>
#include <sstream>

class Product {
private:
    std::string productId;
    std::string name;
    double price;
    int quantity;

public:
    Product(const std::string &productId, const std::string &name, double price, int quantity)
    : productId(productId), name(name), price(price), quantity(quantity)
    {}

    Product() = default;

    const std::string &getProductId() const { return productId; }
    void setProductId(const std::string &productId) { Product::productId = productId; }

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { Product::name = name; }

    double getPrice() const { return price; }
    void setPrice(double price) { Product::price = price; }

    int getQuantity() const { return quantity; }
    void setQuantity(int quantity) { Product::quantity = quantity; }

    friend std::ostream& operator<<(std::ostream &os, const Product &p){
        os << "Product id: " << p.productId << std::endl;
        os << "Product name: " << p.name << std::endl;
        os << "Price id: " << p.price << std::endl;
        os << "Quantity: " << p.quantity << std::endl;

        return os;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "Product ID: " << productId << "\n"
            << "Name: " << name << "\n"
            << "Price: " << price << "\n"
            << "Quantity: " << quantity << "\n";
        return oss.str();
    }

    const void decreaseQuantity(int decreaseValue){
        quantity -= decreaseValue;
    }
};


#endif