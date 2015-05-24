#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_agregarArchivosButton_clicked();
    void on_comprimirArchivosButton_clicked();
    void on_descomprimirArchivoButton_clicked();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
