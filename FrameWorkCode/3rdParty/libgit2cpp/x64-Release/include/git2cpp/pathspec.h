#pragma once

#include "error.h"

#include <git2/pathspec.h>

namespace git
{
    struct Pathspec
    {
        explicit Pathspec(git_strarray const & pathspec)
        {
            if (git_pathspec_new(&ps_, &pathspec))
                throw pathspec_new_error();
        }

        git_pathspec * ptr() const { return ps_; }

        ~Pathspec()
        {
            git_pathspec_free(ps_);
        }

        Pathspec(Pathspec const &) = delete;
        Pathspec & operator=(Pathspec const &) = delete;

    private:
        git_pathspec * ps_;
    };
}
