#ifndef PROJECT_WAREHOUSE_ISALESREPORTGENERATOR_H
#define PROJECT_WAREHOUSE_ISALESREPORTGENERATOR_H

#include <map>
#include "../main_components/Order.h"

class ISalesReportGenerator {
public:
    virtual void generateReport(const std::map<std::string, Order>& orders) = 0;
    virtual std::vector<std::string> getProcessedOrderIds() = 0;
    virtual void addProcessedOrderIds(const std::vector<std::string>& processedOrderIds) = 0;

    virtual ~ISalesReportGenerator() = default;
};


#endif
