#ifndef PROJECT_WAREHOUSE_INMEMORYPRODUCTREPOSITORY_H
#define PROJECT_WAREHOUSE_INMEMORYPRODUCTREPOSITORY_H

#include <map>
#include "../interfaces/IProductRepository.h"

class InMemoryProductRepository : public IProductRepository {
private:
    std::map<std::string, Product> products;

public:
    void addProduct(const Product &product) override {
        products[product.getProductId()] = product;
    }

    void removeProduct(const std::string &productId) override {
        products.erase(productId);
    }

    std::optional<Product> getProduct(const std::string &productId) override {
        auto it = products.find(productId);
        if (it != products.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    std::map<std::string, Product>& getAllProducts() override {
        return products;
    }

    void addAllProducts(const std::map<std::string, Product> &products) override {
        this->products = products;
    }

    ~InMemoryProductRepository() override = default;
};


#endif
