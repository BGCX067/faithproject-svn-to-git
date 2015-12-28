
#ifndef _FAITH_SESSION_HPP__
# define _FAITH_SESSION_HPP__

# include <Wt/Dbo/Session>
# include <Wt/Dbo/backend/Sqlite3>
# include <Wt/Auth/AuthService>
# include <Wt/Auth/PasswordService>
# include <Wt/Auth/Login>

# include "User.hpp"

typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

class Session : public Wt::Dbo::Session
{
    public:
        Session(std::string const & sqliteDB);

    public:
        static void configureAuth();

    public:
        Wt::Auth::Login & login();
        Wt::Auth::Login const & login() const;
        Wt::Auth::AbstractUserDatabase & users();
        Wt::Auth::AbstractUserDatabase const & users() const;
        static Wt::Auth::AuthService & authService();
        static Wt::Auth::PasswordService & passwordService();

    private:
        Wt::Dbo::backend::Sqlite3 _connection;
        UserDatabase * _users;
        Wt::Auth::Login _login;

    private:
        static Wt::Auth::AuthService _authService;
        static Wt::Auth::PasswordService _passwordService;
};

#endif // _FAITH_SESSION_HPP__

