/* Bianca, Ryhan e Tauani - Jogo RPG */
#include<iostream>
#include<iomanip>
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
    vector<Personagem*>derrotados; 
    
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

    int getPV() const{
        return pv;
    }
    void setPV(int PontoVida){
         pv = PontoVida;
    }
    int getPA() const{
        return pa;
    }
    void setPA(int PontoAtaque){
        pa = PontoAtaque;
    }

    int getPD() const{
        return pd;
    }
    void setPD(int PontoDefesa){
        pd = PontoDefesa;
    }
    void adicionarDerrotado(Personagem* derrotado) {
        derrotados.push_back(derrotado);
        //armazenar os personagens derrotados
    }
    
};
class JogoRPG {
protected:
    vector<Personagem*> personagens;

public:
    JogoRPG() {
        // Construtor da classe JogoRPG
    }

    // Método para adicionar personagens ao jogo
    void adicionarPersonagem(Personagem* novoPersonagem) {
        personagens.push_back(novoPersonagem);
    }

    // Método para listar todos os personagens no jogo
    void listarPersonagens() {
        cout << "Lista de Personagens para o combate:" << endl;
        for (const Personagem* personagem : personagens) {
            cout << "Nome: " << personagem->getNome() 
            << ", PV: " << personagem->getPV() 
            << ", PA: " << personagem->getPA() 
            << ", PD: " << personagem->getPD() 
            << endl;
        }
    }
   
    void iniciarCombate(Personagem* personagem1, Personagem* personagem2) {
        
        int rounds = 0;

        while (rounds < 10 && personagem1->getPV() > 0 && personagem2->getPV() > 0) {
            cout << "\t\nRound: " << rounds+1 << endl;
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
/* //validação: Personagem que mais causou danos - vencedor
if (personagem1->getPV() <= 0 && personagem2->getPV() > 0) {
    personagem2->adicionarDerrotado(personagem1);
    cout << personagem2->getNome() << " é o vencedor!" << endl;
} else if (personagem2->getPV() <= 0 && personagem1->getPV() > 0) {
    personagem1->adicionarDerrotado(personagem2);
    cout << personagem1->getNome() << " é o vencedor!" << endl;
} else {
    // Nenhum dos personagens foi derrotado, então compare o dano causado
    int danoTotalPersonagem1 = personagem1->getPA() * 10; // Dano total de 10 rounds
    int danoTotalPersonagem2 = personagem2->getPA() * 10; // Dano total de 10 rounds

    if (danoTotalPersonagem1 > danoTotalPersonagem2) {
        cout << personagem1->getNome() << " é o vencedor com mais danos causados!" <<"com ataque:"<<personagem1->getPA()<< endl;
    } else if (danoTotalPersonagem2 > danoTotalPersonagem1) {
        cout << personagem2->getNome() << " é o vencedor com mais danos causados!" << endl;
    } else {
        cout << "O combate terminou em empate, sem vencedor!" << endl;
    }
} */

        // Exiba as estatísticas do combate após o fim
        exibirEstatisticasCombate(personagem1, personagem2);

    }
   void exibirEstatisticasCombate(Personagem* personagem1, Personagem* personagem2) {
    cout <<string(60, '-') <<endl;
    cout << "\t\tEstatísticas do Combate:" << endl;

    // Configurar largura das colunas
    int larguraColuna = 30;
    cout << string(60, '-') <<endl;
    // Imprimir cabeçalhos
    cout << left << setw(larguraColuna) << "Nome do Personagem";
    cout << left << setw(larguraColuna) << "Pontos de Vida (PV)";
    cout << endl;

    // Imprimir estatísticas do primeiro personagem
    cout << left << setw(larguraColuna) << personagem1->getNome();
    cout << left << setw(larguraColuna) << personagem1->getPV();
    cout << endl;

    // Imprimir estatísticas do segundo personagem
    cout << left << setw(larguraColuna) << personagem2->getNome();
    cout << left << setw(larguraColuna) << personagem2->getPV();
    cout << endl;
    cout << "+---------------------+---------------+---------------------+" <<endl;

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

    jogoRPG.adicionarPersonagem(&bruxo);
    jogoRPG.adicionarPersonagem(&clerigo);
    jogoRPG.adicionarPersonagem(&ladino);
    jogoRPG.adicionarPersonagem(&guerreiro);
    jogoRPG.adicionarPersonagem(&mago);
    jogoRPG.adicionarPersonagem(&druida);

    // Liste todos os personagens no jogo
    jogoRPG.listarPersonagens();

    // Exemplo de iniciar um combate entre personagens
    jogoRPG.iniciarCombate(&bruxo, &clerigo);
;

    return 0;
}
