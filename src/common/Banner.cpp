/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Banner.h"
#include "GitRevision.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
    log(Trinity::StringFormat("{} ({})", GitRevision::GetFullVersion(), applicationName).c_str());
    log(R"(<Ctrl-C> to stop.)");
    log(R"(  ____                              )");
    log(R"( |  _ \ _ __ __ _  __ _  ___  _ __  )");
    log(R"( | | | | '__/ _` |/ _` |/ _ \| '_ \ )");
    log(R"( | |_| | | | (_| | (_| | (_) | | | |)");
    log(R"( |____/|_|  \__,_|\__, |\___/|_| |_|)");
    log(R"(   ____           |___/             )");
    log(R"(  / ___|___  _ __ ___               )");
    log(R"( | |   / _ \| '__/ _ \              )");
    log(R"( | |__| (_) | | |  __/              )");
    log(R"(  \____\___/|_|  \___|              )");
    log(R"(                                    )");
    log(R"(World of Warcraft - Dragonflight 10.2.7 Server)");
    log(R"(                                    )");

    if (logExtraInfo)
        logExtraInfo();
}
