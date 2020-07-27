#pragma once

#include "repo_fwd.h"

#include "blame.h"
#include "blob.h"
#include "commit.h"
#include "diff.h"
#include "index.h"
#include "odb.h"
#include "reference.h"
#include "remote.h"
#include "revspec.h"
#include "revwalker.h"
#include "signature.h"
#include "status.h"
#include "str_array.h"
#include "submodule.h"
#include "tag.h"
#include "tree.h"

#include "internal/optional.h"

#include <string>
#include <vector>

struct git_blame_options;

namespace git
{
    struct non_existing_branch_error
    {};
    struct missing_head_error
    {};

    enum class branch_type
    {
        LOCAL,
        REMOTE,
        ALL
    };

    struct FileDiffHandler
    {
        virtual void line(git_diff_line const &) = 0;

    protected:
        ~FileDiffHandler() = default;
    };

    struct AnnotatedCommit;

    struct Repository
    {
        Commit commit_lookup(git_oid const & oid) const;
        Tree tree_lookup(git_oid const & oid) const;
        Tag tag_lookup(git_oid const & oid) const;
        Blob blob_lookup(git_oid const & oid) const;

        git_oid merge_base(Revspec::Range const & range) const;
        git_oid merge_base(git_oid const &, git_oid const &) const;

        Revspec revparse(const char * spec) const;
        Revspec revparse_single(const char * spec) const;

        RevWalker rev_walker() const;

        git_status_t file_status(const char * filepath) const;

        Object entry_to_object(Tree::OwnedEntry) const;
        Object entry_to_object(Tree::BorrowedEntry) const;

        Index index() const;
        Odb odb() const;

        Diff diff(Tree &, Tree &, git_diff_options const &) const;
        Diff diff_to_index(Tree &, git_diff_options const &) const;
        Diff diff_to_workdir(Tree &, git_diff_options const &) const;
        Diff diff_to_workdir_with_index(Tree &, git_diff_options const &) const;
        Diff diff_index_to_workdir(git_diff_options const &) const;

        Signature signature() const;

        Status status(Status::Options const &) const;

        git_repository_state_t state() const;

        StrArray reference_list() const;

        std::vector<Reference> branches(branch_type, git_reference_t ref_kind = GIT_REFERENCE_ALL) const;

        Reference create_branch(const char * name, Commit const & target, bool force);

        /// @return can be empty
        Reference dwim(const char * shorthand) const;

        AnnotatedCommit annotated_commit_from_ref(Reference const &) const;
        AnnotatedCommit annotated_commit_lookup(git_oid const &) const;

        bool is_bare() const;

        Reference head() const;
        Reference ref(const char * name) const;

        Submodule submodule_lookup(const char * name) const;

        const char * path() const;
        const char * workdir() const;

        git_oid create_commit(const char * update_ref,
                              Signature const & author,
                              Signature const & commiter,
                              const char * message,
                              Tree const & tree,
                              const char * message_encoding = nullptr);

        git_oid create_commit(const char * update_ref,
                              Signature const & author,
                              Signature const & commiter,
                              const char * message,
                              Tree const & tree,
                              Commit const & parent,
                              const char * message_encoding = nullptr);

        void reset_default(Commit const &, git_strarray const & pathspecs);

        void file_diff(std::string const & old_path, git_oid const & old_id,
                       std::string const & new_path, git_oid const & new_id, FileDiffHandler &) const;

        StrArray remotes() const;
        Remote remote(const char * name) const;
        Remote create_remote(const char * name, const char * url);
        void delete_remote(const char * name);
        internal::optional<StrArray> rename_remote(const char * old_name, const char * new_name);
        void set_url    (const char * name, const char * url);
        void set_pushurl(const char * name, const char * url);

        /// @return raw error code
        int checkout_tree(Commit const &, git_checkout_options const &);
        int checkout_head(git_checkout_options const &);

        /// @return raw error code
        int set_head(char const* ref);
        int set_head_detached(git_oid const&);
        int set_head_detached(AnnotatedCommit const&);

        Blame blame_file(const char * path, git_blame_options const &);

        explicit Repository(const char * dir);
        explicit Repository(std::string const & dir);

        struct init_tag
        {};
        static const init_tag init;
        Repository(const char * dir, init_tag);
        Repository(const char * dir, init_tag, git_repository_init_options opts);
        Repository(std::string const & dir, init_tag);

        static internal::optional<std::string> discover(const char * start_path);

    private:
        struct Destroy { void operator() (git_repository *) const; };
        std::unique_ptr<git_repository, Destroy> repo_;
    };

    Object revparse_single(Repository const & repo, const char * spec);
}
