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

