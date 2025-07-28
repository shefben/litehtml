#include "el_input.h"
#include "document.h"

using namespace litehtml;

el_input::el_input(const std::shared_ptr<document>& doc) : html_tag(doc)
{
}

void el_input::parse_attributes()
{
        const char* val = get_attr("checked");
        if(!val) val = get_attr("selected");
        if(val)
        {
                m_checked = true;
                set_pseudo_class(_checked_, true);
        }

        if(get_attr("disabled"))
        {
                m_disabled = true;
                set_pseudo_class(_disabled_, true);
        }
        else
        {
                set_pseudo_class(_enabled_, true);
        }

        if(get_attr("readonly"))
        {
                m_readonly = true;
                set_pseudo_class(_read_only_, true);
        }

        if(get_attr("required"))
        {
                m_required = true;
                set_pseudo_class(_required_, true);
        }

        if(get_attr("invalid"))
        {
                m_valid = false;
                set_pseudo_class(_invalid_, true);
        }
        else
        {
                set_pseudo_class(_valid_, true);
        }

        const char* placeholder = get_attr("placeholder");
        const char* value = get_attr("value");
        if(placeholder && (!value || !*value))
        {
                m_placeholder = true;
                set_pseudo_class(_placeholder_shown_, true);
        }

        html_tag::parse_attributes();
}

