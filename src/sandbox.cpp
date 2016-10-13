/*
* Code snippets to try C++11 and C++14 features
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "common_utilities.h"

static_assert(sizeof(float) == 4, "can't serialize floats !");



#include <Windows.h>
#define ASSERT _ASSERTE

#ifdef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expression)(expresion)
#endif

struct LastException
{
    DWORD result;
    LastException() : result{ GetLastError() } {}
};

struct ManualResetEvent
{
    HANDLE m_handle;

    ManualResetEvent()
    {
        m_handle = CreateEvent(nullptr,
                               true,
                               false,
                               nullptr);

        if (!m_handle) {
            throw LastException();
        }
    }

    ~ManualResetEvent()
    {
        VERIFY(CloseHandle(m_handle));
    }
};


// ========================================================================

void SimpleAssertDemo()
{
    ASSERT(4 == 5);
}

void SimpleVerifyDemo()
{
    auto e = ManualResetEvent{};
    auto e2 = e;
}

// ========================================================================
auto SandboxMain() -> int
{
    //SimpleAssertDemo();

    SimpleVerifyDemo();

    return 0;
}
// ========================================================================
