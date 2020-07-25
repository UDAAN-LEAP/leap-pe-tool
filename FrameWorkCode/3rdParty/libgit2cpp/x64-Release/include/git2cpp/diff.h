#pragma once

#include "buffer.h"
#include "tagged_mask.h"

#include <git2/diff.h>

#include <memory>
#include <functional>

namespace git
{
    namespace diff
    {
        namespace stats
        {
            namespace format
            {
                typedef tagged_mask_t<struct format_tag> type;

                extern const type none;
                extern const type full;
                extern const type _short;
                extern const type number;
                extern const type include_summary;
            }
        }

        enum class format
        {
            patch,
            patch_header,
            raw,
            name_only,
            name_status
        };
    }

    struct Diff
    {
        struct Stats
        {
            Buffer to_buf(diff::stats::format::type, size_t width) const;

        private:
            friend struct Diff;

            explicit Stats(git_diff_stats * stats)
                : stats_(stats)
            {}

        private:
            struct Destroy { void operator() (git_diff_stats*) const; };
            std::unique_ptr<git_diff_stats, Destroy> stats_;
        };

        size_t deltas_num() const;

        void find_similar(git_diff_find_options &);

        Stats stats() const;

        typedef std::function<void(git_diff_delta const &, git_diff_hunk const &, git_diff_line const &)>
            print_callback_t;

        void print(diff::format, print_callback_t print_callback) const;

        explicit Diff(git_diff * diff)
            : diff_(diff)
        {}

    private:
        struct Destroy { void operator() (git_diff *) const; };
        std::unique_ptr<git_diff, Destroy> diff_;
    };
}
