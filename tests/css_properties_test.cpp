#include <gtest/gtest.h>
#include <litehtml.h>
#include "simple_container.h"

using namespace litehtml;

TEST(CSSParsing, TableLayoutAndPageBreak)
{
    simple_container tc;
    auto doc = document::createFromString(
        "<table style='table-layout:fixed; page-break-before:always; orphans:3; widows:4'></table>",
        &tc);
    auto tbl = doc->root()->select_one("table");
    ASSERT_TRUE(tbl);
    EXPECT_EQ(table_layout_fixed, tbl->css().get_table_layout());
    EXPECT_EQ(page_break_always, tbl->css().get_page_break_before());
    EXPECT_EQ(3, tbl->css().get_orphans());
    EXPECT_EQ(4, tbl->css().get_widows());
}
