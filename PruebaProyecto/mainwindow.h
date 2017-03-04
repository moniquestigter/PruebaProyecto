#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QIcon>
#include <QLabel>
#include <QString>
#include <QScrollArea>
#include <QGraphicsView>
#include "rightclick.h"
#include "archivo.h"
#include "lista.h"
#include "folder.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void crearArchivo(Folder * donde, string nomArchivo,string tipo);
    void listarArchivos(Folder * donde);
    void cargarArchivo(string ruta);
    void eliminarArchivo(QPushButton * bt);
    void copiar(string rutaOrigen, string rutaDestino);

    int posxFolder,posYFolder,posxLabel,posYLabel,longiArr,cantDefault,cantDefaultFile,windowWidth,windowHeight,cantScenes,codeBt;
    QPushButton ** arrBotones;
    QLabel **arrLabels;
    int *arrCodes;
    QGraphicsScene **arrScenes;
    Lista * archivos;
    string rutaInicial;
    Folder * inicial;

private slots:
    void on_btCrearFolder_clicked();
    void on_btCrearFile_clicked();
    string updateRuta(string ruta);
    void on_pushButton_2_clicked();

   /*void on_btEliminar_clicked();*/

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
