#include "editstore_window.h"
#include "editting_form.h"
#include "qmessagebox.h"
#include "ui_editstore_window.h"

editstore_window::editstore_window(StoreModel *modelForEditing, int value, QWidget *parent) :
    modelForEditing(modelForEditing),
    value(value),
    QWidget(parent),
    ui(new Ui::editstore_window)
{
    ui->setupUi(this);
    if (value < modelForEditing->stores.size())
        ui->lineEdit->setText(QString::number(value));
}

editstore_window::~editstore_window()
{
    delete ui;
}

void editstore_window::on_pushButton_clicked()
{
        QMessageBox msgBox;
        std::vector<QVariant> stack;
        int toEditId;
        QString checker;
        checker = ui->lineEdit->text();
        bool flag = true;
        if (!(modelForEditing->fieldChecker(checker)))
        {
            msgBox.setText("You are not allowed to edit added stores with NaN ID");
            msgBox.setStandardButtons(QMessageBox::Close);
            msgBox.setDefaultButton(QMessageBox::Close);
            msgBox.setWindowTitle("ERROR");
            msgBox.exec();
            flag = false;
        }

        if (flag)
        {
            toEditId = (ui->lineEdit->text()).toInt();
            editting_form *editor_form = new editting_form(toEditId, modelForEditing);
            editor_form->show();
        }




}

