#include "pch.h"
#include "../PPOISlab3/TransportUnit.h""

TEST(TransportUnitTest, ConstructorInitialization) {
    TransportUnit transport("Truck", 1, 20, 500.0);

    // Проверяем правильность инициализации
    EXPECT_EQ(transport.getName(), "Truck");
    EXPECT_EQ(transport.getID(), 1);
    EXPECT_EQ(transport.getHoldingWeight(), 0);  // По умолчанию вес равен 0
}

TEST(TransportUnitTest, PutProductIncreasesWeight) {
    TransportUnit transport("Truck", 1, 20, 500.0f);
    Product product1("Box", 10.0f, 1.5f);  // Название, ID, вес

    // Добавляем продукт в транспорт
    transport.putProduct(&product1, 10);

    // Проверяем общий вес (10 * вес продукта)
    EXPECT_FLOAT_EQ(transport.getHoldingWeight(), 10 * product1.getWeight());
}

TEST(TransportUnitTest, AddMultipleProducts) {
    TransportUnit transport("Truck", 1.0f, 20.0f, 500.0f);
    Product product1("Box", 10.0f, 1.5f);
    Product product2("Barrel", 11.0f, 5.0f);

    // Добавляем продукты
    transport.putProduct(&product1, 5);
    transport.putProduct(&product2, 2);

    // Проверяем общий вес
    float expectedWeight = (5 * product1.getWeight()) + (2 * product2.getWeight());
    EXPECT_FLOAT_EQ(transport.getHoldingWeight(), expectedWeight);
}
