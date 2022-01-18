/*
 * It is used for zooming-in and zooming-out functionality
 */
#include "zoom.h"
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>
#include <qmath.h>
#include <QDebug>

/*!
 * \brief Graphics_view_zoom::Graphics_view_zoom
 * \param view
 * zoom based upon the factor
 */
Graphics_view_zoom::Graphics_view_zoom(QGraphicsView* view, QGraphicsScene *scene)
  : QObject(view), _view(view)
{
  _view->viewport()->installEventFilter(this);
  _view->setMouseTracking(true);
  _modifiers = Qt::ControlModifier;
  _zoom_factor_base = 1.0015;       //The minimum zoom factor
  _scene = scene;
}

/*!
 * \brief Graphics_view_zoom::gentle_zoom
 * \param factor
 */
void Graphics_view_zoom::gentle_zoom(double factor)
{
  int previousZoomLevel = zoom_level;
  // Restricting the zoom value between 0 and 200
  if ( zoom_level >= 200 && factor > 1 )
      return;
  else if ( zoom_level <= 1 && factor < 1 )
      return;

  // Calculating zoom level
  if ( factor > 1 )
      zoom_level += (factor - 1)*100;
  else if ( factor < 1 )
      zoom_level -= (1 - factor)*100;

  // Returning if zoom_level == 0
  if (zoom_level == 0) {
      zoom_level = previousZoomLevel;
      return;
  }

  // Resetting size of image as this zooming function zooms the image relative to that of the previous image present
  _view->fitInView(_scene->itemsBoundingRect(), Qt::KeepAspectRatio);

  // Calculating new zoom factor from new zoom_level as the size of image is resetted
  factor = zoom_level / 100.0;

  _view->scale(factor, factor);
  _view->centerOn(target_scene_pos);
  QPointF delta_viewport_pos = target_viewport_pos - QPointF(_view->viewport()->width() / 2.0,
                                                             _view->viewport()->height() / 2.0);
  QPointF viewport_center = _view->mapFromScene(target_scene_pos) - delta_viewport_pos;
  _view->centerOn(_view->mapToScene(viewport_center.toPoint()));
  emit zoomed();
}

double Graphics_view_zoom::getDefaultZoomInFactor()
{
    return defaultZoomInFactor;
}

double Graphics_view_zoom::getDefaultZoomOutFactor()
{
    return defaultZoomOutFactor;
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
//        double factor = qPow(_zoom_factor_base, angle);
        double factor = 1;
        if (angle > 0)
            factor = defaultZoomInFactor;
        else if (angle < 0)
            factor = defaultZoomOutFactor;
        gentle_zoom(factor);
        return true;
      }
    }
  }
  Q_UNUSED(object)
  return false;
}
