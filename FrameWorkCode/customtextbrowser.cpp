#include "customtextbrowser.h"
#include <QEvent>
#include <QDebug>
#include <QToolTip>

customTextBrowser::customTextBrowser()
{
//    installEventFilter(this);
}

bool customTextBrowser::eventFilter(QObject *object, QEvent *event)
{

        if (event->type() == QEvent::ToolTip)
        {
   //         QToolTip *toolEvent = static_cast<QToolTip*>(event)
            qDebug() << "Tooltip "<<QEvent :: ToolTip;
            event->accept();

           if(QToolTip::isVisible())
           {

               qDebug() << QToolTip :: text();
           }
        }
    return QWidget::eventFilter(object, event);
}
