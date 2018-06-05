TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std:c++17
SOURCES += \
        main.cpp \
    vector_erase_remove_idiom.cpp \
    vector_items_delete_optimize.cpp \
    vector_element_access.cpp \
    sorted_vector.cpp \
    conditional_map_insert.cpp \
    custom_iterable_range.cpp \
    compatible_custom_iterators.cpp \
    iterator_adapters.cpp \
    algo_in_terms_of_iterators.cpp \
    reverse_iterator_adapters.cpp
