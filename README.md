# KeyLogger
<a name="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/nico-vrn/CorpTrack">
    <img src="Images/logo_keylogger.png" alt="Logo" width="150" height="150">
  </a>

  <h3 align="center">Keylogger physique</h3>

  <p align="center">
    Un keylogger matériel facile à utiliser pour surveiller les frappes au clavier et récupérer les mots de passes de l'ordinateur.
    <br />
   </p>
</div>

## A propose du projet 

Ce projet fournit un programme de keylogger physique, qui peut être utilisé pour surveiller et enregistrer les frappes au clavier d'un ordinateur. Il est conçu pour être discret et efficace, en enregistrant les données dans un fichier sur une carte SD.

Le projet récupère également un payload sur un serveur distant et l'exécute. Une fois configuré, celui-ci récupère tous les mots de passe présent dans l'ordinateur et les envoies à un webhook discord. 


## Prérequis

Pour utiliser ce keylogger, vous aurez besoin de :

* Un microcontrôleur compatible (par exemple, Teensy 4.1)
* Une carte SD pour stocker les données enregistrées
* logiciel [Arduino](https://www.arduino.cc/en/software)
* Une bibliothèque Arduino pour la prise en charge des périphériques USB (USBHost_t36)
* Une bibliothèque Arduino pour la prise en charge des cartes SD (SD)
* un serveur distant (disord, vps ou autres)

## Installation

1. Clonez le dépôt sur votre ordinateur local :

```sh
git clone https://github.com/nico-vrn/KeyLogger.git
```
2. Ouvrez le projet dans l'IDE Arduino.
3. Téléchargez et installez les bibliothèques nécessaires (USBHost_t36 et SD).
4. Modifier le fichier payload_vps.ps1 (ligne 5)
5. Héberger le payload sur discord ou serveur distant
6. Mettre le fichier payload_sd.txt sur la carte sd
7. Modifier le fichier Keylogger.ino en conséquence (ligne 4 à 8)
8. Modifier le fichier payload_vps.ps1 (ligne 5)
9. Téléversez le code sur votre microcontrôleur.
10. ENJOY !

## Fonctionnalités principales

* Enregistrement discret des frappes au clavier
* Stockage des données sur une carte SD
* Téléchargement d'un payload sur un serveur distant
* Exécution d'un payload sur l'ordinateur
* Récupération des mots de passe de l'ordinateur
* Envoie des mots de passe sur un webhook discord

## Contribution

Les contributions sont les bienvenues ! Pour contribuer, suivez les étapes suivantes :

1. Forkez le dépôt.
2. Créez une nouvelle branche avec un nom descriptif pour votre fonctionnalité ou correctif.
3. Faites vos modifications et soumettez-les avec un commit.
4. Créez une pull request vers la branche `main` du dépôt d'origine.

## Auteurs

- Lefranc Nicolas, [@nico-vrn](https://github.com/nico-vrn)

## Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE) pour plus de détails.


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/nico-vrn/KeyLogger?style=for-the-badge
[contributors-url]: https://github.com/nico-vrn/KeyLogger/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/nico-vrn/KeyLogger.svg?style=for-the-badge
[forks-url]: https://github.com/nico-vrn/KeyLogger/network/members
[stars-shield]: https://img.shields.io/github/stars/nico-vrn/KeyLogger.svg?style=for-the-badge
[stars-url]: https://github.com/nico-vrn/KeyLogger/stargazers
[issues-shield]: https://img.shields.io/github/issues/nico-vrn/KeyLogger.svg?style=for-the-badge
[issues-url]: https://github.com/nico-vrn/KeyLogger/issues
