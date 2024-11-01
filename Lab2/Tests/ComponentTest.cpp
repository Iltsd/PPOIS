#include "pch.h"
#include "../PPOISlab2/Component.h"

TEST(ComponentTest, nameTest)
{
	Component* component = new Component("Name");
	EXPECT_EQ(component->getName(), "Name");
}