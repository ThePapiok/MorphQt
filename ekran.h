#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>



struct rgb{
    int red;
    int green;
    int blue;
};

struct war{
    QImage im;
    rgb (*mix)(rgb,rgb);
    float alfa;
};
class Ekran : public QWidget
{
    Q_OBJECT
public:
        explicit Ekran(QWidget *parent = nullptr);
        void dylatacja();
        void erozja();
        void otwarcie();
        void domkniecie();
        void setValue(int);
protected:
        void paintEvent(QPaintEvent *);
private:
        QVector<war> lista;
        QImage im1,im2;
        int value=1;
signals:

};

#endif // EKRAN_H
