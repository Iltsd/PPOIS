#include "pch.h"
#include "../PPOISlab3/StockAdjustment.h"

TEST(StockAdjustmentTest, DeleteExpiredProducts) {
    StockAdjustment stockAdjustment;
    StorageArea storage(1, "Storage 1");
    Product product1("Product 1", 1, 10.0f);
    Product product2("Product 2", 2, 15.0f);

    // Устанавливаем даты для продуктов с помощью setDate
    product1.setDate("2023.01.01");
    product2.setDate("2024.01.01");

    storage.addPoduct(&product1);
    storage.addPoduct(&product2);

    stockAdjustment.addStorageArea(&storage);

    // Мокаем вывод
    testing::internal::CaptureStdout();
    stockAdjustment.deleteExpiredProducts();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что просроченный продукт удалён
    EXPECT_NE(output.find("Просроченный продукт удалён"), std::string::npos);
}
