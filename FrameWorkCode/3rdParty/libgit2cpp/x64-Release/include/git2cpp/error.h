#pragma once

#include <stdexcept>

#include "id_to_str.h"
#include "internal/format.h"

namespace git
{

    struct error_t : std::runtime_error
    {
        explicit error_t(std::string const & message)
            : std::runtime_error(message)
        {}
    };

    struct repository_open_error : error_t
    {
        repository_open_error(std::string const & dir)
            : error_t("Could not open repository on path " + dir)
        {}
    };

    struct repository_init_error : error_t
    {
        explicit repository_init_error(std::string const & dir)
            : error_t("Could not initialize repository on path " + dir)
        {}
    };

    struct index_open_error : error_t
    {
        index_open_error()
            : error_t("Could not open repository index")
        {}
    };

    struct odb_open_error : error_t
    {
        odb_open_error()
            : error_t("Could not open ODB")
        {}
    };

    struct commit_lookup_error : error_t
    {
        explicit commit_lookup_error(git_oid const & id)
            : error_t("Could not lookup commit " + id_to_str(id))
        {}
    };

    struct tree_lookup_error : error_t
    {
        explicit tree_lookup_error(git_oid const & id)
            : error_t("Could not lookup tree " + id_to_str(id))
        {}
    };

    struct tag_lookup_error : error_t
    {
        explicit tag_lookup_error(git_oid const & id)
            : error_t("Could not lookup tag " + id_to_str(id))
        {}
    };

    struct blob_lookup_error : error_t
    {
        explicit blob_lookup_error(git_oid const & id)
            : error_t("Could not lookup blob " + id_to_str(id))
        {}
    };

    struct submodule_lookup_error : error_t
    {
        explicit submodule_lookup_error(std::string const & name)
            : error_t("Could not lookup submodule " + name)
        {}
    };

    struct remote_lookup_error : error_t
    {
        explicit remote_lookup_error(std::string const & name)
            : error_t("Could not lookup remote " + name)
        {}
    };

    struct remote_delete_error : error_t
    {
        explicit remote_delete_error(std::string const & name)
            : error_t("Could not delete remote " + name)
        {}
    };

    struct remote_create_error : error_t
    {
        explicit remote_create_error(const char * name, const char * url)
            : error_t(internal::format("Could not create remote '%s', url='%s'", name, url))
        {}
    };

    struct remote_set_url_error : error_t
    {
        explicit remote_set_url_error(const char * name, const char * url)
            : error_t(internal::format("Could not set url '%s' for remote '%s'", url, name))
        {}
    };

    struct remote_set_pushurl_error : error_t
    {
        explicit remote_set_pushurl_error(const char * name, const char * url)
            : error_t(internal::format("Could not set pushurl '%s' for remote '%s'", url, name))
        {}
    };

    struct commit_parent_error : error_t
    {
        explicit commit_parent_error(git_oid const & id)
            : error_t("Could not get parent for commit " + id_to_str(id))
        {}
    };

    struct commit_tree_error : error_t
    {
        explicit commit_tree_error(git_oid const & id)
            : error_t("Could not get tree for commit " + id_to_str(id))
        {}
    };

    struct revparse_error : error_t
    {
        explicit revparse_error(const char * spec)
            : error_t(internal::format("Could not resolve %s", spec))
        {}
    };

    struct odb_read_error : error_t
    {
        explicit odb_read_error(git_oid const & id)
            : error_t("Could not find obj " + id_to_str(id))
        {}
    };

    struct odb_write_error : error_t
    {
        odb_write_error()
            : error_t("odb write error")
        {}
    };

    struct file_not_found_error : error_t
    {
        explicit file_not_found_error(const char * filepath)
            : error_t(internal::format("file path \"%s\" not found", filepath))
        {}
    };

    struct ambiguous_path_error : error_t
    {
        explicit ambiguous_path_error(const char * filepath)
            : error_t(internal::format("file path \"%s\" is ambiguous", filepath))
        {}
    };

    struct unknown_file_status_error : error_t
    {
        explicit unknown_file_status_error(const char * filepath)
            : error_t(internal::format("unknown error during getting status for file \"%s\"", filepath))
        {}
    };

    struct pathspec_new_error : error_t
    {
        pathspec_new_error()
            : error_t("Could not build pathspec")
        {}
    };

    struct revwalk_new_error : error_t
    {
        revwalk_new_error()
            : error_t("Could not create revision walker")
        {}
    };

    struct invalid_head_error : error_t
    {
        invalid_head_error()
            : error_t("Could not find repository HEAD")
        {}
    };

    struct non_commit_object_error : error_t
    {
        explicit non_commit_object_error(git_oid const & id)
            : error_t("object " + id_to_str(id) + " is not a commit")
        {}
    };

    struct unknown_get_current_branch_error : error_t
    {
        unknown_get_current_branch_error()
            : error_t("failed to get current branch")
        {}
    };

    struct get_status_error : error_t
    {
        get_status_error()
            : error_t("Could not get status")
        {}
    };

    struct signature_create_error : error_t
    {
        signature_create_error()
            : error_t("Unable to create a commit signature."
                      " Perhaps 'user.name' and 'user.email' are not set")
        {}
    };

    struct index_write_tree_error : error_t
    {
        index_write_tree_error()
            : error_t("Unable to write tree from index")
        {}
    };

    struct index_write_error : error_t
    {
        index_write_error()
            : error_t("Unable to write index")
        {}
    };

    struct commit_create_error : error_t
    {
        commit_create_error()
            : error_t("Could not create commit")
        {}
    };

    struct merge_base_error : error_t
    {
        merge_base_error(git_oid const & c1, git_oid const & c2)
            : error_t("Could not find merge base for commits " + id_to_str(c1, 8) + " and " + id_to_str(c2, 8))
        {}
    };

    struct config_open_error : error_t
    {
        config_open_error()
            : error_t("Could not open config")
        {}
    };

    struct branch_create_error : error_t
    {
        enum reason_t
        {
            already_exists,
            invalid_spec,
            unknown
        } reason;

        branch_create_error(reason_t r)
            : error_t("Could not create branch")
            , reason(r)
        {}
    };

    struct blame_file_error : error_t
    {
        explicit blame_file_error(std::string const & path)
            : error_t("Could not blame file " + path)
        {}
    };
}
