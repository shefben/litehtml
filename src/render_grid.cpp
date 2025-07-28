#include "render_grid.h"
#include "html_tag.h"

int litehtml::render_item_grid::_render_content(int x, int y, bool /*second_pass*/, const containing_block_context &self_size, formatting_context* fmt_ctx)
{
        const auto& cols = css().get_grid_template_columns();
        const auto& rows = css().get_grid_template_rows();
        int col_gap = (int)css().get_grid_column_gap().val();
        int row_gap = (int)css().get_grid_row_gap().val();

        std::vector<int> col_lines(cols.size()+1,0);
        for(size_t i=0;i<cols.size();i++)
        {
                col_lines[i+1] = col_lines[i] + (int)cols[i].val();
        }
        std::vector<int> row_lines(rows.size()+1,0);
        for(size_t i=0;i<rows.size();i++)
        {
                row_lines[i+1] = row_lines[i] + (int)rows[i].val();
        }
        int container_width = col_lines.back() + (int)std::max<int>(cols.size()-1,0)*col_gap;
        int container_height = row_lines.back() + (int)std::max<int>(rows.size()-1,0)*row_gap;

        for(const auto& child : m_children)
        {
                int cs = std::max(1, child->src_el()->css().get_grid_column_start());
                int ce = std::max(cs+1, child->src_el()->css().get_grid_column_end());
                cs = std::min(cs, (int)cols.size());
                ce = std::min(ce, (int)cols.size()+1);
                int rs = std::max(1, child->src_el()->css().get_grid_row_start());
                int re = std::max(rs+1, child->src_el()->css().get_grid_row_end());
                rs = std::min(rs, (int)rows.size());
                re = std::min(re, (int)rows.size()+1);

                int x_start = col_lines[cs-1] + col_gap*(cs-1);
                int x_end = col_lines[ce-1] + col_gap*(ce-1);
                int y_start = row_lines[rs-1] + row_gap*(rs-1);
                int y_end = row_lines[re-1] + row_gap*(re-1);
                int w = x_end - x_start;
                int h = y_end - y_start;

                child->render(x_start, y_start, self_size.new_width_height(w, h), fmt_ctx);
        }

        m_pos.width = container_width;
        m_pos.height = container_height;
        return container_width;
}

std::shared_ptr<litehtml::render_item> litehtml::render_item_grid::init()
{
        decltype(m_children) new_children;
        decltype(m_children) inlines;
        auto convert_inlines = [&]()
        {
                if(!inlines.empty())
                {
                        auto anon_el = std::make_shared<html_tag>(src_el());
                        auto anon_ri = std::make_shared<render_item_block>(anon_el);
                        for(const auto& inl : inlines) anon_ri->add_child(inl);
                        anon_ri->parent(shared_from_this());
                        new_children.push_back(anon_ri->init());
                        inlines.clear();
                }
        };

        for(const auto& el : m_children)
        {
                if(el->src_el()->css().get_display() == display_inline_text)
                {
                        if(!el->src_el()->is_white_space()) inlines.push_back(el);
                } else {
                        convert_inlines();
                        el->parent(shared_from_this());
                        new_children.push_back(el->init());
                }
        }
        convert_inlines();
        children() = new_children;
        return shared_from_this();
}

