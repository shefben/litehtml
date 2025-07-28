#include <gtest/gtest.h>
#include <litehtml.h>
#include "simple_container.h"

using namespace litehtml;

TEST(Selectors, InputPseudoClasses)
{
    simple_container tc;
    auto doc = document::createFromString("<input type='text' placeholder='p' />", &tc);
    auto input = doc->root()->select_one("input");
    ASSERT_TRUE(input);
    // placeholder-shown should match because there is placeholder and no value
    EXPECT_EQ(input, doc->root()->select_one("input:placeholder-shown"));
    // enabled because not disabled
    EXPECT_EQ(input, doc->root()->select_one("input:enabled"));
    EXPECT_EQ(nullptr, doc->root()->select_one("input:disabled"));
    // valid by default
    EXPECT_EQ(input, doc->root()->select_one("input:valid"));

    // now input with checked and disabled
    auto doc2 = document::createFromString("<input type='checkbox' checked disabled />", &tc);
    auto in2 = doc2->root()->select_one("input");
    ASSERT_TRUE(in2);
    EXPECT_EQ(in2, doc2->root()->select_one("input:checked"));
    EXPECT_EQ(in2, doc2->root()->select_one("input:disabled"));
    EXPECT_EQ(nullptr, doc2->root()->select_one("input:enabled"));
}

TEST(Selectors, ColumnCombinatorParse)
{
    css_selector sel;
    ASSERT_TRUE(sel.parse("col||td", litehtml::no_quirks_mode));
    ASSERT_EQ(combinator_column, sel.m_combinator);
}

TEST(Selectors, FocusPseudoClasses)
{
    simple_container tc;
    auto doc = document::createFromString("<div id='outer'><div id='inner'></div></div>", &tc);
    auto inner = doc->root()->select_one("#inner");
    auto outer = doc->root()->select_one("#outer");
    ASSERT_TRUE(inner);
    ASSERT_TRUE(outer);

    EXPECT_EQ(nullptr, doc->root()->select_one("#inner:focus"));
    EXPECT_EQ(nullptr, doc->root()->select_one("#outer:focus-within"));

    doc->set_focus_element(inner);

    EXPECT_EQ(inner, doc->root()->select_one("#inner:focus"));
    EXPECT_EQ(inner, doc->root()->select_one("#inner:focus-visible"));
    EXPECT_EQ(outer, doc->root()->select_one("#outer:focus-within"));
}

