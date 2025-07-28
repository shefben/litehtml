#include <litehtml.h>

class simple_container : public litehtml::document_container
{
public:
    litehtml::uint_ptr create_font(const litehtml::font_description&, const litehtml::document*, litehtml::font_metrics*) override { return 0; }
    void delete_font(litehtml::uint_ptr) override {}
    int text_width(const char*, litehtml::uint_ptr) override { return 0; }
    void draw_text(litehtml::uint_ptr, const char*, litehtml::uint_ptr, litehtml::web_color, const litehtml::position&) override {}
    void draw_text_with_shadow(litehtml::uint_ptr, const char*, litehtml::uint_ptr, litehtml::web_color, const litehtml::position&, const std::vector<litehtml::text_shadow>&, int, bool) override {}
    int pt_to_px(int pt) const override { return pt; }
    int get_default_font_size() const override { return 16; }
    const char* get_default_font_name() const override { return "Times"; }
    void draw_list_marker(litehtml::uint_ptr, const litehtml::list_marker&) override {}
    void load_image(const char*, const char*, bool) override {}
    void get_image_size(const char*, const char*, litehtml::size&) override {}
    void draw_image(litehtml::uint_ptr, const litehtml::background_layer&, const std::string&, const std::string&) override {}
    void draw_solid_fill(litehtml::uint_ptr, const litehtml::background_layer&, const litehtml::web_color&) override {}
    void draw_linear_gradient(litehtml::uint_ptr, const litehtml::background_layer&, const litehtml::background_layer::linear_gradient&) override {}
    void draw_radial_gradient(litehtml::uint_ptr, const litehtml::background_layer&, const litehtml::background_layer::radial_gradient&) override {}
    void draw_conic_gradient(litehtml::uint_ptr, const litehtml::background_layer&, const litehtml::background_layer::conic_gradient&) override {}
    void draw_borders(litehtml::uint_ptr, const litehtml::borders&, const litehtml::position&, bool) override {}
    void set_caption(const char*) override {}
    void set_base_url(const char*) override {}
    void link(const litehtml::document::ptr&, const litehtml::element::ptr&) override {}
    void on_anchor_click(const char*, const litehtml::element::ptr&) override {}
    void on_mouse_event(const litehtml::element::ptr&, litehtml::mouse_event) override {}
    void set_cursor(const char*) override {}
    void transform_text(litehtml::string&, litehtml::text_transform) override {}
    void import_css(litehtml::string&, const litehtml::string&, litehtml::string&) override {}
    void set_clip(const litehtml::position&, const litehtml::border_radiuses&) override {}
    void del_clip() override {}
    void get_viewport(litehtml::position&) const override {}
    litehtml::element::ptr create_element(const char*, const litehtml::string_map&, const std::shared_ptr<litehtml::document>&) override { return nullptr; }
    void get_media_features(litehtml::media_features&) const override {}
    void get_language(litehtml::string&, litehtml::string&) const override {}
};
