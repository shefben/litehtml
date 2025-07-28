#include "utf8_strings.h"
#include "document_container.h"
#include "background.h"

void litehtml::document_container::split_text(const char* text, const std::function<void(const char*)>& on_word, const std::function<void(const char*)>& on_space)
{
	std::u32string str;
	std::u32string str_in = (const char32_t*)utf8_to_utf32(text);
	for (auto c : str_in)
	{
		if (c <= ' ' && (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'))
		{
			if (!str.empty())
			{
				on_word(utf32_to_utf8(str));
				str.clear();
			}
			str += c;
			on_space(utf32_to_utf8(str));
			str.clear();
		}
		// CJK character range
		else if (c >= 0x4E00 && c <= 0x9FCC)
		{
			if (!str.empty())
			{
				on_word(utf32_to_utf8(str));
				str.clear();
			}
			str += c;
			on_word(utf32_to_utf8(str));
			str.clear();
		}
		else
		{
			str += c;
		}
	}
	if (!str.empty())
	{
		on_word(utf32_to_utf8(str));
	}
}

void litehtml::document_container::draw_text_with_shadow(uint_ptr hdc, const char* text, uint_ptr hFont, web_color color, const position& pos, const std::vector<text_shadow>& shadow, int letter_spacing, bool rtl)
{
       for(const auto& sh : shadow)
       {
               position sp = pos;
               sp.x += (int)sh.offset_x.val();
               sp.y += (int)sh.offset_y.val();
               draw_text(hdc, text, hFont, sh.color, sp);
       }

       if(letter_spacing == 0)
       {
               draw_text(hdc, text, hFont, color, pos);
       }else
       {
               int x = pos.x;
               utf8_to_utf32 u32(text);
               for(const char32_t* p = u32; *p; ++p)
               {
                       std::string ch = litehtml::utf32_to_utf8( std::u32string(1, *p).c_str() ).c_str();
                       position cp = pos;
                       cp.x = x;
                       draw_text(hdc, ch.c_str(), hFont, color, cp);
                       int adv = text_width(ch.c_str(), hFont) + (p[1]?letter_spacing:0);
                       x += rtl ? -adv : adv;
               }
       }
}

void litehtml::document_container::draw_box_shadow(uint_ptr hdc, const std::vector<box_shadow>& shadow, const position& border_box, const border_radiuses&)
{
       for(const auto& sh : shadow)
       {
               position sp = border_box;
               sp.x += (int)sh.offset_x.val() - (int)sh.spread.val();
               sp.y += (int)sh.offset_y.val() - (int)sh.spread.val();
               sp.width  += (int)(sh.spread.val()*2);
               sp.height += (int)(sh.spread.val()*2);
               background_layer layer;
               layer.border_box = sp;
               draw_solid_fill(hdc, layer, sh.color);
       }
}
