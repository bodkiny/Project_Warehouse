#ifndef PROJECT_WAREHOUSE_IORDERREPOSITORY_H
#define PROJECT_WAREHOUSE_IORDERREPOSITORY_H

#include <optional>
#include <string>
#include <map>
#include "../main_components/Order.h"

class IOrderRepository {
public:
    virtual void addOrder(const Order& order) = 0;
    virtual void addAllOrders(const std::map<std::string, Order>& orders) = 0;
    virtual void removeOrder(const std::string& orderId) = 0;
    virtual std::optional<Order> getOrder(const std::string& orderId) = 0;
    virtual std::map<std::string, Order>& getAllOrders() = 0;

    virtual ~IOrderRepository() = default;
};


#endif
