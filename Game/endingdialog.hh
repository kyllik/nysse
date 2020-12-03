#ifndef ENDINGDIALOG_HH
#define ENDINGDIALOG_HH

#include <QDialog>

namespace Ui {
class EndingDialog;
}

class EndingDialog : public QDialog
{
    Q_OBJECT
signals:
    void closeGame();
public:
    void showScore(int n);
    explicit EndingDialog(QWidget *parent = nullptr);
    ~EndingDialog();
public slots:
    void tellCloseGame();
private:
    Ui::EndingDialog *ui;
};

#endif // ENDINGDIALOG_HH
