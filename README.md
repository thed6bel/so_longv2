# Projet so_long - École 42

## Description
so_long est un projet de l'École 42 qui consiste à créer un petit jeu 2D en utilisant la bibliothèque graphique MinilibX. Le joueur doit collecter tous les objets présents sur la carte puis s'échapper en empruntant le chemin le plus court possible.

## Objectifs
- Créer une interface graphique simple
- Gérer les événements de la fenêtre
- Implémenter une logique de jeu basique
- Travailler avec des sprites et des textures
- Créer et parser des cartes de jeu

## Fonctionnalités
- Affichage d'une carte 2D avec des murs, des espaces vides, des collectibles et une sortie
- Déplacement du joueur avec les touches fléchées ou WASD
- Collecte d'objets et sortie du niveau une fois tous les objets collectés
- Comptage et affichage du nombre de mouvements
- Gestion des collisions avec les murs
- Fermeture propre du jeu avec la touche ESC ou en cliquant sur la croix de la fenêtre

## Compétences développées
- Programmation en C
- Utilisation d'une bibliothèque graphique (MinilibX)
- Gestion des événements et des inputs utilisateur
- Algorithmes de parcours de grille
- Parsing de fichiers

## Prérequis
- GCC
- Make
- MinilibX et ses dépendances (X11 include files pour Linux, Cocoa framework pour macOS)

## Installation et utilisation
1. Clonez ce dépôt :
   ```
   git clone https://github.com/thed6bel/so_long.git
   ```
2. Naviguez dans le dossier du projet :
   ```
   cd so_long
   ```
3. Compilez le projet :
   ```
   make
   ```
4. Lancez le jeu avec une carte :
   ```
   ./so_long maps/map.ber
   ```

## Format de la carte
Les cartes sont des fichiers avec l'extension .ber et doivent respecter les règles suivantes :
- Seulement 5 caractères possibles :
  - 0 : un espace vide
  - 1 : un mur
  - C : un objet à collecter
  - E : une sortie
  - P : la position de départ du joueur
- La carte doit être fermée/entourée par des murs
- Il doit y avoir au moins une sortie, un objet à collecter, et une position de départ

Exemple de carte valide :
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Contrôles
- Flèches directionnelles ou WASD : Déplacement du joueur
- ESC : Quitter le jeu

## Bonus possibles
- Animation des sprites
- Affichage du nombre de mouvements directement dans la fenêtre de jeu
- Implémentation d'ennemis patrouillant
