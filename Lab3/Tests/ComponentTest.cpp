#include "pch.h"
#include "../PPOISlab3/Component.h"

TEST(ComponentTest, ConstructorAndGetters) {


    // �������� ������������ � �����������
    Component component2(1, "My Component");
    EXPECT_EQ(component2.getID(), 1);                          // �������� ID
    EXPECT_EQ(component2.getName(), "My Component");           // �������� �����
}

TEST(ComponentTest, SettersAndNameChange) {
    Component component(1, "My Component");

    // �������� ���
    component.setName("New Name");
    EXPECT_EQ(component.getName(), "New Name");                // ��������, ��� ��� ����������

    // �������� ID
    component.changeID(2);
    EXPECT_EQ(component.getID(), 2);                           // ��������, ��� ID ���������
}
