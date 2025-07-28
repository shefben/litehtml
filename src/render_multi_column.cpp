#include "render_multi_column.h"
#include "document.h"

int litehtml::render_item_multi_column::_render_content(int x, int y, bool /*second_pass*/, const containing_block_context& self_size, formatting_context* fmt_ctx)
{
        int count = 0;
        if(!css().get_column_count().is_predefined())
                count = (int)css().get_column_count().val();
        int gap = css().get_column_gap().calc_percent(self_size.width);
        if(count <= 0)
        {
                if(!css().get_column_width().is_predefined() && css().get_column_width().val() > 0)
                {
                        count = std::max(1, static_cast<int>(self_size.render_width / css().get_column_width().val()));
                }
        }
        if(count <= 0) count = 1;
        int col_width = (self_size.render_width - gap * (count - 1)) / count;

        std::vector<int> col_heights(count, 0);
        int ret_width = 0;

        int idx = 0;
        for(const auto& el : m_children)
        {
                int col = idx % count;
                int cx = x + col * (col_width + gap);
                int cy = y + col_heights[col];
                int rw = el->render(cx, cy, self_size.new_width(col_width), fmt_ctx);
                col_heights[col] += el->height();
                ret_width = std::max(ret_width, rw);
                idx++;
        }
        m_pos.height = *std::max_element(col_heights.begin(), col_heights.end());
        return ret_width * count + gap * (count - 1);
}
