# RPG - Jogo 
### Trio de desenvolvimento: @Bianca Netto, @Ryhan Clayver e @Tauani Vitória. 
Jogo de RPG em C++, para a matéria de Programação Orientada a Objetos, utilizando os paradigmas de Orientação a Objetos.
> [!NOTE] > ### Regras e Princípios
As instruções utilizadas: 
- O RPG simulará um combate em uma arena entre personagens. Terá (no mínimo) as classes JogoRPG,
Personagem, e mais 6 classes distintas representando diferentes arquétipos. Por exemplo, Guerreiro(a),
Bruxo(a), Ladrão, Arqueiro(a), etc.
- A classe Personagem deve ter no mínimo os seguintes atributos:
    -Nome do personagem;
    - Pontos de vida (VID);
    - Pontos de ataque (ATQ);
    - Pontos de defesa (DEF);
    - Lista de personagens derrotados;
- Cada classe que identifica um arquétipo será derivada da classe Personagem.
- Cada arquétipo terá um ataque especial, exclusivo de sua classe. Este ataque poderá ocorrer,
aleatoriamente, durante um round de combate. Ou seja, em vez do ataque normal, ocorrerá o ataque
especial. Este ataque terá um nome específico e causará mais dano do que um ataque normal.
- O ataque especial também poderá causar sangramento, onde o outro personagem sangrará por um número
de rounds calculado aleatoriamente (mínimo de 2 rounds, máximo de 6 rounds). O sangramento causará
uma perda (baixa) de vida a cada round, independente do dano atual recebido no round.
- O sangramento deve ser calculado no início de cada round, portanto, um personagem pode ser derrotado
sem receber dano de ataque no round.
    - Caso ambos os personagens fiquem sem vida devido a sangrarem no início do round, um dos dois
personagens será sorteado para avançar e o outro será considerado derrotado.
- Implemente construtores para inicializar o nome, VID, ATQ e DEF do personagem. Implemente um
método para exibir as estatísticas do personagem.
- Cada personagem irá armazenar a lista de personagens que derrotou. Use alguma estrutura de dados para
armazenar cada personagem que foi derrotado.
- Cada combate poderá durar no máximo 10 rounds. Se nenhum dos dois personagens forem derrotados ao
fim de 10 rounds, o personagem que causou mais dano será considerado o vencedor.
    - Ao fim de cada combate seu jogo deve exibir uma tabela com as estatísticas do combate, considerando
dano efetuado por cada personagem, vida restante de cada personagem, número de rounds ocorridos, e
quantos ataques especiais ocorreram.

-------------------------------------------

- Cada classe que identifica um arquétipo será derivada da classe Personagem.
- Cada arquétipo terá um ataque especial, exclusivo de sua classe. Este ataque poderá ocorrer,
aleatoriamente, durante um round de combate. Ou seja, em vez do ataque normal, ocorrerá o ataque
especial. Este ataque terá um nome específico e causará mais dano do que um ataque normal.
  - O ataque especial também poderá causar sangramento, onde o outro personagem sangrará por um número
de rounds calculado aleatoriamente (mínimo de 2 rounds, máximo de 6 rounds). O sangramento causará
uma perda (baixa) de vida a cada round, independente do dano atual recebido no round.
  - O sangramento deve ser calculado no início de cada round, portanto, um personagem pode ser derrotado
sem receber dano de ataque no round.
- Caso ambos os personagens fiquem sem vida devido a sangrarem no início do round, um dos dois
personagens será sorteado para avançar e o outro será considerado derrotado.
    - Implemente construtores para inicializar o nome, VID, ATQ e DEF do personagem. Implemente um
método para exibir as estatísticas do personagem.
- Cada personagem irá armazenar a lista de personagens que derrotou. Use alguma estrutura de dados para
armazenar cada personagem que foi derrotado.
- Cada combate poderá durar no máximo 10 rounds. Se nenhum dos dois personagens forem derrotados ao
fim de 10 rounds, o personagem que causou mais dano será considerado o vencedor.
    - Ao fim de cada combate seu jogo deve exibir uma tabela com as estatísticas do combate, considerando
dano efetuado por cada personagem, vida restante de cada personagem, número de rounds ocorridos, e
quantos ataques especiais ocorreram.
