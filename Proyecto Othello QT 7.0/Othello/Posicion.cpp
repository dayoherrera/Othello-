

class Posicion{
	private:
		int x,y;
	public:
		Posicion(){}
		Posicion(int x, int y){
			this->x=x;
			this->y=y;
		}
		
		int getX(){ return this->x; }
		int getY(){ return this->y; }
		void setX(int x){ this->x=x; }
		void setY(int y){ this->y=y; }
		void imprimir(){
            //cout << "X: " << this->x << " Y: " << this->y << endl;
		}
};
