#ifndef LITEHTML_RENDER_MULTI_COLUMN_H
#define LITEHTML_RENDER_MULTI_COLUMN_H

#include "render_block_context.h"

namespace litehtml
{
        class render_item_multi_column : public render_item_block_context
        {
        protected:
                int _render_content(int x, int y, bool second_pass, const containing_block_context& self_size, formatting_context* fmt_ctx) override;
        public:
                explicit render_item_multi_column(std::shared_ptr<element>  el) : render_item_block_context(std::move(el)) {}
                std::shared_ptr<render_item> clone() override { return std::make_shared<render_item_multi_column>(src_el()); }
        };
}

#endif // LITEHTML_RENDER_MULTI_COLUMN_H
