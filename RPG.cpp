
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class personagem{
    protected:
    string nome;
    int pv, pa,pd;
    vector <personagem*>derrotados; 
    //derrotados armazena o arquetipo do personagem derrotado

    public:
    personagem(const string& nome, int pv, int pa, int pd) : 
    nome (nome), pv(pv), pa(pa), pd(pd){}
    //const porque nome não muda e string& porque é referencia
    
};
class JogoRPG{


};

class bruxo : public personagem{
    public:
    int atck;
    //Drenagem vital - ataca e se cura 
};

class mago : public personagem{
    public:
    int atck;
    //Explosão arcana - explosão de dano
};

class guerreiro : public personagem{
    public:
    int atck;
    //Frenesi de batalha - aumenta seus atributos de ataque e defesa
};

class druida: public personagem{
    public:
    int atck;
    //ataque elemental - ataque com mais chance de sangramento
};

class clerigo: personagem{
    public:
    int atck;
    //Ascensão celestial - cura em si
};

class ladino: public personagem{
    public:
    int atck;
    //Sombra mortal - dano massivo 
};



/*mais seis classe distintas dos arquetipos que são derivadas do personagem
Pontos de vida (VID).
Pontos de ataque (ATQ).
Pontos de defesa (DEF).
uma lista de struct que puxa as classes personagens
o pai vai ser o personagem e o filho vai ser o arquetipo um vetor de ponteiros*/

int main(){

}
