/*
** main.cpp for Plazza
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Wed Apr 12 11:08:54 2017 gastal_r
** Last update	Sat Apr 15 19:43:08 2017 gastal_r
*/
#include <QApplication>
#include    "Orders.hpp"
#include    "Mutex.hpp"
#include    "ScopedLock.hpp"
#include    "Thread.hpp"
#include    "CondVar.hpp"
#include    "SafeQueue.hpp"
#include    "Plazza.hpp"
#include    "MainWindow.hpp"

int		main(int ac, char *av[])
{
  if (ac != 2)
  {
    std::cout << "Usage: " << av[0] << " [threads numbers per process]" << "\n";
    return (0);
  }
  else if (std::stoi(av[1]) <= 0)
  {
    std::cout << "Thread number need to be positive" << "\n";
    return (0);
  }

  QApplication app(ac, av);

  MainWindow win;

  win.show();
Orders	order;
  Plazza  plazza;
  for (std::string line; std::getline(std::cin, line);)
    {
      //std::cout << "line == " << line << std::endl;
      order.clear();
      if (order.parseLine(line) == -1)
	     return -1;
    }
  plazza.dividOrders(order.getOrders(), std::stoi(av[1]));
  return (app.exec());
}