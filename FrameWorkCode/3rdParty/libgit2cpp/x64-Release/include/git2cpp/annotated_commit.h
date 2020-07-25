#pragma once

#include <memory>

struct git_annotated_commit;
struct git_oid;

namespace git
{
    struct AnnotatedCommit
    {
        AnnotatedCommit(git_annotated_commit * commit)
            : commit_(commit)
        {}

        git_oid const & commit_id()  const;
        char const *    commit_ref() const;

    private:
        friend struct Repository;
        git_annotated_commit * ptr() const { return commit_.get(); }

    private:
        struct Destroy { void operator() (git_annotated_commit*) const; };
        std::unique_ptr<git_annotated_commit, Destroy> commit_;
    };
}
