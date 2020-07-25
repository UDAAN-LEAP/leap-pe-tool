#pragma once

#include "pathspec.h"

#include <memory>

namespace git
{
    struct Repository;

    struct Tree
    {
        struct BorrowedEntry
        {
            const char * name() const;
            git_oid const & id() const;
            git_object_t type() const;
            git_filemode_t filemode() const;

        private:
            friend struct Tree;
            friend struct Repository;

            explicit BorrowedEntry(git_tree_entry const * entry)
                : entry_(entry)
            {}

            git_tree_entry const * ptr() const { return entry_; }

        private:
            git_tree_entry const * entry_;
        };

        struct OwnedEntry
        {
            Tree to_tree() /*&&*/;

        private:
            friend struct Tree;
            friend struct Repository;

            OwnedEntry(git_tree_entry * entry, Repository const & repo);

            git_tree_entry const * ptr() const { return entry_.get(); }

        private:
            struct Destroy { void operator() (git_tree_entry*) const; };
            std::unique_ptr<git_tree_entry, Destroy> entry_;
            Repository const * repo_;
        };

        git_tree const * ptr() const { return tree_.get(); }
        git_tree * ptr() { return tree_.get(); }

        int pathspec_match(uint32_t flags, Pathspec const & ps);

        size_t entrycount() const;

        BorrowedEntry operator[](size_t) const;

        BorrowedEntry operator[](std::string const & filename) const;

        OwnedEntry find(const char * path) const;

        Tree(git_tree *, Repository const &);

        Tree() = default;

        explicit operator bool() const { return tree_ != nullptr; }

    private:
        struct Destroy { void operator() (git_tree*) const; };
        std::unique_ptr<git_tree, Destroy> tree_;
        Repository const * repo_ = nullptr;
    };
}
