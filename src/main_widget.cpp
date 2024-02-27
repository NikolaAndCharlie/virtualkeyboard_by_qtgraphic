#include "main_widget.h"

#include "key_item.h"
#include "keyboard_view.h"
#include "qlayout.h"

MainWidget::MainWidget() {
  SetUI();
  this->setFixedSize(1200, 700);
}

MainWidget::~MainWidget() {}

void MainWidget::SetUI() {
  m_view = new View("Main");
  m_scene = new QGraphicsScene(this);
  KeyItem* item = new KeyItem(100, 100, "W");
  item->setPos(0, 0);
  m_scene->setSceneRect(QRect(0, 0, 1200, 700));
  m_scene->addItem(item);
  m_view->view()->setScene(m_scene);
  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget(m_view);
  this->setLayout(layout);
}
