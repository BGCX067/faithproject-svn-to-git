#ifndef  _FAITH_DB_USER_HPP__
#define  _FAITH_DB_USER_HPP__

#include <Wt/Dbo/Dbo>
#include <string>

namespace Faith
{
    namespace Db
    {
        class User
        {
            public:
                User() {}

            public:
                std::string name;
                std::string password;

                template<class Action>
                    void persist(Action& a)
                    {
                        Wt::Dbo::field(a, name,     "name");
                        Wt::Dbo::field(a, password, "password");
                    }
        };
    }
}

#endif // _FAITH_DB_USER_HPP__

