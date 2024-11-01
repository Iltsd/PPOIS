#include "pch.h"

#include "../PPOISlab2/Schedule.h"

TEST(ScheduleTest, PrintScheduleTest) {
    Schedule* schedule = new Schedule();
    Lesson* math = new Lesson("Mathematics");
    Lesson* physics = new Lesson("Physics");
    Auditorium* auditorium101 = new Auditorium("101", 3);
    Auditorium* auditorium202 = new Auditorium("202", 4);

    schedule->addToSchedule(math, auditorium101);
    schedule->addToSchedule(physics, auditorium202);

    testing::internal::CaptureStdout();
    schedule->printSchedule();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "0Пара:MathematicsВ аудитории: 101-3\n1Пара:PhysicsВ аудитории: 202-4\n";
    EXPECT_EQ(output, expectedOutput);

    delete schedule;
    delete math;
    delete physics;
    delete auditorium101;
    delete auditorium202;
}
