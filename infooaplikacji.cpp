#include "infooaplikacji.h"
#include "ui_infooaplikacji.h"

InfoOAplikacji::InfoOAplikacji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoOAplikacji)
{
    ui->setupUi(this);
    ui->infolabel->setText("<h1>Aplikacja zaliczeniowa</h1> Autorem programu jest jej autor");
}

InfoOAplikacji::~InfoOAplikacji()
{
    delete ui;
}
