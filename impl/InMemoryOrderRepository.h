#ifndef PROJECT_WAREHOUSE_INMEMORYORDERREPOSITORY_H
#define PROJECT_WAREHOUSE_INMEMORYORDERREPOSITORY_H

#include "../interfaces/IOrderRepository.h"

class InMemoryOrderRepository : public IOrderRepository{
public:
    ~InMemoryOrderRepository() override = default;
};


#endif
