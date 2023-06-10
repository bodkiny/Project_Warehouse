#ifndef PROJECT_WAREHOUSE_INMEMORYPRODUCTREPOSITORY_H
#define PROJECT_WAREHOUSE_INMEMORYPRODUCTREPOSITORY_H

#include "../interfaces/IProductRepository.h"

class InMemoryProductRepository : public IProductRepository {
public:
    ~InMemoryProductRepository() override = default;
};


#endif
