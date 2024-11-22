#include "pch.h"
#include "../PPOISlab3/TransportUnit.h""

TEST(TransportUnitTest, ConstructorInitialization) {
    TransportUnit transport("Truck", 1, 20, 500.0);

    // ��������� ������������ �������������
    EXPECT_EQ(transport.getName(), "Truck");
    EXPECT_EQ(transport.getID(), 1);
    EXPECT_EQ(transport.getHoldingWeight(), 0);  // �� ��������� ��� ����� 0
}

TEST(TransportUnitTest, PutProductIncreasesWeight) {
    TransportUnit transport("Truck", 1, 20, 500.0f);
    Product product1("Box", 10.0f, 1.5f);  // ��������, ID, ���

    // ��������� ������� � ���������
    transport.putProduct(&product1, 10);

    // ��������� ����� ��� (10 * ��� ��������)
    EXPECT_FLOAT_EQ(transport.getHoldingWeight(), 10 * product1.getWeight());
}

TEST(TransportUnitTest, AddMultipleProducts) {
    TransportUnit transport("Truck", 1.0f, 20.0f, 500.0f);
    Product product1("Box", 10.0f, 1.5f);
    Product product2("Barrel", 11.0f, 5.0f);

    // ��������� ��������
    transport.putProduct(&product1, 5);
    transport.putProduct(&product2, 2);

    // ��������� ����� ���
    float expectedWeight = (5 * product1.getWeight()) + (2 * product2.getWeight());
    EXPECT_FLOAT_EQ(transport.getHoldingWeight(), expectedWeight);
}
