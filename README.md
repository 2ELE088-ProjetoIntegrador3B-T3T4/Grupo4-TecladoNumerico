# Grupo 4 - TecladoNumerico

Grupo 4 - Teclado Numérico
Composto por Gabriel Trindade Benatti Frizzo, Matheus Rodrigues Garcia e Vitor Hugo Domingues Bogo

## Motivação e justificativa

A escolha do projeto de teclado numérico com switches mecânicos - o componente que efetivamente realiza o acionamento da tecla - se deu pela sua complexidade balanceada, bem como a sua utilidade no cotidiano.

Os membros do grupo veem o periférico como um bem que pode ser usado para auxiliar usuários que trabalham em ambientes laboratoriais e industrias de áreas com grande utilização de números, operações e símbolos matemáticos.

Não só isso mas com pequenas alterações existe a possibilidade de diferenciadas empresas utilizarem o teclado da forma que desejarem, podendo modificar o produto de forma relativamente simples em busca de remapear as teclas para se adequar a situação. Tais modificações incluem, mas não estão limitadas a modificar o digito que cada tecla se referencia, realizar aperto de 2 ou mais teclas com apenas 1 tecla ou mapeamento de comandos internos do sistema operacional, podendo assim realizar trabalhos repetitivos em busca de facilitar a vida do usuário.

Quanto ao uso de switches mecânicos, o uso se dá pela alta durabilidade e confiabilidade em relação ao sistema de teclados por membrana.

##  Objetivos

É esperado que sejam atingidos alguns critérios mínimos para a melhor experiência do usuário, como:

- Personalização e ergonomia: O teclado conta com o sistema de teclas hot-swappable, ou seja, switches facilmente trocáveis por conta da falta de solda, e sim por serem encaixadas manualmente na PCB do teclado.
  - Isso permite que o usuário faça a troca sem grandes dificuldades das teclas de acordo com sua preferência ou necessidade, desde que a pinagem dos novos switches seja compatível com a presente na PCB.

- Os switches são fabricados em diversas forças de atuação, distâncias mínimas e máximas para o clique, níveis de som ao pressionar as teclas e sensações táteis distintas, tornando sua variabilidade enorme.

- O sistema mecânico também possibilita a troca das keycaps - peça que cobre o topo das teclas, rotulando a função de cada uma - à bel-prazer do consumidor, de acordo com sua estética, material e topografia.
  - Com esses dois últimos tópicos buscamos não só dar uma ferramenta nas mãos do usuário como também deixamos a possibilidade de customização própria do usuário em aberto, caso esse venha a desejar.
    > A intenção é que o produto venha completamente funcional para o usuário, que se quiser fazer modificações terá de buscar por si só, aproveitando das comodidades oferecidas para a customização.

- Durabilidade e performance: O estimado para o teclado é que suporte entre 30 e 70 milhões de cliques por tecla, como é estimado para qualquer teclado mecânico.

## Descrição e Funcionamento do Sistema

O sistema tem uma funcionalidade simples, afinal seu único objetivo é "enviar um ou mais sinais para um computador, e que esses sinas sejam entendidos com uma letra do alfabeto e que faça parte do QWERTY"

Portanto, para atingir o objetivo pretendido, o projeto segue a seguinte lógica de funcionamento:

- o microcontrolador STM32F103C8T6 é o centro do projeto, ele será responsável por dialogar com o computador pela porta USB-C, e interpretar o  comportamento da matriz de teclas para saber quando uma foi apertada ou não.
- A matriz de teclas é responsável é onde as teclas estão arranjadas em linhas e colunas (em nosso caso, 3 colunas e 5 linhas), com isso podemos gastar menos GPIOs do microcontrolador e ainda assim ter uma boa quantidade de teclas.
- Por fim o outro componente principal é a entrada USB-C, cujo dela será alimentado todo o sistema da placa e a conversação entre o microcontrolador e o computador é possibilitada.

## Resultados Esperados

O resultado final é um teclado numérico robusto, modular e personalizável, que pode ser utilizado tanto como um periférico de computador quanto como parte de sistemas embarcados, calculadoras, painéis de controle industrial, cofres eletrônicos e sistemas de autenticação.
