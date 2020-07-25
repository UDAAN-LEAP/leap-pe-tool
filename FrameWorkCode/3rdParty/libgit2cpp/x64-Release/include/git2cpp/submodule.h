#pragma once

#include <git2/submodule.h>
#include <memory>

struct git_submodule;
struct git_repository;

namespace git
{
    struct Submodule
    {
        enum class status : unsigned int
        {
            in_head = GIT_SUBMODULE_STATUS_IN_HEAD,
            in_index = GIT_SUBMODULE_STATUS_IN_INDEX,
            in_config = GIT_SUBMODULE_STATUS_IN_CONFIG,
            in_wd = GIT_SUBMODULE_STATUS_IN_WD,
            index_added = GIT_SUBMODULE_STATUS_INDEX_ADDED,
            index_deleted = GIT_SUBMODULE_STATUS_INDEX_DELETED,
            index_modified = GIT_SUBMODULE_STATUS_INDEX_MODIFIED,
            wd_uninitialized = GIT_SUBMODULE_STATUS_WD_UNINITIALIZED,
            wd_added = GIT_SUBMODULE_STATUS_WD_ADDED,
            wd_deleted = GIT_SUBMODULE_STATUS_WD_DELETED,
            wd_modified = GIT_SUBMODULE_STATUS_WD_MODIFIED,
            wd_index_modified = GIT_SUBMODULE_STATUS_WD_INDEX_MODIFIED,
            wd_wd_modified = GIT_SUBMODULE_STATUS_WD_WD_MODIFIED,
            wd_untracked = GIT_SUBMODULE_STATUS_WD_UNTRACKED,
        };

        friend bool contains(status set, status element);

        status get_status() const;

    private:
        friend struct Repository;
        Submodule(git_submodule *, git_repository *);

    private:
        struct Destroy { void operator() (git_submodule*) const; };
        std::unique_ptr<git_submodule, Destroy> sm_;
        git_repository * repo_;
    };
}
