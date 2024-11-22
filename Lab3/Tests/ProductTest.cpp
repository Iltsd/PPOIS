#include "pch.h"
#include "../PPOISlab3/Product.h"

TEST(ProductTest, ConstructorInitialization) {
    Product product("Sample Product", 101, 15.5f);

    // Проверяем правильность инициализации
    EXPECT_EQ(product.getName(), "Sample Product");
    EXPECT_EQ(product.getID(), 101);
    EXPECT_FLOAT_EQ(product.getWeight(), 15.5f);
}

TEST(ProductTest, DefaultDateIsEmpty) {
    Product product("Sample Product", 102, 10.0f);

    // Проверяем, что дата по умолчанию пуста
    EXPECT_EQ(product.getDate(), "");
}

TEST(ProductTest, SetAndRetrieveNameAndID) {
    Product product("Sample Product", 103, 5.0f);

    // Изменяем имя и ID через методы базового класса Component
    product.setName("Updated Product");
    product.changeID(200);

    EXPECT_EQ(product.getName(), "Updated Product");
    EXPECT_EQ(product.getID(), 200);
}

TEST(ProductTest, CategoryNotSetInitially) {
    Product product("Sample Product", 104, 12.5f);

    // Проверяем, что категория не назначена
    EXPECT_EQ(product.getDate(), "");  // Поскольку в реализации категория пока не используется
}
