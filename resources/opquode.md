# Cheatsheet

Le sujet est franchement pas clair, non ? Np, voici un recap des infos utiles.

## VM - Opquodes

| Nom | Opquode | Description |
| --- | ------- | ----------- |
| st | 0x03 | Prend un registre et un registre ou un indirect, et stocke la valeur du registre vers le second paramètre. Par exemple,st r1, 42stocke la valeur de r1 à l’adresse (PC + (42 % IDX_MOD)) |
| sti | 11 | Prend un registre, et deux index (potentiellement des registres).Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiéela valeur du premier paramètre. |
| fork | 0x0c | Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Créeun nouveau processus, qui hérite des différents états de son père, à part son PC,qui est mis à (PC + (1er paramètre % IDX_MOD)) |
| ld | 10 en binaire | Prend un paramètre quelconque et un registre. Charge la valeur du premier paramètre dans le registre binaire, il changera le carry. |
| lld | 13 | lld: Signifielong-load. C’est la même chose que ld, mais sans % IDX_MOD. Modifie le carry. |
| ldi | 0x0a | Prend 2 index et 1 registre, additionne les 2 premiers, traite ça comme une adresse, y lit une valeur de la taille d’un registre et la met dans le 3eme. |
| add | 4 | Prend trois registres, additionne les 2 premiers, et met le résultatdans le troisième, juste avant de modifier le carry.
| sub | 0b101 | Pareil que add, mais utilise une soustraction. |
| zjmp | 9 | Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des paramètres derrière cette opération. Elle prendra un index, et fait un saut à cette adresse si le carry est à 1. |
| or | 7 | Cette opération est un OU bit-à-bit, suivant le même principe que and. |
| xor | 10 en octal | Fait comme and avec un OU exclusif |
| and | 0x06 | Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stocke le résultat dans le registre qui est le 3ème paramètre. Modifie le carry. |
| aff | 10 en hex | Il y a un octet de codage des paramètres, même si c’est un peu bête car il n’y a qu’un paramètre, qui est un registre, dont le contenu est interprété comme la valeur ASCII d’un caractère à afficher sur la sortie standard. Ce code est modulo 256. |
| live | 0x01 | L’instruction qui permet à un processus de rester vivant. A également pour effet de rapporter que le joueur dont le numéro est en paramètre est en vie. Pas d’octet de codage des paramètres. Oh, et son seul paramètre est sur4 octets. |
| lldi | 0x0e | Pareil queldi, mais n’applique aucun modulo aux adresses. Modifiera, par contre, le carry. |

