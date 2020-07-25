#pragma once

#include <cstdio>
#include <string>

#ifdef USE_BOOST
#include <boost/format.hpp>
#endif

namespace git {
namespace internal
{

#ifndef USE_BOOST
    template<typename... Args>
    std::string format(const char * fmt, Args&& ... args)
    {
        auto size = std::snprintf(nullptr, 0, fmt, args...);
        std::string result(size, 0);
        std::snprintf(&result[0], size + 1, fmt, args...);
        return result;
    }
#else
    inline boost::format & format_apply(boost::format & fmt)
    {
        return fmt;
    }

    template<typename T, typename... Args>
    boost::format & format_apply(boost::format & fmt, T && data, Args&& ... args)
    {
        return format_apply(fmt % data, std::forward<Args>(args)...);
    }

    template<typename... Args>
    std::string format(const char * fmt_str, Args&& ... args)
    {
        boost::format fmt(fmt_str);
        return str(format_apply(fmt, std::forward<Args>(args)...));
    }
#endif

}}
