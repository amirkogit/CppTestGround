QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += /std:c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp
#SOURCES += main_template.cpp
#SOURCES += main_simple_vector.cpp
#SOURCES += main_counting_elements_in_two_arrays.cpp
#SOURCES += main_four_elements_sum.cpp
#SOURCES += main_identical_trees.cpp
#SOURCES += main_pair_with_max_product.cpp
