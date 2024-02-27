#include "keyboard_view.h"

#include "qstyle.h"
#include "qwidget.h"
#include "qlayout.h"

void GraphicsView::wheelEvent(QWheelEvent* e) {
  int a = 0;
}


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

QGraphicsView* View::view() const {
  return static_cast<QGraphicsView*>(m_graphic_view);
}

void View::ResetView() {
  
}

void View::ZoomIn(){
}

void View::ZoomOut() {
}
