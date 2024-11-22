#include "pch.h"
#include "../PPOISlab3/Category.h"

TEST(CategoryTest, ConstructorAndGetters) {
    Category category;

    // Проверка по умолчанию
    EXPECT_EQ(category.getProductCategory(), "");  // По умолчанию категория должна быть пустой
}

TEST(CategoryTest, AddAndRemoveCategory) {
    Category::addCategory("Electronics");
    Category::addCategory("Clothing");
    Category* category = new Category();
    testing::internal::CaptureStdout();
    category->showAvailableCategories();  // Печатаем доступные категории
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что категории добавлены
    EXPECT_NE(output.find("Electronics"), std::string::npos);
    EXPECT_NE(output.find("Clothing"), std::string::npos);

    // Удаляем одну категорию
    Category::removeCategory("Clothing");

    testing::internal::CaptureStdout();
    category->showAvailableCategories();  // Печатаем доступные категории
    output = testing::internal::GetCapturedStdout();

    // Проверяем, что "Clothing" удалено
    EXPECT_EQ(output.find("Clothing"), std::string::npos);
    EXPECT_NE(output.find("Electronics"), std::string::npos);  // "Electronics" должна остаться

}

TEST(CategoryTest, SetAndGetCategory) {
    Category category;
    category.setProductCategory(0);  // Устанавливаем категорию по индексу
    EXPECT_EQ(category.getProductCategory(), "Electronics");  // Если индекс 0, категория должна быть пустой

    Category::addCategory("Food");
    category.setProductCategory(1);
    EXPECT_EQ(category.getProductCategory(), "Food");  // Проверяем, что категория установлена корректно

    category.setProductCategory(52);
    EXPECT_EQ(category.getProductCategory(), "Food");  // Индекс 1 выходит за пределы
}
