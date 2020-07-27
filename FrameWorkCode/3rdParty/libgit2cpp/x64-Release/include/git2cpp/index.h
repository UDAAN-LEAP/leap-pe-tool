#pragma once

#include <git2/oid.h>

#include <functional>
#include <memory>

struct git_index;
struct git_repository;
struct git_strarray;
struct git_index_entry;

namespace git
{
    struct Index
    {
        explicit Index(git_repository * repo);
        explicit Index(const char * dir);

        size_t entrycount() const;
        git_index_entry const * operator[](size_t i) const;

        git_index_entry const * get_by_path(const char *path, int stage) const;

        typedef std::function<int(const char * path, const char * mathched_pathspec)> matched_path_callback_t;

        void update_all(git_strarray const & pathspec, matched_path_callback_t cb);
        void add_all(git_strarray const & pathspec, matched_path_callback_t cb, unsigned int flags = 0);
        void clear();

        void add_path(const char *);
        void add_path(std::string const &);

        void remove_path(const char *);
        void remove_path(std::string const &);

        git_oid write_tree() const;

        void write() const;

    private:
        struct Destroy { void operator() (git_index*) const; };
        std::unique_ptr<git_index, Destroy> index_;
    };
}
