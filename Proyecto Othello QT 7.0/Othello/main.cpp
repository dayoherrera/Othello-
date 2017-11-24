#include "othello.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Othello w;
    //Para que la pantalla no pueda cambiar su tamaño
    w.setMaximumHeight(600);
    w.setMinimumHeight(600);
    w.setMaximumWidth(600);
    w.setMinimumWidth(600);
    //Muestra la ventana principal
    w.show();
    //Inicia el tablero
    w.creandoGrupo();



    int mat[8][8];
    for(int i=0; i<8;i++){
       for(int j=0;j<8;j++){
           mat[i][j]=0;
        }
     }

     mat[3][3]=2;
     mat[4][4]=2;
     mat[3][4]=1;
     mat[4][3]=1;

    w.iniciar(mat, true);
    w.revisar();

    return a.exec();
}
