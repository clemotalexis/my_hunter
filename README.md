# My Hunter

**Epitech Project 2029**

## Description

**My Hunter** est un petit jeu vidéo inspiré du célèbre jeu Duck Hunt. Le joueur incarne un chasseur dont l'objectif est de tirer sur des canards qui apparaissent et se déplacent sur l'écran. Ce projet marque le début de l'apprentissage du développement de jeux vidéo avec des concepts de base tels que la gestion des entrées utilisateur, les sprites animés, et la manipulation de fenêtres graphiques.

## Fonctionnalités

### Obligatoires :
- **Gestion des événements** : La fenêtre doit pouvoir être fermée via des événements.
- **Entrées utilisateur** : Gestion des clics de souris pour tirer sur les canards.
- **Sprites animés** : Les canards doivent être animés à l'aide de sprite sheets.
- **Éléments mobiles** : Les canards doivent se déplacer (translation, rotation ou mise à l'échelle).
- **Option `-h`** : Affiche une description rapide du programme et des commandes disponibles.

### Recommandées :
- Les animations doivent être indépendantes de la vitesse du PC.
- Synchronisation des animations via des éléments `sfClock`.
- Résolution de la fenêtre : entre **800x600** et **1920x1080** pixels.
- Cadence d'affichage limitée pour éviter les ralentissements.

### Optionnelles :
- Plusieurs niveaux de jeu.
- Affichage du score en temps réel.
- Enregistrement du meilleur score.
- Affichage d'un viseur sous le curseur.

## Prérequis

- **Bibliothèque graphique** : [CSFML](https://www.sfml-dev.org/download/csfml/)
- **Langage** : C

## Compilation et Exécution

Le projet est compilé via un Makefile et inclut les règles suivantes :
- `make` : Compile le projet.
- `make clean` : Supprime les fichiers objets.
- `make fclean` : Supprime les fichiers objets et binaires.
- `make re` : Recompile entièrement le projet.

Pour exécuter le programme :
```bash
./my_hunter
