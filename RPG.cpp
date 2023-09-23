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
  
};

class mago : public personagem{
    public:
    int atck;
};

class guerreiro : public personagem{
    public:
    int atck;
};

class druida: public personagem{
    public:
    int atck;
};

class clerigo: personagem{
    public:
    int atck;
};

class bandido: public personagem{
    public:
    int atck;
};



/*mais seis classe distintas dos arquetipos que são derivadas do personagem
Pontos de vida (VID).
Pontos de ataque (ATQ).
Pontos de defesa (DEF).
uma lista de struct que puxa as classes personagens
o pai vai ser o personagem e o filho vai ser o arquetipo um vetor de ponteiros*/

int main(){

}
