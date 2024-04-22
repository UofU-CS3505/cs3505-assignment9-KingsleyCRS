/********************************************************************************
** Form generated from reading UI file 'gamelosedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELOSEDIALOG_H
#define UI_GAMELOSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_GameLoseDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *GameLoseDialog)
    {
        if (GameLoseDialog->objectName().isEmpty())
            GameLoseDialog->setObjectName("GameLoseDialog");
        GameLoseDialog->resize(240, 320);
        buttonBox = new QDialogButtonBox(GameLoseDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(GameLoseDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 171, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(GameLoseDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 201, 61));

        retranslateUi(GameLoseDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, GameLoseDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GameLoseDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(GameLoseDialog);
    } // setupUi

    void retranslateUi(QDialog *GameLoseDialog)
    {
        GameLoseDialog->setWindowTitle(QCoreApplication::translate("GameLoseDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GameLoseDialog", "    You LOSE!!!", nullptr));
        label_2->setText(QCoreApplication::translate("GameLoseDialog", "Stay away from the fire and the monster", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLoseDialog: public Ui_GameLoseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELOSEDIALOG_H
