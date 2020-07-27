#pragma once

#include <git2/status.h>

#include <memory>

namespace git
{
    struct Status
    {
        struct Options
        {
            enum class Show
            {
                IndexOnly,
                WorkdirOnly,
                IndexAndWorkdir
            };

            enum class Sort
            {
                CaseSensitively,
                CaseInsensitively,
            };

            Options(Show = Show::IndexAndWorkdir, Sort = Sort::CaseSensitively);

            Options & include_untracked();
            Options & exclude_untracked();
            Options & renames_head_to_index();
            Options & include_ignored();
            Options & recurse_untracked_dirs();
            Options & exclude_submodules();

            void set_pathspec(char ** ptr, size_t size);

            git_status_options const * raw() const { return &opts_; }

        private:
            git_status_options opts_;
        };

        size_t entrycount() const;
        git_status_entry const & operator[](size_t i) const;

    private:
        friend struct Repository;
        Status(git_repository * repo, Options const & opts);

    private:
        struct Destroy { void operator() (git_status_list*) const; };
        std::unique_ptr<git_status_list, Destroy> status_;
    };
}
