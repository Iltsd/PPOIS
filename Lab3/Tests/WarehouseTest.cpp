#include "pch.h"
#include "../PPOISlab3/Warehouse.h"


// ��������� ������������ �� Component ��� Warehouse
TEST(WarehouseTest, InheritFromComponent) {
    Warehouse warehouse(1, "Main Warehouse");

    EXPECT_EQ(warehouse.getID(), 1);                       // ��������� ID
    EXPECT_EQ(warehouse.getName(), "Main Warehouse");      // ��������� ���

    warehouse.setName("New Warehouse");
    warehouse.changeID(2);

    EXPECT_EQ(warehouse.getID(), 2);                       // ��������� ����� ID
    EXPECT_EQ(warehouse.getName(), "New Warehouse");       // ��������� ����� ���
}

// ����� ��� StorageArea
TEST(WarehouseTest, AddStorageAreaAndRetrieve) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    StorageArea storageArea2(2, "Area 2");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addStorageArea(&storageArea2);

    EXPECT_EQ(warehouse.getStorageArea(1), &storageArea1);
    EXPECT_EQ(warehouse.getStorageArea(2), &storageArea2);
}

TEST(WarehouseTest, AddAndRemoveProductFromStorageArea) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");

    storageArea1.addPoduct(&product1);
    storageArea1.addPoduct(&product2);

    // ��������, ��� �������� ���������
    EXPECT_EQ(storageArea1.getProducts().size(), 2);

    storageArea1.removeProduct(1);

    // ��������, ��� ������� �����
    EXPECT_EQ(storageArea1.getProducts().size(), 1);
    EXPECT_EQ(storageArea1.getProducts()[0]->getID(), 2);  // �������, ��� ������� ������ product2
}

TEST(WarehouseTest, IsStorageAvailable) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1", 1);  // �������� 1 ������� � ���� ���������
    Product product1(1, "Product 1");

    storageArea1.addPoduct(&product1);

    // ���������, ��� ��������� ������
    EXPECT_FALSE(storageArea1.isAvailable());

    StorageArea storageArea2(2, "Area 2", 2);
    // ���������, ��� ����� ��������� ��������
    EXPECT_TRUE(storageArea2.isAvailable());
}

// �������� ���������� � ������
TEST(WarehouseTest, ShowAvailableStorages) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    StorageArea storageArea2(2, "Area 2");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addStorageArea(&storageArea2);

    testing::internal::CaptureStdout();
    warehouse.showAvailableStorages();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"), std::string::npos);  // ���������, ��� "Area 1" ���� � ������
    EXPECT_NE(output.find("2"), std::string::npos);  // ���������, ��� "Area 2" ���� � ������
}

// �������� ���������� � ������
TEST(WarehouseTest, WarehouseInfo) {
    Warehouse warehouse(1, "Main Warehouse");
    StorageArea storageArea1(1, "Area 1");
    Worker worker1(1, "John", "Doe", "Smith");

    warehouse.addStorageArea(&storageArea1);
    warehouse.addWorker(&worker1);

    testing::internal::CaptureStdout();
    warehouse.warehouseInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Main Warehouse"), std::string::npos);  // ���������, ��� �������� ������ ���� � ������
    EXPECT_NE(output.find("1"), std::string::npos);
}
