#include "pch.h"

#include "pch.h"
#include "../PPOISlab2/Auditorium.h"


TEST(AuditoriumTest, ConstructorAndPrintTest) {
    Auditorium* auditorium = new Auditorium("101", 3);

    testing::internal::CaptureStdout();
    auditorium->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "101-3\n");

    delete auditorium;
}
