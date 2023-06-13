#ifndef PROJECT_WAREHOUSE_ISERIALIZER_H
#define PROJECT_WAREHOUSE_ISERIALIZER_H


#include <string>
#include "../main_components/Warehouse.h"

class Warehouse;

class ISerializer {
public:
    virtual void serialize(const Warehouse& warehouse) = 0;

    virtual ~ISerializer() = default;
};


#endif
