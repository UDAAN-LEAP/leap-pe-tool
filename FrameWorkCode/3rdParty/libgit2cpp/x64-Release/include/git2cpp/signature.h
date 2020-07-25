#pragma once

#include <git2/types.h>

#include <memory>

struct git_signature;
struct git_repository;

namespace git
{
    struct Signature
    {
        Signature(const char * name, const char * email, git_time_t time, int offset);

    private:
        friend struct Repository;
        explicit Signature(git_repository * repo);

        git_signature const * ptr() const { return sig_.get(); }

    private:
        struct Destroy { void operator() (git_signature*) const; };
        std::unique_ptr<git_signature, Destroy> sig_;
    };
}
