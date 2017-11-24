

template <class T>
class Nodo
{
      T info;
      Nodo<T> *ant, *sig;
      public:
             Nodo()  { ant=sig=NULL; }
             void  set_inf( T val )      { info=val; }
             void  set_ant( Nodo<T> *p ) { ant= p;   }
             void  set_sig( Nodo<T> *p ) { sig= p;   }
             T get_inf()        { return info; }
             Nodo<T> *get_sig() { return sig;  }
             Nodo<T> *get_ant() { return ant;  }

};

template <class T>
class Lista
{
      Nodo<T> *cab;
      int tamano;
 public:
        Nodo <T> *get_cab() { return cab; }
        Nodo<T> *getUltimo();
        Lista ( ) { cab=NULL; tamano=0; }
        int  agregar  ( T nue );
        bool buscar   ( T &bus, Nodo<T> **q=NULL);
        int  eliminar ( T &eli);
        void imprimir ( );
        int getTamano(){ return this->tamano; }
        void vaciar();
};

template <class T>
int Lista<T>::agregar ( T nue )
{
  Nodo<T> *p, *q, *pnue;
  pnue= new Nodo<T>;
  if ( !pnue ) return 0;
  pnue->set_inf ( nue );
  
  	p= cab;
  while (p)
    if ( nue<p->get_inf() ) //el < para ordenarlos de menos a mayor
      break;
    else
    {
      q= p;
      p= p->get_sig();
    }
  pnue->set_sig( p );
  if (p==cab) {
     if ( cab ) cab->set_ant(pnue);
     cab= pnue;

  }
  else if (p)  {
       pnue->set_ant(p->get_ant());
       p->get_ant()->set_sig(pnue);
       p->set_ant(pnue);
  }
  else
  {
      pnue->set_ant(q);
      q->set_sig(pnue);
  }
  tamano++;
  

  return 1;
}

template <class T>
bool Lista<T>::buscar( T &bus, Nodo<T> **q)
{
      Nodo<T> *p;
      for (p=cab; p; p= p->get_sig())
          if ( bus==p->get_inf() )
          {
               if ( q!=NULL ) *q= p;
               bus= p->get_inf();
               return true;
          }
      return false;
}

template <class T>
Nodo<T>* Lista<T>::getUltimo( )
{
      Nodo<T> *p;
      p=this->cab;
      while(p){
        if(p->get_sig()==NULL){
            break;
        }
        p=p->get_sig();
      }
      return p;
}

template <class T>
int Lista<T>::eliminar( T &eli)
{
      Nodo<T> *p= cab;
      if ( !cab ) return -1;
      if ( buscar(eli,&p) )
      {
           if (p==cab)
           {
               cab= p->get_sig();
               if ( cab ) cab->set_ant(NULL);
           }
           else
           {
               p->get_ant()->set_sig(p->get_sig());
               if ( p->get_sig() )
                   p->get_sig()->set_ant( p->get_ant() );
           }
           delete p;
           tamano--;
           return 1;
      }
      else
          return 0;

}

template <class T>
void Lista<T>::vaciar ( )
{
	    Nodo<T> *p;
      if ( !cab ) return;	    
	    p=cab;
	    while(p){
	  		T d=p->get_inf();
			eliminar(d);
			p=p->get_sig();
		}
}

template <class T>
void Lista<T>::imprimir ( )
{
      Nodo<T> *p;
      for (p=cab; p; p= p->get_sig()){
        //cout<<p->get_inf()<<endl;
	  }
		 
}

