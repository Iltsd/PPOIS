#include "pch.h"
#include "../PPOISlab3/Order.h"

TEST(OrderTest, ConstructorAndShowInfo) {
    // ������� �������� ������ Product ��� �����
    Product product("Product1", 1, 10.0f);  // ������� � ������, ID � �����
    Order order(&product, 5);  // ����� �� 5 ������ ��������

    // ������ ����� ������ showinfo()
    testing::internal::CaptureStdout();
    order.showinfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ���������, ��� ���������� � ������ ��������� ���������
    EXPECT_NE(output.find("���������� � ������:"), std::string::npos);
    EXPECT_NE(output.find("�������: Product1"), std::string::npos);
    EXPECT_NE(output.find(" x 5"), std::string::npos);
}
