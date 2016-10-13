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



#include <windows.h>
#include <stdio.h>

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


#ifdef _DEBUG
inline auto Trace(wchar_t const* format, ...)->void
{
    va_list args;
    va_start(args,format);

    wchar_t buffer[256];

    ASSERT(-1 != _vsnwprintf_s(buffer,
                               _countof(buffer)-1,
                               format,
                               args));
    va_end(args);

    OutputDebugStringW(buffer);
}

struct Tracer
{
    char const* m_filename;
    unsigned m_line;

    Tracer(char const* filename, unsigned const line) :
        m_filename{ filename },
        m_line{ line }
    {

    }

    template<typename... Args>
    auto operator()(wchar_t const* format, Args...args) const -> void
    {
        wchar_t buffer[256];

        auto count = swprintf_s(buffer,
            L"%S(%d): ",
            m_filename,
            m_line);

        ASSERT(-1 != count);

        ASSERT(-1 != _snwprintf_s(buffer + count,
            _countof(buffer) - count,
            _countof(buffer) - count - 1,
            format,
            args...));

        OutputDebugStringW(buffer);
    }
};
#endif

#ifdef _DEBUG
#define TRACE Tracer(__FILE__, __LINE__)
#else
#define TRACE __noop
#endif


// ========================================================================
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

void SimpleTraceDemo()
{
    Trace(L"1 + 2 = %d\n",1 + 2);
}

void SimpleTraceDemo2()
{
    TRACE(L"1 + 2 = %d\n", 1 + 2);
}

// ========================================================================
auto SandboxMain() -> int
{
    //SimpleAssertDemo();

    //SimpleVerifyDemo();

    //SimpleTraceDemo();

    SimpleTraceDemo2();

    return 0;
}
// ========================================================================
