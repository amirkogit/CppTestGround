cmake_minimum_required (VERSION 3.1.1)

project(cppTestGround)

add_executable(cppTestGround 
    src/main.cpp
    src/common_utilities.h
    src/common_utilities.cpp
    src/initializer_demo.h
    src/initializer_demo.cpp
    src/range_based_for_loop_demo.h
    src/range_based_for_loop_demo.cpp
    src/variadic_templates_demo.h
    src/variadic_templates_demo.cpp
    src/template_demo.h
    src/template_demo.cpp
    src/lamda_demo.h
    src/lamda_demo.cpp
    src/explicit_initialization_demo.h
    src/explicit_initialization_demo.cpp
    src/unordered_sets_multisets_demo.h
    src/unordered_sets_multisets_demo.cpp
    src/unordered_maps_multimaps_demo.h
    src/unordered_maps_multimaps_demo.cpp
    src/algorithms_demo.h
    src/algorithms_demo.cpp
    hackerrank/hacker_rank_challenges.h
    hackerrank/hacker_rank_challenges.cpp
	hackerrank/cpp_30days_challenges.cpp
	hackerrank/domain_cpp_challenges.cpp
	hackerrank/domain_algorithms_challenges.cpp
	hackerrank/domain_datastructures_challenges.cpp
	hackerrank/weekofcode21_challenges.cpp
	hackerrank/codesprint4_challenges.cpp
 )
