#include "pch.h"
#include "../PPOISlab3/Category.h"

TEST(CategoryTest, ConstructorAndGetters) {
    Category category;

    // �������� �� ���������
    EXPECT_EQ(category.getProductCategory(), "");  // �� ��������� ��������� ������ ���� ������
}

TEST(CategoryTest, AddAndRemoveCategory) {
    Category::addCategory("Electronics");
    Category::addCategory("Clothing");
    Category* category = new Category();
    testing::internal::CaptureStdout();
    category->showAvailableCategories();  // �������� ��������� ���������
    std::string output = testing::internal::GetCapturedStdout();

    // ���������, ��� ��������� ���������
    EXPECT_NE(output.find("Electronics"), std::string::npos);
    EXPECT_NE(output.find("Clothing"), std::string::npos);

    // ������� ���� ���������
    Category::removeCategory("Clothing");

    testing::internal::CaptureStdout();
    category->showAvailableCategories();  // �������� ��������� ���������
    output = testing::internal::GetCapturedStdout();

    // ���������, ��� "Clothing" �������
    EXPECT_EQ(output.find("Clothing"), std::string::npos);
    EXPECT_NE(output.find("Electronics"), std::string::npos);  // "Electronics" ������ ��������

}

TEST(CategoryTest, SetAndGetCategory) {
    Category category;
    category.setProductCategory(0);  // ������������� ��������� �� �������
    EXPECT_EQ(category.getProductCategory(), "Electronics");  // ���� ������ 0, ��������� ������ ���� ������

    Category::addCategory("Food");
    category.setProductCategory(1);
    EXPECT_EQ(category.getProductCategory(), "Food");  // ���������, ��� ��������� ����������� ���������

    category.setProductCategory(52);
    EXPECT_EQ(category.getProductCategory(), "Food");  // ������ 1 ������� �� �������
}
