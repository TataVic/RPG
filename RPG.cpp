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
    int pv, pa, pd; 
    vector <Personagem*> derrotados; 
    //derrotados armazena o arquetipo do personagem derrotado
    
    static string gerarNomeAleatorio() {
        const string nomes[] = {"Alice", "Bob", "Charlie","Pitty","Frank",
        "David", "Emma", "Fiona", "George", "Hannah", "Isabel", "Abigail",
        "Katarina", "Morgana", "Laila", "Qiyana", "Veno", "Max", "Rick",
        "Josephine", "Marcu", "Harry", "Thomas", "Polly", "Ben", "Vegan", 
        "Albert", "Oberon", "Lilith", "Thalia","Zephyr","Celestia", "Hecate",
        "Solstice", "Branwen", "Kaelthas", "Selene", "Orion", "Persephone",
        "Astra", "Asmodeus", "Calliope", "Elysium", "Melissandre", "Hercules"};
        return nomes[rand() % (sizeof(nomes) / sizeof(nomes[0]))];
    } // Método estático para gerar um nome aleatório

    public:
    Personagem(const string& nome, int pv, int pa, int pd) : 
    nome(gerarNomeAleatorio()), pv(pv), pa(pa), pd(pd){}
    //const porque nome não muda e string& porque é referencia

    //metodo recebe dano e faz a subtração dos pontos de vida - Vida atual
    void receberDano(int dano) {
        // Verifica se o dano é positivo (evita cura acidental)
        if (dano > 0) {
            pv -= dano;
            if (pv < 0) {
                pv = 0;  // Garante que os pontos de vida não sejam negativos
            }
        }
    }


    string getNome() const {
        return nome;
    }

    int getPV(){
        return pv;
    }
     void setPV(int PontoVida){
         pv = PontoVida;
    }

    int getPA() {
        return pa;
    }
    void setPA(int PontoAtaque){
        pa = PontoAtaque;
    }

    int getPD() {
        return pd;
    }
    void setPD(int PontoDefesa){
        pd = PontoDefesa;
    }
    
};
class JogoRPG {
public:
    JogoRPG() {
        // Construtor da classe JogoRPG
    }

    void iniciarCombate(Personagem* personagem1, Personagem* personagem2) {
        
        int rounds = 0;

        while (rounds < 10 && personagem1->getPV() > 0 && personagem2->getPV() > 0) {
            cout << "Round: " << rounds+1 << endl;
            rounds++;

            // Lógica para ataques e cálculo de dano
            int dano1 = personagem1->getPA() - personagem2->getPD();
            int dano2 = personagem2->getPA() - personagem1->getPD();

            // Atualizar pontos de vida
            personagem2->receberDano(dano1);
            personagem1->receberDano(dano2);

            //Estatistica de dano por turno
            int danospersonagem1 = personagem1->getPA() - personagem2->getPD();
            int danospersonagem2 = personagem2->getPA() - personagem1->getPD();

            if (danospersonagem1 > 0) {
                personagem2->receberDano(danospersonagem1);
                cout << "Perda de vida de " << personagem2->getNome() << ": " << danospersonagem1 << " pontos." << endl;
            } else {
                cout << "O ataque de " << personagem1->getNome() << " não causou dano a " << personagem2->getNome() << "." << endl;
            }
            if (danospersonagem2 > 0) {
                personagem2->receberDano(danospersonagem2);  // Corrigido aqui
                cout << "Perda de vida de " << personagem1->getNome() << ": " << danospersonagem2 << " pontos." << endl;
            } else {
                cout << "O ataque de " << personagem2->getNome() << " não causou dano a " << personagem1->getNome() << "." << endl;
            }

            // Fim do combate após 10 rounds
            if (rounds == 10 || personagem1->getPV()  <= 0 || personagem2->getPV() <= 0) {
                cout << "\nO combate terminou!\n" << endl;
                break;
            }
        }

        // Exiba as estatísticas do combate após o fim
        exibirEstatisticasCombate(personagem1, personagem2);
    }

    void exibirEstatisticasCombate(Personagem* personagem1, Personagem* personagem2) {
        // Método para exibir as estatísticas do combate, incluindo dano, vida restante, etc.

        cout << "Estatísticas do Combate:" << endl;
        cout << personagem1->getNome() << ": PV=" << personagem1->getPV() << endl;
        cout << personagem2->getNome() << ": PV=" << personagem2->getPV() << endl;
    }
};

class Bruxo : public Personagem {
public:
    Bruxo()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das faixas desejadas para PV, PA e PD do Bruxo
    }
private:
    // PV (70-90), PA (15-35) e PD (10-15)
    int gerarPV() {
        return rand() % (90 - 70 + 1) + 70;
    }
    int gerarPA() {
        return rand() % (35 - 15 + 1) + 15;
    }
    int gerarPD() {
        return rand() % (15 - 10 + 1) + 10;
    }
};

class Mago : public Personagem{
public:
    Mago()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das faixas desejadas para PV, PA e PD do Mago
    }

private:
    //PV (70-90), PA (10-25) e PD (15-20)
    int gerarPV() {
        return rand() % (90 - 70 + 1) + 70;
    }
    int gerarPA() {
        return rand() % (25 - 10 + 1) + 10;
    }
    int gerarPD() {
        return rand() % (20 - 15 + 1) + 15;
    }
};
    //Explosão arcana - explosão de dano

class Guerreiro : public Personagem{
public:
     Guerreiro()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das faixas desejadas para PV, PA e PD do Guerreiro
    }
private:
    //PV (80-100), PA (10-25) e PD (20-25)
    int gerarPV() {
        return rand() % (100 - 80 + 1) + 80;
    }
    int gerarPA() {
        return rand() % (25 - 10 + 1) + 10;
    }
    int gerarPD() {
        return rand() % (25 - 20 + 1) + 20;
    }
    //Frenesi de batalha - aumenta seus atributos de ataque e defesa
};

class Druida: public Personagem{
public:
        Druida()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das novas faixas desejadas para PV, PA e PD do Druida
    }

private:
    //PV (90-100), PA (20-30) e PD (15-20)
    int gerarPV() {
        return rand() % (100 - 90 + 1) + 90;
    }
    int gerarPA() {
        return rand() % (30 - 20 + 1) + 20;
    }
    int gerarPD() {
        return rand() % (20 - 15 + 1) + 15;
    }
    //ataque elemental - ataque com mais chance de sangramento
};

class Clerigo: public Personagem{
public:
    Clerigo()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das faixas desejadas para PV, PA e PD do Clerigo
    }

private:
    //PV (75-90), PA (15-20) e PD (15-23)
    int gerarPV() {
        return rand() % (90 - 75 + 1) + 75;
    }
    int gerarPA() {
        return rand() % (20 - 15 + 1) + 15;
    }
    int gerarPD() {
        return rand() % (23 - 15 + 1) + 15;
    }
    //Ascensão celestial - cura em si
};

class Ladino: public Personagem{
public:
        Ladino()
        : Personagem(gerarNomeAleatorio(), gerarPV(), gerarPA(), gerarPD()) {
        // Valores aleatórios dentro das faixas desejadas para PV, PA e PD do Ladino
    }

private:
    //PV (70-90), PA (25-35) e PD (15-25)
    int gerarPV() {
        return rand() % (90 - 70 + 1) + 70;
    }
    int gerarPA() {
        return rand() % (35 - 25 + 1) + 25;
    }
    int gerarPD() {
        return rand() % (25 - 15 + 1) + 15;
    }
    //Sombra mortal - dano massivo e sangramento
};


int main(){

    srand(static_cast<unsigned>(time(nullptr)));

    JogoRPG jogoRPG;    

    Bruxo bruxo;
    Clerigo clerigo;
    Ladino ladino;
    Guerreiro guerreiro;
    Mago mago;
    Druida druida;

    

    cout << "Nome do Bruxo: " << bruxo.getNome() << endl;
    cout << "PV: " << bruxo.getPV() << ", PA: " << bruxo.getPA() << ", PD: " << bruxo.getPD() << endl;

        cout << "Nome do Ladino: " << ladino.getNome() << endl;
    cout << "PV: " << ladino.getPV() << ", PA: " << ladino.getPA() << ", PD: " << ladino.getPD() << endl;

        cout << "Nome do Clerigo: " << clerigo.getNome() << endl;
    cout << "PV: " << clerigo.getPV() << ", PA: " << clerigo.getPA() << ", PD: " << clerigo.getPD() << endl;

        cout << "Nome do Guerreiro: " << guerreiro.getNome() << endl;
    cout << "PV: " << guerreiro.getPV() << ", PA: " << guerreiro.getPA() << ", PD: " << guerreiro.getPD() << endl;

        cout << "Nome do Mago: " << mago.getNome() << endl;
    cout << "PV: " << mago.getPV() << ", PA: " << mago.getPA() << ", PD: " << mago.getPD() << endl;

        cout << "Nome do Druida: " << druida.getNome() << endl;
    cout << "PV: " << druida.getPV() << ", PA: " << druida.getPA() << ", PD: " << druida.getPD() << endl;


jogoRPG.iniciarCombate(&bruxo, &clerigo);

    return 0;
}
