
#ifndef _FAITH_APPLICATION_HPP__
# define _FAITH_APPLICATION_HPP__

#include <Wt/WApplication>
#include <Wt/Dbo/Session>
#include "Session.hpp"

namespace Faith
{
    class Application : public Wt::WApplication
    {
        public:
            Application(Wt::WEnvironment const & env);

        private:
            Faith::Session _session;
    };
}

#endif // _FAITH_APPLICATION_HPP__

