# Guide Répertoire & Solutions Thématiques (C++)
Ce document regroupe les explications théoriques et les réponses détaillées aux questions posées dans la série d'exercices portant sur le passage de paramètres, la programmation orientée objet, l'encapsulation, l'héritage et le polymorphisme.
## Exercice 1 — Passage de paramètres et Références
### 1. Résultat affiché par le programme
L'affichage produit par le programme est : **15 20**
 * **Analyse du comportement :**
   * La variable x est transmise au premier paramètre a, qui est une **référence** (int &a). Par conséquent, l'opération a += 5 modifie directement la valeur de la variable x en mémoire, qui passe de 10 à 15.
   * La variable y est transmise au second paramètre b, qui est un **passage par valeur** (int b). L'opération b += 10 ne modifie qu'une copie locale interne à la fonction. La variable y conserve donc sa valeur d'origine, c'est-à-dire 20.
### 2. Différence entre le passage par valeur et le passage par référence
 * **Passage par valeur :**
   * Une copie conforme de l'argument est créée en mémoire pour la fonction.
   * Toute modification apportée au paramètre dans la fonction n'affecte pas la variable d'origine.
   * Consomme plus de ressources mémoire si l'objet transmis est de grande taille.
 * **Passage par référence :**
   * Aucun objet n'est copié ; la fonction reçoit un alias (adresse) de la variable d'origine.
   * Toute modification appliquée au paramètre modifie immédiatement et directement la variable d'origine.
   * Plus efficace en terme de performances pour les structures ou objets volumineux.
### 3. Modification requise pour impacter les deux variables
Pour que la modification soit effective sur les deux arguments transmis à la fonction, le deuxième paramètre doit également être déclaré par référence. Il suffit d'ajouter le symbole & devant le nom du deuxième paramètre dans l'en-tête de la fonction (int &b).
### 4. Rôle de l'opérateur & dans la déclaration des paramètres
Dans l'en-tête d'une fonction, l'opérateur & placé après le type du paramètre indique un **passage par référence**. Il signale au compilateur qu'au lieu d'allouer de la mémoire pour une nouvelle copie, la fonction doit lier ce paramètre directement à l'espace mémoire de l'argument passé lors de l'appel.
<img width="1366" height="768" alt="ex1" src="https://github.com/user-attachments/assets/13c14770-3c67-4114-8a48-a2f940b4bc1c" />

exercice 2:
<img width="1366" height="768" alt="ex2" src="https://github.com/user-attachments/assets/ca43a164-d3cc-4b39-91f4-b7701c8c24cf" />

## Exercice 3 — Héritage et Polymorphisme
### 1. Structure de l'héritage
 * **Classe mère (Vehicule) :** Définit les attributs communs à tous les véhicules (immatriculation, marque, vitesse maximale) sous la visibilité protected, permettant aux classes dérivées d'y accéder directement.
 * **Classes dérivées (Voiture et Camion) :**
   * Voiture hérite de Vehicule et ajoute des attributs spécifiques : le nombre de portes et le type de carburant.
   * Camion hérite de Vehicule et ajoute des attributs spécifiques : la capacité de charge et le nombre d'essieux.
<img width="1366" height="768" alt="Capture d&#39;écran 2026-10-25 231349" src="https://github.com/user-attachments/assets/1aa6f3dc-3749-4ae1-be42-5f5f76af0510" />
