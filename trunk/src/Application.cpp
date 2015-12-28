
#include <Wt/WContainerWidget>
#include <Wt/WBorderLayout>
#include <Wt/WFitLayout>
#include <Wt/WText>
#include <Wt/Dbo/backend/Sqlite3>

#include "Application.hpp"
#include "db/DbHandler.hpp"
#include "db/User.hpp"


Faith::Application::Application(Wt::WEnvironment const & env) :
    Wt::WApplication(env)
{
    this->setTitle("Faith");
    this->_session.setConnectionPool(Faith::Db::SingleDbHandler::getInstance()->getConnectionPool());

    Wt::Dbo::Transaction transaction(this->_session);
    Wt::Dbo::ptr<Faith::Db::User> joe = this->_session.find<Faith::Db::User>().where("name = ?").bind("Joe");
    std::cerr << "Joe has pwd: " << joe->password << std::endl;

    Wt::WContainerWidget *container = new Wt::WContainerWidget();
    Wt::WBorderLayout* layout = new Wt::WBorderLayout();
    layout->addWidget(new Wt::WText(joe->password), Wt::WBorderLayout::North);
    layout->addWidget(new Wt::WText("treeview"), Wt::WBorderLayout::West);
    layout->addWidget(new Wt::WText("description"), Wt::WBorderLayout::Center);
    layout->addWidget(new Wt::WText("footer"), Wt::WBorderLayout::South);
    container->setLayout(layout, Wt::AlignCenter);
    container->resize(Wt::WLength::Auto, Wt::WLength::Auto);
    this->root()->addWidget(container);
}

