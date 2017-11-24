

class Tablero{
	private:
		int tab[8][8];
		int puntaje;
		int cod;
		int codPa;
        int x,y;

	public:
		Tablero(){}
        Tablero(int tabl[8][8], int puntaje, int cod, int codPa, int x, int y){
    		int fila, col;
    		for(fila=0; fila<8; fila++){
        		for(col=0; col<8; col++){
            		this->tab[fila][col]=tabl[fila][col];
        		}
    		}
			this->puntaje=puntaje;
			this->cod=cod;
			this->codPa=codPa;
            this->x=x;
            this->y=y;
		}
		int getPuntaje(){ return this->puntaje; }
        int getCod(){ return this->cod; }
        int getX(){ return this->x; }
        int getY(){ return this->y; }
		int getCodPa(){ return this->codPa; }
		
		void setCod(int puntaje){ this->cod=cod; }
		void setCodPa(int puntaje){ this->codPa=codPa; }
		void setPuntaje(int puntaje){ this->puntaje=puntaje; }
		
		void getTablero(int mapa[8][8]){ 
    		int fila, col;
    		for(fila=0; fila<8; fila++){
        		for(col=0; col<8; col++){
            		mapa[fila][col]=this->tab[fila][col];
        		}
    		}
		}
		
		
		void setTablero(int mapa[8][8]){ 
    		int fila, col;
    		for(fila=0; fila<8; fila++){
        		for(col=0; col<8; col++){
            		this->tab[fila][col]=mapa[fila][col];
        		}
    		}
		}
		
		void imprimir(){
    		int fila, col;
    //		cout<<"Tablero - puntaje: "<<this->puntaje<<endl;
    		for(fila=0; fila<8; fila++){
        		for(col=0; col<8; col++){
            //		cout<< this->tab[fila][col] << " ";
        		}
        //		cout<<endl;
    		}
		}
		
		bool operator< ( Tablero t ) { return this->puntaje<t.getPuntaje();  }
       	bool operator> ( Tablero t ) { return this->puntaje>t.getPuntaje();  }
       	bool operator==( Tablero t ) { return this->puntaje==t.getPuntaje();  }
      // 	friend ostream &operator<< ( ostream &p, Tablero t ) { return p << "Puntaje: " << t.puntaje << endl;}
};
