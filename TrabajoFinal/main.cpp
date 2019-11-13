#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace sf;
using namespace std;

//vector<int> a(1);


class bala{
public:

    bala(double x,double y)
    {
        string imagen;
        imagen="bala.png";
        t_bala.loadFromFile(imagen);
        s_bala.setTexture(t_bala);
        s_bala.setPosition(x,y);
    }
    Sprite get_sprite(){return s_bala;}

    void modo1(){
        s_bala.setPosition(s_bala.getPosition().x+1.2,s_bala.getPosition().y);


    }

private:
    Sprite s_bala;
    Texture t_bala;




};

class jugador{
public:
    bala *b;
    jugador()
    {   textura.loadFromFile("alien.png");
        figura.setTexture(textura);
        _gravedad=true;
        //b=new bala(0,0);
    }

    void gravedad()
    {   if(_gravedad)
            figura.setPosition(figura.getPosition().x,figura.getPosition().y+2);
    }


    Sprite getsprite(){return figura;}
    void controles()
    {       if (Keyboard::isKeyPressed(Keyboard::Up)){_gravedad=0;
                figura.setPosition(figura.getPosition().x,figura.getPosition().y-10);
                //_gravedad=1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)){
                figura.setPosition(figura.getPosition().x,figura.getPosition().y+10);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                figura.setPosition(figura.getPosition().x-10,figura.getPosition().y);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                figura.setPosition(figura.getPosition().x+10,figura.getPosition().y);
            }

            if (Keyboard::isKeyPressed(Keyboard::Space)){
                cout<<"ss";
                b=new bala(figura.getPosition().x,figura.getPosition().y);
                //b->get_sprite().setPosition(figura.getPosition().x,figura.getPosition().y);
            }
            //else
                // _gravedad=1;

    }

private:
    Texture textura;
    Sprite figura;
    bool _gravedad;
    int num_bala;

};





class enemigo{
public:
    enemigo()
    {   //int n_enemigos=rand()%4+1;
        string imagen;
        imagen="alien.png";
        t_enemigo.loadFromFile(imagen);
        s_enemigo.setTexture(t_enemigo);
        s_enemigo.setPosition(700,rand()%600+1);
        mov_vertical=rand()%1+0;
        mov_horizontal=1;
    }
    void mover1()
    {   if(mov_vertical==1){
            s_enemigo.setPosition(s_enemigo.getPosition().x-5,s_enemigo.getPosition().y+1);
            if(s_enemigo.getPosition().y>600)
                mov_vertical=0;
        }
        else{
            s_enemigo.setPosition(s_enemigo.getPosition().x-5,s_enemigo.getPosition().y-1);
            if(s_enemigo.getPosition().y<0)
                mov_vertical=1;
        }

        if(s_enemigo.getPosition().x<-100)
            s_enemigo.setPosition(700,rand()%600+1);

    }

    void mover2()
    {   if(mov_vertical==1){
            s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y+1);
            if(s_enemigo.getPosition().y>600)
                mov_vertical=0;
        }
        else{
            s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y-1);
            if(s_enemigo.getPosition().y<0)
                mov_vertical=1;
        }

        if(mov_horizontal==1){
            s_enemigo.setPosition(s_enemigo.getPosition().x-1,s_enemigo.getPosition().y);
            if(s_enemigo.getPosition().x<0)
                mov_horizontal=0;
        }
        else{
            s_enemigo.setPosition(s_enemigo.getPosition().x+1,s_enemigo.getPosition().y);
            if(s_enemigo.getPosition().x>700)
                mov_horizontal=1;
        }
    }

    void mover3(double x)
    {
        if(mov_vertical==1){
            s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y+1);
            if(s_enemigo.getPosition().y>600)
                mov_vertical=0;
        }
        else{
            s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y-1);
            if(s_enemigo.getPosition().y<0)
                mov_vertical=1;
        }

        if(mov_horizontal==1){
            s_enemigo.setPosition(s_enemigo.getPosition().x-1,s_enemigo.getPosition().y);
            if(s_enemigo.getPosition().x<x)
                mov_horizontal=0;
        }
        else{
            s_enemigo.setPosition(s_enemigo.getPosition().x+1,s_enemigo.getPosition().y);
            if(s_enemigo.getPosition().x>700)
                mov_horizontal=1;
        }
    }

    void mover4(double x,double y)
    {
        s_enemigo.setPosition(s_enemigo.getPosition().x-1,s_enemigo.getPosition().y);
        if(s_enemigo.getPosition().x<x)
            if(s_enemigo.getPosition().y>y)
                s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y-1);
            else
                s_enemigo.setPosition(s_enemigo.getPosition().x,s_enemigo.getPosition().y+1);
    }

    Sprite getsprite(){return s_enemigo;}

private:
    Texture t_enemigo;
    Sprite s_enemigo;
    int mov_vertical;
    int mov_horizontal;

};




class bloque{
public:
    bloque()
    {
        string imagen;
        imagen="bloque.png";
        t_bloque.loadFromFile(imagen);
        s_bloque.setTexture(t_bloque);
        s_bloque.setScale(rand()%2+1,rand()%3+1);
        s_bloque.setPosition(700,rand()%600+1);
    }


    void mover()
    {
        s_bloque.setPosition(s_bloque.getPosition().x-10,s_bloque.getPosition().y);
        if(s_bloque.getPosition().x<-100){
            s_bloque.setPosition(700,rand()%600+1);
            s_bloque.setScale(rand()%2+1,rand()%3+1);
        }
    }
    Sprite getsprite(){return s_bloque;}
private:
    Texture t_bloque;
    Sprite s_bloque;
};

class juegofinal{
public:
    juegofinal(float _ancho,float _alto,string _titulo)
    {   ventana=new RenderWindow(VideoMode(_ancho,_alto),_titulo);
        game_over=false;
        ventana->setFramerateLimit(60);
        tfondo.loadFromFile("fondo.png");
        sfondo.setTexture(tfondo);
        sfondo.setScale(_ancho/tfondo.getSize().x,_alto/tfondo.getSize().y);
        crono1=3;
        crono2=6;
        crono3=9;
        crono4=12;
        gameloop1();
    }

    void procesar_evento()
    {
        while(ventana->pollEvent(evento)){
            if(evento.type==Event::Closed)
                ventana->close();
            if(evento.type==Event::KeyPressed)
                jugador1.controles();



        }
    }

    void gameloop1()
    {   while(!game_over)
        {   tiempo1=reloj1.getElapsedTime();
            cout<<tiempo1.asSeconds()<<endl;
            jugador1.gravedad();
            ventana->clear();
            procesar_evento();
            ventana->draw(sfondo);
            ventana->draw(jugador1.getsprite());
            ventana->draw(jugador1.b->get_sprite());
            jugador1.b->modo1();
            for(int i=0;i<4;i++)
            {
                ventana->draw(mons_lv1[i].getsprite());
                //mons_lv1[i].mover1();
                //mons_lv1[i].mover2();
                //mons_lv1[i].mover3(jugador1.getsprite().getPosition().x);
                mons_lv1[i].mover4(jugador1.getsprite().getPosition().x+400,jugador1.getsprite().getPosition().y);
            }
            for(int i=0;i<2;i++)
            {
                ventana->draw(bloques[i].getsprite());
                bloques[i].mover();
            }
            ventana->display();
        }
    }

    void gameloop2()
    {   while(!game_over)
        {   tiempo1=reloj1.getElapsedTime();
            cout<<tiempo1.asSeconds()<<endl;

            jugador1.gravedad();
            ventana->clear();
            procesar_evento();
            ventana->draw(sfondo);
            ventana->draw(jugador1.getsprite());
            ventana->draw(jugador1.b->get_sprite());
            jugador1.b->modo1();
            //ventana->dra
            for(int i=0;i<4;i++)
            {
                ventana->draw(mons_lv1[i].getsprite());
                //mons_lv1[i].mover1();
                //mons_lv1[i].mover2();
                //mons_lv1[i].mover3(jugador1.getsprite().getPosition().x);
                //mons_lv1[i].mover4(jugador1.getsprite().getPosition().x+400,jugador1.getsprite().getPosition().y);
            }
            for(int i=0;i<2;i++)
            {
                ventana->draw(bloques[i].getsprite());
                bloques[i].mover();
            }
            ventana->display();
        }
    }

private:
    RenderWindow *ventana;
    Texture tfondo;
    Sprite  sfondo;
    Clock reloj1;
    Time tiempo1;
    int crono1;
    int crono2;
    int crono3;
    int crono4;
    bool game_over;
    Event evento;
    jugador jugador1;
    enemigo mons_lv1[4];
    enemigo mons_lv2[2];
    bloque bloques[2];
};

int main(){
    juegofinal(800,600,"juego final");
    return 1;
}

