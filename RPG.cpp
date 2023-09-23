/* Bianca, Ryhan e Tauani - Jogo RPG */
#include<iostream>
#include <string>
#include <vector>
#include <cstdlib>  // Para as funções rand() e srand()
#include <ctime>    // Para a função time()
using namespace std;
/*uma lista de struct que puxa as classes personagens
o pai vai ser o personagem e o filho vai ser o arquetipo um vetor de ponteiros*/ 

class Personagem{
    protected:
    string nome;
    int pv, pa,pd; 
    vector <Personagem*>derrotados; 
    //derrotados armazena o arquetipo do personagem derrotado
    
    static string gerarNomeAleatorio() {
        const string nomes[] = {"Alice", "Bob", "Charlie", "David", "Emma", "Fiona", "George", "Hannah", "Isabel"};
        return nomes[rand() % (sizeof(nomes) / sizeof(nomes[0]))];
    } // Método estático para gerar um nome aleatório

    public:
    Personagem(const string& nome, int pv, int pa, int pd) : 
    nome(gerarNomeAleatorio()), pv(pv), pa(pa), pd(pd){}
    //const porque nome não muda e string& porque é referencia

    string getNome() const {
        return nome;
    }

    int getPV() const {
        return pv;
    }

    int getPA() const {
        return pa;
    }

    int getPD() const {
        return pd;
    }
    
};
class JogoRPG {
public:
    JogoRPG() {
        // Construtor da classe JogoRPG
    }

    void iniciarCombate(Personagem* personagem1, Personagem* personagem2) {
        // Método para iniciar um combate entre dois personagens
        int rounds = 0;
        while (rounds < 10) {  // Limite de 10 rounds
            rounds++;
            //lógica de combate aqui
            // Calcular os ataques, verifique condições de vitória, etc.

            // Exibir o número do round
            cout << "Round " << rounds << endl;

            // Fim do combate após 10 rounds
            if (rounds == 10) {
                cout << "O combate terminou!" << endl;
                break;
            }
        }

        // Exiba as estatísticas do combate após o fim
        exibirEstatisticasCombate(personagem1, personagem2);
    }

private:
    void exibirEstatisticasCombate(Personagem* personagem1, Personagem* personagem2) {
        // Método para exibir as estatísticas do combate, incluindo dano, vida restante, etc.

        cout << "Estatísticas do Combate:" << endl;
        cout << personagem1->getNome() << ": PV=" << personagem1->getPV() << endl;
        cout << personagem2->getNome() << ": PV=" << personagem2->getPV() << endl;
    }
};

class Bruxo : public Personagem{
    public:
    int atck;
    //Drenagem vital - ataca e se cura e causa sangramento
};

class Mago : public Personagem{
    public:
    int atck;
    //Explosão arcana - explosão de dano
};

class Guerreiro : public Personagem{
    int atck;
    //Frenesi de batalha - aumenta seus atributos de ataque e defesa
};

class Druida: public Personagem{
    int atck;
    //ataque elemental - ataque com mais chance de sangramento
};

class Clerigo: public Personagem{
    int atck;
    //Ascensão celestial - cura em si
};

class Ladino: public Personagem{
    int atck;
    //Sombra mortal - dano massivo e sangramento
};


int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    
    return 0;
}
