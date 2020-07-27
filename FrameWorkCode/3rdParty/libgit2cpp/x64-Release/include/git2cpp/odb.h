#pragma once

#include "odb_object.h"

#include <git2/oid.h>

struct git_odb;

namespace git
{
    struct Odb
    {
        OdbObject read(git_oid const & oid) const;
        git_oid write(const void * data, size_t len, git_object_t type);

    private:
        friend struct Repository;
        explicit Odb(git_repository * repo);

    private:
        struct Destroy { void operator() (git_odb* odb) const; };
        std::unique_ptr<git_odb, Destroy> odb_;
    };
}
