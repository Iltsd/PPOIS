#include "pch.h"
#include "../PPOISlab3/Component.h"

TEST(ComponentTest, ConstructorAndGetters) {


    // Проверка конструктора с параметрами
    Component component2(1, "My Component");
    EXPECT_EQ(component2.getID(), 1);                          // Проверка ID
    EXPECT_EQ(component2.getName(), "My Component");           // Проверка имени
}

TEST(ComponentTest, SettersAndNameChange) {
    Component component(1, "My Component");

    // Изменяем имя
    component.setName("New Name");
    EXPECT_EQ(component.getName(), "New Name");                // Проверка, что имя изменилось

    // Изменяем ID
    component.changeID(2);
    EXPECT_EQ(component.getID(), 2);                           // Проверка, что ID изменился
}
