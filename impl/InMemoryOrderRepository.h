#ifndef PROJECT_WAREHOUSE_INMEMORYORDERREPOSITORY_H
#define PROJECT_WAREHOUSE_INMEMORYORDERREPOSITORY_H

#include <map>
#include "../interfaces/IOrderRepository.h"

class InMemoryOrderRepository : public IOrderRepository{
private:
    std::map<std::string, Order> orders;
public:
    void addOrder(const Order &order) override {
        orders[order.getOrderId()] = order;
    }

    void removeOrder(const std::string &orderId) override {
        orders.erase(orderId);
    }

    std::optional<Order> getOrder(const std::string &orderId) override {
        auto it = orders.find(orderId);
        if (it != orders.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    std::map<std::string, Order>& getAllOrders() override {
        return orders;
    }

    void addAllOrders(const std::map<std::string, Order> &orders) override {
        this->orders = orders;
    }

    ~InMemoryOrderRepository() override = default;
};


#endif
