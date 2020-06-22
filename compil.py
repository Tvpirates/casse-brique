import os as os
from os import system

with open("./commandes.txt", 'r') as file:
    cmds = file.readlines()

print("Génération .exe en cours")

for cmd in cmds:
    os.system(cmd)

print(".exe généré")
