#include "rubberband.h"

#include <QPainter>
#include <QMap>
#include <QMouseEvent>
#include <QSize>
#include <QPointF>
#include <QRectF>
#include<QDebug>

/*!
 * \fn RubberBand::RubberBand
 * \brief Initializes the gripColor, gripSize, dragPos, dragGrip and moveEnabled
 * \param parent Passed to QWidget to set the parent
 */
RubberBand::RubberBand(QWidget *parent)
    : QWidget{parent}
{
    m_moveEnabled = false;
    m_gripSize = QSize(8, 8);
    m_gripColor = QColor(Qt::blue);
    m_dragPos = QPointF();
    m_dragGrip = NoGrip;
}

/*!
 * \fn RubberBand::isMoveEnabled
 * \brief Returns value accordingly if move is enabled/disabled
 * \return true if move is enabled otherwise false
 */
bool RubberBand::isMoveEnabled() const
{
    return m_moveEnabled;
}

/*!
 * \fn RubberBand::setMoveEnabled
 * \brief Sets the moveEnabled to the value passed
 * \param enabled Used for setting if move is enabled
 */
void RubberBand::setMoveEnabled(bool enabled)
{
    m_moveEnabled = enabled;
}

/*!
 * \fn RubberBand::gripSize
 * \brief Returns the grip size
 * \return Grip size (QSize)
 */
QSize RubberBand::gripSize() const
{
    return m_gripSize;
}

/*!
 * \fn RubberBand::setGripSize
 * \brief Sets the grip size if size passed is valid
 * \param size Grip size is set to the value of this parameter
 */
void RubberBand::setGripSize(const QSize &size)
{
    if (m_gripSize != size && size.isValid()) {
        m_gripSize = size;
        update();
    }
}

/*!
 * \fn RubberBand::gripColor
 * \brief Returns the Grip Color
 * \return Grip color (QColor)
 */
QColor RubberBand::gripColor() const
{
    return m_gripColor;
}

/*!
 * \fn RubberBand::setGripColor
 * \brief Sets the grip color to the color passed
 * \param color Grip color is set to the value of this parameter
 */
void RubberBand::setGripColor(const QColor &color)
{
    if (m_gripColor != color) {
        m_gripColor = color;
        update();
    }
}

/*!
 * \fn RubberBand::paintEvent
 * \brief This functions paints the entire rubber band and the grips
 * \details
 * 1. Calculates the grip positions.
 * 2. Draws big rectangle in which image is enclosed
 * 3. Draws all grips
 * \param event Unused parameter
 */
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

/*!
 * \fn RubberBand::mousePressEvent
 * \brief When mouse button is clicked this function gets fired which is used for getting the grip which is grabbed
 * \details
 * 1. Calculate grip positions.
 * 2. Find the grip rectangle inside which mouse button was pressed.
 * 3. If move is enabled store the original position in a data member
 * \param event Used for getting the position where mouse button was pressed.
 * \sa gripPositions()
 */
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
                switch (m_dragGrip) {
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
            }
        }

        if (m_dragGrip == NoGrip && m_moveEnabled) {
            m_dragPos = event->windowPos();
        }
    }
}

/*!
 * \fn RubberBand::mouseMoveEvent
 * \brief This function keeps track of mouse pointer. It handles resizing the geometry of the rubber band.
 * \details
 * 1. Mark the cursor style according to the grip box chosen.
 * 2. Resize the rect of original rubber band and if rect is not less than minimum size or not more than the maximum size of the widget set then emit the resized/moved signals accordingly.
 * \param event Used for getting the position of the mouse pointer
 */
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

/*!
 * \fn RubberBand::mouseReleaseEvent
 * \brief Emits the moveFinished or resizeFinished signals according to the action performed when mouse button is released
 * \param event Unused parameter
 */
void RubberBand::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    if (!m_dragPos.isNull()) {
        if (m_dragGrip == NoGrip) {
            emit moveFinished(geometry());
        } else {
            if (m_diffBetweenPrevNowGeometry)
                emit resizeFinished(geometry());
                qDebug()<<"Resize Finished";
        }
    }

    m_diffBetweenPrevNowGeometry = false;
    m_dragPos = QPointF();
    m_dragGrip = NoGrip;
    setCursor(Qt::ArrowCursor);

    update();
}

/*!
 * \fn RubberBand::gripPositions
 * \brief Returns the mapping of the widget grips' to their position on the rubber band
 * \return Mapping of the grip to its position in the widget
 */
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
