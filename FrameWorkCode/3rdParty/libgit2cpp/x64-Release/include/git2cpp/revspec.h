#pragma once

#include "object.h"

extern "C" {
#include <git2/revparse.h>
}

namespace git
{
    struct Repository;

    struct Revspec
    {
        struct Range
        {
            Object from, to;

            Range(git_object * single, Repository const & repo)
                : from(single, repo)
            {}

            explicit Range(git_revspec const & revspec, Repository const & repo)
                : from(revspec.from, repo)
                , to(revspec.to, repo)
            {}
        };

        Object const * single() const;
        Range const * range() const;

        Object * single();

        unsigned int flags() const;

        Revspec(git_object * single, Repository const &);
        Revspec(git_revspec const &, Repository const &);

    private:
        unsigned int flags_ = 0;
        Range revspec_;
    };
}
