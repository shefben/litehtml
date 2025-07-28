cmake_minimum_required(VERSION 3.11)

add_executable(selector_pseudo_class_test
    selector_pseudo_class_test.cpp
)

add_executable(grid_layout_test
    grid_layout_test.cpp
)

add_executable(table_layout_test
    table_layout_test.cpp
)

target_include_directories(selector_pseudo_class_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
target_include_directories(grid_layout_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_include_directories(table_layout_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

find_package(GTest REQUIRED)
target_link_libraries(selector_pseudo_class_test PRIVATE GTest::gtest GTest::gtest_main litehtml)
target_link_libraries(grid_layout_test PRIVATE GTest::gtest GTest::gtest_main litehtml)
target_link_libraries(table_layout_test PRIVATE GTest::gtest GTest::gtest_main litehtml)

enable_testing()
add_test(NAME selector_pseudo_class_test COMMAND selector_pseudo_class_test)
add_test(NAME grid_layout_test COMMAND grid_layout_test)
add_test(NAME table_layout_test COMMAND table_layout_test)
