
#include <Wt/WLogger>
#include <Wt/Auth/Dbo/UserDatabase>
#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/Auth/PasswordVerifier>
#include <Wt/Auth/HashFunction>

#include "Session.hpp"
#include "User.hpp"

Wt::Auth::AuthService Session::_authService;
Wt::Auth::PasswordService Session::_passwordService(Session::_authService);

Session::Session(std::string const & sqliteDB) :
    _connection(sqliteDB)
{
    this->setConnection(this->_connection);

    this->mapClass<User>("user");
    this->mapClass<AuthInfo>("auth-info");
    this->mapClass<AuthInfo::AuthIdentityType>("auth-identity");
    this->mapClass<AuthInfo::AuthTokenType>("auth-token");

    try
    {
        this->createTables();
        Wt::log("info") << "Database have been generated";
    } catch (std::exception & e) {
        // Table already exists.
        Wt::log("info") << "Database have not been regenerated";
    }

    this->_users = new UserDatabase(*this);
}

void Session::configureAuth()
{
    // Auth service
    Session::_authService.setAuthTokensEnabled(true, "logincookie");
    Session::_authService.setEmailVerificationEnabled(false);

    // Password service
    Wt::Auth::PasswordVerifier * verifier = new Wt::Auth::PasswordVerifier();
    verifier->addHashFunction(new Wt::Auth::BCryptHashFunction(7));
    Session::_passwordService.setVerifier(verifier);
    Session::_passwordService.setAttemptThrottlingEnabled(true);
}

Wt::Auth::Login & Session::login()
{
    return this->_login;
}

Wt::Auth::Login const & Session::login() const
{
    return this->_login;
}

Wt::Auth::AbstractUserDatabase & Session::users()
{
    return *this->_users;
}

Wt::Auth::AbstractUserDatabase const & Session::users() const
{
    return *this->_users;
}

Wt::Auth::AuthService & Session::authService()
{
    return Session::_authService;
}

Wt::Auth::PasswordService & Session::passwordService()
{
    return Session::_passwordService;
}

