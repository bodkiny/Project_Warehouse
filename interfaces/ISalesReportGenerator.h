#ifndef PROJECT_WAREHOUSE_ISALESREPORTGENERATOR_H
#define PROJECT_WAREHOUSE_ISALESREPORTGENERATOR_H

#include <vector>
#include "../main_components/Order.h"

class ISalesReportGenerator {
public:
    virtual void generateReport(const std::vector<Order>& orders) = 0;

    virtual ~ISalesReportGenerator() = default;
};


#endif
