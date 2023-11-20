#include "mainwindow.h"
#include "startscreen.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QMessageBox>
#include <QTimer>
#include <QVBoxLayout>
#include <iostream>

int MainWindow::kInstanceCount = 0;
std::vector<std::pair<MainWindow *, std::string>> MainWindow::listOfTheWindows;

MainWindow::MainWindow(int userId, QString userName,
                       std::shared_ptr<Database> dbPtr, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_userId(userId),
      m_userName(userName) {
  ui->setupUi(this, userName);
  kInstanceCount++;
  if (dbPtr)
    m_dbPtr = dbPtr;
  else
    m_dbPtr = make_shared<Database>();

  auto timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &MainWindow::updateChats);
  timer->start(10);
}

MainWindow::~MainWindow() {
  delete ui;
  kInstanceCount--;
  if (kInstanceCount <= 0)
    qApp->exit(0);
}

MainWindow *MainWindow::createClient(std::shared_ptr<Database> dbPtr) {
  StartScreen s(dbPtr);
  auto result = s.exec();
  if (result == QDialog::Rejected) {
    return nullptr;
  }
  auto w = new MainWindow(s.userId(), s.userName(), s.getDatabase());
  w->setAttribute(Qt::WA_DeleteOnClose);

  listOfTheWindows.push_back(std::make_pair(w, s.userName().toStdString()));

  return w;
}

void MainWindow::on_messageLineEdit_returnPressed() {
  on_sendMessageButton_clicked();
}

void MainWindow::on_sendMessageButton_clicked() {
  m_dbPtr->addChatMessage(m_userName.toStdString(),
                          ui->messageLineEdit->text().toStdString());
}

void MainWindow::on_privateMessageSendButton_clicked() {
  QDialog dial(this);
  dial.setModal(true);
  auto *l = new QVBoxLayout();
  dial.setLayout(l);
  auto userListWgt = new QListWidget(&dial);
  l->addWidget(userListWgt);
  auto buttonBox = new QDialogButtonBox(
      QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dial);
  l->addWidget(buttonBox);

  connect(buttonBox, &QDialogButtonBox::accepted, &dial, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, &dial, &QDialog::reject);

  auto userList = m_dbPtr->getUserList();
  for (auto user : userList) {
    userListWgt->addItem(QString::fromStdString(user));
  }

  userListWgt->setCurrentRow(0);

  auto result = dial.exec();

  if (result == QDialog::Accepted && userListWgt->currentItem()) {
    m_dbPtr->addPrivateMessage(m_userName.toStdString(),
                               userListWgt->currentItem()->text().toStdString(),
                               ui->messageLineEdit->text().toStdString());
  }
}

void MainWindow::on_actionOpen_another_client_triggered() {
  auto w = createClient(m_dbPtr);
  w->show();
}

void MainWindow::on_actionClose_this_client_triggered() { this->close(); }

void MainWindow::updateChats() {
  auto chatMessages = m_dbPtr->getChatMessages();
  QString chat;
  for (const auto &msg : chatMessages) {
    chat.append(QString::fromStdString(msg) + "\n");
  }
  if (ui->commonChatBrowser->toPlainText() != chat)
    ui->commonChatBrowser->setText(chat);

  chat.clear();

  auto privateMessages = m_dbPtr->getPrivateMessage();

  for (const auto &msg : privateMessages) {
    if (QString::fromStdString(msg.getSender()) != m_userName &&
        msg.getDest() != m_userId)
      continue;

    QString prefix;

    if (m_userName == QString::fromStdString(msg.getSender()) &&
        m_userId == msg.getDest())
      prefix = "self message: ";
    else if (m_userName == QString::fromStdString(msg.getSender()))
      prefix = "message to" + QString(" <%1>: ").arg(QString::fromStdString(
                                  m_dbPtr->getUserName(msg.getDest())));
    else
      prefix = "<" + QString::fromStdString(msg.getSender()) +
               ">: " + "say to you: ";

    chat.append(prefix + QString::fromStdString(msg.getText()) + "\n");
  }
  if (ui->privateChatBrowser->toPlainText() != chat)
    ui->privateChatBrowser->setText(chat);
}

void MainWindow::on_banButton_clicked() {
  QDialog di(this);
  di.setModal(true);
  QVBoxLayout layou;
  QListWidget listWid(&di);
  layou.addWidget(&listWid);
  di.setLayout(&layou);

  auto userList = m_dbPtr->getUserList();

  QDialogButtonBox buBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &di);

  for (auto user : userList) {
    listWid.addItem(QString::fromStdString(user));
  }

  connect(&buBox, &QDialogButtonBox::accepted, [&]() {
    QString selectedUser = listWid.currentItem()->text();
    MainWindow *windowToBan = getListOfTheWindows(selectedUser.toStdString());
    if (windowToBan) {
      // Показываем сообщение о блокировке
      QMessageBox::information(windowToBan, "Блокировка",
                               "Вы заблокированы на 1 минуту");

      // Заблокировать окно на 1 минуту
      windowToBan->setEnabled(false);

      // Установить QTimer для разблокировки через 1 минуту
      QTimer::singleShot(60000, windowToBan,
                         [windowToBan]() { windowToBan->setEnabled(true); });
    }
  });

  connect(&buBox, &QDialogButtonBox::rejected, &di, &QDialog::reject);

  layou.addWidget(&buBox);

  di.exec();
}

void MainWindow::on_disconnectButton_clicked() {
  QDialog di(this);
  di.setModal(true);
  QVBoxLayout layou;
  QListWidget listWid(&di);
  layou.addWidget(&listWid);
  di.setLayout(&layou);

  auto userList = m_dbPtr->getUserList();

  QDialogButtonBox buBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &di);

  for (auto user : userList) {
    listWid.addItem(QString::fromStdString(user));
  }

  connect(&buBox, &QDialogButtonBox::accepted, [&]() {
    QString selectedUser = listWid.currentItem()->text();
    MainWindow *windowToClose = getListOfTheWindows(selectedUser.toStdString());
    if (windowToClose) {
      windowToClose->close(); // Закрыть окно, если оно найдено
    }
  });

  connect(&buBox, &QDialogButtonBox::rejected, &di, &QDialog::reject);

  layou.addWidget(&buBox);

  di.exec();
}

void MainWindow::on_correspondenceButton_clicked() {
  QDialog dial(this);
  dial.setModal(true);
  auto *l = new QVBoxLayout();
  dial.setLayout(l);
  auto userListWgt = new QListWidget(&dial);
  l->addWidget(userListWgt);
  auto buttonBox = new QDialogButtonBox(
      QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dial);
  l->addWidget(buttonBox);

  connect(buttonBox, &QDialogButtonBox::accepted, &dial, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, &dial, &QDialog::reject);

  auto userList = m_dbPtr->getUserList();
  for (auto user : userList) {
    userListWgt->addItem(QString::fromStdString(user));
  }

  userListWgt->setCurrentRow(0);

  auto result = dial.exec();

  if (result == QDialog::Accepted && userListWgt->currentItem()) {
    auto listOfMessages = m_dbPtr->getPrivateMessage(m_dbPtr->searchUserByName(
        userListWgt->currentItem()->text().toStdString()));
    QDialog di(this);
    di.setModal(true);
    QVBoxLayout layou;
    QListWidget listWid(&di);
    layou.addWidget(&listWid);
    di.setLayout(&layou);

    QDialogButtonBox buBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                           &di);

    connect(&buBox, &QDialogButtonBox::accepted, &di, &QDialog::accept);
    connect(&buBox, &QDialogButtonBox::rejected, &di, &QDialog::reject);

    layou.addWidget(&buBox);
    for (auto message : listOfMessages)
      listWid.addItem(QString::fromStdString("from " + message.getSender() +
                                             " >: " + message.getText()));

    di.exec();
  }
}

MainWindow *MainWindow::getListOfTheWindows(const std::string &name) const {
  for (const auto &vec : listOfTheWindows) {
    if (name.compare(vec.second) == 0)
      return vec.first;
  }
  return nullptr;
}
