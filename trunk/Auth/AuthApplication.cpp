
#include <Wt/Auth/AuthWidget>
#include <Wt/WContainerWidget>

#include "AuthApplication.hpp"

AuthApplication::AuthApplication(Wt::WEnvironment const & env) :
    Wt::WApplication(env),
    _session(appRoot() + "faith.db")
        
{
    this->_session.login().changed().connect(this, &AuthApplication::authEvent);

    this->setTitle("Faith");
    // this->useStyleSheet("maCSS.css");

    Wt::Auth::AuthWidget * authWidget = new Wt::Auth::AuthWidget(Session::authService(), this->_session.users(), this->_session.login());
    //authWidget->addPasswordAuth(&Session::passwordService());
    // authWidget->setRegistrationEnabled(true); // A virer ! :P
    authWidget->processEnvironment();
    this->root()->addWidget(authWidget);
}

void AuthApplication::authEvent()
{
    if (this->_session.login().loggedIn())
        std::cout << "user logged in" << std::endl;
    else
        std::cout << "user logegd out" << std::endl;
}
