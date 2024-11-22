#include "pch.h"
#include "../PPOISlab3/Warehouse.h"


// Проверяем наследование от Component для Warehouse
TEST(WarehouseTest, InheritFromComponent) {
    Warehouse warehouse(1, "Main Warehouse");

    EXPECT_EQ(warehouse.getID(), 1);                       // Проверяем ID
    EXPECT_EQ(warehouse.getName(), "Main Warehouse");      // Проверяем имя

    warehouse.setName("New Warehouse");
    warehouse.changeID(2);

    EXPECT_EQ(warehouse.getID(), 2);                       // Проверяем новый ID
    EXPECT_EQ(warehouse.getName(), "New Warehouse");       // Проверяем новое имя
}

// Тесты для StorageArea
TEST(WarehouseTest, AddStorageAreaAndRetrieve) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    StorageArea storageArea2(2, "Area 2");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addStorageArea(&storageArea2);

    EXPECT_EQ(warehouse.getStorageArea(1), &storageArea1);
    EXPECT_EQ(warehouse.getStorageArea(2), &storageArea2);
}

TEST(WarehouseTest, AddAndRemoveProductFromStorageArea) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");

    storageArea1.addPoduct(&product1);
    storageArea1.addPoduct(&product2);

    // Проверка, что продукты добавлены
    EXPECT_EQ(storageArea1.getProducts().size(), 2);

    storageArea1.removeProduct(1);

    // Проверка, что продукт удалён
    EXPECT_EQ(storageArea1.getProducts().size(), 1);
    EXPECT_EQ(storageArea1.getProducts()[0]->getID(), 2);  // Ожидаем, что остался только product2
}

TEST(WarehouseTest, IsStorageAvailable) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1", 1);  // Максимум 1 продукт в этом хранилище
    Product product1(1, "Product 1");

    storageArea1.addPoduct(&product1);

    // Проверяем, что хранилище занято
    EXPECT_FALSE(storageArea1.isAvailable());

    StorageArea storageArea2(2, "Area 2", 2);
    // Проверяем, что новое хранилище доступно
    EXPECT_TRUE(storageArea2.isAvailable());
}

// Проверка информации о складе
TEST(WarehouseTest, ShowAvailableStorages) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    StorageArea storageArea2(2, "Area 2");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addStorageArea(&storageArea2);

    testing::internal::CaptureStdout();
    warehouse.showAvailableStorages();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"), std::string::npos);  // Проверяем, что "Area 1" есть в выводе
    EXPECT_NE(output.find("2"), std::string::npos);  // Проверяем, что "Area 2" есть в выводе
}

// Проверка информации о складе
TEST(WarehouseTest, WarehouseInfo) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    Worker worker1(1, "John", "Doe", "Smith");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addWorker(&worker1);

    testing::internal::CaptureStdout();
    warehouse.warehouseInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Main Warehouse"), std::string::npos);  // Проверяем, что название склада есть в выводе
    EXPECT_NE(output.find("1"), std::string::npos);
}
