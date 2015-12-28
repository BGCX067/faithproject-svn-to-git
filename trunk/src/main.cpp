
#include <Wt/WServer>

#include "Application.hpp"
#include "db/DbHandler.hpp"

Wt::WApplication* createApplication(Wt::WEnvironment const & env)
{
    return new Faith::Application(env);
}

int main(int ac, char** av)
{
    Faith::Db::SingleDbHandler::getInstance()->init("faith.sqlite");
    return Wt::WRun(ac, av, &createApplication);
}
