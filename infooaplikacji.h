#ifndef INFOOAPLIKACJI_H
#define INFOOAPLIKACJI_H

#include <QDialog>

namespace Ui {
class InfoOAplikacji;
}

class InfoOAplikacji : public QDialog
{
    Q_OBJECT

public:
    explicit InfoOAplikacji(QWidget *parent = 0);
    ~InfoOAplikacji();

private:
    Ui::InfoOAplikacji *ui;
};

#endif // INFOOAPLIKACJI_H
