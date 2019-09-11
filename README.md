Sistemas Microprocessados I

Prova 1:
    - Definições gerais sobre sistemas embarcados, microcontroladores e microprocessadores;
    - Componentes de um sistema microprocessado (slide 3 e 4);
    - Ciclo de instrução;
    - MSP430:
        + Arquitetura geral;
        + Configuração de porta;
        + Interrupções;
        + Configuração de clock.

==============================================================================================================================================

    RESUMO SLIDE 2

- Circuitos Digitais com Lógica Fixa
    + São circuitos criados a partir de portas lógicas para implementar uma lógica combinacional ou sequencial;
    + Podem ser construidos de forma discreta (portas individuais) ou integrada (chip).

- Circuitos Digitais Programáveis
    + São circuitos que por meio de conexão de blocos básicos permite a construção de circuitos mais complexos;
    + Ele pode ser visto com uma caixa preta.

    + PLA:
        > Dois planos de conexão (AND e OR);
        > Os dois planos de conexão deixava os circuitos implementados mais lentos.
    
    + PAL:
        > Densevolvido para solucionar problema de lentidão do PLA;
        > Apenas o plano  de conexão AND é programável;
        > Limitação de combinar de no maximo 32 inputs/outputs.

- CPLD (Complex Programmable Logic Device)
    + São circuitos digitais programáveis mais complexos;
    + Permite combinar uma quantidade maior de inputs e outputs;
    + Pode ter desde 2 blocos de PAL ate mais de 100 blocos.

- FPGA (Field Programáveis Gate Array)
    + Dispositivo lógico programavel que tem capacidade de implemantar circuitos mais complexo que os do CPLD;
    + Composto de blocos lógicos;
    + Possui entradas e saídas lógicas, fios de conexão e chaves.

- VHDL
    + Linguagem de descrição de Hardware;
    + Proposito inicial de descrever, documentar, circuitos digitais complexos.

- Sistemas embarcados
    + Vantagens:
        > Baixo custo da Engenharia de hardware;
        > Dimensões reduzidas;
        > Baixo custo por unidade na produção em grande escala.

    + Desvantagens:
        > Complexidade no densevolvido;
        > Alto custo no desenvolvimento de software (plataformas, software, firmware).

=============================================================================================================================================

    RESUMO SLIDE 3

- Sistemas Microprocessados
    + Sistemas microprocessados possuim um microprocessador;
    + Funciona como um sistema sequencial síncrono;
    + Cada grupo de pulsos de clock é executada uma nova instrução.

    > Pulso de Clock
        # Gerado por um oscilador;
        # Usado para sincronizar os sistemas microprocessados;
        # Com aumento da velocidade dos microprocessadores, diferentes partes dos circuitos funcionam com frequencias diferentes.

    > Desempenho
        # Throughput: Quantidade total de trabalho executado em um intervalo de tempo.
        # Tempo de execução: tempo gasto pelo processador para realizar uma tarefa, excluindo acessos a memoria e I/O.
        # Tempo de resposta (latência): tempo de duracao de um programacao, incluindo acesso a memória.

- Estruta e Diagrama de um Sistema microprocessado Genérico
    + Barramento:
        > Conjunto de condutores elétricos que permite a comunicação entre componentes do computador (CPU, memória, disp. de I/O);
        > Os sinais que trafegam no barramento são: Dados, relógio, endereços e sinais de controle;
        > As informações que trafegam no barramento obedecem um protocolo;
        
        > Classificação do Barramento (Quanto à Funcionalidade)
            # Barramento de Dados (bidirecinal): fornecem o meio de transmissão de dados entre os módulos do sistema.
            # Barramento de endereços (unidirecional): usadas para designar fonte e destino dos dados do barramento de dados.
            # Barramento de controle (bidirecional): usadas para controlar o acesso e o uso de linhas de dados e endereços.
            # Barramento de controle (bidirecional): usadas para controlar o acesso e o uso de linhas de dados e endereços.
        
        > Classificação do Barramento (Quanto à Temporização)
            # Barramento Assíncrono: O controle ocorre exclusivamente por meio de sinais trocados entre os dispositivos. 
                                     Os ciclos de barramentos podem ter qualquer duração e não precisam ser iguais para todos as situações.
            
            # Barramento Síncrono: Este tipo de barramento exige que todo o tráfego de dados e controle seja sincronizado 
                                   sob uma mesma base de tempo (clock). 
        
        > Vantagens:
            # Baixo custo na comunicação entre componentes;
            # Permite a fácil adição de novos dispositivos no computador.

        > Desvantagens:
            # Criação de engarrafamento (bottleneck) na comunicação, limitando a máxima vazão de dados (throughput) para dispositivos de I/O.   

        > Sinais típicos de controle:
            # Memory Write: Causa a escrita de dados do barramento de dados no endereço especificado no barramento de endereços;
            # Memory Read: Causa dados de um endereço especificado pelo barramento de endereço ser posto no barramento de dados;
            # I/O Write: Causa dados no barramento de dados serem enviados para uma porta de saída (dispositivo de I/O);
            # I/O Read: Causa a leitura de dados de um dispositivo de I/O, os quais serão colocados no barramento de dados;
            # Bus request: Indica que um módulo pede controle do barramento do sistema;
            # Reset: Inicializa todos os módulos.
        
        > Caracteristicas de acesso
            # Todo dispositivo de memória ou I/O deve ser exclusivo no acesso ao barramento.

        > Dispositivos
            # Master: dispositivos que controlam o protocolo de acesso ao barramento para leitura ou escrita de dados.
            # Slave: dispositivos que simplesmente obedecem a requisição do master.
            # Exemplo: "A CPU ordena que o controlador de disco leia ou escreva um bloco de dados."

        > Arbitragem do Barramento
            # Arbitragem Descentralizada: Quando foi ou mais dispositivos querem se tornar mestres do barramento ao mesmo tempo, 
                                          pode existir uma inviabilidade de operações (caos) do sistema.

            # Arbistragem Centralizada: Um arbitro decide qual mestre controla o barramento.

        > Circuito de Reset
            # Watchdog Timer: Inicializa o sistema ao ligar e/ou sub comando externo.
        
        > Memória de Programa
            # Memória onde a CPU vai procurar as instruções a executar.
        
        > Memória de Dados
            # Memória onde a CPU lê e escreve dados durante a operação normal.
        
        > Seleção de Endereços
            # Lógica para escolher qual memória ou periférico a CPU vai utilizar.
        
        > Portas de I/O
            # Dispositivos de entrada/saída (Input/Output) para comunicação com o mundo externo.
  
- Dispositivos e Circuitos Agregados aos Sistemas Microprocessados
    + Buffers

    + Latches
    
    + Drivers
    
    + Decodificador de Endereços
    
    + Memórias
    
    + Dispositivos de I/O

