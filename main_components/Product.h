#ifndef PROJECT_WAREHOUSE_PRODUCT_H
#define PROJECT_WAREHOUSE_PRODUCT_H


#include <string>

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

    const std::string &getProductId() const { return productId; }
    void setProductId(const std::string &productId) { Product::productId = productId; }

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { Product::name = name; }

    double getPrice() const { return price; }
    void setPrice(double price) { Product::price = price; }

    int getQuantity() const { return quantity; }
    void setQuantity(int quantity) { Product::quantity = quantity; }
};


#endif