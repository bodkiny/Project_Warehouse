#ifndef PROJECT_WAREHOUSE_CSVSALESREPORTGENERATOR_H
#define PROJECT_WAREHOUSE_CSVSALESREPORTGENERATOR_H

#include "../interfaces/ISalesReportGenerator.h"

class CsvSalesReportGenerator : public ISalesReportGenerator{
public:
    ~CsvSalesReportGenerator() override = default;
};


#endif
