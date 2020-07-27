#pragma once

#include <memory>

struct git_remote;
struct git_oid;
struct git_transfer_progress;
struct git_cred;

namespace git
{
    struct Remote
    {
        const char * url()      const;
        const char * pushurl()  const;

        struct FetchCallbacks
        {
            virtual void update_tips(char const * refname, git_oid const & a, git_oid const & b) {}
            virtual void sideband_progress(char const * str, int len) {}
            virtual void transfer_progress(git_transfer_progress const &) {}

            virtual git_cred* acquire_cred(const char * url, const char * username_from_url, unsigned int allowed_types) = 0;
        };

        void fetch(FetchCallbacks &, char const * reflog_message = nullptr);

    private:
        friend struct Repository;

        struct Destroy { void operator() (git_remote*) const; };

        explicit Remote(git_remote * remote)
            : remote_(remote)
        {}

        std::unique_ptr<git_remote, Destroy> remote_;
    };
}
