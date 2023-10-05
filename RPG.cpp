//Bianca, Ryhan e Tauani
#include<iostream>
#include<iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personagem {
protected:
    string nome, classe;
    int pv, pa, pd;
    int danoTotalCausado;
    vector<Personagem*> derrotados;

    static string gerarNomeAleatorio() {
        const string nomes[] = {"Alice", "Bob", "Charlie", "Pitty", "Frank", "David", "Emma", "Fiona", "George", "Hannah", "Isabel", "Abigail", "Katarina", "Morgana", "Laila", "Qiyana", "Veno", "Max", "Rick", "Josephine", "Marcu", "Harry", "Thomas", "Polly", "Ben", "Vegan", "Albert", "Oberon", "Lilith", "Thalia", "Zephyr", "Celestia", "Hecate", "Solstice", "Branwen", "Kaelthas", "Selene", "Orion", "Persephone", "Astra", "Asmodeus", "Calliope", "Elysium", "Melissandre", "Hercules"};
        return nomes[rand() % (sizeof(nomes) / sizeof(nomes[0]))];
    }

public:
    Personagem(const string& nome, const string& classe, int pv, int pa, int pd)
        : nome(gerarNomeAleatorio()), classe(classe), pv(pv), pa(pa), pd(pd), danoTotalCausado(0) {}

    void receberDano(int dano) {
        if (dano > 0) {
            pv -= dano;
            if (pv < 0) {
                pv = 0;
            }
        }
    }

    string getNome() const {
        return nome;
    }
    
    string getClasse() const {
        return classe;
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

    void adicionarDerrotado(Personagem* derrotado) {
        derrotados.push_back(derrotado);
    }

    int getDanoTotalCausado() const {
        return danoTotalCausado;
    }

    void adicionarDanoCausado(int dano) {
        if (dano > 0) {
            danoTotalCausado += dano;
        }
    }
};

class JogoRPG {
protected:
    vector<Personagem*> personagens;

public:
    JogoRPG() {}

    void adicionarPersonagem(Personagem* novoPersonagem) {
        personagens.push_back(novoPersonagem);
    }

    void listarPersonagens() {
        cout << "Lista de Personagens para o combate:" << endl;
        for (const Personagem* personagem : personagens) {
            cout << "Personagem: " << personagem->getNome() << " - " << personagem->getClasse()
                << ", PV: " << personagem->getPV()
                << ", PA: " << personagem->getPA()
                << ", PD: " << personagem->getPD()
                << endl;
        }
    }

    void iniciarCombate(Personagem* personagem1, Personagem* personagem2) {
        int rounds = 0;

        while (rounds < 10 && personagem1->getPV() > 0 && personagem2->getPV() > 0) {
            cout << "\t\nRound: " << rounds + 1 << endl;
            rounds++;
            swap(personagem1, personagem2);

            int danospersonagem1 = personagem1->getPA() - personagem2->getPD();
            int danospersonagem2 = personagem2->getPA() - personagem1->getPD();

            if (danospersonagem1 > 0) {
                personagem2->receberDano(danospersonagem1);
                cout << "Perda de vida de " << personagem2->getNome() << ": " << danospersonagem1 << " pontos." << endl;
                personagem1->adicionarDanoCausado(danospersonagem1);
            }
            else {
                cout << "O ataque de " << personagem1->getNome() << " não causou dano a " << personagem2->getNome() << "." << endl;
            }
            if (danospersonagem2 > 0) {
                personagem1->receberDano(danospersonagem2);
                cout << "Perda de vida de " << personagem1->getNome() << ": " << danospersonagem2 << " pontos." << endl;
                personagem2->adicionarDanoCausado(danospersonagem2);
            }
            else {
                cout << "O ataque de " << personagem2->getNome() << " não causou dano a " << personagem1->getNome() << "." << endl;
            }

            cout << "-------Vida restante de " << personagem1->getNome() << ": " << personagem1->getPV() << " pontos de vida." << endl;
            cout << "-------Vida restante de " << personagem2->getNome() << ": " << personagem2->getPV() << " pontos de vida." << endl;

            if (rounds == 10 || personagem1->getPV() <= 0 || personagem2->getPV() <= 0) {
                cout << "\n\t\tO combate terminou!\n" << endl;
                break;
            }
        }

        if (personagem1->getPV() <= 0 && personagem2->getPV() > 0) {
            personagem2->adicionarDerrotado(personagem1);
            cout << "\t\t" << personagem2->getNome() << " venceu!" << endl;
        }
        else if (personagem2->getPV() <= 0 && personagem1->getPV() > 0) {
            personagem1->adicionarDerrotado(personagem2);
            cout << "\t\t" << personagem1->getNome() << " venceu!" << endl;
        }
        else {
            int danoTotalPersonagem1 = personagem1->getDanoTotalCausado();
            int danoTotalPersonagem2 = personagem2->getDanoTotalCausado();

            if (danoTotalPersonagem1 > danoTotalPersonagem2 && personagem1->getPV() == 0 && personagem2->getPV() == 0) {
                cout << "\t\t" << personagem1->getNome() << " é o vencedor com mais danos causados!" << " com ataque:" << personagem1->getPA() << endl;
            }
            else if (danoTotalPersonagem2 > danoTotalPersonagem1 && personagem1->getPV() == 0 && personagem2->getPV() == 0) {
                cout << "\t\t" << personagem2->getNome() << " é o vencedor com mais danos causados!" << endl;
            }
            else {
                cout << "\t" << "O combate terminou em empate, sem vencedor!" << endl;
            }
        }

        exibirEstatisticasCombate(personagem1, personagem2);
    }
void exibirEstatisticasCombate(Personagem* personagem1, Personagem* personagem2) {
    cout << "\n" << string(60, '-') << endl;
    cout << "\t\tEstatísticas do Combate:" << endl;

    int larguraColuna = 30;
    cout << string(60, '-') << endl;

// Tabela para o Personagem 1
    cout << left << setw(larguraColuna) << "Nome do Personagem 1:";
    cout << left << setw(larguraColuna) << "Arquétipo:";
    cout << endl;
    cout << left << setw(larguraColuna) << personagem1->getNome();
    cout << left << setw(larguraColuna) << personagem1->getClasse();
    cout << endl;

    cout << setw(larguraColuna) << "PV:";
    cout << left << setw(larguraColuna) << "PA:";
    cout << endl;
    cout << left << setw(larguraColuna) << personagem1->getPV();
    cout << left << setw(larguraColuna) << personagem1->getPA();
    cout << endl;
    cout << setw(larguraColuna) << "PD:";
     cout <<  left <<setw(larguraColuna) << "Dano Total:";
    cout << endl;
    cout << left << setw(larguraColuna) << personagem1->getPD();
    cout << left << setw(larguraColuna) << personagem1->getDanoTotalCausado();
    cout << endl;
    cout << string(60, '-') << endl;

// Tabela para o Personagem 2 
    cout << left << setw(larguraColuna) << "Nome do Personagem 2:";
    cout << left << setw(larguraColuna) << "Arquétipo:";
    cout << endl;

    cout << left << setw(larguraColuna) << personagem2->getNome();
    cout << left << setw(larguraColuna) << personagem2->getClasse();
    cout << endl;

    cout << setw(larguraColuna) << "PV:";
    cout << left << setw(larguraColuna) << "PA:";
    cout << endl;
    cout << left << setw(larguraColuna) << personagem2->getPV();
    cout << left << setw(larguraColuna) << personagem2->getPA();
    cout << endl;



    cout << setw(larguraColuna) << "PD:";
     cout <<  left <<setw(larguraColuna) << "Dano Total:";
    cout << endl;
    cout << left << setw(larguraColuna) << personagem2->getPD();
    cout << left << setw(larguraColuna) << personagem2->getDanoTotalCausado();
    cout << endl;

    cout << "--------------------------------------------------------------" << endl;
}




};

class Bruxo : public Personagem {
public:
    Bruxo()
        : Personagem(gerarNomeAleatorio(), "Bruxo", gerarPV(), gerarPA(), gerarPD()) {}

private:
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

class Mago : public Personagem {
public:
    Mago()
        : Personagem(gerarNomeAleatorio(), "Mago", gerarPV(), gerarPA(), gerarPD()) {}

private:
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

class Guerreiro : public Personagem {
public:
    Guerreiro()
        : Personagem(gerarNomeAleatorio(), "Guerreiro", gerarPV(), gerarPA(), gerarPD()) {}

private:
    int gerarPV() {
        return rand() % (100 - 80 + 1) + 80;
    }

    int gerarPA() {
        return rand() % (25 - 10 + 1) + 10;
    }

    int gerarPD() {
        return rand() % (25 - 20 + 1) + 20;
    }
};

class Druida : public Personagem {
public:
    Druida()
        : Personagem(gerarNomeAleatorio(), "Druida", gerarPV(), gerarPA(), gerarPD()) {}

private:
    int gerarPV() {
        return rand() % (100 - 90 + 1) + 90;
    }

    int gerarPA() {
        return rand() % (30 - 20 + 1) + 20;
    }

    int gerarPD() {
        return rand() % (20 - 15 + 1) + 15;
    }
};

class Clerigo : public Personagem {
public:
    Clerigo()
        : Personagem(gerarNomeAleatorio(), "Clerigo", gerarPV(), gerarPA(), gerarPD()) {}

private:
    int gerarPV() {
        return rand() % (90 - 75 + 1) + 75;
    }

    int gerarPA() {
        return rand() % (20 - 15 + 1) + 15;
    }

    int gerarPD() {
        return rand() % (23 - 15 + 1) + 15;
    }
};

class Ladino : public Personagem {
public:
    Ladino()
        : Personagem(gerarNomeAleatorio(), "Ladino", gerarPV(), gerarPA(), gerarPD()) {}

private:
    int gerarPV() {
        return rand() % (90 - 70 + 1) + 70;
    }

    int gerarPA() {
        return rand() % (35 - 25 + 1) + 25;
    }

    int gerarPD() {
        return rand() % (25 - 15 + 1) + 15;
    }
};

int main() {
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

    jogoRPG.listarPersonagens();

    jogoRPG.iniciarCombate(&bruxo, &clerigo);

    return 0;
}
