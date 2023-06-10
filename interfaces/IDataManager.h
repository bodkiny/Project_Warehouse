#ifndef PROJECT_WAREHOUSE_IDATAMANAGER_H
#define PROJECT_WAREHOUSE_IDATAMANAGER_H

#include <string>
#include <vector>
#include "../main_components/Product.h"
#include "../main_components/Order.h"
#include "../main_components/SalesReport.h"

class IDataManager {
public:
    virtual std::vector<Product> getProducts() = 0;
    virtual void saveProducts(const std::vector<Product>& products) = 0;

    virtual std::vector<Order> getOrders() = 0;
    virtual void saveOrders(const std::vector<Order>& orders) = 0;

    virtual std::vector<SalesReport> getSalesReports() = 0;
    virtual void saveSalesReports(const std::vector<SalesReport>& reports) = 0;

    virtual ~IDataManager() = default;
};


#endif
