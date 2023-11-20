#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Database.h"
#include <QtWidgets/QMainWindow>
#include <memory>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(int userId, QString userName,
             std::shared_ptr<Database> dbPtr = nullptr,
             QWidget *parent = nullptr);

  ~MainWindow();

  static MainWindow *createClient(std::shared_ptr<Database> dbPtr = nullptr);

  static int kInstanceCount;

  MainWindow *getListOfTheWindows(const std::string &) const;
  static std::vector<std::pair<MainWindow *, std::string>> listOfTheWindows;

private slots:
  void on_messageLineEdit_returnPressed();

  void on_sendMessageButton_clicked();

  void on_privateMessageSendButton_clicked();

  void on_actionOpen_another_client_triggered();

  void on_actionClose_this_client_triggered();

  void updateChats();

  void on_banButton_clicked();

  void on_disconnectButton_clicked();

  void on_correspondenceButton_clicked();

private:
  Ui::MainWindow *ui;
  std::shared_ptr<Database> m_dbPtr;
  int m_userId;
  QString m_userName;
};
#endif // MAINWINDOW_H
