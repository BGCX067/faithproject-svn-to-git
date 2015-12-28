
#ifndef _FAITH_AUTHAPPLICATION_HPP__
# define _FAITH_AUTHAPPLICATION_HPP__

#include <Wt/WApplication>

#include "Session.hpp"

class AuthApplication : public Wt::WApplication
{
    public:
        AuthApplication(Wt::WEnvironment const & env);

    public:
        void authEvent();

    private:
        Session _session;
};

#endif // _FAITH_AUTHAPPLICATION_HPP__

