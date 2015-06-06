#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imf.h"
#include <qwt_plot_curve.h>
#include <qwt_point_data.h>
#include <vector>
#include <cmath>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <qwt_symbol.h>

const float A1 = 0.256;
const float A2 = 0.137;
const float A3 = 0.137;

float f(float x);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->obliczIMF_button, SIGNAL(clicked()),this,SLOT(on_obliczIMF_button()));

    this->rysujWykresIMF();

}

void MainWindow::rysujWykresIMF()
{
    QString wynikObliczen = QString("Średnia masa w Galaktyce = %1 M_SUN <br/>");
    wynikObliczen += QString("liczba gwiazd pomiedzy 0.08 a 1 M_sun = %1 <br/>");
    wynikObliczen += QString("liczba gwiazd pomiedzy 1 a 8 M_sun = %1 <br/>");
    wynikObliczen += QString("liczba gwiazd pomiedzy 8 a 21 M_sun = %1 <br/>");
    wynikObliczen += QString("liczba gwiazd pomiedzy 21 a 150 M_sun = %1 <br/>");
    ui->label->setText(wynikObliczen);


    QwtPlot  *plot = ui->qwtPlot;
     plot->setTitle( "Stellar Initial Mass Function" );
     plot->setCanvasBackground( Qt::white );
     plot->insertLegend( new QwtLegend() );

     plot->setAxisAutoScale(QwtPlot::xBottom,true);
     plot->setAxisAutoScale(QwtPlot::yLeft,true);

     QwtPlotGrid *grid = new QwtPlotGrid();
     grid->attach( plot );

     QwtPlotCurve *curve = new QwtPlotCurve();
     curve->setTitle( "Alpha = - 1.3" );
     curve->setPen( Qt::blue, 4 ),
     curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

     QwtPlotCurve *curve1 = new QwtPlotCurve();
     curve1->setTitle( "Alpha = - 2.2" );
     curve1->setPen( Qt::red, 4 ),
     curve1->setRenderHint( QwtPlotItem::RenderAntialiased, true );

     QwtPlotCurve *curve2 = new QwtPlotCurve();
     curve2->setTitle( "Alpha = - 2.7" );
     curve2->setPen( Qt::green, 4 ),
     curve2->setRenderHint( QwtPlotItem::RenderAntialiased, true );

     QPolygonF points1, points2,points3;
     float x=0.08;
     while(x < log(150)){
         //points1 << QPointF(log(x),log(f(x)));

         if (x<0.5){
          points1 << QPointF(log(x),log(f(x)));
          }
         if ((x>=0.5)&&(x<1.)){
          points2 << QPointF(log(x),log(f(x)));
          }
         if ((x>=1.0)&&(x<=150.)){
          points3 << QPointF(log(x),log(f(x)));
          }

         x+=0.01;
     }

     curve->setSamples( points1 );
    curve1->setSamples( points2 );
      curve2->setSamples( points3 );
     curve->attach( plot );
     curve1->attach(plot);
     curve2->attach(plot);
     //plot->resize( 600, 400 );
     plot->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionInformacja_o_aplikacji_triggered()
{
    info = new InfoOAplikacji(this);
    info->setWindowTitle("Informacja o aplikacji");
    info->show();
}

void MainWindow::on_obliczIMF_button()
{
    Imf imf_wylicz;
    QString wynikObliczen = QString("Średnia masa w Galaktyce = %1 M_SUN <br/>").arg(imf_wylicz.sredniaMasa);
    wynikObliczen += QString("liczba gwiazd pomiedzy 0.08 a 1 M_sun = %1 <br/>").arg(imf_wylicz.starBetweenBDSun);
    wynikObliczen += QString("liczba gwiazd pomiedzy 1 a 8 M_sun = %1 <br/>").arg(imf_wylicz.starBetween18);
    wynikObliczen += QString("liczba gwiazd pomiedzy 8 a 21 M_sun = %1 <br/>").arg(imf_wylicz.starBetween821);
    wynikObliczen += QString("liczba gwiazd pomiedzy 21 a 150 M_sun = %1 <br/>").arg(imf_wylicz.starBetween21150);
    ui->label->setText(wynikObliczen);

}

float f(float x)
{
  float b;
  if (x<0.5){
   b=A1*pow(x,(-1.3));
   }
  if ((x>=0.5)&&(x<1.)){
   b=A2*pow(x,(-2.2));
   }
  if ((x>=1.0)&&(x<=150.)){
   b=A2*pow(x,-2.7);
   }
  return b;
}
