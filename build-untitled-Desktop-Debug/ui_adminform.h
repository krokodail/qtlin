/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *loginLineEdit;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptButton;
    QPushButton *registerButton;
    QPushButton *loginButton;

    void setupUi(QWidget *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName(QString::fromUtf8("AdminForm"));
        AdminForm->resize(750, 166);
        verticalLayout = new QVBoxLayout(AdminForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        loginLineEdit = new QLineEdit(AdminForm);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, loginLineEdit);

        label_2 = new QLabel(AdminForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordLineEdit = new QLineEdit(AdminForm);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        label_3 = new QLabel(AdminForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(AdminForm);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label = new QLabel(AdminForm);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        acceptButton = new QPushButton(AdminForm);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        horizontalLayout->addWidget(acceptButton);

        registerButton = new QPushButton(AdminForm);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        horizontalLayout->addWidget(registerButton);

        loginButton = new QPushButton(AdminForm);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdminForm);

        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QWidget *AdminForm)
    {
        AdminForm->setWindowTitle(QApplication::translate("AdminForm", "Form", nullptr));
        label_2->setText(QApplication::translate("AdminForm", "Password:", nullptr));
        label_3->setText(QApplication::translate("AdminForm", "Confirm:", nullptr));
        label->setText(QApplication::translate("AdminForm", "Login:", nullptr));
        acceptButton->setText(QApplication::translate("AdminForm", "ok", nullptr));
        registerButton->setText(QApplication::translate("AdminForm", "registration", nullptr));
        loginButton->setText(QApplication::translate("AdminForm", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
