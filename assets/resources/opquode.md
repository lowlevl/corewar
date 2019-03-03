# Cheatsheet

Le sujet est franchement pas clair, non ? Np, voici un recap des infos utiles.


## VM - Opquodes

> **Note:** Les opcode du sujet de 42 ont l'air d'être exactement les mêmes que ceux du sujet d'epitech. On peut donc s'y référer pour la compréhension.


### Memo

| Nom  | opcode |
| ---- | ------- |
| live | 0x01    |
| ld   | 0x02    |
| st   | 0x03    |
| add  | 0x04    |
| sub  | 0x05    |
| and  | 0x06    |
| or   | 0x07    |
| xor  | 0x08    |
| zjmp | 0x09    |
| ldi  | 0x0a    |
| sti  | 0x0b    |
| fork | 0x0c    |
| lld  | 0x0d    |
| lldi | 0x0e    |
| aff  | 0x10    |


### Meaning

Note: for long example and description, please read epitech subject in assets.

- **live**: takes 1 parameter: 4 bytes that represent the player’s number.It indicates that the player is alive.
- **ld**: takes 2 parameters. It loads the value of the first parameter into the second parameter, which must bea register (not the PC). This operation modifies the carry.ld 34,r3loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MOD intor3.
- **st**: takes 2 parameters. It stores the first parameter’s value (which is a register) into the second (whether aregister or a number).


---
Made with 💖  and 🍵  by glodi.
