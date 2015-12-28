
#include <iostream>
#include <exception>

#include <Wt/WLogger>
#include <Wt/Dbo/backend/Sqlite3>

#include "db/DbHandler.hpp"
#include "db/User.hpp"

void Faith::Db::DbHandler::init(std::string const & connectionStr)
{
    this->_connectionPool.reset(new Wt::Dbo::FixedSqlConnectionPool(
        new Wt::Dbo::backend::Sqlite3(connectionStr),
        100
    ));

    Faith::Session session;
    session.setConnectionPool(*this->_connectionPool);
    try {
        session.createTables();
        Wt::log("info") << "Database generated";
    } catch (std::exception const & e) {
        Wt::log("info") << "Database already exists";
    }

    Wt::Dbo::Transaction transaction(session);
    Faith::Db::User * user = new Faith::Db::User();
    user->name = "Joe";
    user->password = "Secret";
    Wt::Dbo::ptr<Faith::Db::User> userPtr = session.add(user);
    transaction.commit();
}

Wt::Dbo::FixedSqlConnectionPool & Faith::Db::DbHandler::getConnectionPool()
{
    if (!this->_connectionPool)
        throw std::runtime_error("DbHandler._connectionPool does not exist");
    return (*this->_connectionPool);
}

