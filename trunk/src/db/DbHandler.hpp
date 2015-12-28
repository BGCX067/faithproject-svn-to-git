
#ifndef _FAITH_DB_DBHANDLER_HPP__
# define _FAITH_DB_DBHANDLER_HPP__

#include <string>
#include <memory>
#include <Wt/Dbo/SqlConnection>
#include <Wt/Dbo/FixedSqlConnectionPool>
#include <tools/Singleton.hpp>
#include "Session.hpp"

namespace Faith
{
    namespace Db
    {
        class DbHandler
        {
            public:
                void init(std::string const & connectionStr);
                Wt::Dbo::FixedSqlConnectionPool & getConnectionPool();

            private:
                std::unique_ptr<Wt::Dbo::FixedSqlConnectionPool> _connectionPool;
        };

        typedef Faith::Tools::Singleton<DbHandler> SingleDbHandler;
    }
}

#endif // _FAITH_DB_DBHANDLER_HPP__
