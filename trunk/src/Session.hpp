#ifndef  _FAITH_SESSION_HPP__
#define  _FAITH_SESSION_HPP__

#include <Wt/Dbo/Session>

namespace Faith
{
    class Session : public Wt::Dbo::Session
    {
        public:
            Session();
    };
}

#endif // _FAITH_SESSION_HPP__

