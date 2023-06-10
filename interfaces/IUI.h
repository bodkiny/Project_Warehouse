#ifndef PROJECT_WAREHOUSE_IUI_H
#define PROJECT_WAREHOUSE_IUI_H

#include <vector>
#include <string>
#include "../main_components/Product.h"
#include "../main_components/Order.h"

class IUI {
public:
    virtual void displayMenu() = 0;
    virtual void displayProducts(const std::vector<Product>& products) = 0;
    virtual void displayOrders(const std::vector<Order>& orders) = 0;
    virtual void displayMessage(const std::string& message) = 0;
    virtual std::string getInput() = 0;

    virtual ~IUI() = default;
};


#endif
