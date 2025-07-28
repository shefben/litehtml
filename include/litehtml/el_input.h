#ifndef LH_EL_INPUT_H
#define LH_EL_INPUT_H

#include "html_tag.h"

namespace litehtml
{
        class el_input : public html_tag
        {
                bool m_checked = false;
                bool m_disabled = false;
                bool m_readonly = false;
                bool m_required = false;
                bool m_valid = true;
                bool m_placeholder = false;
        public:
                explicit el_input(const std::shared_ptr<document>& doc);

                void parse_attributes() override;

                bool is_checked() const { return m_checked; }
                bool is_disabled() const { return m_disabled; }
                bool is_readonly() const { return m_readonly; }
                bool is_required() const { return m_required; }
                bool is_valid() const { return m_valid; }
                bool is_placeholder_shown() const { return m_placeholder; }
        };
}

#endif // LH_EL_INPUT_H
