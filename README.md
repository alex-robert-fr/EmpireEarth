# Empire Earth ⚡

Bienvenue sur le projet **Empire Earth** ! Ce projet a pour objectif de recréer l'expérience épique d'Empire Earth, mais avec un style graphique minimaliste et plutôt réaliste, des performances optimisées et de meilleurs mécaniques stratégiques. ✨

---

## 🎯 **Objectifs**

- **Gameplay :** Inclure des mécaniques complexes avec une gestion des ressources, des unités, des bâtiments, et un système d'ères complet.
- **Mode LAN :** Synchronisation en temps réel pour des parties à plusieurs.
- **Graphismes :** Un style minimaliste mais réaliste, avec des animations détaillé.
- **Performance :** Doit fonctionner sur des PC très bas de gamme (Vieux CPU, < 8 Go de RAM).
- **Mods :** Doit permettre la création de mods pour la communauté

_Pas d'intelligence artificielle (IA) dans cette version initiale : tout est axé sur le multijoueur et les fondamentaux du gameplay. ⚡_

---

## 🌐 **Roadmap**

Voici notre évolution vers la version 1.0 :

### Phase 1 : **"The Foundations of a New World"**

#### Structure du projet

- [ ] Organiser les fichiers et modules en suivant une architecture modulaire.
- [ ] Configurer le dépôt pour utiliser le workflow Gitflow.
- [ ] Configurer un système de CI/CD pour automatiser les builds, les tests et le déploiement.

#### Implémentation de la boucle principale.

- [ ] Mettre en place une boucle à taux fixe avec interpolation.
- [ ] Implémenter des gestionnaires pour les événements du jeu (input, logique).
- [ ] Ajouter un moyens pour déboguer les performances.

#### Entity Component System (ECS)

- [ ] Définir un système ECS basique avec gestion des entités et des composants.
- [ ] Implémenter des systèmes simples (ex. : position des entités).

#### Gestion hybride des ressources

- [ ] Créer un gestionnaire de ressources pour charger/décharger dynamiquement.
- [ ] Implémenter une gestion des erreurs si une ressource manque.

### Phase 2 : **"A Simple World is a Cool World"**

#### Unité de base

- [ ] Créer une entité d’unité avec des déplacements basiques.
- [ ] Implémenter des points de vie pour les unités.

#### Bâtiment de base

- [ ] Créer une entité bâtiment avec des propriétés basiques (coût, temps de construction).
- [ ] Permettre la destruction de bâtiments.

#### Ressources

- [ ] Créer une entité ressource avec des propriétés basiques.

#### Interface utilisateur basique

- [ ] Créer un menu pour quitter ou relancer une partie.
- [ ] Ajouter un zoom et un déplacement dynamique sur la carte.

### Phase 3 : **"Welcome to the Internet"**

#### Mode LAN basique

- [ ] Mettre en place un modèle client-serveur.
- [ ] Ajouter un système de synchronisation des positions des unités.
- [ ] Gérer les déconnexions et reconnexions simples des joueurs.

#### Interface LAN

- [ ] Créer une interface simple pour héberger/rejoindre une partie.
- [ ] Permettre aux joueurs de choisir une couleur ou une faction.

### Phase 4 : **"The Beginning of a New Era"**

#### Gestion avancée des unités

- [ ] Ajouter des actions avancées (attaquer, récolter des ressources, construire).
- [ ] Implémenter des animations pour chaque action.

#### Bâtiments avancés

- [ ] Ajouter des bâtiments nécessitant des ressources pour fonctionner.
- [ ] Implémenter des bâtiments producteurs d’énergie (centrales, éoliennes).
- [ ] Permettre la construction d’infrastructures (routes, ponts).

#### Système de technologie

- [ ] Définir un arbre technologique avec des prérequis et des bonus.
- [ ] Implémenter des technologies spécifiques à chaque ère.

#### HUD immersif

- [ ] Créer un HUD plus détaillé avec des informations contextuelles (unités/bâtiments).

### Phase 5: Exploring the World

### Phase 6: Expanding the Gameplay

### Phase 7: Immersion & Realism

### Phase 8 : Towards Perfection

### Phase 9: V1 Release
