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
        sleep_ms(tempoF); //tempo de espera do fim 0,125 segundos da ultima repetição do 'for' mais 2,875 resultando em 3 segundos exatos
    }
}
