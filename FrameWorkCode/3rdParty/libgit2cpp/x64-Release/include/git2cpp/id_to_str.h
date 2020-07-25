#pragma once

#include <string>

#include <git2/oid.h>

namespace git
{
    std::string id_to_str(git_oid const & oid);

    std::string id_to_str(git_oid const & oid, size_t digits_num);

    git_oid str_to_id(const char * str);
}
