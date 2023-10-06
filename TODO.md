# TODO: atividades que devem ser desenvolvidas
(A) O sensor deve ler o valor do ultrassonico e salvar no HR[10]

(B) O sensor deve converter o valor de HR[10] para centimetros e salvar no HR[11]

(C) O sensor deve converter para 0.1f litros com o valor do HR[3] (litros/cm). Caso o valor de HR[3] seja 0 deve ser o valor de HR[10]

(D) O sensor deve converter para 0.1f% com o valor de HR[4] (total em litros). Caso o valor de HR[4] seja 0 deve ser o valor de HR[10]

(F) O sensor deve ter como selecionar o endereço pelo HR[0] (endereço modbus) #inicializar

(G) O sensor deve ter como selecionar a velocidade pelo HR[1] (baud rate) #inicializar

(H) Mostrar no display OLED o valor medido em HR[11] centimetros

(I) Mostrar no display endereço modbus HR[0]

(J) Mostrar no display baud rate HR[1]

(K) Os valores de HR[0] ~ HR[9] devem ser gravados na EEPROM uma única vez, quando são alterados.

(L) Os valores de HR[0] ~ HR[9] devem ser atualizados sempre que inicialiar o sensor e se alterados devem ser salvos na EEPROM.


# #inicializar = se valor for alterado, só tomará efeito ao inicializar