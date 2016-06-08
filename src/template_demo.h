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

#pragma once
class Template_Demo
{
public:
    Template_Demo();
    ~Template_Demo();

    template<typename T1, typename T2>
    void Sum(const T1& firstArg, const T2& secondArg);
};

template<typename T1, typename T2>
void Template_Demo::Sum(const T1& firstArg, const T2& secondArg)
{
    std::cout << "\nSum = " << (firstArg + secondArg);
}


