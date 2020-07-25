#pragma once

namespace git
{
    struct Initializer
    {
        Initializer();
        ~Initializer();

        Initializer(Initializer const &) = delete;
        Initializer & operator=(Initializer const &) = delete;
    };
}

#define auto_git_initializer            \
    ::git::Initializer git_initializer; \
    (void)git_initializer
