# ASCIIRogueLikeGame
Project for my 3rd Software Development for Gaming Module - [Project Brief](https://github.com/rossliam2212/ASCIIRogueLikeGame/blob/main/Project%20Brief.pdf).

## QuickLinks
- [ASCII Character Tables](#ascii-character-tables)
- [Gameplay](#gameplay)
- [Game Levels](#game-levels)
- [UML Class Diagram](#uml-class-diagram)

## ASCII Character Tables

#### Environment
| **Symbol**      | **Name**  | **Description**                                                          |
|:----------------|:----------|:-------------------------------------------------------------------------|
| +               | Door      | Indicates a door that can be entered to travel to another room.          |
| #               | Path      | Indicates a path that the player can travel along to move between rooms. |
| -               | Roof      | The roof of a room. The player **CANNOT** pass through this character.   |
| &#124;          | Wall      | The wall of a room. The player **CANNOT** pass through this character.   |
| >               | Next Level| Indicates the entry point for the next level.                            |

#### Game Items
| **Symbol** | **Name**      | **Description**                                                                              |
|:-----------|:--------------|:---------------------------------------------------------------------------------------------|
| *          | Gold Coin     | Gold Coins can are used to buy weapons from the buy menu,                                    |
| ^          | Health Potion | Health Potions are used to restore health back to the max.                                   |
| ?          | Weapon        | Weapons are used to attack monsters. Each weapon picked up has randomly generated stats.     |
| $          | Buy Menu      | Gives the player an opportunity to buy stronger weapons with gold coins they have collected. |

#### Characters
| **Symbol** | **Name** | **Description**       |
|:-----------|:---------|:----------------------|
| @          | Player   | The Player Character. |
| Z          | Zombie   | The Zombie Monster.   |
| S          | Skeleton | The Skeleton Monster. |
| G          | Goblin   | The Goblin Monster.   |
| O          | Ogre     | The Ogre Monster.     |


## Gameplay

### Player
The player is represented by the '@' symbol. The objective of the player is to make their way through
each level wiping out all the monsters that they face. The  player has a few different attributes: strength,
health points, experience points level and experience points. These stats are displayed just above the inventory.

- **Strength:** This is the damage the player does when are not holding a weapon.
- **Health Points:** This is the players health. The player can restore their health to the max by using a heath potion.
- **Experience Points Level:** This is the experience level the player is at. Every time the player collects 100xp, they level up. When the player does level up, their max health and strength get increased.
- **Experience Points:** Experience points are collected by killing monsters. Each monster give different xp when killed.

#### Controls
| **Key**     | **Description**       |
|-------------|-----------------------|
| W           | Move Up               |
| A           | Move Left             |
| S           | Move Down             |
| D           | Move Right            |
| R           | Use Health Potion     |
| B           | Open Buy Menu         |
| Q           | Drop Current Weapon   |
| Right Arrow | Cycle through weapons |

#### Game Items
There are four different game items scattered throughout each level that the player must use to their advantage.These
items are gold coins, health potions, weapons and the buy menu. Each item that the player picks up, aside from the buy 
menu gets added to their inventory and can then be used. The players inventory is displayed at the bottom of the screen 
and it shows how many gold coins, health potion and what weapons the player has and is currently using. The strength of 
each weapon and the number of attacks remaining on each weapon is also displayed so the player can use their strongest 
weapons.

The buy menu game item gives the player a single opportunity to buy stronger weapons. Once picked up, the buy menu can be 
activated by pressing 'B'. This will display three weapons at the bottom of the screen that the player can buy using the 
gold coins that they have collected. The stats for these weapons are calculated based on the players current xp level and also the 
level that the buy menu is activated in. Once a weapon is purchased, it is added to the players inventory and the gold 
coins are removed.

#### Attacking
The player can attack a monster by trying to move into the same position as the monster. Once the player has done this, the 
attack loop automatically starts and both the player and the monster will have a chance to make their attack. The player
gets the first chance to attack and then the monster gets their chance. This will continue until either the player of monster
is killed.

#### Game History
All of the events that occur while playing the game are logged to the [GameSessionHistory txt file](https://github.com/rossliam2212/ASCIIRogueLikeGame/blob/main/Code/GameSessionHistory.txt). 

List of events that get logged:
- When the player picks up an item.
- When the player buys a weapon from the buy menu.
- When the player uses an item (Gold Coin/Heath Potion).
- When the player xp is leveled up.
- When the playe rmoves to a new level.
- When the player starts an attack on a monster.
- When the player deals damage to a monster.
- When the monster deals damage to the player.
- When a monster is killed.
- When the player is killed.
- When the game is over.

Here is an sample GameSessionHistory txt file:
```
Game Session Started @ Wed Nov 23 14:33:20 2022

Wed Nov 23 14:33:23 2022
	- Picked Up Item -> Gold Coin @ position (4, 8)
Wed Nov 23 14:33:25 2022
	- Picked Up Item -> Gold Coin @ position (20, 8)
Wed Nov 23 14:33:26 2022
	- Picked Up Item -> Gold Coin @ position (21, 9)
Wed Nov 23 14:33:27 2022
	- Picked Up Item -> Gold Coin @ position (22, 3)
Wed Nov 23 14:33:28 2022
	- Picked Up Item -> Gold Coin @ position (22, 1)
Wed Nov 23 14:33:31 2022
	- Picked Up Item -> Health Potion @ position (3, 2)
Wed Nov 23 14:33:36 2022
	- Used Item -> Health Potion
Wed Nov 23 14:33:43 2022
	- Picked Up Weapon -> Stick(10 damage) @ position (42, 7)
Wed Nov 23 14:33:45 2022
	- Picked Up Item -> Gold Coin @ position (53, 8)
Wed Nov 23 14:33:48 2022
	- Picked Up Item -> Gold Coin @ position (72, 9)
Wed Nov 23 14:34:01 2022
	- Picked Up Item -> Gold Coin @ position (76, 8)
Wed Nov 23 14:34:05 2022
	- Picked Up Item -> Gold Coin @ position (81, 9)
Wed Nov 23 14:34:06 2022
	- Picked Up Item -> Gold Coin @ position (78, 6)
Wed Nov 23 14:34:06 2022
	- Picked Up Item -> Gold Coin @ position (78, 2)
Wed Nov 23 14:34:10 2022
	- Picked Up Item -> Health Potion @ position (72, 17)
Wed Nov 23 14:34:11 2022
	- Picked Up Item -> Gold Coin @ position (65, 19)
Wed Nov 23 14:34:12 2022
	- Picked Up Item -> Gold Coin @ position (65, 16)
Wed Nov 23 14:34:15 2022
	- Picked Up Item -> Gold Coin @ position (79, 19)
Wed Nov 23 14:34:15 2022
	- Picked Up Item -> Gold Coin @ position (79, 16)
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Used Item -> Gold Coin
Wed Nov 23 14:34:27 2022
	- Bought Weapon for 12 gold coins -> Bayonet(26 damage)
Wed Nov 23 14:34:51 2022
	- Picked Up Item -> Gold Coin @ position (43, 19)

Wed Nov 23 14:34:52 2022
	- Attack Started -> Attacking Goblin (100hp) @ position (37, 20)

		- Dealt 26 damage to Goblin (74hp remaining)
		- Goblin dealt 10 damage to You (90hp remaining)
		- Dealt 26 damage to Goblin (48hp remaining)
		- Goblin dealt 10 damage to You (80hp remaining)
		- Dealt 26 damage to Goblin (22hp remaining)
		- Goblin dealt 10 damage to You (70hp remaining)
		- Dealt 26 damage to Goblin (-4hp remaining)

		- Killed Monster -> Goblin(+10xp) w/ Bayonet(2 attacks remaining) @ position (37, 20)


Wed Nov 23 14:34:59 2022
	- Attack Started -> Attacking Goblin (100hp) @ position (34, 23)

		- Dealt 26 damage to Goblin (74hp remaining)
		- Goblin dealt 10 damage to You (60hp remaining)
		- Dealt 26 damage to Goblin (48hp remaining)
		- Goblin dealt 10 damage to You (50hp remaining)
		- Dealt 26 damage to Goblin (22hp remaining)
		- Goblin dealt 10 damage to You (40hp remaining)
		- Dealt 26 damage to Goblin (-4hp remaining)

		- Killed Monster -> Goblin(+10xp) w/ Bayonet(2 attacks remaining) @ position (34, 23)

Wed Nov 23 14:35:06 2022
	- Picked Up Item -> Health Potion @ position (28, 22)
Wed Nov 23 14:35:10 2022
	- Used Item -> Health Potion
Wed Nov 23 14:35:12 2022
	- Picked Up Item -> Gold Coin @ position (31, 19)

Wed Nov 23 14:35:17 2022
	- Attack Started -> Attacking Skeleton (100hp) @ position (41, 23)

		- Dealt 26 damage to Skeleton (74hp remaining)
		- Skeleton dealt 20 damage to You (80hp remaining)
		- Dealt 26 damage to Skeleton (48hp remaining)
		- Skeleton dealt 20 damage to You (60hp remaining)
		- Dealt 26 damage to Skeleton (22hp remaining)
		- Skeleton dealt 20 damage to You (40hp remaining)
		- Dealt 26 damage to Skeleton (-4hp remaining)

		- Killed Monster -> Skeleton(+20xp) w/ Bayonet(2 attacks remaining) @ position (41, 23)

Wed Nov 23 14:35:23 2022
	- Used Item -> Health Potion

====================================================
Wed Nov 23 14:35:25 2022
	 Moved to Level 2
====================================================

Wed Nov 23 14:35:33 2022
	- Attack Started -> Attacking Zombie (100hp) @ position (1, 6)

		- Dealt 26 damage to Zombie (74hp remaining)
		- Zombie dealt 15 damage to You (85hp remaining)
		- Dealt 26 damage to Zombie (48hp remaining)
		- Zombie dealt 15 damage to You (70hp remaining)
		- Dealt 26 damage to Zombie (22hp remaining)
		- Zombie dealt 15 damage to You (55hp remaining)
		- Dealt 26 damage to Zombie (-4hp remaining)

		- Killed Monster -> Zombie(+15xp) w/ Bayonet(2 attacks remaining) @ position (1, 6)

Wed Nov 23 14:35:40 2022
	- Picked Up Item -> Health Potion @ position (15, 1)
Wed Nov 23 14:35:41 2022
	- Used Item -> Health Potion

Wed Nov 23 14:35:43 2022
	- Attack Started -> Attacking Zombie (100hp) @ position (14, 3)

		- Dealt 26 damage to Zombie (74hp remaining)
		- Zombie dealt 15 damage to You (85hp remaining)
		- Dealt 26 damage to Zombie (48hp remaining)
		- Zombie dealt 15 damage to You (70hp remaining)
		- Dealt 26 damage to Zombie (22hp remaining)
		- Zombie dealt 15 damage to You (55hp remaining)
		- Dealt 26 damage to Zombie (-4hp remaining)

		- Killed Monster -> Zombie(+15xp) w/ Bayonet(2 attacks remaining) @ position (14, 3)

Wed Nov 23 14:35:52 2022
	- Picked Up Item -> Gold Coin @ position (15, 8)
Wed Nov 23 14:35:55 2022
	- Picked Up Weapon -> Knuckleduster(10 damage) @ position (7, 16)
Wed Nov 23 14:36:12 2022
	- Picked Up Item -> Gold Coin @ position (37, 3)

Wed Nov 23 14:36:16 2022
	- Attack Started -> Attacking Skeleton (100hp) @ position (42, 5)

		- Dealt 26 damage to Skeleton (74hp remaining)
		- Skeleton dealt 20 damage to You (35hp remaining)
		- Dealt 26 damage to Skeleton (48hp remaining)
		- Skeleton dealt 20 damage to You (15hp remaining)
		- Dealt 26 damage to Skeleton (22hp remaining)
		- Skeleton dealt 20 damage to You (-5hp remaining)

		 You were killed by Skeleton (22hp remaining)

Game Over @ Wed Nov 23 14:36:20 2022
```

### Monster Behaviour
There are a few types of monsters, which are shown in the [character table](#ascii-character-tables) above. Monsters have
similar attributes to the player. They have a strength, health points and a death xp. They also have a follow distance.
This is the amount of spaces that can be between them and the player before they start to follow the player. All monsters
work in the same way but have different stats for each of their attributes. Therefore, some monsters are stronger and more
dangerous than others, so the player must choose their weapons and attacks wisely.

## Game Levels
There are 5 different levels that the player must make their way through. The levels are all in basic txt files can be 
found [here](https://github.com/rossliam2212/ASCIIRogueLikeGame/tree/main/Code/levels). 

Here is an example of how the level 1 looks when playing the game.

![1](https://user-images.githubusercontent.com/73957889/203439973-41bdd2e2-830e-4bb4-b654-c86a336b2ae8.png)

## UML Class Diagram
