#pragma once

#include <git2/types.h>
#include <memory>

struct git_reference;
struct git_oid;

namespace git
{
    struct Reference
    {
        Reference()
            : ref_(nullptr)
        {}

        explicit Reference(git_reference * ref);

        explicit operator bool() const { return ref_ != nullptr; }

        const char * name() const;
        git_reference_t type() const;
        git_oid const & target() const;
        const char * symbolic_target() const;

        bool has_same_target_as(Reference const & other) const;

    private:
        friend struct Repository;
        git_reference * ptr() const { return ref_.get(); }

    private:
        struct Destroy { void operator() (git_reference*) const; };
        std::unique_ptr<git_reference, Destroy> ref_;
    };
}
