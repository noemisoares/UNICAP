#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

#define IN1 7                       // Pino 1 do motor
#define IN2 6                       // Pino 2 do motor
#define IN3 5                       // Pino 3 do motor
#define IN4 4                       // Pino 4 do motor

int led1 = 13;                     // LED 1
int led2 = 12;                     // LED 2

char cha;                          // Variável para armazenar o comando recebido

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial na taxa de 9600 bps
  
  // Configura os pinos dos motores e LEDs como saída
  pinMode(IN1, OUTPUT);   
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  
  // Inicializa os motores e LEDs em estado desligado
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  stopMotors();  // Para os motores inicialmente
}

void loop() {  
  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);  // Aguarda a leitura do comando

    // Executa o comando recebido
    executeCommand(cha);
  }
}

// Função para executar o comando correspondente
void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      moveForward();  // Mover para frente
      break;
    case BACKWARD:
      moveBackward();  // Mover para trás
      break;
    case LEFT:
      turnLeft();  // Virar para a esquerda
      break;
    case RIGHT:
      turnRight();  // Virar para a direita
      break;
    case CIRCLE:
      // Adicione a lógica para ação de CIRCLE aqui, se necessário
      break;
    case CROSS:
      stopMotors();  // Parar imediatamente
      break;
    case TRIANGLE:
      toggleLEDs();  // Alternar LEDs
      break;
    case SQUARE:
      sendStatus();  // Retornar o status ou qualquer outra operação de informação
      break;
    case START:
      startProcess();  // Iniciar um processo ou operação
      break;
    case PAUSE:
      pauseProcess();  // Pausar um processo ou operação
      break;
    default:
      // Caso o comando seja inválido
      break;
  }
}

// Funções de controle de movimento
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Função para alternar os LEDs
void toggleLEDs() {
  static bool ledsOn = false;  // Variável para armazenar o estado dos LEDs
  if (ledsOn) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  ledsOn = !ledsOn;  // Alterna o estado dos LEDs
}

// Funções para operações adicionais
void sendStatus() {
  Serial.println("Status: Motores e LEDs funcionando corretamente.");
}

void startProcess() {
  Serial.println("Processo iniciado.");
}

void pauseProcess() {
  Serial.println("Processo pausado.");
}
