#pragma once

#ifdef USE_BOOST
    #include <boost/optional.hpp>
    #include <boost/utility/typed_in_place_factory.hpp>
    #define GIT_USE_BOOST_OPTIONAL

#elif defined(__has_include) && __has_include(<optional>)
    #include <optional>
    #define GIT_USE_STD_OPTIONAL

#elif defined(__has_include) && __has_include(<experimental/optional>)
    #include <experimental/optional>
    #define GIT_USE_STD_EXPERIMENTAL_OPTIONAL

#else
    #include <memory>
    #include <cstddef>
#endif

namespace git {
namespace internal
{
#if defined(GIT_USE_BOOST_OPTIONAL)
    #undef GIT_USE_BOOST_OPTIONAL
    using boost::optional;
    using boost::none_t;
    using boost::none;

    template<typename T, typename ...Args>
    optional<T> & emplace(optional<T> & opt, Args&&... args)
    {
        opt = boost::in_place<T>(std::forward<Args>(args)...);
        return opt;
    }

    template<typename T>
    bool has_value(optional<T> const & opt)
    {
        return opt.is_initialized();
    }

#elif defined(GIT_USE_STD_OPTIONAL)
    #undef GIT_USE_STD_OPTIONAL
    using std::optional;
    using none_t = std::nullopt_t;
    const none_t none = std::nullopt;

    template<typename T, typename ...Args>
    optional<T> & emplace(optional<T> & opt, Args&&... args)
    {
        opt.emplace(std::forward<Args>(args)...);
        return opt;
    }

    template<typename T>
    bool has_value(optional<T> const & opt)
    {
        return opt.has_value();
    }

#elif defined(GIT_USE_STD_EXPERIMENTAL_OPTIONAL)
    #undef GIT_USE_STD_EXPERIMENTAL_OPTIONAL
    using std::experimental::optional;
    using none_t = std::experimental::nullopt_t;
    const none_t none = std::experimental::nullopt;

    template<typename T, typename ...Args>
    optional<T> & emplace(optional<T> & opt, Args&&... args)
    {
        opt.emplace(std::forward<Args>(args)...);
        return opt;
    }

    template<typename T>
    bool has_value(optional<T> const & opt)
    {
        return static_cast<bool>(opt);
    }

#else
    typedef std::nullptr_t none_t;
    const none_t none = nullptr;

    //Simple (and incomplete) optional implementations
    template<typename T>
    class optional
    {
    private: //type alias
        typedef typename std::aligned_storage<sizeof(T), alignof(T)>::type StorageT;

    public: //type traits
        enum non_movable_t{};
        enum non_copyable_t{};

        static const bool movable = std::is_move_constructible<T>::value && std::is_move_assignable<T>::value;
        static const bool copyable = std::is_copy_constructible<T>::value && std::is_copy_assignable<T>::value;
        typedef typename std::conditional<movable, T, non_movable_t>::type MovableT;
        typedef typename std::conditional<copyable, T, non_copyable_t>::type CopyableT;

    public: //initializing and attribution
        constexpr optional(none_t t = none)
            : initialized(false)
        {}

        optional(T const & v) { assign(v);}
        optional(T      && v) { assign(std::move(v));}

        optional(optional const &  other) { assign(other);}
        optional(optional       && other) { assign(std::move(other));}

        optional & operator=(none_t none)  { reset(); return *this;}
        optional & operator=(T && v)       { return assign(std::move(v));}
        optional & operator=(const T & v)  { return assign(v);}

        optional & operator=(optional const &  other){ return assign(other);}
        optional & operator=(optional       && other){ return assign(std::move(other));}

        ~optional() { reset(); }

    public: //getting value

        T const & value()        const { return reinterpret_cast<T const &>(storage); }
        T       & value()              { return reinterpret_cast<T &>(storage); }

        T const & operator*  ()  const { return value(); }
        T       & operator * ()        { return value(); }

        T const * operator -> () const { return &value(); }
        T       * operator -> ()       { return &value(); }

    public: //querying state

        explicit operator bool() const { return initialized; }

    public: //change state
        void reset()
        {
            if (initialized)
            {
                value().~T();
                initialized = false;
            }
        }

        template<typename ...Args>
        void emplace(Args&&... args){
            if (initialized)
                reset();
            init(std::forward<Args>(args)...);
        }

    private: //assign
        optional & assign(MovableT && value)   {
            return set_from_value(std::move(value));
        }
        optional & assign(CopyableT const & value)  {
            return set_from_value(value);
        }
        optional & assign(optional const & other)  {
            return set_or_reset(other.value(), other.initialized);
        }
        optional & assign(optional && other)  {
            return set_or_reset(std::move(other.value()), other.initialized);
        }

    protected:
        template<typename U>
        optional & set_or_reset(U&& u, bool isValid)
        {
            if (isValid)
                set_from_value(std::forward<U>(u));
            else
                reset();

            return *this;
        }

        template<typename U>
        optional & set_from_value(U&& u)
        {
            if (initialized)
                reinterpret_cast<T&>(storage) = std::forward<U>(u);
            else
                init(std::forward<U>(u));

            return *this;
        }

        template<typename ...Args>
        void init(Args&& ... args){
            new (&storage) T(std::forward<Args>(args)...);
            initialized = true;
        }

    protected:
        StorageT storage;
        bool initialized;
    };

    template<typename T, typename ...Args>
    optional<T> & emplace(optional<T> & opt, Args&&... args){
        opt.emplace(std::forward<Args>(args)...);
        return opt;
    }

    template<typename T>
    bool has_value(optional<T> const & opt)
    {
        return static_cast<bool>(opt);
    }
#endif

}}//namespace git
