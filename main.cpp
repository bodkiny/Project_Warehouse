#include "main_components/Warehouse.h"
#include "impl/InMemoryProductRepository.h"
#include "impl/InMemoryOrderRepository.h"
#include "impl/CommandLineUI.h"
#include "impl/ConsoleProductGenerator.h"
#include "impl/ConsoleOrderGenerator.h"
#include "impl/BinaryFileSerializer.h"
#include "impl/BinaryFileDeserializer.h"
#include "impl/CsvSalesReportGenerator.h"

int main() {

    InMemoryProductRepository productRepository;
    InMemoryOrderRepository orderRepository;
    CommandLineUI ui;
    ConsoleProductGenerator consoleProductGenerator;
    ConsoleOrderGenerator consoleOrderGenerator;
    BinaryFileSerializer fileSerializer;
    BinaryFileDeserializer fileDeserializer;
    CsvSalesReportGenerator reportGenerator;


    Warehouse warehouse(
            productRepository,
            orderRepository,
            ui,
            consoleProductGenerator,
            consoleOrderGenerator,
            fileSerializer,
            reportGenerator);

    fileDeserializer.deserialize(warehouse);
    warehouse.processUserInput();
    warehouse.serialize(warehouse);

    return 0;
}
