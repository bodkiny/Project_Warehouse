#ifndef PROJECT_WAREHOUSE_IPRODUCTREPOSITORY_H
#define PROJECT_WAREHOUSE_IPRODUCTREPOSITORY_H

#include <string>
#include <optional>
#include <map>
#include "../main_components/Product.h"

class IProductRepository {
public:
    virtual void addProduct(const Product& product) = 0;
    virtual void removeProduct(const std::string& productId) = 0;
    virtual std::optional<Product> getProduct(const std::string& productId) = 0;
    virtual std::map<std::string, Product>& getAllProducts() = 0;

    virtual ~IProductRepository() = default;
};


#endif
