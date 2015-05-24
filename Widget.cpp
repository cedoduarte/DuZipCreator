#include "Widget.h"
#include "ui_Widget.h"
#include <JlCompress.h>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_agregarArchivosButton_clicked()
{
    auto archivos = QFileDialog::getOpenFileNames(this,
            "Abrir archivos", "/", "Files (*.*)");
    for (const auto &ia : archivos) {
        ui->listWidget->addItem(ia);
    }
}

void Widget::on_comprimirArchivosButton_clicked()
{
    const int nRows = ui->listWidget->count();
    if (nRows == 0) {
        return;
    }
    auto archivoZip = QFileDialog::getSaveFileName(this,
                    "Guardar Zip", "/", "Zip Files (*.zip)");
    QStringList archivos;
    for (int i = 0; i < nRows; ++i) {
        archivos.append(ui->listWidget->item(i)->text());
    }
    if (JlCompress::compressFiles(archivoZip, archivos)) {
        QMessageBox::information(this, "Zip File", "Comprimido con éxito");
    } else {
        QMessageBox::critical(this, "Zip File", "Error de compresión");
    }
}

void Widget::on_descomprimirArchivoButton_clicked()
{
    auto zip = QFileDialog::getOpenFileName(this,
            "Zip File", "/", "Zip Files (*.zip)");
    auto zipped = JlCompress::getFileList(zip);
    auto carpeta = QFileDialog::getExistingDirectory(this, "Destino", "/");
    if (!JlCompress::extractFiles(zip, zipped, carpeta).isEmpty()) {
        QMessageBox::information(this, "Zip Files",
                "Descomprimido con éxito");
    } else {
        QMessageBox::critical(this, "Zip Files",
                "Error de descompresión");
    }
}
