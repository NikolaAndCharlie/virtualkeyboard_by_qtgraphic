#include "main_widget.h"

#include "key_item.h"
#include "keyboard_view.h"
#include "qcoreapplication.h"
#include "qdir.h"
#include "qfile.h"
#include "qiodevice.h"
#include "qlayout.h"
#include "qtextstream.h"

MainWidget::MainWidget() : m_cap_clicked(false) {
  SetUI();
  this->setFixedSize(1200, 700);
}

MainWidget::~MainWidget() {}

void MainWidget::SetUI() {
  m_view = new View("Main");
  m_scene = new QGraphicsScene(this);
  ReadKeyText();
  m_scene->setSceneRect(QRect(0, 0, 800, 300));
  m_view->view()->setScene(m_scene);
  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget(m_view);
  this->setLayout(layout);
}

void MainWidget::ReadKeyText() {
  QString text_string =
      QCoreApplication::applicationDirPath() + "/keyboard.txt";
  text_string = QDir::toNativeSeparators(text_string);

  QFile file(text_string);
  if (!file.open(QIODevice::ReadOnly)) {
    return;
  }
  QTextStream out(&file);
  int row = 0;
  while (!out.atEnd()) {
    QString str = out.readLine();
    QStringList key_list = str.split("&&");
    for (int i = 0; i < key_list.size(); ++i) {
      QString key_str = key_list.at(i);
      KeyItem* item = new KeyItem(50 * i, row * 50, key_str);
      connect(item, &KeyItem::Clicked, this, &MainWidget::GetItemClickedString);
      item->setPos(50 * i + 25, row * 50 + 25);

      m_scene->addItem(item);
    }
    row++;
  }
}

void MainWidget::GetItemClickedString(const QString& str) {
  QString s = str;
  if (str == "Cap") {
    m_cap_clicked = m_cap_clicked ? false: true;
    QList<QGraphicsItem*> items = m_scene->items();
    for (int i = 0; i < items.size(); ++i) {
      QGraphicsItem* item = items.at(i);
      KeyItem* key_item = static_cast<KeyItem*>(item);
      QString key_item_str = key_item->GetStr();
      if (key_item_str.size() == 1) {
        QChar chr = key_item_str.at(0);
        if (chr.isLetter()) {
          if (m_cap_clicked) {
            key_item_str = key_item_str.toUpper();
          } else {
            key_item_str = key_item_str.toLower();
          }
          key_item->SetStr(key_item_str);
        }
      }
    }
  }
}
