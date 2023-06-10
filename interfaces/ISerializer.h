#ifndef PROJECT_WAREHOUSE_ISERIALIZER_H
#define PROJECT_WAREHOUSE_ISERIALIZER_H


#include <string>
#include "../main_components/Warehouse.h"

class ISerializer {
public:
    virtual void serialize(const std::string& filePath, const Warehouse& warehouse) = 0;

    virtual ~ISerializer() = default;
};


#endif
