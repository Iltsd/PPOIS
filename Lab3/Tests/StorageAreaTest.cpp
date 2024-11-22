#include "pch.h"
#include "../PPOISlab3/StorageArea.h"

TEST(StorageAreaTest, ConstructorAndGetters) {
    // �������� ������������ � �����������
    StorageArea storageArea(1, "Storage 1", 100);
    EXPECT_EQ(storageArea.getName(), "Storage 1");          // �������� �����
    EXPECT_EQ(storageArea.getID(), 1);                       // �������� ID
    EXPECT_EQ(storageArea.isAvailable(), true);              // ��������� ������ ���� �������� (��� ���������)

    // �������� ������������ �� ���������
    StorageArea defaultStorage(1);
    EXPECT_EQ(defaultStorage.getName(), "Not Defined");     // ��� �� ���������
    EXPECT_EQ(defaultStorage.getID(), 1);                    // ID �� ���������
    EXPECT_EQ(defaultStorage.isAvailable(), true);           // ��������� ������ ���� ��������
}

TEST(StorageAreaTest, AddProductAndRemoveProduct) {
    StorageArea storageArea(1, "Storage 1", 3);
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");
    Product product3(3, "Product 3");

    storageArea.addPoduct(&product1);
    storageArea.addPoduct(&product2);

    // ���������, ��� ��� �������� ���������
    EXPECT_EQ(storageArea.getProducts().size(), 2);

    storageArea.removeProduct(1);  // ������� ������� � ID 1

    // ���������, ��� ������� � ID 1 �����
    EXPECT_EQ(storageArea.getProducts().size(), 1);
    EXPECT_EQ(storageArea.getProducts()[0]->getID(), 2);  // �������, ��� ������� ������ ������� � ID 2
}

TEST(StorageAreaTest, IsStorageAvailable) {
    StorageArea storageArea(1, "Storage 1", 2);
    Product product1(1, "Product 1");

    EXPECT_TRUE(storageArea.isAvailable());  // ��������� ������ ���� ��������

    storageArea.addPoduct(&product1);
    EXPECT_TRUE(storageArea.isAvailable());  // ��������� �� ��� �������� (����� ����)

    Product product2(2, "Product 2");
    storageArea.addPoduct(&product2);
    EXPECT_FALSE(storageArea.isAvailable());  // ��������� ������ ���� ������, ������������ ���������� ���������
}

TEST(StorageAreaTest, AddProductExceedingCapacity) {
    StorageArea storageArea(1, "Storage 1", 2);  // ����������� 2 ��������
    Product product1(1, "Product 1");
    Product product2(2, "Product 2");
    Product product3(3, "Product 3");

    storageArea.addPoduct(&product1);
    storageArea.addPoduct(&product2);

    // ���������, ��� ��������� �� ��������� ������ �������, ���� ��� �����������
    EXPECT_EQ(storageArea.getProducts().size(), 2);  // ������ ���� ������ ��� ��������
    storageArea.addPoduct(&product3);
    EXPECT_EQ(storageArea.getProducts().size(), 3);  // ���������� ��������� ����������
}
