/*
 * Copyright (c) 2020-2022 Advanced Robotics at the University of Washington <robomstr@uw.edu>
 *
 * This file is part of aruw-edu.
 *
 * aruw-edu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * aruw-edu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with aruw-edu.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>

#include "control/standard.hpp"

#include "drivers.hpp"

namespace control
{
class ARUW_EDU_Standard : public testing::Test
{
protected:
    ARUW_EDU_Standard() : robot(drivers){};

    Drivers drivers;

    Robot robot;
};

TEST_F(ARUW_EDU_Standard, Initialization)
{
    EXPECT_CALL(drivers.commandScheduler, registerSubsystem)
        .WillOnce([](tap::control::Subsystem *sub) {
            EXPECT_NE(nullptr, dynamic_cast<chassis::ChassisSubsystem *>(sub));
        });

    robot.initSubsystemCommands();
}
}  // namespace control
