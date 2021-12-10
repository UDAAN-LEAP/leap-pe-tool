/*
 * It is used for zooming-in and zooming-out functionality
 */
#include "zoom.h"
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>
#include <qmath.h>

/*!
 * \brief Graphics_view_zoom::Graphics_view_zoom
 * \param view
 * zoom based upon the factor
 */
Graphics_view_zoom::Graphics_view_zoom(QGraphicsView* view)
  : QObject(view), _view(view)
{
  _view->viewport()->installEventFilter(this);
  _view->setMouseTracking(true);
  _modifiers = Qt::ControlModifier;
  _zoom_factor_base = 1.0015;       //The minimum zoom factor
}

/*!
 * \brief Graphics_view_zoom::gentle_zoom
 * \param factor
 */
void Graphics_view_zoom::gentle_zoom(double factor) {
  if ( zoom_level >= 200 && factor >= 1.1 )
      return;
  else if ( zoom_level <= 0 && factor <= 0.9 )
      return;
  _view->scale(factor, factor);
  _view->centerOn(target_scene_pos);
  QPointF delta_viewport_pos = target_viewport_pos - QPointF(_view->viewport()->width() / 2.0,
                                                             _view->viewport()->height() / 2.0);
  QPointF viewport_center = _view->mapFromScene(target_scene_pos) - delta_viewport_pos;
  _view->centerOn(_view->mapToScene(viewport_center.toPoint()));
  emit zoomed();

  // Calculating zoom level which should be between 0 - 200

  if ( factor >= 1.1 )
      zoom_level += 10;
  else if ( factor <= 0.9 )
      zoom_level -= 10;
}

/*!
 * \brief Graphics_view_zoom::set_modifiers
 * \param modifiers
 */
void Graphics_view_zoom::set_modifiers(Qt::KeyboardModifiers modifiers) {
  _modifiers = modifiers;

}

/*!
 * \brief Graphics_view_zoom::set_zoom_factor_base
 * \param value
 */
void Graphics_view_zoom::set_zoom_factor_base(double value) {
  _zoom_factor_base = value;
}

/*!
 * \brief Graphics_view_zoom::eventFilter
 * \param object
 * \param event
 * Waits for the zoom to occur
 * This is an event filter which checks for 2 events, mouse click and mouse moves, it can scale the image by the amount of movement detected
 * \return true
 * \sa keyboardModifiers
*/
bool Graphics_view_zoom::eventFilter(QObject *object, QEvent *event)
{
  //! If its a basic mouse movement
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
    QPointF delta = target_viewport_pos - mouse_event->pos();
    if (qAbs(delta.x()) > 5 || qAbs(delta.y()) > 5) {
      target_viewport_pos = mouse_event->pos();
      target_scene_pos = _view->mapToScene(mouse_event->pos());
    }
  }
  //! if event change is on mouse wheel
  else if (event->type() == QEvent::Wheel)
  {
    QWheelEvent* wheel_event = static_cast<QWheelEvent*>(event);
    if (QApplication::keyboardModifiers() == _modifiers)
    {
      if (wheel_event->orientation() == Qt::Vertical)
      {
        double angle = wheel_event->angleDelta().y();
        double factor = qPow(_zoom_factor_base, angle);
        gentle_zoom(factor);
        return true;
      }
    }
  }
  Q_UNUSED(object)
  return false;
}
