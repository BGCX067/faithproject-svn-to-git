#include "Session.hpp"
#include "db/User.hpp"

Faith::Session::Session()
{
    this->mapClass<Faith::Db::User>("user");
}

