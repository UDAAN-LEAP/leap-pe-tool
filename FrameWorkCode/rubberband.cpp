#include "rubberband.h"

#include <QPainter>
#include <QMap>
#include <QMouseEvent>
#include <QSize>
#include <QPointF>
#include <QRectF>

RubberBand::RubberBand(QWidget *parent)
    : QWidget{parent}
{
    m_moveEnabled = true;
    m_gripSize = QSize(8, 8);
    m_gripColor = QColor(Qt::blue);
    m_dragPos = QPointF();
    m_dragGrip = NoGrip;
}

bool RubberBand::isMoveEnabled() const
{
    return m_moveEnabled;
}

void RubberBand::setMoveEnabled(bool enabled)
{
    m_moveEnabled = enabled;
}

QSize RubberBand::gripSize() const
{
    return m_gripSize;
}

void RubberBand::setGripSize(const QSize &size)
{
    if (m_gripSize != size && size.isValid()) {
        m_gripSize = size;
        update();
    }
}

QColor RubberBand::gripColor() const
{
    return m_gripColor;
}

void RubberBand::setGripColor(const QColor &color)
{
    if (m_gripColor != color) {
        m_gripColor = color;
        update();
    }
}

void RubberBand::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QMap<Grip, QRectF> positions = gripPositions();
    QPainter painter(this);

    if (!m_dragPos.isNull()) {
        painter.setPen(QPen(m_gripColor, 1, Qt::SolidLine));
        painter.drawRect(0, 0, size().width() - 1, size().height() - 1);
    }

    for (const QRectF &rc : positions.values()) {
        painter.fillRect(rc, QBrush(m_gripColor));
    }
}

void RubberBand::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isVisible()) {
        QMap<Grip, QRectF> positions = gripPositions();
        QPoint pos = event->pos();

        for (const Grip &key : positions.keys()) {
            const QRectF &rc = positions.value(key);

            if (rc.contains(pos)) {
                m_dragPos = event->windowPos();
                m_dragGrip = key;
                break;
            }
        }

        if (m_dragGrip == NoGrip && m_moveEnabled) {
            m_dragPos = event->windowPos();
        }
    }
}

void RubberBand::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragPos.isNull()) {
        QPoint pos = event->pos();
        QMap<Grip, QRectF> positions = gripPositions();

        for (const Grip &key : positions.keys()) {
            const QRectF &rc = positions.value(key);

            if (rc.contains(pos)) {
                switch (key) {
                case NoGrip:
                    break;
                case Left:
                case Right:
                    setCursor(Qt::SizeHorCursor);
                    break;
                case TopMiddle:
                case BottomMiddle:
                    setCursor(Qt::SizeVerCursor);
                    break;
                case TopLeft:
                case BottomRight:
                    setCursor(Qt::SizeFDiagCursor);
                    break;
                case TopRight:
                case BottomLeft:
                    setCursor(Qt::SizeBDiagCursor);
                    break;
                }
                break;
            } else {
                setCursor(Qt::ArrowCursor);
            }
        }
    } else {
        QPointF pos = event->windowPos();
        QRectF rc = geometry();
        QRectF prevGeo = rc;

        switch(m_dragGrip) {
        case NoGrip:
            rc.moveLeft(rc.left() + pos.rx() - m_dragPos.rx());
            rc.moveTop(rc.top() + pos.ry() - m_dragPos.ry());
            break;
        case BottomRight:
            rc.setWidth(rc.width() + pos.rx() - m_dragPos.rx());
            rc.setHeight(rc.height() + pos.ry() - m_dragPos.ry());
            break;
        case TopLeft:
            rc.setLeft(rc.left() + pos.rx() - m_dragPos.rx());
            rc.setTop(rc.top() + pos.ry() - m_dragPos.ry());
            break;
        case TopMiddle:
            rc.setTop(rc.top() + pos.ry() - m_dragPos.ry());
            break;
        case TopRight:
            rc.setWidth(rc.width() + pos.rx() - m_dragPos.rx());
            rc.setTop(rc.top() + pos.ry() - m_dragPos.ry());
            break;
        case Left:
            rc.setLeft(rc.left() + pos.rx() - m_dragPos.rx());
            break;
        case Right:
            rc.setWidth(rc.width() + pos.rx() - m_dragPos.rx());
            break;
        case BottomLeft:
            rc.setLeft(rc.left() + pos.rx() - m_dragPos.rx());
            rc.setHeight(rc.height() + pos.ry() - m_dragPos.ry());
            break;
        case BottomMiddle:
            rc.setHeight(rc.height() + pos.ry() - m_dragPos.ry());
            break;
        }
        if (rc != prevGeo) {
            m_diffBetweenPrevNowGeometry = true;
        }

        for (bool _b = false; _b == false; _b = true) {
            QSize minSize = minimumSize();
            if (minSize.isValid() && (rc.width() < minSize.width() || rc.height() < minSize.height()))
                break;

            QSize maxSize = maximumSize();
            if (maxSize.isValid() && (rc.width() > maxSize.width() || rc.height() > maxSize.height()))
                break;

            m_dragPos = pos;
            setGeometry(rc.toRect());

            if (m_dragGrip == NoGrip) {
                emit moved(geometry());
            } else {
                emit resized(geometry());
            }
        }
    }
}

void RubberBand::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    if (!m_dragPos.isNull()) {
        if (m_dragGrip == NoGrip) {
            emit moveFinished(geometry());
        } else {
            if (m_diffBetweenPrevNowGeometry)
                emit resizeFinished(geometry());
        }
    }

    m_diffBetweenPrevNowGeometry = false;
    m_dragPos = QPointF();
    m_dragGrip = NoGrip;

    update();
}

QMap<RubberBand::Grip, QRectF> RubberBand::gripPositions() const
{
    QMap<Grip, QRectF> positions;
    QRectF rc = rect();
    double gw = m_gripSize.width();
    double gh = m_gripSize.height();
    double rw = rc.width();
    double rh = rc.height();

    positions.insert(TopLeft, QRectF(0, 0, gw, gh));
    positions.insert(TopRight, QRectF(rw - gw, 0, gw, gh));
    positions.insert(BottomLeft, QRectF(0, rh - gh, gw, gh));
    positions.insert(BottomRight, QRectF(rw - gw, rh - gh, gw, gh));

    if (rw >= gw * 3.0) {
        positions.insert(TopMiddle, QRectF( (rw / 2.0) - (gw / 2.0), 0, gw, gh ));
        positions.insert(BottomMiddle, QRectF( (rw / 2.0) - (gw / 2.0), rh - gh, gw, gh ));
    }

    if (rh >= gh * 2.0) {
        positions.insert(Left, QRectF( 0, (rh / 2.0) - (gh / 2.0), gw, gh ));
        positions.insert(Right, QRectF( rw - gw, (rh / 2.0) - (gh / 2.0), gw, gh ));
    }

    return positions;
}
