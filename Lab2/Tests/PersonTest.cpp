#include "pch.h"
#include "../PPOISlab2/Person.h"

TEST(PersonTest, fioTest)
{
	Person* person = new Person("Bob");
	person->setName("Kirill");

	EXPECT_EQ(person->getName(), "Kirill");
}