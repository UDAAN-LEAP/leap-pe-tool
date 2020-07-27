#pragma once

#include <git2/types.h>
#include <memory>

namespace git
{
    struct OdbObject
    {
        explicit OdbObject(git_odb_object * obj)
            : obj_(obj)
        {}

        git_object_t type() const;
        unsigned char const * data() const;
        size_t size() const;

    private:
        struct Destroy { void operator() (git_odb_object *) const; };
        std::unique_ptr<git_odb_object, Destroy> obj_;
    };
}
