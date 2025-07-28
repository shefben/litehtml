#include <gtest/gtest.h>
#include <litehtml.h>
#include "simple_container.h"

using namespace litehtml;

TEST(TableLayout, FixedWidthDistribution)
{
    simple_container tc;
    auto doc = document::createFromString(
        "<table id='t' style='table-layout:fixed;width:200px'>"
        "<tr><td id='a' style='width:50px'>1</td><td id='b'>2</td></tr>"
        "</table>", &tc);
    doc->render(200);
    auto a = doc->root()->select_one("#a");
    auto b = doc->root()->select_one("#b");
    ASSERT_TRUE(a && b);
    EXPECT_EQ(a->get_placement().width, 50);
    EXPECT_EQ(b->get_placement().width, 150);
}

TEST(Pagination, PropertiesParse)
{
    simple_container tc;
    auto doc = document::createFromString("<div id='d' style='page-break-before:always;orphans:3;widows:2'></div>", &tc);
    auto el = doc->root()->select_one("#d");
    ASSERT_TRUE(el);
    EXPECT_EQ(el->css().get_page_break_before(), page_break_always);
    EXPECT_EQ(el->css().get_orphans(), 3);
    EXPECT_EQ(el->css().get_widows(), 2);
}
