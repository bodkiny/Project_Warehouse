#ifndef PROJECT_WAREHOUSE_IPRODUCTGENERATOR_H
#define PROJECT_WAREHOUSE_IPRODUCTGENERATOR_H

#include "../main_components/Product.h"

class IProductGenerator {
public:
    virtual Product generateProduct() = 0;

    virtual ~IProductGenerator() = default;
};


#endif
