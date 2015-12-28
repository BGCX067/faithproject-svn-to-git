
#ifndef _FAITH_USER_HPP__
# define _FAITH_USER_HPP__

# include <Wt/Dbo/Dbo>
# include <Wt/WGlobal>

class User;

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

class User
{
    public:
        User() {}

        template <class Action>
        void persist(Action&) {}
};

#endif // _FAITH_USER_HPP__

