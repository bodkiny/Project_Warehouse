#ifndef PROJECT_WAREHOUSE_CSVSALESREPORTGENERATOR_H
#define PROJECT_WAREHOUSE_CSVSALESREPORTGENERATOR_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "../interfaces/ISalesReportGenerator.h"

class CsvSalesReportGenerator : public ISalesReportGenerator{
private:
    std::vector<std::string> processedOrderIds;
public:

    void generateReport(const std::map<std::string, Order> &orders) override {
        std::cout << "=== Report generation ===" << std::endl;

        //Checking if any new orders were added
        if(noOrdersHaveBeenAdded(orders)){
            std::cout << "No new orders have been added!" << std::endl;
            return;
        }

        // File name generation based on the current date
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);
        std::ostringstream oss;
        oss << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S");
        std::string fileName = "../files/reports/sales_report_" + oss.str() + ".csv";

        // Opening a file for recording
        std::ofstream outputFile(fileName);
        if (!outputFile) {
            std::cerr << "Failed to open the output file." << std::endl;
            return;
        }

        // Header writing
        outputFile << "Order ID, Customer Name, Order Date, Total Price" << std::endl;

        // Writing order details
        for (const auto& orderPair : orders) {
            const Order& order = orderPair.second;

            // Checking whether the order has already been processed
            if (std::find_if(processedOrderIds.begin(), processedOrderIds.end(), [&order](const std::string& orderId) {
                return orderId == order.getOrderId();
            }) != processedOrderIds.end()) {
                continue;
            }

            // Recording order details
            outputFile << order.getOrderId() << ","
                       << order.getCustomerName() << ","
                       << order.getOrderDateStringValue() << ","
                       << calculateTotalPrice(order) << std::endl;

            // Adding an order ID to the processed orders repository
            processedOrderIds.push_back(order.getOrderId());
        }

        outputFile.close();

        std::cout << "Sales report generated successfully. File name: " << fileName << std::endl;
    }

    std::vector<std::string> getProcessedOrderIds(){
        return processedOrderIds;
    }

    void addProcessedOrderIds(const std::vector<std::string> &processedOrderIds) override {
        this->processedOrderIds = processedOrderIds;
    }

    ~CsvSalesReportGenerator() override = default;

private:
    double calculateTotalPrice(const Order& order) {
        double totalPrice = 0.0;
        for (const Product& product : order.getProducts()) {
            totalPrice += product.getPrice() * product.getQuantity();
        }
        return totalPrice;
    }

    bool noOrdersHaveBeenAdded(const std::map<std::string, Order> &orders) {
        for (const auto& orderPair : orders) {
            const std::string& orderId = orderPair.first;

            if (std::find(processedOrderIds.begin(), processedOrderIds.end(), orderId) == processedOrderIds.end()) {
                return false;
            }
        }

        return true;
    }
};


#endif
