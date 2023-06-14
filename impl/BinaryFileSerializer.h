#ifndef PROJECT_WAREHOUSE_BINARYFILESERIALIZER_H
#define PROJECT_WAREHOUSE_BINARYFILESERIALIZER_H


#include <fstream>
#include "../interfaces/ISerializer.h"
#include "CsvSalesReportGenerator.h"

class BinaryFileSerializer : public ISerializer {
public:
    void serialize(const Warehouse& warehouse) override {
        std::ofstream outputFile("../files/bin/warehouse_state.bin", std::ios::binary);
        if (!outputFile) {
            // TODO Handling file opening error
            return;
        }

        size_t productCount = warehouse.getAllProductsInStock().size();
        size_t orderCount = warehouse.getAllOrders().size();

        outputFile.write(reinterpret_cast<const char*>(&productCount), sizeof(productCount));
        outputFile.write(reinterpret_cast<const char*>(&orderCount), sizeof(orderCount));

        const std::map<std::string, Product>& products = warehouse.getAllProductsInStock();
        for (const auto& pair : products) {
            serializeProduct(pair.second, outputFile);
        }

        const std::map<std::string, Order>& orders = warehouse.getAllOrders();
        for (const auto& pair : orders) {
            serializeOrder(pair.second, outputFile);
        }

        serializeCsvSalesReportGenerator(warehouse.getReportGenerator(), outputFile);

        outputFile.close();
    }

private:
    void serializeCsvSalesReportGenerator(ISalesReportGenerator& reportGenerator, std::ofstream& outputFile) {
        size_t processedOrderIdsSize = reportGenerator.getProcessedOrderIds().size();
        outputFile.write(reinterpret_cast<const char*>(&processedOrderIdsSize), sizeof(processedOrderIdsSize));
        for (const std::string& orderId : reportGenerator.getProcessedOrderIds()) {
            size_t orderIdSize = orderId.size();
            outputFile.write(reinterpret_cast<const char*>(&orderIdSize), sizeof(orderIdSize));
            outputFile.write(orderId.c_str(), orderIdSize);
        }
    }

    void serializeOrder(const Order& order, std::ofstream& outputFile) {
        saveStringToFile(order.getOrderId(), outputFile);
        saveStringToFile(order.getCustomerName(), outputFile);
        saveTimePointToFile(order.getOrderDate(), outputFile);

        size_t productCount = order.getProducts().size();
        outputFile.write(reinterpret_cast<const char*>(&productCount), sizeof(productCount));

        for (const Product& product : order.getProducts()) {
            serializeProduct(product, outputFile);
        }
    }

    void saveTimePointToFile(const std::chrono::system_clock::time_point& timePoint, std::ofstream& outputFile) {
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
        outputFile.write(reinterpret_cast<const char*>(&time), sizeof(time));
    }

    void serializeProduct(const Product& product, std::ofstream& outputFile) {
        saveStringToFile(product.getProductId(), outputFile);
        saveStringToFile(product.getName(), outputFile);
        const double price = product.getPrice();
        outputFile.write(reinterpret_cast<const char*>(&price), sizeof(double));
        const int quantity = product.getQuantity();
        outputFile.write(reinterpret_cast<const char*>(&quantity), sizeof(int));
    }

    void saveStringToFile(const std::string& str, std::ofstream& outputFile) {
        size_t size = str.size();
        outputFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outputFile.write(str.data(), size);
    }
};


#endif
