<p>
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/5523b2d0-aeb7-485c-8bdd-dbb5c23ea22e p align="left">
  <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/ee78a014-0f7c-4ffa-82ed-bfce217817c7  p align ="right">
</p>

<br>
<br>

<h4>
  <h4 align ="center">Année scolaire: 2022 - 2023    
  &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp     
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
Pour ce qui est de la couche qui va nécessier notre attention, nous avons pris la couche 2.
<br> 
  
<h2>
  <h2 align ="center"> Etape 2 : Profilage sur le FPGA et réalisation de l'IP
</h2>
<br>
Dans un premier temps, nous allons exécuter le code sur ARM. Pour se faire, on va instancier sur Vivado le processeur puis utiliser l'environnement SDK pour développer le code qui sera utilisé sur le processeur. Ensuite, nous afficherons le résultat reconnu par la structure sur des LEDS. Nous utiliserons ici la carte ZedBoard comprenant le FPGA Zynq7000. Le code se trouve dans ce repository. L'exécution et compilation du code nous permet d'avoir le résulat précédemment observé:
<br>
<br>
<p>
 <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/5b7e5c97-cce2-48d6-8e0f-fc5f3eb550a0 >
</p>
<br> 
 On va ensuite afficher le résultat sur les leds. On peut effectuer cela grâce à deux fonctions : XGPIO_Initialize qui permet d'initialiser l'IP (à mettre dans le main) puis le XGPIO_SetWrite qui permet d'écrire le résultat indexmax(résultat reconnu par la structure) sur les leds. Nous visualisons le résultat suivant:
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
  
<h2>
  <h2 align ="center"> Etape 4 : Objectif secondaire
</h2>
<br>

