#include "pch.h"
#include "../PPOISlab3/Order.h"

TEST(OrderTest, ConstructorAndShowInfo) {
    // Создаем фейковый объект Product для теста
    Product product("Product1", 1, 10.0f);  // Продукт с именем, ID и весом
    Order order(&product, 5);  // Заказ на 5 единиц продукта

    // Мокаем вывод метода showinfo()
    testing::internal::CaptureStdout();
    order.showinfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что информация о заказе выводится корректно
    EXPECT_NE(output.find("Информация о заказе:"), std::string::npos);
    EXPECT_NE(output.find("Продукт: Product1"), std::string::npos);
    EXPECT_NE(output.find(" x 5"), std::string::npos);
}
