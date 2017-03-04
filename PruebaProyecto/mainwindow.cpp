
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScrollBar>
#include <QMessageBox>
#include <QImage>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include "folder.h"
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    windowWidth = 1600;
    windowHeight = 1000;
    resize(windowWidth, windowHeight);
    posxFolder = 60;
    posYFolder = 170;
    posxLabel = posxFolder;
    posYLabel = 238;
    longiArr = 0;
    codeBt = 0;
    cantDefault = 0;
    cantDefaultFile = 0;
    arrBotones = new QPushButton*[500];
    arrLabels = new QLabel*[500];
    arrScenes = new QGraphicsScene*[500];
    arrCodes = new int[500];
    rutaInicial = "root/";
    inicial = new Folder("FolderInicial",rutaInicial,this);
    cantScenes = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

string MainWindow::updateRuta(string r){
    string updated = rutaInicial + r + "/";
    return updated;
}

void MainWindow::crearArchivo(Folder *donde, string nomArchivo, string tipo){
    if(tipo == "Folder"){
        Folder * nuevo= new Folder(nomArchivo, donde->getRuta(),this);
        Archivo * nuevoArchivo = (Archivo*)nuevo;
        nuevoArchivo->tipo == tipo;
     }
    else{
        ArchivoText * nuevo = new ArchivoText(nomArchivo,donde->getRuta());
        Archivo * nuevoArchivo = (Archivo*)nuevo;
        nuevoArchivo->tipo == tipo;

    }
}


void MainWindow::on_btCrearFolder_clicked()
{
     string name = ui->nombreArch->text().toStdString();
    /* QGraphicsScene * scene;
     QGraphicsView view(scene);
     QGraphicsView *view = new QGraphicsView();

     ui->MainWindow::frame;
     view->setScene(scene);*/

     arrBotones[longiArr] = new QPushButton(this);
     arrBotones[longiArr]->setText("");
     arrBotones[longiArr]->setStyleSheet("border-image:url(:/imagen/prefix2/folder.png);");
     arrBotones[longiArr]->setGeometry(QRect(QPoint(posxFolder,posYFolder),QSize(81,71)));
     posxFolder+=100;
     ui->nombreArch->setText("");
     if(posxFolder>=1420){
         posxFolder = 60;
         posYFolder+=150;
     }
     arrBotones[longiArr]->show();

    string def = "Folder";
    if(name == ""){
        string defaultName = def + std::to_string(cantDefault++);
        crearArchivo(inicial,defaultName,def);
        /*LABELS*/
        arrLabels[longiArr] = new QLabel(this);
        arrLabels[longiArr]->resize(100,81);
        arrLabels[longiArr]->setText(defaultName.c_str());
        arrLabels[longiArr]->setGeometry(QRect(QPoint(posxLabel,posYLabel),QSize(61,16)));
        posxLabel+=100;
        if(posxLabel>=1420){
           posxLabel = 60;
           posYLabel+=150;
         }
        arrLabels[longiArr]->show();
        longiArr++;
    }
    else{
        crearArchivo(inicial,name,def);
        /*LABELS*/
        arrLabels[longiArr] = new QLabel(this);
        arrLabels[longiArr]->resize(100,81);
        arrLabels[longiArr]->setText(name.c_str());
        arrLabels[longiArr]->setGeometry(QRect(QPoint(posxLabel,posYLabel),QSize(61,16)));
        posxLabel+=100;
        if(posxLabel>=1420){
           posxLabel = 60;
           posYLabel+=150;
         }
        arrLabels[longiArr]->show();
        longiArr++;
    }
}

void MainWindow::on_btCrearFile_clicked(){

    string name = ui->nombreArch->text().toStdString();
    arrBotones[longiArr] = new QPushButton(this);
    arrBotones[longiArr]->setText("");
    arrBotones[longiArr]->setStyleSheet("border-image:url(:/imagen/prefix2/file.png);");
    arrBotones[longiArr]->setGeometry(QRect(QPoint(posxFolder,posYFolder),QSize(81,71)));
    posxFolder+=100;
    ui->nombreArch->setText("");
    if(posxFolder>=1420){
        posxFolder = 60;
        posYFolder+=150;
    }
    arrBotones[longiArr]->show();

    string def = "File";
    if(name == ""){
        string defaultName = def + std::to_string(cantDefaultFile++) + ".txt";
        crearArchivo(inicial,defaultName,def);

        /*LABELS*/
        arrLabels[longiArr] = new QLabel(this);
        arrLabels[longiArr]->resize(81,81);
        arrLabels[longiArr]->setText(defaultName.c_str());
        arrLabels[longiArr]->setGeometry(QRect(QPoint(posxLabel,posYLabel),QSize(61,16)));
        posxLabel+=100;
        if(posxLabel>=1420){
            posxLabel = 60;
            posYLabel+=150;
         }
                arrLabels[longiArr]->show();
     }
     else{
        string nombreCompleto = name + ".txt";
        crearArchivo(inicial,nombreCompleto,def);
        /*LABELS*/
        arrLabels[longiArr] = new QLabel(this);
        arrLabels[longiArr]->resize(81,81);
        arrLabels[longiArr]->setText(nombreCompleto.c_str());
        arrLabels[longiArr]->setGeometry(QRect(QPoint(posxLabel,posYLabel),QSize(61,16)));
        posxLabel+=100;
        if(posxLabel>=1420){
            posxLabel = 60;
            posYLabel+=150;
        }
        arrLabels[longiArr]->show();
      }
        longiArr++;
    }

/*void MainWindow::cargarArchivo(string ruta){
    string rutaSig = updateRuta(ruta);
    for(int a = 0; a<longiArr; a++){
        if(arrWidgets[a] == )
    }

}*/

void MainWindow::on_pushButton_2_clicked()
{
    QObject * senderObj = sender();
     if(senderObj->isWidgetType()){
         QPushButton * button = qobject_cast<QPushButton*>(senderObj);
    string nombreArchivo;
    for(int a = 0; a<longiArr; a++){
        if(arrBotones[a] == button){
            nombreArchivo = arrLabels[a]->text().toStdString();
        }
    }
    if(nombreArchivo.find(".txt")){
        /*QUE ABRA UN MESSAGE BOX PARA TYPEAR*/
    }
    else{/*ES FOLDER tiene que abrir la lista*/
        Folder * temp = inicial;
       /* for(int a = 0; a<temp->list->longiLista; a++){
            if(temp->nombre == nombreArchivo)
                cargarArchivo(temp->getRuta());
        }*/
    }
   }
}

/*void MainWindow::eliminarArchivo(QPushButton * bt){
    for(int a = 0; a<longiArr; a++){
        if(arrBotones[a] == bt){
            delete arrBotones[a];
            /*arrBotones[a] = arrBotones[a+1];
            arrBotones[a+1]->setGeometry(QRect(QPoint(posxFolder-=60,posYFolder),QSize(81,71))); */
            /*arrLabels[a] = arrLabels[a+1];
            arrLabels[a+1]->setGeometry(QRect(QPoint(posxLabel-=60,posYLabel),QSize(61,16)));
        }
    }
}*/

/*void MainWindow::on_btEliminar_clicked()
{
     string name = ui->nombreArch->text().toStdString();
     for(int a = 0; a<longiArr; a++){
         if(arrBotones[a]->text().toStdString() == name)
            connect(arrBotones[a],SIGNAL(clicked()),ui->btEliminar,SLOT(close()));
         }
         /*Archivo * folder = donde->list->buscar(updateRuta(nombreArchivo));
         donde = (Folder*)folder;
         for(int a = 0; donde->list->longiLista; a++){
             if(updateRuta(nombreArchivo).find(donde->getRuta())){
                 Archivo * file = donde->list->buscar(nombreArchivo);
                 donde->list->eliminar(file);
             }
             else{
                 cout<<"Ese archivo no existe"<<endl;
             }

         }
         QMessageBox msgBox;
         msgBox.setText("Esta seguro que lo desea borrar?");
         msgBox.setStandardButtons(QMessageBox::Yes);
         msgBox.addButton(QMessageBox::No);
         if(msgBox.exec() == QMessageBox::Yes){
             eliminarArchivo(button);
         }else {
           msgBox.close();
         }
     }
}*/
