#include "shadowwindow.h"

#include <QPainter>

ShadowWindow::ShadowWindow( QWidget * parent )
    : QWidget( parent )
{
    setWindowFlags( Qt::Tool | Qt::FramelessWindowHint );
    setAttribute( Qt::WA_TranslucentBackground );

    layout = new QVBoxLayout();
    layout->setContentsMargins( 9, 9, 9, 9 );
    layout->setSpacing( 0 );
    setLayout( layout );

    shadowPixmap.load( ":/shadow" );
}

void ShadowWindow::paintEvent( QPaintEvent * event )
{
    QPainter painter( this );
    painter.drawPixmap( 0, 0, shadowPixmap, 0, 0, 14, 14 );
    painter.drawPixmap( 14, 0, width() - 28, 14, shadowPixmap, 14, 0, 1, 14 );
    painter.drawPixmap( width() - 14, 0, shadowPixmap, 15, 0, 14, 14 );

    painter.drawPixmap( 0, 14, 14, height() - 28, shadowPixmap, 0, 14, 14, 1 );
    painter.drawPixmap( 0, height() - 14, shadowPixmap, 0, 15, 14, 14 );

    painter.drawPixmap( width() - 14, 14, 14, height() - 28, shadowPixmap, 15, 14, 14, 1 );
    painter.drawPixmap( width() - 14, height() - 14, shadowPixmap, 15, 15, 14, 14 );

    painter.drawPixmap( 14, height() - 14, width() - 28, 14,  hadowPixmap, 15, 15, 1, 14 );

    QWidget::paintEvent( event );
}
