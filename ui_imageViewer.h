/********************************************************************************
** Form generated from reading ui file 'imageViewer.ui'
**
** Created: Sat Jan 30 14:29:23 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(527, 475);
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 3, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 3, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 7, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 7, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 5, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Aksharyogini"));
        font.setPointSize(16);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(14);
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 0, 7, 1, 1);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        QWidget::setTabOrder(pushButton_11, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_10);
        QWidget::setTabOrder(pushButton_10, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_4);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form", "Control Panel", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Form", "Zoom In", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "Zoom Out", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Form", "Right", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Form", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Form", "Up", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Form", "Clock Wise", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Form", "Anti Clock Wise", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Form", "Down", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Zoom", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Pan", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Rotate", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("Form", "Open", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "Quit", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Form", "Clear", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
