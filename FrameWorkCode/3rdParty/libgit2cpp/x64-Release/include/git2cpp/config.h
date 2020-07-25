#pragma once

#include <memory>
#include <string>
#include <stdexcept>

struct git_config;

namespace git
{
    struct Config
    {
        explicit Config(std::string const & filename);

        struct no_such_key_error : std::exception
        {
            explicit no_such_key_error(std::string key)
                : key_(std::move(key))
            {}

            const char * what() const noexcept override
            {
                return "no such key in config";
            }

            std::string const & key() const { return key_; }

        private:
            std::string key_;
        };

        std::string operator[](const char * key) const;

        int get_int(const char * key) const;

    private:
        struct Destroy { void operator() (git_config*) const; };
        std::unique_ptr<git_config, Destroy> cfg_;
    };
}
