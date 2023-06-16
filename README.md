<p>
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/5523b2d0-aeb7-485c-8bdd-dbb5c23ea22e p align="left">
  <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/ee78a014-0f7c-4ffa-82ed-bfce217817c7  p align ="right">
</p>

<br>

<br>

<h4>
  Yasmine AMANGAR          -       Stéphane KOUAKOU
   <h4 align ="center"> Année scolaire: 2022 - 2023    
  &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp     &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp 
  Spécialité et classe: EISE4
</h4>
<br>
  
<h1>
 <h1 align ="center">Projet CoDesign
</h1>
<br>
  
<p>
  &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp
  &nbsp &nbsp &nbsp &nbsp    
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/6517e3ec-59d0-44dd-9ef3-2836e5f5c4d5 p align="center">
</p>
  
<br>
 
<h2>
  <h2 align ="center"> Objectif
</h2> 
&nbsp Notre objectif lors de ce projet était de réaliser un profil d’exécution et une analyse permettant d’identifier les endroits de <ins>LeNet</ins> à
paralléliser(ces endroits devront être voraces en terme de puissance de calcul et se prêter à une parallélisation efficace).
<br>
<br>
<strong><ins>Qu'est-ce que LeNet?</ins></strong>
<br>
&nbsp Il s'agit d'une structure de réseau de neuronnes proposée par Yann LeCun en 1998. Cette structure implémente des neurones artificiels pouvant servir dans le traitement d'image.
<br>
<br>
  
<strong><ins>Objectif secondaire:</ins> </strong>Mettre toutes les couches en LENET dans le FPGA
<br>
<ins>Règles</ins> (imposées par l'encadreur):
<br>
 - Tous les poids doivent être dans le coeur (créer une fonction pour tout calculer)
 - Fréquence: Minimum 100 MHz
 - Latence et intervale: Gain sur le temps de latence
 - Surface(LUT): Optimiser en surface
<br>

<h2>
  <h2 align ="center"> Etape 1 : Mesure des intervales
</h2>
 
 On nous fournit ici la fonction main et  qui contient plusieurs fonctions. On peut citer entre autres:
  - calculateLayer1, calculateLayer2, calculateLayer3, calculateLayer4, calculateLayer5: ces fonctions permettent d'effectuer les différents calculs importants dans les couches. C'est grâce à leur traitement qu'on peut obtenir le numéro à la fin.
  
  - InitHostMem, readIn et output: Cette fonction permet d'initialiser les poids des 4 premières couches ainsi que les connexions entre celles-ci en lisant dans les fichiers lw1.wei, lw2.wei, lw3.wei et lw4.wei. 
  
  - Dans le main, après l'utilisation des 5 calculateLayer, on utilise une boucle for pour déterminer le chiffre pausiblement identifié par la structure. 
<br> 
  
  La compilation nous donne le résultat suivant:

<p>
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/1b482abb-6018-4e0f-a5f6-ce6becf29f57 width = 200 height=200 >
  <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/1e8140ca-caa4-4e9b-b7ee-eb518ce68cc7 width = 200 height=200 >
</p>
<br>   
Ici, la structure a reconnu le chiffre 2 mis à son entrée. 
<br>  
Dans la suite, on utilise l'option -pg du compilateur gcc pour faire un profil d’exécution. Cela nous permet d'identifier les fonctions chronophages, c'est-à-dire celles qui nécessitent le plus de temps.
On obtient comme résultat:
<br>
<br>
<p>
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/40ca7fdb-ae20-4c61-ac23-78dcea659854>
</p>
<br> 
L'ordinateur utilisé est assez rapide, ce qui explique ces temps nuls. Chaque membre de notre binôme ayant un ordinateur, on a testé et obtenu des résultats différents: l'un layer2 et l'autre l'autre layer3 (cela est d'autant plus logique vu la taille des Layers 2 et 3 dans ce projet)
 
La fonction dtime, utilisé d'ailleurs nous permet d'observer ce résultat. dtime fonctionne comme un chronomètre et nous assure d'avoir le temps à un instant donné. Après quelques modifications du code main, on obtient ces résultats après souvent plusieurs simulations:
<br>
<p>  
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/04ec95d0-887d-48b5-801b-4f7449f6fa4b width = 200 height=200 >
  <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/34fa8c8b-d955-41e0-a42c-ce1c016a3154 width = 200 height=200 >
</p>
<br> 
Pour ce qui est de la couche qui va nécessiter notre attention, nous avons pris la couche 2.
<br> 
  
<h2>
  <h2 align ="center"> Etape 2 : Profilage sur le FPGA et réalisation de l'IP
</h2>
<br>
Dans un premier temps, nous allons exécuter le code sur ARM. Pour se faire, on va instancier sur Vivado le processeur puis utiliser l'environnement SDK pour développer le code qui sera utilisé sur le processeur. Ensuite, nous afficherons le résultat reconnu par la structure sur des LEDS. Nous utiliserons ici la carte ZedBoard comprenant le FPGA Zynq7000. Le code se trouve dans ce repository. 
<br>
Les étapes à sa suivre pour arriver à SDK sont les suivantes:
  
  - Créer un diagramme block, qui sera vide au départ
  
  - Ajouter le composant Zynq
  
  - Sélectionner ensuite le GPIO (l'API matériel à mettre dans le FPGA pour contrôler nos sorties numériques)
  
  - Cliquer sur l'option Block Automation qui permet de faire les branchements entre nos composants ajoutés précédemment.
  
  - Choisir nos LEDS à mettre en sortie
  
  - Valider le design 
  
  - Générer le HDL Wrapper (permet de traduire le block design en un fichier source que peut comprendre Vivado)
  
  - Générer output products (permet de générer le produit (soit simulation, design,...)
  
  - Cliquer sur Generate Bitstream pour faire la synthèse, le mapping et routing (connexion) dans le FPGA et enfin    l'implémentation.
  
  - Cliquer sur Export puis Export Hardware et cocher l'option include Bitstream
  
  - Enfin Cliquer sur File puis lancer SDK (il convient de noter que pour les nouvelles versions, il s'agit de Vitis et que nous sommes sur une ancienne version de vivado)
<br>  
L'exécution et compilation du code nous permet d'avoir le résulat précédemment observé dans SDK:
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/5b7e5c97-cce2-48d6-8e0f-fc5f3eb550a0 >
</p>
<br> 
 On va ensuite afficher le résultat sur les leds. On peut effectuer cela grâce à deux fonctions : XGPIO_Initialize qui permet d'initialiser l'IP (à mettre dans le main) puis le XGPIO_SetWrite qui permet d'écrire le résultat indexmax(résultat reconnu par la structure) sur les leds. Nous visualisons le résultat :
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/aa19a386-61d0-433d-90bf-8e5268d4870b >
</p>
<br>   
<h2>
  <h2 align ="center"> Etape 3 : High Level Synthesis - HLS
</h2>
<br>
Ici, on va maintenant créer avec Vivado Hls une IP-AXI materielle pour la deuxième couche(Layer2). On va créer un fichier à part pour cette couche et y mettre le calculateLayer2. Puis on va le rajouter dans la partie source. Pour ce qui est des autres fichiers, il faut les mettre dans le Test Bench. 
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/63c6e665-3abc-4ec2-8f56-ebae79f3bf66 >
</p>
<br> 
Dans Project settings, on va cliquer sur synthesis et rajouter notre fichier contenant le calculateLayer2 comme Top function. On peut lancer Run C simulation pour être sûr que tout fonctionne. On va aussi lancer run C synthesis et observer ceci:
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/4d7a90ad-b799-4b5c-97f2-acd6f6570eb6 >
</p>
<br>
On a 23% d'utilistion de LUT(éléments logiques, soit la surface) et 2% de la BRAM. Ces données nous rassurent surtout que le temps d'opération estimé est de de 10,44 ns(12ns).

On va ensuite lancer Run C/RTL Cosimulation puis cliquer sur Export pour exporter l'IP (rappel: si vous êtes sur une version antérieure, prière de mettre l'année de votre ordinateur à 2020 pour pouvoir exporter).
  
On va ensuite rajouter l'IP générer dans le projet Vivado (cette fois-ci et non Vivado HLS) en allant dans les paramètres du projet puis dans ceux de l'IP (repository) et rajouter le dossier impl qui est généré à l'issu de l'étape précédente. Cela va ajouter notre IP et on va ensuite suivre les mêmes  étapes pour à SDK. Cela devrait ressembler à ça au final:
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/319874a9-ad56-47bc-a9b1-d11bc358d0e7 >
</p>
<br>
On va ensuite lancer SDK et faire les modifications nécessaires. On aura à utiliser les fonctions:
  
  - XCalculateLayer2_Initialize pour initialiser l'IP à son adresse
  
  - XCalculateLayer2_Write pour instancialiser le poids et le nombre de neurones.
  
  - XCalculateLayer2_Start pour démarrer les calculs
  
  - XCalculateLayer2_IsDone qui permet de savoir si les calculs sont finis (à utiliser comme dans la boucle while)
  
  - XCalculateLayer2_Read pour lire les valeurs à l'issue du calcul
  
On obtient ceci:
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/130039f7-93b1-4af8-9398-9e36dad39c93 >
</p>
<br>
La structure retient toujours la structure 2.
<h2>
  <h2 align ="center"> Etape 4 : Objectif secondaire
</h2>
<br>
Pour cette partie, on a essayé de respecter toutes les conditions imposées par l'encadreur. En respectant les mêmes étapes que pour le layer 2, on essaiera cette fois d'implémenter pour tous les autres layers. Voici un exemple d'implémnentation du code:
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/c99612de-4df2-4bfd-9a10-a147e231c2f6 >
</p>
<br>
  
On obtient en simulation les résultats suivants:
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/ef0e2764-1b0a-4702-8dfd-e339fb1ce736>
</p>
<br>
  
  Le premier constant qui nous frappe est le temps estimé qui ne semble pas respecter nos 10 ns. En allant regarder les schémas blocks dans Vivado(grâce à l'aide de l'encadreur), on va vite se rendre compte du problème car il s'agit de la fonction SIGMOID qui au départ utilise la fonction tanh. Etant appelée plusieurs fois pour le calcul de somme, on a donc un problème de petits temps qui s'ajoutent à la chaîne. On a fait alors ce qui semble intéressant en termes de perspectives: créer un tableau de valeurs pour des sommes de la formule de SIGMOID. On passera pour cela par matlab pour générer ces valeurs. Voici un example du code.
<br>
<p>
 <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/b74dcd3f-1b09-4d4b-9219-7d15d095c739>
</p>
<br>  
 
Grâce à ce code, on va générer 8354 valeurs avec des sommes allant de 0 et pour un part 1/1000. Pourquoi 8354? Parce que la formule nous permet de majorer entre 0 et 1.759. Comme en témoigne ce tracé.
<br>
<p>
 <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/550282ff-7dd6-4dc2-b02e-b974d92a8b64>
</p>
<br>  
On ajoute ces valeurs dans un tableau dans le fichier tab_tanh. On modifie alors SIGMOID pour avoir cette fonction renvoyant vers une valeur du tableau:
<br>
<p>
 <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/b5be0234-3a1a-4adc-acee-e54261cad523>
</p>
<br>  
  
Après modification du code, on se rend compte que le nombre de BRAM est limité et donc on prend plus que ce que ne peut recevoir cette dernière.

<br>
<p>
 <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/692c34b0-cb0e-45ef-af5f-09ed8b995052>
</p>
<br>  
C'est que va entrer en jeu les directives (HLS pragma) qui permettent d'optimiser notre code. Notre BRAM étant trop rempli mais la LUTROM disposant d'espace, on se propose donc de rajouter les poids d'une ou plusieurs couches dans cette dernière. On aura alors:
<br>
<p>
 <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/54b9da96-9c33-4963-a0c0-5fd5cbe96e90>
</p>
<br> 
L'utilisation de la BRAM passe de 109%  à 102% (Malgré les combinaisons pour répartir les couches entre BRAM et LUTROM, on arrive pas à faire plus de 2%). On a alors quelques suggestions pour palier à ce problème:
  
  - Diviser le tableau Layer3_Weights_CPU en 5 tableaux pour faire directement faire la somme dans la boucle for permettant le calculateLayer4.
  
  - Penser à réduire la tab_tanh de taille(changer le pas de 1/1000 à 1/100)
  
  - Ne pas oublier de rechercher des moyens d'optimiser le code
  
Quoi qu'il en soit, il existe une multitude de pistes à explorer qui peuvent nous permettent d'améliorer ce travail déjà effectuer.
<br>

