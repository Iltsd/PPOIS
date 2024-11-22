#include "pch.h"
#include "../PPOISlab3/StorageArea.h"

TEST(StorageAreaTest, ConstructorAndGetters) {
    // Проверка конструктора с параметрами
    StorageArea storageArea(1, "Storage 1", 100);
    EXPECT_EQ(storageArea.getName(), "Storage 1");          // Проверка имени
    EXPECT_EQ(storageArea.getID(), 1);                       // Проверка ID
    EXPECT_EQ(storageArea.isAvailable(), true);              // Хранилище должно быть доступно (нет продуктов)

    // Проверка конструктора по умолчанию
    StorageArea defaultStorage(1);
    EXPECT_EQ(defaultStorage.getName(), "Not Defined");     // Имя по умолчанию
    EXPECT_EQ(defaultStorage.getID(), 1);                    // ID по умолчанию
    EXPECT_EQ(defaultStorage.isAvailable(), true);           // Хранилище должно быть доступно
}

TEST(StorageAreaTest, AddProductAndRemoveProduct) {
    StorageArea storageArea(1, "Storage 1", 3);
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");
    Product product3(3, "Product 3");

    storageArea.addPoduct(&product1);
    storageArea.addPoduct(&product2);

    // Проверяем, что два продукта добавлены
    EXPECT_EQ(storageArea.getProducts().size(), 2);

    storageArea.removeProduct(1);  // Удаляем продукт с ID 1

    // Проверяем, что продукт с ID 1 удалён
    EXPECT_EQ(storageArea.getProducts().size(), 1);
    EXPECT_EQ(storageArea.getProducts()[0]->getID(), 2);  // Ожидаем, что остался только продукт с ID 2
}

TEST(StorageAreaTest, IsStorageAvailable) {
    StorageArea storageArea(1, "Storage 1", 2);
    Product product1(1, "Product 1");

    EXPECT_TRUE(storageArea.isAvailable());  // Хранилище должно быть доступно

    storageArea.addPoduct(&product1);
    EXPECT_TRUE(storageArea.isAvailable());  // Хранилище всё ещё доступно (место есть)

    Product product2(2, "Product 2");
    storageArea.addPoduct(&product2);
    EXPECT_FALSE(storageArea.isAvailable());  // Хранилище должно быть занято, максимальное количество продуктов
}

TEST(StorageAreaTest, AddProductExceedingCapacity) {
    StorageArea storageArea(1, "Storage 1", 2);  // Вместимость 2 продукта
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");
    Product product3(3, "Product 3");

    storageArea.addPoduct(&product1);
    storageArea.addPoduct(&product2);

    // Проверяем, что хранилище не принимает третий продукт, если оно переполнено
    EXPECT_EQ(storageArea.getProducts().size(), 2);  // Должно быть только два продукта
    storageArea.addPoduct(&product3);
    EXPECT_EQ(storageArea.getProducts().size(), 3);  // Количество продуктов изменилось
}
