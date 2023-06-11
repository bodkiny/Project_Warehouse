#ifndef PROJECT_WAREHOUSE_IORDERGENERATOR_H
#define PROJECT_WAREHOUSE_IORDERGENERATOR_H

#include <map>
#include "../main_components/Order.h"

class IOrderGenerator {
public:
    virtual Order generateOrder(std::map<std::string, Product>& products) = 0;

    virtual ~IOrderGenerator() = default;
};


#endif
