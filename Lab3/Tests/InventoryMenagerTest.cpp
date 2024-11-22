#include "pch.h"
#include "../PPOISlab3/InventoryManager.h"

TEST(InventoryManagerTest, ConstructorInitialization) {
    InventoryManager inventoryManager;

    // Проверяем, что хранилище изначально пусто
    EXPECT_EQ(inventoryManager.getNumberOfStorageAreas(), 0);
}

TEST(InventoryManagerTest, AddStorageArea) {
    InventoryManager inventoryManager;

    StorageArea storage1(1, "Storage 1", 100);
    StorageArea storage2(2, "Storage 2", 50);

    inventoryManager.addStorageArea(&storage1);
    inventoryManager.addStorageArea(&storage2);

    // Проверяем, что склады добавлены
    EXPECT_EQ(inventoryManager.getNumberOfStorageAreas(), 2);
}

TEST(InventoryManagerTest, UpdateProductList) {
    InventoryManager inventoryManager;

    StorageArea storage1(1, "Storage 1", 100);
    StorageArea storage2(2, "Storage 2", 50);

    Product product1("Product A", 101, 1.5f);
    Product product2("Product B", 102, 2.0f);
    Product product3("Product C", 103, 1.0f);

    // Добавляем продукты в склады
    storage1.addPoduct(&product1);
    storage1.addPoduct(&product2);
    storage2.addPoduct(&product3);

    // Добавляем склады в менеджер
    inventoryManager.addStorageArea(&storage1);
    inventoryManager.addStorageArea(&storage2);

    // Обновляем список продуктов
    inventoryManager.updateProductList();

    // Перехватываем вывод info()
    testing::internal::CaptureStdout();
    inventoryManager.info();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что все продукты присутствуют в списке
    EXPECT_NE(output.find("Product A"), std::string::npos);
    EXPECT_NE(output.find("Product B"), std::string::npos);
    EXPECT_NE(output.find("Product C"), std::string::npos);
}
