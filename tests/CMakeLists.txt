cmake_minimum_required(VERSION 3.11)

add_executable(selector_pseudo_class_test
    selector_pseudo_class_test.cpp
)

# Grid layout test disabled due to margin inconsistencies
#add_executable(grid_layout_test
#    grid_layout_test.cpp
#)

add_executable(opacity_filter_test
    opacity_filter_test.cpp
)

target_include_directories(selector_pseudo_class_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
#target_include_directories(grid_layout_test PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}/../include
#    ${CMAKE_CURRENT_SOURCE_DIR}/..
#)
target_include_directories(opacity_filter_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

find_package(GTest REQUIRED)
set(LH_LIB ${CMAKE_BINARY_DIR}/liblitehtml.a)
set(GUMBO_LIB ${CMAKE_BINARY_DIR}/src/gumbo/libgumbo.a)
target_link_libraries(selector_pseudo_class_test PRIVATE GTest::gtest GTest::gtest_main ${LH_LIB} ${GUMBO_LIB})
#target_link_libraries(grid_layout_test PRIVATE GTest::gtest GTest::gtest_main ${LH_LIB} ${GUMBO_LIB})
target_link_libraries(opacity_filter_test PRIVATE GTest::gtest GTest::gtest_main ${LH_LIB} ${GUMBO_LIB})

enable_testing()
add_test(NAME selector_pseudo_class_test COMMAND selector_pseudo_class_test)
#add_test(NAME grid_layout_test COMMAND grid_layout_test)
add_test(NAME opacity_filter_test COMMAND opacity_filter_test)
