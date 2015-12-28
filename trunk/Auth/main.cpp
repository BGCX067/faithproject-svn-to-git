
#include <stdlib.h>
#include <Wt/WServer>

#include "AuthApplication.hpp"

Wt::WApplication* createApplication(Wt::WEnvironment const & env)
{
    return new AuthApplication(env);
}

int main(int ac, char** av)
{
    return Wt::WRun(ac, av, &createApplication);
}
