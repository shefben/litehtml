cmake_minimum_required(VERSION 3.11)

add_executable(selector_pseudo_class_test
    selector_pseudo_class_test.cpp
)

add_executable(css_properties_test
    css_properties_test.cpp
)

target_include_directories(selector_pseudo_class_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

find_package(GTest REQUIRED)
target_link_libraries(selector_pseudo_class_test PRIVATE GTest::gtest GTest::gtest_main litehtml)
target_link_libraries(css_properties_test PRIVATE GTest::gtest GTest::gtest_main litehtml)

enable_testing()
add_test(NAME selector_pseudo_class_test COMMAND selector_pseudo_class_test)
add_test(NAME css_properties_test COMMAND css_properties_test)
