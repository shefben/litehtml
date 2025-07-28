#include <gtest/gtest.h>
#include <litehtml.h>
#include "simple_container.h"
using namespace litehtml;

TEST(CSS, OpacityInheritance)
{
    simple_container tc;
    auto doc = document::createFromString(
        "<div id='o' style='opacity:0.5'><span id='i' style='opacity:0.5'>t</span></div>",
        &tc);
    auto outer = doc->root()->select_one("#o");
    auto inner = doc->root()->select_one("#i");
    ASSERT_TRUE(outer && inner);
    EXPECT_FLOAT_EQ(outer->css().get_opacity(), 0.5f);
    EXPECT_NEAR(inner->css().get_opacity(), 0.25f, 0.001f);
}

TEST(CSS, FilterParse)
{
    simple_container tc;
    auto doc = document::createFromString(
        "<div id='f' style='filter:blur(4px)'></div>", &tc);
    auto el = doc->root()->select_one("#f");
    ASSERT_TRUE(el);
    auto tokens = el->css().get_filter();
    ASSERT_EQ(tokens.size(), 1u);
    EXPECT_EQ(tokens[0].type, litehtml::CV_FUNCTION);
    EXPECT_EQ(tokens[0].name, "blur");
}
