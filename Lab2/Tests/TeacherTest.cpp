#include "pch.h"
#include "../PPOISlab2/Teacher.h"

TEST(TeacherTest, printTest)
{
	Teacher* teacher = new Teacher("Doe","Jane","bob");

	teacher->changeWorkingDays(4, 3);

	std::string expected = "Количесво рабочих часов Jane Doe bob:\n0 0 0 6 0 0 0 \n";
	testing::internal::CaptureStdout();
	teacher->showWorkigDays();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(expected, output);


}