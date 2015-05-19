#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include <QtGui/QTransform>
#include <math.h>

#include <Math/tvector2d.h>
#include <Math/tquaternion.h>

#include <Material/tschott.h>
#include <Material/tglass.h>

//#include <gsl/gsl_interp.h>
//#include <gsl/gsl_errno.h>
//#include <gsl/gsl_spline.h>

int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);

    TSchott* b270 = new TSchott(20, "b270");

    double arr[6] = {2.28657500E+000, -8.73345820E-003, 1.17428840E-002,
                     2.90417560E-004, -1.25066950E-005, 9.26462530E-007};

    b270->setDispCoeff(arr, 6);


//    double n_tem = b270.get_refractive_index(1550, 20.0, 1.2);
    b270->setWave(330, 2700);

    double n_std = b270->get_refractive_index(1550);

    cout << b270->getName().toStdString() << ":" << n_std << endl;

    double* disp = new double[10];
    double* temp = new double[10];

    b270->getDispCoeff(disp);
    b270->getTempCoeff(temp);

    TGlass gls(TDielectricBase::Schott, 20, "b270",
               disp, 10, temp, 10);

    double n_c = gls.getGlassPtr()->get_refractive_index(1550, 20);

    cout << n_c << endl;

    delete [] disp;
    delete [] temp;
    delete b270;

//    TVector2D vec(3.2, 4.5);
//    TVector4D vec4(vec);
//    vec4.normalize();

//    TQuaternion t(vec4);

//    qDebug() << vec << endl;
//    qDebug() << vec4 << endl << t << endl;

//    QTransform trans;

//    qDebug() << trans << endl;

//    trans.scale(2, 2);

//    qDebug() << trans << endl;

//    trans.rotate(30);

//    qDebug() << trans << endl;

//    double x[4] = {1, 2, 3, 4};
//    double y[4] = {2, 4, 6, 8};

//    gsl_interp_accel* acc = gsl_interp_accel_alloc();

//    gsl_interp* lineInter = gsl_interp_alloc(gsl_interp_linear, 4);

//    gsl_interp_init(lineInter, x, y, 4);

//    double rslt[4];

//    int i = 0;
//    for (double xi = x[0]; xi < x[3] && i < 4; xi += 0.1, ++i)
//    {
//        rslt[i] = gsl_interp_eval(lineInter, x, y, xi, acc);
//        cout << rslt[i] << endl;
//    }

//    double xa = gsl_interp_eval(lineInter, x, y, 3.5, acc);

//    cout << xa << endl;


//    QString str = QString("%1 : %2").arg("求得的职位:").arg(rslt);
//    cout << str.data() << endl;

//    cout << gsl_interp_name(lineInter) << endl;
//    cout << gsl_interp_min_size(lineInter) << endl;


//    gsl_interp_free(lineInter);
//    gsl_interp_accel_free(acc);


//    int i;
//    double xi, yi, x[10], y[10];

//    printf ("#m=0,S=2\n");
//    for (i = 0; i < 10; i++)
//    {
//    x[i] = i + 0.5 * sin (i);
//    y[i] = i + cos (i * i);
//    printf ("%g %g\n", x[i], y[i]);
//    }
//    printf ("#m=1,S=0\n");
//    {
//    gsl_interp_accel *acc
//    = gsl_interp_accel_alloc ();
//    gsl_spline *spline
//    = gsl_spline_alloc (gsl_interp_cspline, 10);
//    gsl_spline_init (spline, x, y, 10);
//    for (xi = x[0]; xi < x[9]; xi += 0.01)
//    {
//    yi = gsl_spline_eval (spline, xi, acc);
//    printf ("%g %g\n", xi, yi);
//    }
//    gsl_spline_free (spline);
//    gsl_interp_accel_free (acc);
//    }
    return a.exec();
}
