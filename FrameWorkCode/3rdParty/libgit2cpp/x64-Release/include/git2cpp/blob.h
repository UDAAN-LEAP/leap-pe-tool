#pragma once

#include <cstddef>
#include <memory>

struct git_blob;

namespace git
{
    struct Blob
    {
        explicit Blob(git_blob *);

        std::size_t size() const;
        const void * content() const;

    private:
        friend struct Repository;

        git_blob const * ptr() const { return blob_.get(); }

    private:
        struct Destroy { void operator() (git_blob *) const; };

        std::unique_ptr<git_blob, Destroy> blob_;
    };
}
