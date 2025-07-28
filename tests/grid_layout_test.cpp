#include <gtest/gtest.h>
#include <litehtml.h>
#include "simple_container.h"

using namespace litehtml;

TEST(Grid, BasicPlacement)
{
    simple_container tc;
    auto doc = document::createFromString(
        "<div id='c' style='display:grid;grid-template-columns:100px 100px;grid-template-rows:50px 50px;grid-column-gap:10px;grid-row-gap:5px;margin:0'>"
        "<div id='a' style='grid-column:1/2;grid-row:1/2;width:50px;height:30px'></div>"
        "<div id='b' style='grid-column:2/3;grid-row:1/3;width:50px;height:40px'></div>"
        "</div>", &tc);
    doc->render(220);
    auto a = doc->root()->select_one("#a");
    auto b = doc->root()->select_one("#b");
    ASSERT_TRUE(a && b);
    auto posA = a->get_placement();
    auto posB = b->get_placement();
    EXPECT_EQ(posA.x, 0);
    EXPECT_EQ(posA.y, 0);
    EXPECT_EQ(posB.x, 110); // 100 + gap
    EXPECT_EQ(posB.y, 0);
}

