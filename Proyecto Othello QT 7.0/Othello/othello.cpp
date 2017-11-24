#include "othello.h"
#include "ui_othello.h"
#include <QDebug>
#include <QPushButton>
#include <QIcon>
#include <QPixmap>
#include <QTimer>
#include "Lista.h"
Othello::Othello(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Othello)
{
    ui->setupUi(this);
    timerId = startTimer(2000);
}

Othello::~Othello()
{
    delete ui;
}

void Othello::iniciar(int mat[8][8], bool band){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            this->mat[i][j]=mat[i][j];
        }
    }
    this->band=band;
    this->juega=1;
    this->jugob=false;
    this->jugon=false;
    this->pudob=true;
    this->pudon=true;
    this->cantBlancas=0;
    this->cantNegras=0;
    this->nivel=false;
    this->suge=false;
    ui->ganador->setVisible(false);
    ui->ganador->setDisabled(true);
    this->actual(this->mat,juega);
    pintar();
    ui->labelNegras->setText("Azules: 2");
    ui->labelBlancas->setText("Blancas: 2");
    QPixmap pixmap1;
    if(pixmap1.load("JuegoNuevo.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap1);
        ui->BotonNuevo->setIcon(ButtonIcon);
        ui->BotonNuevo->setIconSize(pixmap1.rect().size());
    }
    QPixmap pixmap2;
    if(pixmap2.load("Sugerencia.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap2);
        ui->BotonSuge->setIcon(ButtonIcon);
        ui->BotonSuge->setIconSize(pixmap2.rect().size());
    }
    QPixmap pixmap3;
    if(pixmap3.load("Salir.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap3);
        ui->BotonSalir->setIcon(ButtonIcon);
        ui->BotonSalir->setIconSize(pixmap3.rect().size());
    }
    QPixmap pixmap4;
    if(pixmap4.load("Menu.png")){
        QIcon ButtonIcon;
        ui->label->setPixmap(pixmap4);
    }


    QPixmap pixmap6;
    if(pixmap6.load("Salir.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap6);
        ui->Salir->setIcon(ButtonIcon);
        ui->Salir->setIconSize(pixmap6.rect().size());
    }

    QPixmap pixmap7;
    if(pixmap7.load("Ayuda.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap7);
        ui->Ayuda->setIcon(ButtonIcon);
        ui->Ayuda->setIconSize(pixmap7.rect().size());
    }

    QPixmap pixmap8;
    if(pixmap8.load("Creditos.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap8);
        ui->Creditos->setIcon(ButtonIcon);
        ui->Creditos->setIconSize(pixmap8.rect().size());
    }

    QPixmap pixmap9;
    if(pixmap9.load("jugvsjug.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap9);
        ui->jugvsjug->setIcon(ButtonIcon);
        ui->jugvsjug->setIconSize(pixmap9.rect().size());
    }

    QPixmap pixmap10;
    if(pixmap10.load("jugvscom.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap10);
        ui->jugvscom->setIcon(ButtonIcon);
        ui->jugvscom->setIconSize(pixmap10.rect().size());
    }

    QPixmap pixmap11;
    if(pixmap11.load("ayudaMenu.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap11);
        ui->ayudita->setIcon(ButtonIcon);
        ui->ayudita->setIconSize(pixmap11.rect().size());
    }
    ui->ayudita->setVisible(false);
    ui->ayudita->setDisabled(true);

    QPixmap pixmap12;
    if(pixmap12.load("creditosMenu.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap12);
        ui->creditoMenu->setIcon(ButtonIcon);
        ui->creditoMenu->setIconSize(pixmap12.rect().size());
    }
    ui->creditoMenu->setVisible(false);
    ui->creditoMenu->setDisabled(true);

    QPixmap pixmap13;
    if(pixmap13.load("facil.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap13);
        ui->facil->setIcon(ButtonIcon);
        ui->facil->setIconSize(pixmap13.rect().size());
    }

    QPixmap pixmap14;
    if(pixmap14.load("dificil.png")){
        QIcon ButtonIcon;
        ButtonIcon.addPixmap(pixmap14);
        ui->dificil->setIcon(ButtonIcon);
        ui->dificil->setIconSize(pixmap14.rect().size());
    }
}


QString Othello::getJugadorDeTurno(){
    return ui->jugador->text();
}

void Othello::mostrar(){
    QString jugador =getJugadorDeTurno();
    qDebug() << jugador;

}



void Othello::creandoGrupo(){

    ui->buttonGroup->addButton(ui->c000,0);
    ui->buttonGroup->addButton(ui->c011,1);
    ui->buttonGroup->addButton(ui->c022,2);
    ui->buttonGroup->addButton(ui->c033,3);
    ui->buttonGroup->addButton(ui->c044,4);
    ui->buttonGroup->addButton(ui->c055,5);
    ui->buttonGroup->addButton(ui->c066,6);
    ui->buttonGroup->addButton(ui->c077,7);
    ui->buttonGroup->addButton(ui->c100,10);
    ui->buttonGroup->addButton(ui->c111,11);
    ui->buttonGroup->addButton(ui->c122,12);
    ui->buttonGroup->addButton(ui->c133,13);
    ui->buttonGroup->addButton(ui->c144,14);
    ui->buttonGroup->addButton(ui->c155,15);
    ui->buttonGroup->addButton(ui->c166,16);
    ui->buttonGroup->addButton(ui->c177,17);
    ui->buttonGroup->addButton(ui->c200,20);
    ui->buttonGroup->addButton(ui->c211,21);
    ui->buttonGroup->addButton(ui->c222,22);
    ui->buttonGroup->addButton(ui->c233,23);
    ui->buttonGroup->addButton(ui->c244,24);
    ui->buttonGroup->addButton(ui->c255,25);
    ui->buttonGroup->addButton(ui->c266,26);
    ui->buttonGroup->addButton(ui->c277,27);
    ui->buttonGroup->addButton(ui->c300,30);
    ui->buttonGroup->addButton(ui->c311,31);
    ui->buttonGroup->addButton(ui->c322,32);
    ui->buttonGroup->addButton(ui->c333,33);
    ui->buttonGroup->addButton(ui->c344,34);
    ui->buttonGroup->addButton(ui->c355,35);
    ui->buttonGroup->addButton(ui->c366,36);
    ui->buttonGroup->addButton(ui->c377,37);
    ui->buttonGroup->addButton(ui->c400,40);
    ui->buttonGroup->addButton(ui->c411,41);
    ui->buttonGroup->addButton(ui->c422,42);
    ui->buttonGroup->addButton(ui->c433,43);
    ui->buttonGroup->addButton(ui->c444,44);
    ui->buttonGroup->addButton(ui->c455,45);
    ui->buttonGroup->addButton(ui->c466,46);
    ui->buttonGroup->addButton(ui->c477,47);
    ui->buttonGroup->addButton(ui->c500,50);
    ui->buttonGroup->addButton(ui->c511,51);
    ui->buttonGroup->addButton(ui->c522,52);
    ui->buttonGroup->addButton(ui->c533,53);
    ui->buttonGroup->addButton(ui->c544,54);
    ui->buttonGroup->addButton(ui->c555,55);
    ui->buttonGroup->addButton(ui->c566,56);
    ui->buttonGroup->addButton(ui->c577,57);
    ui->buttonGroup->addButton(ui->c600,60);
    ui->buttonGroup->addButton(ui->c611,61);
    ui->buttonGroup->addButton(ui->c622,62);
    ui->buttonGroup->addButton(ui->c633,63);
    ui->buttonGroup->addButton(ui->c644,64);
    ui->buttonGroup->addButton(ui->c655,65);
    ui->buttonGroup->addButton(ui->c666,66);
    ui->buttonGroup->addButton(ui->c677,67);
    ui->buttonGroup->addButton(ui->c700,70);
    ui->buttonGroup->addButton(ui->c711,71);
    ui->buttonGroup->addButton(ui->c722,72);
    ui->buttonGroup->addButton(ui->c733,73);
    ui->buttonGroup->addButton(ui->c744,74);
    ui->buttonGroup->addButton(ui->c755,75);
    ui->buttonGroup->addButton(ui->c766,76);
    ui->buttonGroup->addButton(ui->c777,77);

    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
                this, SLOT(onGroupButtonClicked(int)));

}


void Othello::pintar(){


    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){

            int indice = i*10 + j;


            if(this->mat[i][j]==5){

                QPixmap pixmap;
                if(pixmap.load("TableroConMarca.png")){
                    QIcon ButtonIcon;
                    ButtonIcon.addPixmap(pixmap);
                    ui->buttonGroup->button(indice)->setIcon(ButtonIcon);
                    ui->buttonGroup->button(indice)->setIconSize(pixmap.rect().size());
                }




            }
            if(this->mat[i][j]==1){
                QPixmap pixmap;
                if(pixmap.load("FichaNegra.png")){
                    QIcon ButtonIcon;
                    ButtonIcon.addPixmap(pixmap);
                    ui->buttonGroup->button(indice)->setIcon(ButtonIcon);
                    ui->buttonGroup->button(indice)->setIconSize(pixmap.rect().size());
                }
               // ui->buttonGroup->button(indice)->setStyleSheet("background-color: black");
            }
            if(this->mat[i][j]==2){
                QPixmap pixmap;
                if(pixmap.load("FichaBlanca.png")){
                    QIcon ButtonIcon;
                    ButtonIcon.addPixmap(pixmap);
                    ui->buttonGroup->button(indice)->setIcon(ButtonIcon);
                    ui->buttonGroup->button(indice)->setIconSize(pixmap.rect().size());
                }
               //ui->buttonGroup->button(indice)->setStyleSheet("background-color: white");
            }
            if(this->mat[i][j]==0){
                QPixmap pixmap;
                if(pixmap.load("Tablero.png")){
                    QIcon ButtonIcon;
                    ButtonIcon.addPixmap(pixmap);
                    ui->buttonGroup->button(indice)->setIcon(ButtonIcon);
                    ui->buttonGroup->button(indice)->setIconSize(pixmap.rect().size());
                }
               //ui->buttonGroup->button(indice)->setStyleSheet("background-color: white");
            }

        }
    }

}

void Othello::evaluar(int mat[8][8], int x, int y, int turno){ //evaluando las 8 posiciones

    int i=0,j=0;
    int w;
    int x0=x, y0=y; //tomando valores iniciales de X y Y

    if(turno==1){ //evalua la w en la matriz, sera el otro usuario en la matriz
        w=2;
    }else{
        w=1;
    }

    if(mat[x0-1][y0-1]==w){//diagonal izquierda superior

        x=x0;
        y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x--;
            y--;

            if(mat[x][y]==turno || mat[x][y]==5){
                //cout<<"igual a turno";
                break;
            }

            if(mat[x][y]==0 && x!=-1 && y!=-1){
                //cout<<"x1: "<<x<<endl;
                //cout<<"y1: "<<y<<endl;
                mat[x][y]=5;
                break;
            }
        }
    }

    if(mat[x0-1][y0+1]==w){ //diagonal derecha superior

        x=x0;
        y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x--;
                y++;

            if(mat[x][y]==turno || mat[x][y]==5){
                    break;
            }

            if(mat[x][y]==0 && x!=-1 && y!=8){
                    mat[x][y]=5;
                //cout<<"x2: "<<x<<endl;
                //cout<<"y2: "<<y<<endl;
                    break;
            }
        }
    }

    if(mat[x0-1][y0]==w){ //vertical hacia arriba

        x=x0;
        y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x--;

            if(mat[x][y]==turno || mat[x][y]==5){
                    break;
            }

            if(mat[x][y]==0 && x!=-1 ){
                //cout<<"x3: "<<x<<endl;
                //cout<<"y3: "<<y<<endl;
                mat[x][y]=5;
                break;
            }
        }
    }

    if(mat[x0+1][y0]==w){ //vertical hacia abajo

         x=x0;
         y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x++;

            if(mat[x][y]==turno || mat[x][y]==5){
                break;
            }

            if(mat[x][y]==0 && x!=8){
                //cout<<"x4: "<<x<<endl;
                //cout<<"y4: "<<y<<endl;
                mat[x][y]=5;
                break;
            }
        }
    }

    if(mat[x0+1][y0-1]==w){//diagonal izquierda inferior

        x=x0;
         y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x++;
            y--;

            if(mat[x][y]==turno || mat[x][y]==5){
                break;
            }

            if(mat[x][y]==0 && x!=8 && y!=-1){
                //cout<<"x5: "<<x<<endl;
                //cout<<"y5: "<<y<<endl;
                mat[x][y]=5;
                break;
            }
        }
    }

    if((mat[x0+1][y0+1]==w)){ //diagonal derecha inferior

        x=x0;
        y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x++;
                y++;

            if(mat[x][y]==turno || mat[x][y]==5){
                    break;
            }

            if(mat[x][y]==0 && x!=8 && y!=8){
                //cout<<"x6: "<<x<<endl;
                //cout<<"y6: "<<y<<endl;
                    mat[x][y]=5;
                    break;
            }
        }
    }

    if(mat[x0][y0-1]==w){ //horizontal hacia la izquierda

        x=x0;
        y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                y--;

            if(mat[x][y]==turno || mat[x][y]==5){
                    break;
            }

            if(mat[x][y]==0 && y!=-1){
                //cout<<"x7: "<<x<<endl;
                //cout<<"y7: "<<y<<endl;
                    mat[x][y]=5;
                    break;
            }
        }
    }

    if(mat[x0][y0+1]==w){ //horizontal hacia la derecha

         x=x0;
         y=y0;

        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            y++;

            if(mat[x][y]==turno || mat[x][y]==5){
                break;
            }

            if(mat[x][y]==0 && y!=8){
                //cout<<"x8: "<<x<<endl;
                //cout<<"y8: "<<y<<endl;
                mat[x][y]=5;
                break;
            }
        }

    }
}

void Othello::actual(int mat[8][8], int turno){

        for(int i=0; i<8;i++){

            for(int j=0;j<8;j++){

                if(mat[i][j]==turno){

                    //funcionar que envia posicion
                    evaluar(mat, i, j, turno);
                }
            }
        }
}

void Othello::poner(int mat[8][8], int x, int y, int turno){

    for(int i=0; i<8;i++){

        for(int j=0;j<8;j++){

            if(i==x && j==y && mat[i][j]==5){
                mat[i][j]=turno;
            }

        }
    }
}

bool Othello::puedeJugar(int mat[][8]){ //evalua si hay movimiento en el turno


    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(mat[i][j]==5){
                return true;
            }
        }
    }

    return false;
}

void Othello::evaluarContrario(int mat[8][8], int x, int y, int turno){ //evaluando las 8 posiciones

    int i=0,j=0;
    int a=0,b=0;
    int w;
    int x0=x, y0=y; //tomando valores iniciales de X y Y
    int vecPos[20][2];
    int cont=0;
    int contG=-1;

    if(turno==1){ //evalua la w en la matriz, sera el otro usuario en la matriz
        w=2;
    }else{
        w=1;
    }

    if(mat[x0-1][y0-1]==w){//diagonal izquierda superior

        x=x0;
        y=y0;
        contG+=cont;

        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x--;
            y--;

            if(mat[x][y]==0){

                break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"1"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){
                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if((mat[x0-1][y0+1]==w)){ //diagonal derecha superior

        x=x0;
        y=y0;
        contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x--;
                y++;

            if(mat[x][y]==0){
                break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"2"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){

                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if(mat[x0-1][y0]==w){ //vertical hacia arriba

        x=x0;
        y=y0;
        contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x--;

            if(mat[x][y]==0){
                    break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"3"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){

                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if(mat[x0+1][y0]==w){ //vertical hacia abajo

         x=x0;
         y=y0;
         contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x++;

            if(mat[x][y]==0){
                break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"4"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){

                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if(mat[x0+1][y0-1]==w){//diagonal izquierda inferior

        x=x0;
         y=y0;
         contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            x++;
            y--;

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
            //	cout<<"5"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){

                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if((mat[x0+1][y0+1]==w)){ //diagonal derecha inferior

        x=x0;
        y=y0;

        contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                x++;
                y++;

            if(mat[x][y]==0){
                    break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"6"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){ //colorea

                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

    if(mat[x0][y0-1]==w){ //horizontal hacia la izquierda

        x=x0;
        y=y0;
        contG+=cont;
        cont=0;

    //	system("PAUSE");
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

                y--;

            if(mat[x][y]==0){
                    break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"7"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){
                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;

                }

                break;
            }
        }
    }

    if(mat[x0][y0+1]==w){ //horizontal hacia la derecha

         x=x0;
         y=y0;
            contG+=cont;
        cont=0;
        while((x>=0 && x<=7) && (y>=0 && y<=7)){

            y++;

            if(mat[x][y]==0){
                break;
            }

            if(mat[x][y]==w){
                vecPos[i][0]=x;
                vecPos[i][1]=y;
                i++;
                cont++;

            }

            if(mat[x][y]==5){
                  break;
             }

            if(mat[x][y]==turno){
                //cout<<"8"<<endl;
                for(int k=contG+1;k<contG+cont+1;k++){
                    a=vecPos[k][0];
                    b=vecPos[k][1];
                    mat[a][b]=turno;
                }

                break;
            }
        }
    }

}

void Othello::limpiar(int mat[8][8]){

    for(int i=0; i<8;i++){

        for(int j=0;j<8;j++){


            if(mat[i][j]==5){
               mat[i][j]=0;
            }
        }
    }
}

void Othello::contarFichas(int mat[][8], int &blancas, int &negras){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){

            if(mat[i][j]==1){
                negras++;
            }
            if(mat[i][j]==2){
                blancas++;
            }
        }
    }
    QString ne("Azules: ");
    QString bl("Blancas: ");
    QString n = QString::number(negras);
    QString b = QString::number(blancas);
    ne.append(n);
    bl.append(b);
    ui->labelNegras->setText(ne);
    ui->labelBlancas->setText(bl);
    //cout << endl << "Negras(1): " << negras << "  Blancas(2): " << blancas << endl << endl;
}

void Othello::on_BotonNuevo_clicked()
{
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

    iniciar(mat, this->band);
}

void Othello::on_ganador_clicked(){
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

    iniciar(mat, this->band);
}

void Othello::on_jugvsjug_clicked(){
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

    iniciar(mat, false);
}

void Othello::on_jugvscom_clicked(){
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

    iniciar(mat, true);
}

void Othello::on_Ayuda_clicked(){

    ui->ayudita->setEnabled(true);
    ui->ayudita->setVisible(true);
}

void Othello::on_Creditos_clicked(){

    ui->creditoMenu->setEnabled(true);
    ui->creditoMenu->setVisible(true);
}

void Othello::on_facil_clicked(){

    nivel=false;
    qDebug()<<"false";
}

void Othello::on_dificil_clicked(){

    nivel=true;
    qDebug()<<"true";
}

void Othello::on_BotonSuge_clicked(){

    this->suge=true;
}

void Othello::inicializar_tablero(int ma[][8], int m[][8]){
    for(int fila=0; fila<8; fila++){
        for(int col=0; col<8; col++){
            ma[fila][col] =m[fila][col];
        }
     }
}

int Othello::contarLibres(int mat[][8]){
    int cont=0;
    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(mat[i][j]==5){
                cont++;
            }
        }
    }

    return cont;
}

int Othello::funcion_heuristica(int mat[][8]){

    int mi_ficha = 2;
    int op_ficha = 1;

    int mis_fichas = 0, op_fichas = 0, i, j, k, my_front_tiles = 0, opp_front_tiles = 0, x, y;
    double p = 0, c = 0, l = 0, m = 0, f = 0, d = 0;

    int X1[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int Y1[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int V[][8]={
        {20, -3, 11, 8, 8, 11, -3, 20},
        {-3, -7, -4, 1, 1, -4, -7, -3},
        {11, -4, 2, 2, 2, 2, -4, 11},
        {8, 1, 2, -3, -3, 2, 1, 8},
        {8, 1, 2, -3, -3, 2, 1, 8},
        {11, -4, 2, 2, 2, 2, -4, 11},
        {-3, -7, -4, 1, 1, -4, -7, -3},
        {20, -3, 11, 8, 8, 11, -3, 20}
    };

// Piece difference, frontier disks and disk squares
//Diferencia de piezas, discos de frontera y cuadrados de disco
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)  {
            if(mat[i][j] == mi_ficha)  {
                d += V[i][j];
                mis_fichas++;
            } else if(mat[i][j] == op_ficha)  {
                d -= V[i][j];
                op_fichas++;
            }
            if(mat[i][j] != 0)   {
                for(k=0; k<8; k++)  {
                    x = i + X1[k];
                    y = j + Y1[k];
                    if(x >= 0 && x < 8 && y >= 0 && y < 8 && mat[x][y] == 0) {
                        if(mat[i][j] == mi_ficha)  my_front_tiles++;
                        else opp_front_tiles++;
                        break;
                    }
                }
            }
        }
    if(mis_fichas > op_fichas)
        p = (100.0 * mis_fichas)/(mis_fichas + op_fichas);
    else if(mis_fichas < op_fichas)
        p = -(100.0 * op_fichas)/(mis_fichas + op_fichas);
    else p = 0;

    if(my_front_tiles > opp_front_tiles)
        f = -(100.0 * my_front_tiles)/(my_front_tiles + opp_front_tiles);
    else if(my_front_tiles < opp_front_tiles)
        f = (100.0 * opp_front_tiles)/(my_front_tiles + opp_front_tiles);
    else f = 0;

// Corner occupancy
    mis_fichas = op_fichas = 0;
    if(mat[0][0] == mi_ficha) mis_fichas++;
    else if(mat[0][0] == op_ficha) op_fichas++;
    if(mat[0][7] == mi_ficha) mis_fichas++;
    else if(mat[0][7] == op_ficha) op_fichas++;
    if(mat[7][0] == mi_ficha) mis_fichas++;
    else if(mat[7][0] == op_ficha) op_fichas++;
    if(mat[7][7] == mi_ficha) mis_fichas++;
    else if(mat[7][7] == op_ficha) op_fichas++;
    c = 25 * (mis_fichas - op_fichas);

// cercanos a las esquinas
    mis_fichas = op_fichas = 0;
    if(mat[0][0] == 0)   {
        if(mat[0][1] == mi_ficha) mis_fichas++;
        else if(mat[0][1] == op_ficha) op_fichas++;
        if(mat[1][1] == mi_ficha) mis_fichas++;
        else if(mat[1][1] == op_ficha) op_fichas++;
        if(mat[1][0] == mi_ficha) mis_fichas++;
        else if(mat[1][0] == op_ficha) op_fichas++;
    }
    if(mat[0][7] == 0)   {
        if(mat[0][6] == mi_ficha) mis_fichas++;
        else if(mat[0][6] == op_ficha) op_fichas++;
        if(mat[1][6] == mi_ficha) mis_fichas++;
        else if(mat[1][6] == op_ficha) op_fichas++;
        if(mat[1][7] == mi_ficha) mis_fichas++;
        else if(mat[1][7] == op_ficha) op_fichas++;
    }
    if(mat[7][0] == 0)   {
        if(mat[7][1] == mi_ficha) mis_fichas++;
        else if(mat[7][1] == op_ficha) op_fichas++;
        if(mat[6][1] == mi_ficha) mis_fichas++;
        else if(mat[6][1] == op_ficha) op_fichas++;
        if(mat[6][0] == mi_ficha) mis_fichas++;
        else if(mat[6][0] == op_ficha) op_fichas++;
    }
    if(mat[7][7] == 0)   {
        if(mat[6][7] == mi_ficha) mis_fichas++;
        else if(mat[6][7] == op_ficha) op_fichas++;
        if(mat[6][6] == mi_ficha) mis_fichas++;
        else if(mat[6][6] == op_ficha) op_fichas++;
        if(mat[7][6] == mi_ficha) mis_fichas++;
        else if(mat[7][6] == op_ficha) op_fichas++;
    }
    l = -12.5 * (mis_fichas - op_fichas);

// Mobility

    int mataux[8][8];
    inicializar_tablero(mataux,mat);
    actual(mataux,2);
    mis_fichas = contarLibres(mataux);

    inicializar_tablero(mataux,mat);
    actual(mataux,1);
    op_fichas = contarLibres(mataux);



    if(mis_fichas > op_fichas)
        m = (100.0 * mis_fichas)/(mis_fichas + op_fichas);
    else if(mis_fichas < op_fichas)
        m = -(100.0 * op_fichas)/(mis_fichas + op_fichas);
    else m = 0;

// final weighted score
    double puntaje = (10 * p) + (801.724 * c) + (382.026 * l) + (78.922 * m) + (74.396 * f) + (10 * d);
    return puntaje;
}

void Othello::llenarVectorPosiciones(int mat[][8], Posicion posiciones[]){
    int k=0;
    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(mat[i][j]==5){
                posiciones[k].setX(i);
                posiciones[k].setY(j);
                k++;
            }
        }
    }

}

int Othello::crear_posibles_tableros(int mat[][8], int turno){

    int mapa_aux[8][8];
        int mapa_aux2[8][8];
        int mapa_aux3[8][8];
        int mapa_aux4[8][8];

        int tableros1=0;
        int tableros2=0;
        int tableros3=0;
        int tableros4=0;

        int cant5=0;

        cant5= contarLibres(mat);
        Posicion posiciones[cant5];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
        llenarVectorPosiciones(mat,posiciones);


        Lista<Tablero> nivel1;
        Lista<Tablero> nivel2;
        Lista<Tablero> nivel3;
        Lista<Tablero> nivel4;

        inicializar_tablero(mapa_aux, mat); //Guardo el tablero inicial

        int p=0;
        //cout<<"Mapa inicial "<<endl;
        //mostrar(mat);
        //cout<<endl;
        while(tableros1<cant5){
            //cout << "Nivel 1" << endl;
            //---------------------------------NIVEL 1
            poner(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 2);
            evaluarContrario(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 2);
            limpiar(mapa_aux);
            //mostrar(mapa_aux); //Mostrando los posibles tableros

            Tablero tabNiv1(mapa_aux, p, tableros1, -1, 0,0);
            p++;
            nivel1.agregar(tabNiv1);

            actual(mapa_aux,1);
            inicializar_tablero(mapa_aux2, mapa_aux); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador


            int cant = contarLibres(mapa_aux2);

            if(cant!=0){

                Posicion posiciones2[cant];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                llenarVectorPosiciones(mapa_aux2,posiciones2);

                while(tableros2<cant){
                    //cout << "Nivel 2" << endl<<endl;
                    poner(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 1);
                    evaluarContrario(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 1);
                    limpiar(mapa_aux2);
                    //mostrar(mapa_aux2); //Mostrando los posibles tableros

                    Tablero tabNiv2(mapa_aux2, p, tableros2, tableros1,0,0);
                    p++;
                    nivel2.agregar(tabNiv2);
                            //cout<<endl<<"cambio"<<endl;
                            //mostrar(mapa_aux2);
                    actual(mapa_aux2,2);
                    //cout<<endl<<"xsxwxwx"<<endl;
                            //mostrar(mapa_aux2);
                    inicializar_tablero(mapa_aux3, mapa_aux2); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador
                    //cout<<"con 5 "<< endl;

                    int cant3 = contarLibres(mapa_aux3);

                    if(cant3!=0){

                        Posicion posiciones3[cant3];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                        llenarVectorPosiciones(mapa_aux3,posiciones3);
                            //cout<<endl<<"este mismitico no e"<<endl;
                            //	mostrar(mapa_aux3);
                        while(tableros3<cant3){
                            //cout << "Nivel 3" << endl<<endl;
                            poner(mapa_aux3, posiciones3[tableros3].getX(), posiciones3[tableros3].getY(), 2);
                            evaluarContrario(mapa_aux3, posiciones3[tableros3].getX(), posiciones3[tableros3].getY(), 2);

                            //cout<<endl<<"X: "<<posiciones3[tableros3].getX()<<" Y: "<<posiciones3[tableros3].getY()<<endl;

                            //mostrar(mapa_aux3);
                            //cout<<endl;
                            limpiar(mapa_aux3);
                            //mostrar(mapa_aux3); //Mostrando los posibles tableros

                            Tablero tabNiv3(mapa_aux3,p, tableros3, tableros2,0,0);
                            p++;
                            nivel3.agregar(tabNiv3);

                            actual(mapa_aux3,1);
                           // cout<<endl; mostrar(mapa_aux3);
                            inicializar_tablero(mapa_aux4, mapa_aux3); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador
                            //	cout<<endl;
                                //mostrar(mapa_aux4);
                            int cant4 = contarLibres(mapa_aux4);

                            if(cant4!=0){

                                Posicion posiciones4[cant4];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                                llenarVectorPosiciones(mapa_aux4,posiciones4);

                                //cout<<endl<<"cant4: "<<cant4;
                                while(tableros4<cant4){
                                    //	cout << "Nivel 4" << endl<<endl;
                                    poner(mapa_aux4, posiciones4[tableros4].getX(), posiciones4[tableros4].getY(), 1);
                                    evaluarContrario(mapa_aux4, posiciones4[tableros4].getX(), posiciones4[tableros4].getY(), 1);
                                    limpiar(mapa_aux4);
                                    //mostrar(mapa_aux4); //Mostrando los posibles tableros

                                    //Crear lista de valores que me arroje la funcion heuristica
                                    int puntaje=funcion_heuristica(mapa_aux4);
                                   // cout<<endl<<"puntaje: "<<puntaje;
                                    Tablero tabNiv4(mapa_aux4, puntaje, tableros4, tableros3,0,0);
                                    nivel4.agregar(tabNiv4);

                                    inicializar_tablero(mapa_aux4,mapa_aux3);
                                    tableros4++;
                                }

                                int pun4, codPa4;
                                pun4=nivel4.get_cab()->get_inf().getPuntaje();
                                codPa4=nivel4.get_cab()->get_inf().getCodPa();
                                Nodo<Tablero> *cabNiv3;
                                cabNiv3=nivel3.get_cab();

                                while(cabNiv3){
                                    if(cabNiv3->get_inf().getCod()==codPa4){
                                        int m3[8][8];
                                        cabNiv3->get_inf().getTablero(m3);
                                        Tablero ta3(m3, pun4, cabNiv3->get_inf().getCod(), cabNiv3->get_inf().getCodPa(),0,0);
                                        cabNiv3->set_inf(ta3);
                                    }
                                    cabNiv3=cabNiv3->get_sig();
                                }

                                inicializar_tablero(mapa_aux3,mapa_aux2);

                                tableros4=0;
                                nivel4.vaciar();
                            }
                            tableros3++;
                        }

                        int pun3, codPa3;
                        pun3=nivel3.getUltimo()->get_inf().getPuntaje();
                        codPa3=nivel3.getUltimo()->get_inf().getCodPa();
                        Nodo<Tablero> *cabNiv2;
                        cabNiv2=nivel2.get_cab();

                        while(cabNiv2){
                            if(cabNiv2->get_inf().getCod()==codPa3){
                                int m2[8][8];
                                cabNiv2->get_inf().getTablero(m2);
                                Tablero ta2(m2, pun3, cabNiv2->get_inf().getCod(), cabNiv2->get_inf().getCodPa(),0,0);
                                cabNiv2->set_inf(ta2);
                            }
                            cabNiv2=cabNiv2->get_sig();
                        }

                        inicializar_tablero(mapa_aux2, mapa_aux);

                        tableros3=0;
                        nivel3.vaciar();
                    }
                    tableros2++;
                }
                int pun2, codPa2;
                Nodo<Tablero> *auxi2 = new Nodo<Tablero>();
                pun2=nivel2.get_cab()->get_inf().getPuntaje();
                codPa2=nivel2.get_cab()->get_inf().getCodPa();
                Nodo<Tablero> *cabNiv1;
                cabNiv1=nivel1.get_cab();
                while(cabNiv1){
                    if(cabNiv1->get_inf().getCod()==codPa2){
                        int m1[8][8];
                        cabNiv1->get_inf().getTablero(m1);
                        Tablero ta1(m1, pun2, cabNiv1->get_inf().getCod(), cabNiv1->get_inf().getCodPa(),0,0);
                        cabNiv1->set_inf(ta1);
                    }
                    cabNiv1=cabNiv1->get_sig();
                }

                inicializar_tablero(mapa_aux, mat);

                tableros2=0;
                nivel2.vaciar();
            }
            tableros1++;
        }
        nivel1.getUltimo()->get_inf().getTablero(mat);
        //cout<<endl<<endl;
        //mostrar(mat);
        //nivel1.imprimir();
        return 0;
}

int Othello::nivel_facil(int mat[][8], int turno){

    int mapa_aux[8][8];
        int mapa_aux2[8][8];
        int mapa_aux3[8][8];
        int mapa_aux4[8][8];

        int tableros1=0;
        int tableros2=0;
        int tableros3=0;
        int tableros4=0;

        int cant5=0;

        cant5= contarLibres(mat);
        Posicion posiciones[cant5];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
        llenarVectorPosiciones(mat,posiciones);


        Lista<Tablero> nivel1;
        Lista<Tablero> nivel2;
        Lista<Tablero> nivel3;
        Lista<Tablero> nivel4;

        inicializar_tablero(mapa_aux, mat); //Guardo el tablero inicial

        int p=0;
        //cout<<"Mapa inicial "<<endl;
        //mostrar(mat);
        //cout<<endl;
        while(tableros1<cant5){
            //cout << "Nivel 1" << endl;
            //---------------------------------NIVEL 1
            poner(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 2);
            evaluarContrario(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 2);
            limpiar(mapa_aux);
            //mostrar(mapa_aux); //Mostrando los posibles tableros

            Tablero tabNiv1(mapa_aux, p, tableros1, -1, 0,0);
            p++;
            nivel1.agregar(tabNiv1);

            actual(mapa_aux,1);
            inicializar_tablero(mapa_aux2, mapa_aux); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador


            int cant = contarLibres(mapa_aux2);

            if(cant!=0){

                Posicion posiciones2[cant];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                llenarVectorPosiciones(mapa_aux2,posiciones2);

                while(tableros2<cant){


                    //cout << "Nivel 2" << endl<<endl;
                    poner(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 1);
                    evaluarContrario(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 1);
                    limpiar(mapa_aux2);
                    //mostrar(mapa_aux2); //Mostrando los posibles tableros

                    int puntaje=funcion_heuristica(mapa_aux2);

                    Tablero tabNiv2(mapa_aux2, puntaje, tableros2, tableros1,0,0);
                    p++;
                    nivel2.agregar(tabNiv2);
                            //cout<<endl<<"cambio"<<endl;
                            //mostrar(mapa_aux2);
                    actual(mapa_aux2,2);
                    //cout<<endl<<"xsxwxwx"<<endl;
                            //mostrar(mapa_aux2);
                    inicializar_tablero(mapa_aux2, mapa_aux); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador

                    tableros2++;
                }
                int pun2, codPa2;
                Nodo<Tablero> *auxi2 = new Nodo<Tablero>();
                pun2=nivel2.get_cab()->get_inf().getPuntaje();
                codPa2=nivel2.get_cab()->get_inf().getCodPa();
                Nodo<Tablero> *cabNiv1;
                cabNiv1=nivel1.get_cab();
                while(cabNiv1){
                    if(cabNiv1->get_inf().getCod()==codPa2){
                        int m1[8][8];
                        cabNiv1->get_inf().getTablero(m1);
                        Tablero ta1(m1, pun2, cabNiv1->get_inf().getCod(), cabNiv1->get_inf().getCodPa(),0,0);
                        cabNiv1->set_inf(ta1);
                    }
                    cabNiv1=cabNiv1->get_sig();
                }

                inicializar_tablero(mapa_aux, mat);

                tableros2=0;
                nivel2.vaciar();
            }
            tableros1++;
        }
        nivel1.getUltimo()->get_inf().getTablero(mat);
        //cout<<endl<<endl;
        //mostrar(mat);
        //nivel1.imprimir();
        return 0;
}

Posicion Othello::sugerencia(int mat[][8], int turno){

    int mapa_aux[8][8];
        int mapa_aux2[8][8];
        int mapa_aux3[8][8];
        int mapa_aux4[8][8];

        int tableros1=0;
        int tableros2=0;
        int tableros3=0;
        int tableros4=0;

        int cant5=0;

        cant5= contarLibres(mat);
        Posicion posiciones[cant5];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
        llenarVectorPosiciones(mat,posiciones);


        Lista<Tablero> nivel1;
        Lista<Tablero> nivel2;
        Lista<Tablero> nivel3;
        Lista<Tablero> nivel4;

        inicializar_tablero(mapa_aux, mat); //Guardo el tablero inicial

        int p=0;
        //cout<<"Mapa inicial "<<endl;
        //mostrar(mat);
        //cout<<endl;
        while(tableros1<cant5){
            //cout << "Nivel 1" << endl;
            //---------------------------------NIVEL 1
            poner(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 1);
            evaluarContrario(mapa_aux, posiciones[tableros1].getX(), posiciones[tableros1].getY(), 1);
            limpiar(mapa_aux);
            //mostrar(mapa_aux); //Mostrando los posibles tableros

            Tablero tabNiv1(mapa_aux, p, tableros1, -1, posiciones[tableros1].getX(), posiciones[tableros1].getY());
            p++;
            nivel1.agregar(tabNiv1);

            actual(mapa_aux,2);
            inicializar_tablero(mapa_aux2, mapa_aux); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador


            int cant = contarLibres(mapa_aux2);

            if(cant!=0){

                Posicion posiciones2[cant];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                llenarVectorPosiciones(mapa_aux2,posiciones2);

                while(tableros2<cant){
                    //cout << "Nivel 2" << endl<<endl;
                    poner(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 2);
                    evaluarContrario(mapa_aux2, posiciones2[tableros2].getX(), posiciones2[tableros2].getY(), 2);
                    limpiar(mapa_aux2);
                    //mostrar(mapa_aux2); //Mostrando los posibles tableros

                    Tablero tabNiv2(mapa_aux2, p, tableros2, tableros1, posiciones2[tableros2].getX(), posiciones2[tableros2].getY());
                    p++;
                    nivel2.agregar(tabNiv2);
                            //cout<<endl<<"cambio"<<endl;
                            //mostrar(mapa_aux2);
                    actual(mapa_aux2,1);
                    //cout<<endl<<"xsxwxwx"<<endl;
                            //mostrar(mapa_aux2);
                    inicializar_tablero(mapa_aux3, mapa_aux2); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador
                    //cout<<"con 5 "<< endl;

                    int cant3 = contarLibres(mapa_aux3);

                    if(cant3!=0){

                        Posicion posiciones3[cant3];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                        llenarVectorPosiciones(mapa_aux3,posiciones3);
                            //cout<<endl<<"este mismitico no e"<<endl;
                            //	mostrar(mapa_aux3);
                        while(tableros3<cant3){
                            //cout << "Nivel 3" << endl<<endl;
                            poner(mapa_aux3, posiciones3[tableros3].getX(), posiciones3[tableros3].getY(), 1);
                            evaluarContrario(mapa_aux3, posiciones3[tableros3].getX(), posiciones3[tableros3].getY(), 1);

                            //cout<<endl<<"X: "<<posiciones3[tableros3].getX()<<" Y: "<<posiciones3[tableros3].getY()<<endl;

                            //mostrar(mapa_aux3);
                            //cout<<endl;
                            limpiar(mapa_aux3);
                            //mostrar(mapa_aux3); //Mostrando los posibles tableros

                            Tablero tabNiv3(mapa_aux3,p, tableros3, tableros2, posiciones3[tableros3].getX(), posiciones3[tableros3].getY());
                            p++;
                            nivel3.agregar(tabNiv3);

                            actual(mapa_aux3,2);
                           // cout<<endl; mostrar(mapa_aux3);
                            inicializar_tablero(mapa_aux4, mapa_aux3); //Guardo mi mapa creado en un mapa aux  ya con los 5 del otro jugador
                            //	cout<<endl;
                                //mostrar(mapa_aux4);
                            int cant4 = contarLibres(mapa_aux4);

                            if(cant4!=0){

                                Posicion posiciones4[cant4];//Vector de las posiciones x=fila y=columna de donde se encuentra cada uno de los 5
                                llenarVectorPosiciones(mapa_aux4,posiciones4);

                                //cout<<endl<<"cant4: "<<cant4;
                                while(tableros4<cant4){
                                    //	cout << "Nivel 4" << endl<<endl;
                                    poner(mapa_aux4, posiciones4[tableros4].getX(), posiciones4[tableros4].getY(), 2);
                                    evaluarContrario(mapa_aux4, posiciones4[tableros4].getX(), posiciones4[tableros4].getY(), 2);
                                    limpiar(mapa_aux4);
                                    //mostrar(mapa_aux4); //Mostrando los posibles tableros

                                    //Crear lista de valores que me arroje la funcion heuristica
                                    int puntaje=funcion_heuristica(mapa_aux4);
                                   // cout<<endl<<"puntaje: "<<puntaje;
                                    Tablero tabNiv4(mapa_aux4, puntaje, tableros4, tableros3, posiciones4[tableros4].getX(), posiciones4[tableros4].getY());
                                    nivel4.agregar(tabNiv4);

                                    inicializar_tablero(mapa_aux4,mapa_aux3);
                                    tableros4++;
                                }

                                int pun4, codPa4;
                                pun4=nivel4.get_cab()->get_inf().getPuntaje();
                                codPa4=nivel4.get_cab()->get_inf().getCodPa();
                                Nodo<Tablero> *cabNiv3;
                                cabNiv3=nivel3.get_cab();

                                while(cabNiv3){
                                    if(cabNiv3->get_inf().getCod()==codPa4){
                                        int m3[8][8];
                                        cabNiv3->get_inf().getTablero(m3);
                                        Tablero ta3(m3, pun4, cabNiv3->get_inf().getCod(), cabNiv3->get_inf().getCodPa(), cabNiv3->get_inf().getX(),cabNiv3->get_inf().getY());
                                        cabNiv3->set_inf(ta3);
                                    }
                                    cabNiv3=cabNiv3->get_sig();
                                }

                                inicializar_tablero(mapa_aux3,mapa_aux2);

                                tableros4=0;
                                nivel4.vaciar();
                            }
                            tableros3++;
                        }

                        int pun3, codPa3;
                        pun3=nivel3.getUltimo()->get_inf().getPuntaje();
                        codPa3=nivel3.getUltimo()->get_inf().getCodPa();
                        Nodo<Tablero> *cabNiv2;
                        cabNiv2=nivel2.get_cab();

                        while(cabNiv2){
                            if(cabNiv2->get_inf().getCod()==codPa3){
                                int m2[8][8];
                                cabNiv2->get_inf().getTablero(m2);
                                Tablero ta2(m2, pun3, cabNiv2->get_inf().getCod(), cabNiv2->get_inf().getCodPa(), cabNiv2->get_inf().getX(),cabNiv2->get_inf().getY());
                                cabNiv2->set_inf(ta2);
                            }
                            cabNiv2=cabNiv2->get_sig();
                        }

                        inicializar_tablero(mapa_aux2, mapa_aux);

                        tableros3=0;
                        nivel3.vaciar();
                    }
                    tableros2++;
                }
                int pun2, codPa2;
                Nodo<Tablero> *auxi2 = new Nodo<Tablero>();
                pun2=nivel2.get_cab()->get_inf().getPuntaje();
                codPa2=nivel2.get_cab()->get_inf().getCodPa();
                Nodo<Tablero> *cabNiv1;
                cabNiv1=nivel1.get_cab();
                while(cabNiv1){
                    if(cabNiv1->get_inf().getCod()==codPa2){
                        int m1[8][8];
                        cabNiv1->get_inf().getTablero(m1);
                        Tablero ta1(m1, pun2, cabNiv1->get_inf().getCod(), cabNiv1->get_inf().getCodPa(), cabNiv1->get_inf().getX(),cabNiv1->get_inf().getY());
                        cabNiv1->set_inf(ta1);
                    }
                    cabNiv1=cabNiv1->get_sig();
                }

                inicializar_tablero(mapa_aux, mat);

                tableros2=0;
                nivel2.vaciar();
            }
            tableros1++;
        }
        //nivel1.getUltimo()->get_inf().getTablero(mat);
        //cout<<endl<<endl;
        //mostrar(mat);
        //nivel1.imprimir();

        Posicion retorna(nivel1.getUltimo()->get_inf().getX(),nivel1.getUltimo()->get_inf().getY());

        return retorna;
}


void Othello::onGroupButtonClicked(int id){


        if(this->juega==1){
            ui->BotonSuge->setEnabled(false);
            int x, y;
            x=id/10;
            y=id-(x*10);
            if(this->mat[x][y]==5){
                this->jugon = true;
               ui->jugador->setText("Jugador 1");
                //this->juega=2;
                this->poner(this->mat,x,y,juega);
                this->pudon = true;
                this->pintar();
                this->evaluarContrario(this->mat, x, y, juega);
                this->pintar();
                this->limpiar(this->mat);
                this->pintar();

                ui->jugador->setText("Jugador 2");
                this->actual(this->mat, 2);
                pintar();
                this->cantBlancas = 0;
                this->cantNegras = 0;
                this->contarFichas(this->mat, this->cantBlancas,this->cantNegras);

                 juega=2;

            }else{
                this->pudon = false;
            }
         }
    if(band==false){
           if(this->juega==2){
               ui->BotonSuge->setEnabled(true);
               int x, y;
               x=id/10;
               y=id-(x*10);
               if(this->mat[x][y]==5){
                   this->jugob = true;
                  ui->jugador->setText("Jugador 2");
                   //this->juega=2;
                   this->poner(this->mat,x,y,juega);
                   this->pudob = true;
                   this->pintar();
                   this->evaluarContrario(this->mat, x, y, juega);
                   this->pintar();
                   this->limpiar(this->mat);
                   this->pintar();

                   ui->jugador->setText("Jugador 1");
                   this->actual(this->mat, 1);
                   pintar();
                   this->cantBlancas = 0;
                   this->cantNegras = 0;
                   this->contarFichas(this->mat, this->cantBlancas,this->cantNegras);

                    juega=1;

               }else{
                   this->pudon = false;
               }
            }
           if(jugon){
                   juega=2;
                   jugon=false;
               }
               if(jugob){
                   juega=1;
                   jugob=false;
               }

     }
}


void Othello::revisar(){
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(update()));

}


void Othello::timerEvent(QTimerEvent *event)
{
    //qDebug() << "Update...";
    if(jugon ){
            juega=2;
            jugon=false;

            //TURNO COMPUTADORA
            this->cantBlancas = 0;
            this->cantNegras = 0;
            this->contarFichas(this->mat, this->cantBlancas,this->cantNegras);
            ui->BotonSuge->setDisabled(false);
            if(this->puedeJugar(this->mat)){
                this->jugob = true;
                ui->jugador->setText("Jugador 2");
                //mat[x][y]=juega;
                this->pudob = true;
                this->pintar();
                //this->evaluarContrario(this->mat, x, y, juega);

                if(nivel==false){
                    this->nivel_facil(this->mat, juega);

                }else{
                    this->crear_posibles_tableros(this->mat, juega);
                }

                this->pintar();
                //this->limpiar(this->mat);

                ui->jugador->setText("Jugador 1");
                this->actual(this->mat, 1);
                pintar();
                this->cantBlancas = 0;
                this->cantNegras = 0;
                this->contarFichas(this->mat, this->cantBlancas,this->cantNegras);
            }else{
                this->pudob = false;
            }
            juega=1;
            jugon=false;
    }
    if(jugob || pudob==false){
        juega=1;
        jugob=false;
    }

    if(juega==1){

        if(!this->puedeJugar(this->mat)){
                juega=2;
                jugon=true;
                jugob=false;
                this->actual(this->mat, 2);
        }
    }

    if(juega==2){

        if(!this->puedeJugar(this->mat)){
                juega=1;
                jugob=true;
                jugon=false;
                this->actual(this->mat, 1);
        }
    }

    int mat_llena=0;
    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(mat[i][j]!=5 && mat[i][j]!=0){

                mat_llena++;
            }
        }

    }

    if(mat_llena==64 ||(pudon==false && pudob==false)){ //Ninguno puede poner entonces se evalua quien gano
        if(this->cantBlancas==this->cantNegras){
               ui->ganador->setText("Empate");
               ui->ganador->setVisible(true);
               ui->ganador->setEnabled(true);
        }else{
            if(this->cantBlancas>this->cantNegras){
                ui->ganador->setText("Ganan las blancas");
                 ui->ganador->setVisible(true);
                 ui->ganador->setEnabled(true);
            }else{
                ui->ganador->setText("Ganan las azules");
                 ui->ganador->setVisible(true);
                 ui->ganador->setEnabled(true);
            }
        }
      }


    if(suge==true){

        int pos;
        Posicion aquella;
        aquella=sugerencia(this->mat,1);

        for(int i=0;i<8;i++){

            for(int j=0;j<8;j++){

                if(i==aquella.getX() && j==aquella.getY()){

                    pos = i*10 + j;

                    QPixmap pixmap;
                    if(pixmap.load("otramarca.png")){
                        QIcon ButtonIcon;
                        ButtonIcon.addPixmap(pixmap);
                        ui->buttonGroup->button(pos)->setIcon(ButtonIcon);
                        ui->buttonGroup->button(pos)->setIconSize(pixmap.rect().size());
                    }
                }
            }
        }

        suge=false;
    }

    if(band==false){
        ui->facil->setDisabled(true);
        ui->facil->setVisible(false);

        ui->dificil->setDisabled(true);
        ui->dificil->setVisible(false);
    }
}
