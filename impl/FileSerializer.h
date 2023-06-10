#ifndef PROJECT_WAREHOUSE_FILESERIALIZER_H
#define PROJECT_WAREHOUSE_FILESERIALIZER_H


#include "../interfaces/ISerializer.h"

class FileSerializer : public ISerializer{
public:
    ~FileSerializer() override = default;
};


#endif
