/* Bianca, Ryhan e Tauani - Jogo RPG */
#include<iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
/*mais seis classe distintas dos arquetipos que são derivadas do personagem
Pontos de vida (VID).
Pontos de ataque (ATQ).
Pontos de defesa (DEF).
uma lista de struct que puxa as classes personagens
o pai vai ser o personagem e o filho vai ser o arquetipo um vetor de ponteiros*/ 

class Personagem{
    protected:
    string nome;
    int pv, pa,pd; 
    /*  pv - ponto de vida
        pa - ponto de ataque
        pd - ponto de defesa */
    vector <Personagem*>derrotados; 
    //derrotados armazena o arquetipo do personagem derrotado

    public:
    Personagem(const string& nome, int pv, int pa, int pd) : 
    nome (nome), pv(pv), pa(pa), pd(pd){}
    //const porque nome não muda e string& porque é referencia
    
};
class JogoRPG{


};

class Bruxo : public personagem{
    public:
    int atck;
    //Drenagem vital - ataca e se cura e causa sangramento
};

class Mago : public personagem{
    public:
    int atck;
    //Explosão arcana - explosão de dano
};

class Guerreiro : public personagem{
    int atck;
    //Frenesi de batalha - aumenta seus atributos de ataque e defesa
};

class Druida: public personagem{
    int atck;
    //ataque elemental - ataque com mais chance de sangramento
};

class Clerigo: public personagem{
    int atck;
    //Ascensão celestial - cura em si
};

class Ladino: public personagem{
    int atck;
    //Sombra mortal - dano massivo e sangramento
};


int main(){

    return 0;
}
