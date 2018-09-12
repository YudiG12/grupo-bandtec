int pinoSensor = 5; //Saída do sensor na A5.
int valorLido = 0; //Variável auxiliar.
float temperatura = 0; //Variável que armazenará a temperatura lida
int linha = 0; //Variável que se refere as linhas do excel.

void setup() { //Função que será executada uma.
 Serial.begin(9600); //Inicia a comunicação serial a 9600 bauds.
 Serial.println("CLEARDATA"); //Reset comunicação serial.
 Serial.println("LABEL,Hora, Temperatura,linha"); //Nomeia a coluna
}

void loop() { //Função que será executada continuamente.
  valorLido = analogRead(pinoSensor); //Leitura analógica da porta A0.
  temperatura = (valorLido*0.00488); //5 volts/1023 = 0.0048 precisão do A/D.
  temperatura = temperatura*100; //Converte milivolts para celcius - cada 10mV == 1 grau C.
  linha++;
  Serial.print("DATA, TIME, "); //Inicia a impressão dos dados, fica sempre iniciando.
  Serial.print(temperatura);
  Serial.print(",");
  Serial.println(linha);


if(linha > 100) //loop para limitar a qte de dados.
{
  linha = 0;
  Serial.println("ROW,SET,2"); //Alimentação das linhas sempre com os dados iniciados.
}
delay(1000); //Tempo 5 seg para realizar outra leitura.
}
