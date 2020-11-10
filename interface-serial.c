#include <mbed.h>

PwmOut _led(LED1);

Serial pc(USBTX, USBRX, 9600);

char c = '\0';

void get_char(){
  c = pc.getc();
}

int main(){
    pc.attach(&get_char);

    while (1){
        if (c != '\0'){
            if(c == '+'){
                if (brightness >= 1.0) brightness = 1.0;
                else brightness += 0.05;
            }
            else if(c == '-'){
                if (brightness <= 0.0) brightness = 0.0;
                else brightness -= 0.05;
            }
            else if(c == '*'){
                brightness = 1.0;
            }
            else if(c == '/'){
                brightness = 0.0;
            }
            else pc.printf("Error\n");
        }
        float brightness = _led.read();
        wait_ms(100);
    }
}
