#ifndef PROJECT_WAREHOUSE_IUI_H
#define PROJECT_WAREHOUSE_IUI_H

#include <map>
#include <string>
#include <optional>
#include "../main_components/Product.h"
#include "../main_components/Order.h"

class IUI {
public:
    virtual void displayMenu() = 0;
    virtual void displayProducts(std::map<std::string, Product>& products) = 0;
    virtual void displayOrders(const std::map<std::string, Order>& orders) = 0;
    virtual void displayExactOrder(const std::optional<Order>& orderOpt) = 0;
    virtual void displayMessage(const std::string& message) = 0;
    virtual std::string getInput() = 0;

    virtual ~IUI() = default;
};


#endif
