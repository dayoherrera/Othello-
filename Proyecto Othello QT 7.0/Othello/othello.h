#ifndef OTHELLO_H
#define OTHELLO_H
#include "Posicion.cpp"
#include "Tablero.cpp"
#include <QWidget>
#include<QTimerEvent>

namespace Ui {
class Othello;
}

class Othello : public QWidget
{
    Q_OBJECT
    int mat[8][8];
    int juega;
    bool jugob, jugon, band;
    bool pudob, pudon;
    bool puedeJ;
    bool suge;
    bool nivel;
    QTimer *timer;
    int timerId;
    int x,y;
    int cantBlancas, cantNegras;
public:
    explicit Othello(QWidget *parent = 0);

    void iniciar(int mat[8][8], bool band);
    void mostrar();
    void pintar();
    void limpiar(int mat[8][8]);
    void poner(int mat[8][8], int x, int y, int turno);
    void evaluar(int mat[8][8], int x, int y, int turno);
    void evaluarContrario(int mat[8][8], int x, int y, int turno);
    void actual(int mat[8][8], int turno);
    bool puedeJugar(int mat[][8]);
    void contarFichas(int mat[][8], int &blancas, int &negras);
    void inicializar_tablero(int ma[][8], int m[][8]);
    int contarLibres(int mat[][8]);
    int funcion_heuristica(int mat[][8]);
    void llenarVectorPosiciones(int mat[][8], Posicion posiciones[]);
    int crear_posibles_tableros(int mat[][8], int turno);
    int nivel_facil(int mat[][8], int turno);
    Posicion sugerencia(int mat[][8], int turno);
    void revisar();
    void creandoGrupo();
    QString getJugadorDeTurno();

    ~Othello();

private slots:
    void onGroupButtonClicked(int id);

    void on_BotonNuevo_clicked();
    void on_ganador_clicked();
    void on_jugvsjug_clicked();
    void on_jugvscom_clicked();
    void on_Ayuda_clicked();
    void on_Creditos_clicked();
    void on_BotonSuge_clicked();
    void on_facil_clicked();
    void on_dificil_clicked();

protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::Othello *ui;
};

#endif // OTHELLO_H
