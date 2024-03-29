#include "keyboard_view.h"

#include "key_item.h"
#include "qevent.h"
#include "qlayout.h"
#include "qstyle.h"
#include "qwidget.h"

void View::SetUpMatrix() {}

View::View(const QString& name, QWidget* parent) : QFrame(parent) {
  m_graphic_view = new GraphicsView(this);
  m_graphic_view->setRenderHint(QPainter::Antialiasing, false);
  m_graphic_view->setDragMode(QGraphicsView::RubberBandDrag);
  m_graphic_view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
  m_graphic_view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  m_graphic_view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

  qreal scale = 1;
  QTransform mat;
  mat.scale(scale, scale);
  mat.rotate(0);
  m_graphic_view->setTransform(mat);

  int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
  QSize icon_size(size, size);

  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget(m_graphic_view);
  this->setLayout(layout);
}

void GraphicsView::wheelEvent(QWheelEvent* e) {
  if (e->angleDelta().y() > 0) {
    m_scale += 0.1;
  } else {
    m_scale -= 0.1;
  }
  QList<QGraphicsItem*> select_items = scene()->selectedItems();
  if (select_items.size() > 0) {
    for (QGraphicsItem* item : select_items) {
      KeyItem* key_item = static_cast<KeyItem*>(item);
      key_item->Zoom(m_scale);
    }
  } else {
    QTransform trans;
    trans.scale(m_scale, m_scale);
    setTransform(trans);
  }
}
QGraphicsView* View::view() const {
  return static_cast<QGraphicsView*>(m_graphic_view);
}

void View::ResetView() {}

void View::ZoomIn() {}

void View::ZoomOut() {}

void View::wheelEvent(QWheelEvent* e) {
 int a = 0;
}
