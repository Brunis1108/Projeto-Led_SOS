# Projeto-Led_SOS
1. INTRODUÇÃO
 O presente relatório tem o objetivo de explicar o projeto no qual implementa um 
sistema embarcado fazendo uso do led externo da placa Bit Dog Lab que está conectado 
ao GPIO 13 da placa Raspberry Pi Pico W, onde ele terá que emitir a mensagem SOS em 
código morse, com as seguintes especificações:
 • Um ponto (".") é representado pelo LED aceso por 0,2 segundos.
 • Um traço ("-") é representado pelo LED aceso por 0,8 segundos.
 • O intervalo entre pontos e traços dentro de uma mesma letra é de 0,125 segundos.
 • O intervalo entre letras é de 0,25 segundos.
 • Após o envio do sinal completo, há uma pausa de 3 segundos antes do reinício.
 Na programação do projeto é realizado em linguagem C que faz uso das 
bibliotecas pico/stdlib.h para estabelecer a conexão com a placa e realizar o 
gerenciamento do LED.
 2. DESENVOLVIMENTO
 Configuração do Ambiente
 Hardware Utilizado:
 • Placa de desenvolvimento: Raspberry Pi Pico W.
 • LED vermelho conectado ao pino GPIO 13.
 • Resistor de 220 ohm em série com o LED.
 • Protoboard e cabos para conexão.
Software Utilizado:
 • Ambiente de Desenvolvimento: Visual Studio Code com extensões para 
C/C++.
 • SDK da Raspberry Pi Pico W: Inclui a biblioteca pico/stdlib.h.
 • Ferramentas de Compilação: GCC ARM e CMake.
 Configuração Inicial do Projeto:
 • Configurar o SDK da Raspberry Pi Pico W seguindo a documentação oficial.
 • Criar um arquivo CMakeLists.txt para configurar o build do projeto.
 • Configurar o LED como saída no pino GPIO 13.
 Código Implementado
 O Seguinte código foi implementado na placa para picar o led de acordo com o 
indicado, formando a palavra SOS em código morse:
 #include "pico/stdlib.h"
 #include <stdio.h>
 #define led_pin_red 13
 uint16_t tempo1 = 200, tempo2 = 800, tempoP = 125,tempoF = 2875;
 void letra_S() {// função para reproduzir a letra S em codigo morse
 for(int i = 0; i < 3; i++) {//reproduzir 3 vezes
 gpio_put(led_pin_red, true); //liga o led
 sleep_ms(tempo1);  //espera um tempo ligado
 gpio_put(led_pin_red, false); //desliga o led
 sleep_ms(tempoP);  //espera um tempo desligado
 }
 }
void letra_O() { // função para reproduzir a letra O em codigo morse
    for(int i = 0; i < 3; i++) { //repetir 3 vezes
        gpio_put(led_pin_red, true);//liga o led
        sleep_ms(tempo2);  //espera um tempo ligado
        gpio_put(led_pin_red, false); //desliga o led
        sleep_ms(tempoP);  //espera um tempo desligado
    }
 }
 int main() {
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
    while (true) {
        letra_S();  //trazendo a reprodução da função letra_S
        sleep_ms(tempoP); //epera mais 0,125 segundos para completar os 0,250
        letra_O();  //trazendo a reprodução da função letra_O
        sleep_ms(tempoP);  
        letra_S();  //trazendo a reprodução da função letra_S
        sleep_ms(tempoF); //tempo de espera do fim 0,125 segundos da ultima repetição 
do 'for' mais 2,875 resultando em 3 segundos exatos
    }
 }
 Descrevendo o Código:
 1.Bibliotecas Utilizadas:
 • pico/stdlib.h: Proporciona usar funções necessárias para inicializar os GPIOs 
e manipular o LED.
 • stdio.h: Utilizada para depuração.
 2.Definições e Variáveis:
 • #define led_pin_red 13: Define o pino GPIO 13 como o pino vermelho do 
LED.
 • As variáveis tempo1, tempo2, tempoP, tempoL e tempoF armazenam os 
tempos para duração, dos pontos, traços e divisão de letras e palavras.
 3.Lógica Principal:
 • O LED pisca representando assim o código Morse "...---..."(SOS).
 • O programa faz uso do gpio_put para ligar e desligar o LED.
• A função sleep_ms introduzem os delays necessários para fazer a pausa 
dos respectivos intervalos.
 • Um loop infinito garante a repetição do ciclo.
 4.Testes 
1. Configuração no Wokwi:
 • Foi configurado o Raspberry Pi Pico W no ambiente Wokwi.
 • O LED foi conectado ao pino GPIO 13, com resistor em série.
 • O código foi carregado e executado no simulador.
 2. Resultados:
 • O LED piscou seguindo a dinâmica definida para o sinal SOS.
 • Os tempos de pausa e os ciclos foram executados corretamente.
 3. Conclusão
 O projeto atendeu a todos os requisitos especificados, transmitindo o sinal SOS 
corretamente por meio de um LED conectado ao GPIO 13. A implementação 
modularizada e o uso de variáveis para controle de tempo facilitaram a manutenção e 
compreensão do código. A simulação no Wokwi confirmou o funcionamento correto antes 
da implementação em hardware real, pois foi possível fazer testes e verificar erros 
cometidos antes do uso da placa real, conseguindo fazer os ajustes necessários para seu 
funcionamento ideal
