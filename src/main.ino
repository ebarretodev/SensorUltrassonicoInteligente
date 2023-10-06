#include <SoftwareSerial.h>
#include <ModbusRTUSlave.h>

//declaração de pinos TRIGGER e ECHO
const int TriggerPin = ;
const int EchoPin= ;

//Variáveis máximas e minimas do sensor
const int holdingRegister[6] = ;
const int holdingRegister[7] = ;

//Pinos de comunicação
const uint8_t rxPin = 11;
const uint8_t txPin = 12;
const uint8_t dePin = 13;

//inicia o softwareSerial e a comunicação modbus
SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUSlave modbus(mySerial, dePin);

//cria 20 Holding Register
uint16_t holdingRegister[20];

//executa a leitura do sensor ultrassonico
long readUltrassonicDistance(int PinoTrigger, int PinoEcho)
{
  pinMode(PinoTrigger, OUTPUT);
  digitalWrite(PinoTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(PinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinoTrigger, LOW);
  pinMode(PinoEcho, INPUT);
  return pulseIn(PinoEcho, HIGH);
}

void setup() 
{
  modbus.configureHoldingRegisters(holdingRegister, 20); // TAG holding registers, quantidade de holdingRegister's(20)
  modbus.begin(holdingRegister[0], holdingRegister[1], holdingRegister[2]); // slave id, baud rate, config (optional)
}

void loop() 
{
  modbus.poll();
  holdingRegister[0] = 0;
  holdingRegister[1] = 39800;
  // holdingRegister[2] = ;
  // holdingRegister[3] = ;
  // holdingRegister[4] = ;
  // holdingRegister[5] = ;
  // holdingRegister[6] = ;
  // holdingRegister[7] = ;
  // holdingRegister[8] = ;
  // holdingRegister[9] = ;
  holdingRegister[10] = readUltrassonicDistance(int PinoTrigger, int PinoEcho);
  holdingRegister[11] = 0.01723 * readUltrassonicDistance(TriggerPin, EchoPin);
  // holdingRegister[12] = ;
  holdingRegister[13] = (holdingRegister[11] - holdingRegister[6])*100/(holdingRegister[7] - holdingRegister[6]);
  // holdingRegister[14] = ;
  // holdingRegister[15] = ;
  // holdingRegister[16] = ;
  // holdingRegister[17] = ;
  // holdingRegister[18] = ;
  // holdingRegister[19] = ;
  updateholdingRegister();
}