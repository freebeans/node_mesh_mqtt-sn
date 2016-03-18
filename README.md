# gnrc_networking example

This example shows you how to try out the code in two different ways: Either by communicating
between the RIOT machine and its Linux host, or by communicating between two RIOT instances.
Note that the former only works with native, i.e. if you run RIOT on your Linux machine.

## Mudanças

Detecção e inicialização automática do RPL na interface sem fio. Logo após reset, se o botão
for pressionado, o programa cai no shell. Caso contrário, começa a enviar pacotes MQTT-SN para
um endereço definido em "config.h". RSMB ainda não os recebe, mas a estrutura parece correta
e aparece no WireShark (SAMR21 não trava).

A implementação do MQTT-SN genérico foi tirada de:
https://www.eclipse.org/paho/clients/c/embedded-sn/
