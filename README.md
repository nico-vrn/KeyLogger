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
    <img src="images/logo.png" alt="Logo" width="150" height="120">
  </a>

  <h3 align="center">Keylogger physique</h3>

  <p align="center">
    Un keylogger matériel facile à utiliser pour surveiller les frappes au clavier.
    <br />
   </p>
</div>

## A propose du projet 

Ce projet fournit un programme de keylogger physique, qui peut être utilisé pour surveiller et enregistrer les frappes au clavier d'un ordinateur. Il est conçu pour être discret et efficace, en enregistrant les données dans un fichier sur une carte SD.


## Prérequis

Pour utiliser ce keylogger, vous aurez besoin de :

* Un microcontrôleur compatible (par exemple, Teensy 4.1)
* Une carte SD pour stocker les données enregistrées
* logiciel [Arduino](https://www.arduino.cc/en/software)
* Une bibliothèque Arduino pour la prise en charge des périphériques USB (USBHost_t36)

## Installation

1. Clonez le dépôt sur votre ordinateur local :

```sh
git clone https://github.com/nico-vrn/KeyLogger.git
```
2. Ouvrez le projet dans l'IDE Arduino.
3. Téléchargez et installez les bibliothèques nécessaires (USBHost_t36 et SD).
4. Téléversez le code sur votre microcontrôleur.

## Fonctionnalités principales

* Enregistrement discret des frappes au clavier
* Stockage des données sur une carte SD
* Facile à installer et à utiliser
* Compatible avec une variété de microcontrôleurs

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
