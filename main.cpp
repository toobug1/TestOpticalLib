#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include <QtGui/QTransform>
#include <math.h>

#include <Math/tvector2d.h>
#include <Math/tquaternion.h>

#include <Material/tschott.h>
#include <Material/tglass.h>
#include <Material/tdielectricbase.h>
#include <Material/tsellmeier1.h>

//#include <gsl/gsl_interp.h>
//#include <gsl/gsl_errno.h>
//#include <gsl/gsl_spline.h>

int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);

//    TSchott* b270 = new TSchott(20, "b270");

    double disp[6] = {1.03961212E+000, 6.00069867E-003, 2.31792344E-001,
                     2.00179144E-002, 1.01046945E+000, 1.03560653E+002};

    double temp[6] = {1.8600E-006, 1.3100E-008, -1.3700E-011,
                     4.3400E-007, 6.2700E-010, 1.7000E-001};

    TGlass gls(TDielectricBase::Sellmeier1, 20.0, "bk7",
               disp, 6, temp, 6);

    cout << gls.getGlassPtr()->getName().toStdString() << " : ";

    cout << gls.getRefractiveIndex(1550, 20.0);

    return a.exec();
}
