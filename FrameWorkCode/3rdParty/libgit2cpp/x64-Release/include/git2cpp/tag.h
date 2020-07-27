#pragma once

#include <git2/types.h>
#include <memory>

struct git_tag;
struct git_oid;

namespace git
{
    struct Repository;
    struct Object;

    struct Tag
    {
        explicit Tag(git_tag *);

        Object target(Repository const &) const;

        git_oid const & target_id()     const;
        git_object_t    target_type()   const;

        const char * name() const;
        const char * message() const;
        git_signature const * tagger() const;

    private:
        struct Destroy { void operator() (git_tag*) const; };
        std::unique_ptr<git_tag, Destroy> tag_;
    };
}
