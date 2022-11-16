# ASCIIRogueLikeGame
Project for my 3rd Software Development for Gaming Module - [Project Brief](https://github.com/rossliam2212/ASCIIRogueLikeGame/blob/main/Project%20Brief.pdf).

## QuickLinks
- [ASCII Character Tables](#ascii-character-tables)
- [Gameplay](#gameplay)
- [Game Map](#game-map)
- [UML Class Diagram](#uml-class-diagram)

## ASCII Character Tables

#### Environment
| **Symbol**      | **Name**  | **Description**                                                          |
|:----------------|:----------|:-------------------------------------------------------------------------|
| +               | Door      | Indicates a door that can be entered to travel to another room.          |
| #               | Path      | Indicates a path that the player can travel along to move between rooms. |
| -               | Roof      | The roof of a room. The player **CANNOT** pass through this character.   |
| &#124;          | Wall      | The wall of a room. The player **CANNOT** pass through this character.   |

#### Game Items
| **Symbol** | **Name**      | **Description**                                                                          |
|:-----------|:--------------|:-----------------------------------------------------------------------------------------|
| *          | Gold Coin     | Gold Coins can are used to buy weapons from the buy menu                                 |
| ^          | Health Potion | Health Potions are used to restore health back to the max.                               |
| ?          | Weapon        | Weapons are used to attack monsters. Each weapon picked up has randomly generated stats. |

#### Characters
| **Symbol** | **Name**  | **Description**       |
|:-----------|:----------|:----------------------|
| @          | Player    | The Player Character. |
| Z          | Zombie    | The Zombie Monster.   |
| S          | Skeleton  | The Skeleton Monster. |


## Gameplay

### Player
The player is represented by the '@' symbol. The objective of the player is to make their way through 
each level wiping out all the monsters that they face. The  player has a few different attributes: strength, 
health points, experience points level and experience points. These stats are displayed just above the inventory.

- **Strength:** This is the damage the player does when are not holding a weapon.
- **Health Points:** This is the players health. The player can restore their health to the max by using a heath potion.
- **Experience Points Level:** This is the experience level the player is at. Every time the player collects 100xp, they level up. When the player does level up, their max health and strength get increased.
- **Experience Points:** Experience points are collected by killing monsters. Each monster give different xp when killed.

There are three different game items scattered throughout each level that the player must use to their advantage.These 
items are gold coins, health potions and weapons. Each item that the player picks up gets added to their inventory and 
can then be used. The players inventory is displayed at the bottom of the screen and it shows how many gold coins, 
health potion and what weapons the player has and is currently using. The strength of each weapon is also displayed so 
the player can use their strongest weapons.  

#### Controls
| **Key**     | **Description**       |
|-------------|-----------------------|
| W           | Move Up               |
| A           | Move Left             |
| S           | Move Down             |
| D           | Move Right            |
| R           | Use Health Potion     |
| Q           | Drop Current Weapon   |
| Right Arrow | Cycle through weapons |


### Monster Behaviour
There are a few types of monsters, which are shown in the [characters table](#ascii-character-tables) above. Monsters have
similar attributes to the player. They have a strength, health points and a death xp. They also have a follow distance. 
This is the amount of spaces that can be between them and the player before they start to follow the player. All monsters
work in the same way but have different stats for each of the attributes. Therefore, some monsters are stronger and more 
dangerous than others, so the player must choose their attacks wisely.

## Game Map

*Insert Image of Maps*

## UML Class Diagram
