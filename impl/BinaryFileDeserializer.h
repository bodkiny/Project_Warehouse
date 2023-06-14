#ifndef PROJECT_WAREHOUSE_BINARYFILEDESERIALIZER_H
#define PROJECT_WAREHOUSE_BINARYFILEDESERIALIZER_H


#include <filesystem>
#include <fstream>
#include "../interfaces/IDeserializer.h"

class BinaryFileDeserializer : public IDeserializer{
public:
    void deserialize(Warehouse& warehouse) override {

        std::ifstream inputFile("../files/bin/warehouse_state.bin", std::ios::binary | std::ios::in);
        if (!inputFile.is_open()) {
            //throw std::runtime_error("Failed to open file: ../files/bin/warehouse_state.bin");
            return;
        }

        size_t productCount;
        size_t orderCount;

        inputFile.read(reinterpret_cast<char*>(&productCount), sizeof(productCount));
        inputFile.read(reinterpret_cast<char*>(&orderCount), sizeof(orderCount));

        for (size_t i = 0; i < productCount; ++i) {
            Product product = loadProductFromFile(inputFile);
            warehouse.addProductToStock(product);
        }

        for (size_t i = 0; i < orderCount; ++i) {
            Order order = loadOrderFromFile(inputFile);
            warehouse.addOrder(order);
        }

        std::vector<std::string> processedOrderIds = deserializeCsvSalesReportGenerator(inputFile);
        warehouse.addProcessedOrderIds(processedOrderIds);

        Order::setOrderCounter(orderCount);

        inputFile.close();
    }

private:
    std::vector<std::string> deserializeCsvSalesReportGenerator(std::ifstream& inputFile)
    {
        std::vector<std::string> processedOrderIds;

        // Restoring the storage of processed orders
        size_t processedOrderIdsSize;
        inputFile.read(reinterpret_cast<char*>(&processedOrderIdsSize), sizeof(processedOrderIdsSize));
        for (size_t i = 0; i < processedOrderIdsSize; ++i) {
            size_t orderIdSize;
            inputFile.read(reinterpret_cast<char*>(&orderIdSize), sizeof(orderIdSize));
            std::string orderId(orderIdSize, ' ');
            inputFile.read(&orderId[0], orderIdSize);
            processedOrderIds.push_back(orderId);
        }

        return processedOrderIds;
    }

    Product loadProductFromFile(std::ifstream& inputFile) const {
        Product product;
        product.setProductId(loadStringFromFile(inputFile));
        product.setName(loadStringFromFile(inputFile));
        double productPrice;
        inputFile.read(reinterpret_cast<char*>(&productPrice), sizeof(double));
        int productQuantity;
        inputFile.read(reinterpret_cast<char*>(&productQuantity), sizeof(int));

        product.setPrice(productPrice);
        product.setQuantity(productQuantity);

        return product;
    }

    Order loadOrderFromFile(std::ifstream& inputFile) {
        Order order;
        order.setOrderId(loadStringFromFile(inputFile));
        order.setCustomerName(loadStringFromFile(inputFile));
        order.setOrderDate(loadTimePointFromFile(inputFile));

        size_t productCount;
        inputFile.read(reinterpret_cast<char*>(&productCount), sizeof(productCount));

        std::vector<Product> products;
        for (size_t i = 0; i < productCount; ++i) {
            Product product = loadProductFromFile(inputFile);
            products.push_back(product);
        }

        order.setProducts(products);

        return order;
    }

    std::string loadStringFromFile(std::ifstream& inputFile) const
    {
        std::string str;
        std::size_t size;
        inputFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        str.resize(size);
        inputFile.read(reinterpret_cast<char*>(&str[0]), size);
        return str;
    }

    std::chrono::system_clock::time_point loadTimePointFromFile(std::ifstream& inputFile) const {
        std::time_t time;
        inputFile.read(reinterpret_cast<char*>(&time), sizeof(time));
        return std::chrono::system_clock::from_time_t(time);
    }
};


#endif
