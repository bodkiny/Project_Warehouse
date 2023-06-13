#ifndef PROJECT_WAREHOUSE_IDESERIALIZER_H
#define PROJECT_WAREHOUSE_IDESERIALIZER_H


#include <string>
#include "../main_components/Warehouse.h"

class IDeserializer {
public:
    virtual void deserialize(Warehouse& warehouse) = 0;

    virtual ~IDeserializer() = default;
};


#endif
