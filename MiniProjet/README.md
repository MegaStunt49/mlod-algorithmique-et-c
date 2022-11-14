# Description du projet
Refaire un jeu style super hexagon (ex: https://www.youtube.com/watch?v=5mDjFdetU28)
Mais cette fois en cercles, des cercles coupés grossissent et le but est de les esquiver,
Le joueur est bloqué à une certaine distance du centre et ne peut que tourner autour pour rentrer dans les cercles.
# Comment compiler
gcc -o game game.c -Wall -std=c11 /home/bot/Raylib.git/src/libraylib.a -lm -lrt -ldl -lX11 -lGL -lpthread
# Comment exécuter
./game
# Comment utiliser le projet
2 fleches de direction pour déplacer un curseur et rentrer dans les entrées de cercles
# URL vidéo de démo

# Quelques détails sur votre implémentation

# Extensions / améliorations possibles
Rendre le jeu plus rapide serait difficile,
Mais cela serait possible en ayant des niveaux à patern à apprendre au lieu du mini-jeu infini qui est pour l'instant en place.