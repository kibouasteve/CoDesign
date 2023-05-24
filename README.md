<p>
  <img src= https://github.com/kibouasteve/CoDesign/assets/71629695/5523b2d0-aeb7-485c-8bdd-dbb5c23ea22e p align="left">
  <img src=https://github.com/kibouasteve/CoDesign/assets/71629695/ee78a014-0f7c-4ffa-82ed-bfce217817c7  p align ="right">
</p>

<br>
<br>

<h4>
  <h4 align ="center">Année scolaire: 2022 - 2023    
  &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp     &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp
  &nbsp &nbsp &nbsp 
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
<h2>
  <h2 align ="center"> Etape 2 : Profilage sur le FPGA et réalisation de l'IP
</h2>
<br>
  
<h2>
  <h2 align ="center"> Etape 3 : High Level Synthesis - HLS
</h2>
<br>
  
<h2>
  <h2 align ="center"> Etape 4 : Objectif secondaire
</h2>
<br>

