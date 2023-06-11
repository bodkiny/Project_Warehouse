cmake_minimum_required(VERSION 3.23)
project(Project_Warehouse)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_Warehouse main.cpp interfaces/IDataManager.h interfaces/IProductRepository.h interfaces/IOrderRepository.h interfaces/ISalesReportGenerator.h interfaces/IUI.h impl/CommandLineUI.h impl/CsvSalesReportGenerator.h impl/InMemoryProductRepository.h impl/InMemoryOrderRepository.h impl/FileDataManager.h main_components/Product.h main_components/Order.h main_components/Warehouse.h main_components/SalesReport.h interfaces/ISerializer.h interfaces/IDeserializer.h impl/FileSerializer.h impl/FileDeserializer.h interfaces/IOrderGenerator.h interfaces/IProductGenerator.h impl/ConsoleProductGenerator.h impl/ConsoleOrderGenerator.h)
