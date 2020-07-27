#pragma once

#include <git2/types.h>
#include <memory>

struct git_object;
struct git_oid;
struct git_tree;
struct git_tag;

namespace git
{
    struct Repository;

    struct Blob;
    struct Commit;
    struct Tree;
    struct Tag;

    struct Object
    {
        Object() = default;
        Object(git_object * obj, Repository const &);

        explicit operator bool() const { return obj_.operator bool(); }

        git_object_t type() const;
        git_oid const & id() const;

        Commit to_commit() /*&&*/;
        Tree to_tree() /*&&*/;
        Blob to_blob() /*&&*/;
        Tag  to_tag()  /*&&*/;

    private:
        git_blob    * as_blob();
        git_commit  * as_commit();
        git_tree    * as_tree();
        git_tag     * as_tag();

    private:
        struct Destroy { void operator() (git_object*) const; };
        std::unique_ptr<git_object, Destroy> obj_;
        Repository const * repo_ = nullptr;
    };
}
