/********************************************************************************
** Form generated from reading UI file 'windialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDIALOG_H
#define UI_WINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_winDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *verticalSlider;
    QSlider *horizontalSlider;

    void setupUi(QDialog *winDialog)
    {
        if (winDialog->objectName().isEmpty())
            winDialog->setObjectName("winDialog");
        winDialog->resize(800, 800);
        buttonBox = new QDialogButtonBox(winDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(110, 760, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalSlider = new QSlider(winDialog);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(720, 630, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        horizontalSlider = new QSlider(winDialog);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(510, 700, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(winDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, winDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, winDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(winDialog);
    } // setupUi

    void retranslateUi(QDialog *winDialog)
    {
        winDialog->setWindowTitle(QCoreApplication::translate("winDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winDialog: public Ui_winDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDIALOG_H
