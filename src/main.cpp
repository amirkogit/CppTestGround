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

#include <iostream>
#include "initializer_demo.h"
#include "range_based_for_loop_demo.h"
#include "variadic_templates_demo.h"
#include "template_demo.h"
#include "lamda_demo.h"
#include "explicit_initialization_demo.h"
#include "unordered_sets_multisets_demo.h"
#include "unordered_maps_multimaps_demo.h"
#include "algorithms_demo.h"

void RunInitializerDemo()
{
    std::cout << "Initializer Demo\n";

    Initializer_Demo id1(2, 3);
    id1.PrintSelf();

    Initializer_Demo id2{ 1, 2, 3, 4, 5, 6 };
    id2.PrintSelf();

    Initializer_Demo id3{ 2, 3 };
    id3.PrintSelf();
}

void RunRangeBasedForLoopDemo()
{
    std::cout << "Range based for loop Demo\n";

    range_based_for_loop_demo rangedemo;
    rangedemo.MultiplyVectorElements();
    rangedemo.AddAllArrayElements();
}

void RunVariadicTemplatesDemo()
{
    std::cout << "Variadic templates demo\n";

    variadic_templates_demo vtd;
    vtd.Print(7.5, "hello", "world", 45);
}

void RunTemplateDemo()
{
    std::cout << "Templates demo\n";

    Template_Demo td;
    td.Sum(9, 1);
    td.Sum(7.3, 2.5);
    //td.Sum("Hello", "World");
}

void RunLamdaDemo()
{
    std::cout << "Lambda demo\n";

    Lamda_Demo ld;
    ld.SimpleLamda();

    ld.ParameterizedLamda();

    ld.ReturnTypeLambda();

    ld.CaptureLambda();

    ld.MutableLambda();

    ld.ReturnLambda();
}

void RunExplicitInitializationDemo()
{
    Explicit_Initialization_Demo eid;
    eid.Fundamental_Types_Explicit_Initialization();
}

void RunUnorderedSetsMultiSetsDemo()
{
    UnorderedSetsMultiSetsDemo usms_demo;
    usms_demo.SimpleMultiset();
    
}

void RunUnorderedMapsMultiMapsDemo()
{
    UnorderedMapsMultiMapsDemo unordered_maps_multimaps_demo;
    unordered_maps_multimaps_demo.SimpleMultimap();
}

void RunAlgorithmsDemo()
{
    AlgorithmsDemo algo_demo;
    algo_demo.SimpleTransform();
}

/////////////////////////////////////////////////////////////////
// Dummy test stud for real quick testing
// include headers specific for this testing //
//
//
// end header includes //
void RunDummy()
{

}
/////////////////////////////////////////////////////////////////

int main()
{
    RunDummy();

    //RunInitializerDemo();

    //RunRangeBasedForLoopDemo();

    //RunVariadicTemplatesDemo();

    //RunTemplateDemo();

    //RunLamdaDemo();

    //RunExplicitInitializationDemo();

    //RunUnorderedSetsMultiSetsDemo();

    //RunUnorderedMapsMultiMapsDemo();

    RunAlgorithmsDemo();

    // wait for user to press any key
    getchar();
    return 0;
}