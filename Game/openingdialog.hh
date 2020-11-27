#ifndef OPENINGDIALOG_HH
#define OPENINGDIALOG_HH

#include <QDialog>

namespace Ui {
class OpeningDialog;
}

class OpeningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpeningDialog(QWidget *parent = nullptr);
    ~OpeningDialog();
signals:
    void tellGameLenght(int lenght);
public slots:
    void endDialog();
private slots:

private:

    Ui::OpeningDialog *ui;
    int gameLenght_;
};

#endif // OPENINGDIALOG_HH
