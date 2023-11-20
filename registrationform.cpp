#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>

RegistrationForm::RegistrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::on_loginButton_clicked()
{
    emit loginRequested();
}

void RegistrationForm::on_buttonBox_rejected()
{
    emit rejected();
}

void RegistrationForm::on_buttonBox_accepted()
{
    if(ui -> passwordEdit -> text() !=
            ui -> passwordConfirmEdit -> text())
    {
        QMessageBox::critical(this, tr("error"),
                              tr("Passwords not match"));
        return;
    }
    auto userId = m_dbPtr -> addUser(ui ->loginEdit->text().toStdString(),
                       ui -> passwordEdit->text().toStdString());
    switch(userId)
    {
    case -1:
        QMessageBox::critical(this, tr("error"),
                              tr("Incorrect Login"));
        return;

    case -2:
        QMessageBox::critical(this, tr("error"),
                              tr("Login already exists"));
        return;

        default:     emit accepted(userId, ui -> loginEdit -> text());
    }

}

void RegistrationForm::setDatabase(std::shared_ptr<Database> dbPtr)
{
    m_dbPtr = dbPtr;
}
