#include "pch.h"
#include "../PPOISlab3/Delivery.h"


TEST(DeliveryTest, ConstructorAndShowInfo) {
    // ������� �������� ������� ��� �����
    TransportUnit transport("Truck1", 1, 10, 2000);
    Worker worker(1, "John", "Doe", "Middle");
    Delivery delivery(&transport, "2024-12-01", &worker);

    // ������ ����� ������ ShowInfo()
    testing::internal::CaptureStdout();
    delivery.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ���������, ��� ���������� � �������� ��������� ���������
    EXPECT_NE(output.find("2024-12-01"), std::string::npos);
    EXPECT_NE(output.find("���������: Truck1"), std::string::npos);
    EXPECT_NE(output.find("ID ��������: 1"), std::string::npos);
}
