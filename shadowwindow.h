#ifndef SHADOWWINDOW_H
#define SHADOWWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
#include <QVBoxLayout>

class ShadowWindow : public QWidget
{
    Q_OBJECT
    
public:
    ShadowWindow( QWidget * parent = 0 );

private:
    QVBoxLayout * layout;
    QPixmap shadowPixmap;

protected:
    void paintEvent( QPaintEvent * event );
};

#endif // SHADOWWINDOW_H
