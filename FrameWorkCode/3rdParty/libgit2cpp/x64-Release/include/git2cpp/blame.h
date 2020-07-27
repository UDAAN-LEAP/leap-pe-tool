#pragma once

#include <memory>

struct git_blame;
struct git_blame_hunk;

namespace git
{
    struct Blame
    {
        uint32_t hunk_count() const;

        const git_blame_hunk * hunk_byindex(uint32_t index) const;

        const git_blame_hunk * hunk_byline(size_t lineno) const;

        explicit Blame(git_blame * blame)
            : blame_(blame)
        {}

    private:
        struct Destroy { void operator() (git_blame *) const; };
        std::unique_ptr<git_blame, Destroy> blame_;
    };
}
