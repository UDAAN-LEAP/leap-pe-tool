#ifndef RUBBERBAND_H
#define RUBBERBAND_H

#include <QWidget>

class RubberBand : public QWidget
{
    Q_OBJECT

public:
    explicit RubberBand(QWidget *parent = nullptr);
    bool isMoveEnabled() const;
    void setMoveEnabled(bool enabled);
    QSize gripSize() const;
    void setGripSize(const QSize &size);
    QColor gripColor() const;
    void setGripColor(const QColor &color);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    enum Grip {
        NoGrip = 0,
        BottomRight,
        TopLeft,
        TopMiddle,
        TopRight,
        Left,
        Right,
        BottomLeft,
        BottomMiddle
    };

private:
    bool m_moveEnabled;
    QSize m_gripSize;
    QColor m_gripColor;
    QPointF m_dragPos;
    Grip m_dragGrip;
    bool m_diffBetweenPrevNowGeometry = false;

private:
    QMap<Grip, QRectF> gripPositions() const;

signals:
    void resized(const QRect &rect);
    void resizeFinished(const QRect &rect);
    void moved(const QRect &rect);
    void moveFinished(const QRect &rect);
};

#endif // RUBBERBAND_H
