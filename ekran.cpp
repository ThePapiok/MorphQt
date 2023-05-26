#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <QImage>
#include <iostream>

using namespace std;

Ekran::Ekran(QWidget *parent)
    : QWidget{parent}
{
    im1=QImage(":/zdj/img.png");
    im2=QImage(1200, 8000, QImage::Format_RGB32);
    im2.fill(0);
}


void Ekran::dylatacja()
{
    QRgb kolor;
    QRgb bialy=qRgb(255,255,255);
    bool wyjdz;
    for(int i=0;i<im1.height();i++)
    {
        for(int j=0;j<im1.width();j++)
        {
            wyjdz=false;
            for(int k=i-value;k<=i+value;k++)
            {
                for(int l=j-value;l<=j+value;l++)
                {
                    if(k>=0&&k<im1.height()&&l>=0&&l<im1.width()&&(k!=i||l!=j))
                    {
                        kolor=im1.pixel(l,k);
                        if(kolor==qRgb(255,255,255))
                        {
                            im2.setPixel(j,i,bialy);
                            wyjdz=true;
                            break;
                        }
                    }
                }
                if(wyjdz)
                {
                    break;
                }
            }
        }
    }
    im1=im2;
    im2.fill(0);
    update();

}




void Ekran::erozja()
{
    bool wszystkie;
    QRgb kolor;
    QRgb bialy=qRgb(255,255,255);
    for(int i=0;i<im1.height();i++)
    {
        for(int j=0;j<im1.width();j++)
        {
            wszystkie=true;
            for(int k=i-value;k<=i+value;k++)
            {
                for(int l=j-value;l<=j+value;l++)
                {
                    if(k>=0&&k<im1.height()&&l>=0&&l<im1.width()&&(k!=i||l!=j))
                    {
                        kolor=im1.pixel(l,k);
                        if(kolor!=qRgb(255,255,255))
                        {
                            wszystkie=false;
                            break;
                        }
                    }
                }
                if(!wszystkie)
                {
                    break;
                }
            }
            if(wszystkie)
            {
                im2.setPixel(j,i,bialy);
            }
        }
    }
    im1=im2;
    im2.fill(0);
    update();
}

void Ekran::otwarcie()
{
    erozja();
    dylatacja();
}

void Ekran::domkniecie()
{
    dylatacja();
    erozja();
}

void Ekran::setValue(int a)
{
    value=a;
}

void Ekran::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0,0,im1);
}
