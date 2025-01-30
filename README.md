1. INTRODUÇÃO
A linguagem escolhida para desenvolver o programa foi a linguagem C. Foi 
escolhido também dois algoritmos de escalonamento: o Circular e com Prioridade 
para os processos em estados “pronto”, “bloqueado” e “em execução”.  
O escalonador Circular, conhecido como Round-Robin, atribui uma fatia de 
tempo (quantum), há uma fila de processos prontos para a execução. 
Já o escalonador com prioridade, cada processo tem sua prioridade, o de maior 
prioridade é o primeiro a ser escolhido para ser executado, a cada execução os 
processos têm suas prioridades reduzidas e podem ser agrupados em classes de 
prioridade.

2. CONCLUSÃO
Neste trabalho, desenvolvemos um programa na linguagem C que simula um 
escalonador simples, implementando dois algoritmos de escalonamento: o escalonador 
circular (Round-Robin) e o escalonador com prioridade. O programa aborda a 
competição por recursos de CPU entre os processos nos estados “pronto”, “bloqueado” 
e “em execução”. 
A estrutura do programa incluiu a definição de processos, uma fila para gerenciar os 
processos prontos, e funções específicas para cada algoritmo de escalonamento. Cada 
função foi documentada para fornecer uma compreensão clara de seu propósito, 
parâmetros e comportamento. 
Durante a execução do programa, observamos a simulação do escalonamento, onde os 
processos foram movidos entre os estados de "pronto", "bloqueado" e "em execução" de 
acordo com o algoritmo escolhido. Isso proporcionou uma visão prática de como os 
escalonadores operam no ambiente multiprogramado, onde vários processos competem 
pela CPU simultaneamente. 
Ao final do trabalho, o código fornecido pode servir como uma base para experimentos 
mais avançados ou como referência para compreender os conceitos básicos de 
escalonamento de processos em sistemas operacionais. Concluímos que a 
implementação eficaz de escalonadores é crucial para otimizar o uso dos recursos do 
sistema e garantir um desempenho eficiente em ambientes multiprogramados.
