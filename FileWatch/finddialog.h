#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

private slots:

    void on_btnFind_clicked();

private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
