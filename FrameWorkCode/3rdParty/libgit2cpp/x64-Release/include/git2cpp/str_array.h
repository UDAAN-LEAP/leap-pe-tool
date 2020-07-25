#pragma once

#include <git2/strarray.h>

#include <cstring>

namespace git
{
    struct StrArray
    {
        explicit StrArray(git_strarray const & str_array)
            : str_array_(str_array)
        {}

        StrArray(StrArray const &) = delete;
        StrArray& operator =(StrArray const &) = delete;

        StrArray(StrArray && other) noexcept
            : str_array_(other.str_array_)
        {
            std::memset(&other.str_array_, 0, sizeof(git_strarray));
        }

        StrArray& operator =(StrArray && other) noexcept
        {
            std::swap(str_array_, other.str_array_);
            return *this;
        }

        size_t count() const { return str_array_.count; }

        const char * operator[](size_t i) const
        {
            return str_array_.strings[i];
        }

        ~StrArray()
        {
            git_strarray_free(&str_array_);
        }

    private:
        git_strarray str_array_;
    };
}
