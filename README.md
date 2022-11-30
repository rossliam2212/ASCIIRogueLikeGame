# ASCIIRogueLikeGame
Project for my 3rd Software Development for Gaming Module - [Project Brief](https://github.com/rossliam2212/ASCIIRogueLikeGame/blob/main/Project%20Brief.pdf).

## QuickLinks
- [ASCII Character Tables](#ascii-character-tables)
  - [Environment Characters](#environment-characters)
  - [Game Items Characters](#game-item-characters)
  - [Player and Monster Characters](#player-and-monster-characters)
- [Gameplay](#gameplay)
  - [Player](#player)
    - [Controls](#controls)
    - [Game Items](#game-items)
    - [Attacking](#attacking)
  - [Monster Behaviour](#monster-behaviour)
  - [Game History](#game-history)
- [Game Levels](#game-levels)
- [UML Class Diagram](#uml-class-diagram)

## ASCII Character Tables

#### Environment Characters
| **Symbol**      | **Name**    | **Description**                                                           |
|:----------------|:------------|:--------------------------------------------------------------------------|
| +               | Door        | Indicates a door that can be entered to travel to another room.           |
| #               | Path        | Indicates a path that the player can travel along to move between rooms.  |
| -               | Roof        | The roof of a room. The player **CANNOT** pass through this character.    |
| &#124;          | Wall        | The wall of a room. The player **CANNOT** pass through this character.    |
| >               | Next Level  | Indicates the entry point for the next level.                             |

#### Game Item Characters
| **Symbol** | **Name**      | **Description**                                                                              |
|:-----------|:--------------|:---------------------------------------------------------------------------------------------|
| *          | Gold Coin     | Gold Coins can are used to buy weapons from the buy menu,                                    |
| ^          | Health Potion | Health Potions are used to restore health back to the max.                                   |
| ?          | Weapon        | Weapons are used to attack monsters. Each weapon picked up has randomly generated stats.     |
| $          | Buy Menu      | Gives the player an opportunity to buy stronger weapons with gold coins they have collected. |

#### Player and Monster Characters
| **Symbol** | **Name** | **Description**       |
|:-----------|:---------|:----------------------|
| @          | Player   | The Player Character. |
| Z          | Zombie   | The Zombie Monster.   |
| S          | Skeleton | The Skeleton Monster. |
| G          | Goblin   | The Goblin Monster.   |
| O          | Ogre     | The Ogre Monster.     |


## Gameplay

### Player
The player is represented by the '@' symbol. The objective of the player is to survive their way through
each level wiping out all the monsters that they face. The  player has a few different attributes: strength,
health points, experience points level and experience points. These stats are displayed just above the inventory.

- **Strength:** This is the damage the player does when are not holding a weapon.
- **Health Points:** This is the player's health. The player can restore their health to the max by using a heath potion.
- **Experience Points Level:** This is the experience level the player is at. Every time the player collects 70xp, they level up. When the player does level up, their max health and strength get increased.
- **Experience Points:** Experience points are collected by killing monsters. Each monster gives different xp when killed.

<!--
![stats](https://user-images.githubusercontent.com/73957889/203876543-b0d1d787-6e27-47d8-9c76-ce30e21482e7.png)
-->
![4](https://user-images.githubusercontent.com/73957889/204525670-a9f2a4d9-6013-4b3a-8a0e-5ee8f7eeffb2.PNG)

The player only has one life. This means that if the player is killed by a monster during the game, the game is over. When the
player is killed, the game over UI is displayed on screen.

![gameOver](https://user-images.githubusercontent.com/73957889/204901167-34e5fcf2-1710-414c-bb83-e28d125f2579.png)

However, if the player survives their way through each level and reaches the very end, then the game is over and the player wins.
When the player does win, the game over win UI is displayed on screen.

![gameWin](https://user-images.githubusercontent.com/73957889/204901195-3316426b-fc5f-40ed-84b4-9ad1d6f1ec9e.png)

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
There are four different game items scattered throughout each level that the player must use to their advantage. These
items are gold coins, health potions, weapons and the buy menu, which are shown in the [character table](#game-item-characters) above. Each 
item that the player picks up, aside from the buy menu gets added to their inventory and can then be used. The players 
inventory is displayed at the bottom of the screen, and it shows how many gold coins, health potion and what weapons the 
player has and is currently using. The strength of each weapon and the number of attacks remaining on each weapon is also 
displayed so the player can use their strongest weapons. When all of a weapons attacks have been used, the weapon is considered 
broken removed from the players inventory.

<!--
![inventory](https://user-images.githubusercontent.com/73957889/203876530-868dbc71-9be1-4720-b28b-c921ca9f17ae.png)
-->
![2](https://user-images.githubusercontent.com/73957889/204525765-34eb1d87-b3f6-4fb2-8da7-46ae709e9ea0.PNG)

The buy menu game item gives the player a single opportunity to buy stronger weapons. Once picked up, the buy menu can be
activated by pressing 'B'. This will display three weapons at the bottom of the screen which the player can buy using the
gold coins that they have collected. The stats for these weapons are calculated based on the players current xp level and also the
level that the buy menu is activated in. Once a weapon is purchased, it is added to the players inventory and the gold
coins are removed.

![Buy Menu](https://user-images.githubusercontent.com/73957889/203667829-aab46500-2e64-40b1-9f10-5c5ebe5be22f.png)

#### Attacking
The player can attack a monster by trying to move into the same position as the monster. Once the player has done this, the
attack loop automatically starts and both the player and the monster will have a chance to make their attack. The attacking UI,
which is displayed at the bottom of the screen under the inventory, is displayed and shows each attack that the player and monster
make. Neither the player nor monster will be able to move once an attack has started. The player gets the first chance to attack and
then the monster gets their chance. This will continue until either the player or monster is killed. If the monster kills the player,
then the game is over.

![3](https://user-images.githubusercontent.com/73957889/204525875-1e6aa8b7-77ad-4f6c-af90-134a4170da69.PNG)

### Monster Behaviour
There are a few types of monsters, which are shown in the [character table](#player-and-monster-characters) above. Monsters have
similar attributes to the player. They have a strength, health points, a death xp. The death xp is the amount of xp that the player
receives when they kill the monster. They also have a follow distance. This is the amount of spaces that can be between them and the
player before they start to follow the player. All monsters work in the same way but have different stats for each of their attributes.
Therefore, some monsters are stronger and more dangerous than others, so the player must choose their weapons and attacks and use
their health potions wisely. Monsters also drop gold coins when they are killed which get added to the players inventory. The amount
of gold coins dropped depends on the monster.

### Game History
All the events that occur while playing the game are logged to the [GameSessionHistory txt file](https://github.com/rossliam2212/ASCIIRogueLikeGame/blob/main/Code/GameSessionHistory.txt)
along with the time and date that they occurred on.

List of events that get logged:
- When the game starts.
- When the player picks up an item.
- When the player buys a weapon from the buy menu.
- When the player uses an item (Gold Coin/Heath Potion or Drops Weapon).
- When the player's weapon breaks.
- When the player xp is leveled up.
- When the player moves to a new level.
- When the player starts an attack on a monster.
- When the player deals damage to a monster.
- When the monster deals damage to the player.
- When a monster is killed.
- When the player is killed.
- When the player beats the game.
- When the game is over.

Here is an example GameSessionHistory txt file:
```
Game Session Started @ Wed Nov 30 19:57:59 2022

Wed Nov 30 19:58:08 2022
	- Picked Up Item -> Gold Coin @ position (4, 8)
Wed Nov 30 19:58:09 2022
	- Picked Up Item -> Health Potion @ position (3, 2)
Wed Nov 30 19:58:10 2022
	- Used Item -> Health Potion
Wed Nov 30 19:58:13 2022
	- Picked Up Item -> Gold Coin @ position (22, 1)
Wed Nov 30 19:58:14 2022
	- Picked Up Item -> Gold Coin @ position (22, 3)
Wed Nov 30 19:58:15 2022
	- Picked Up Item -> Gold Coin @ position (21, 9)
Wed Nov 30 19:58:24 2022
	- Picked Up Weapon -> Pike(17 damage) @ position (42, 7)
Wed Nov 30 19:58:28 2022
	- Picked Up Item -> Gold Coin @ position (53, 8)
Wed Nov 30 19:58:30 2022
	- Picked Up Item -> Gold Coin @ position (72, 9)
Wed Nov 30 19:58:31 2022
	- Picked Up Item -> Gold Coin @ position (76, 8)
Wed Nov 30 19:58:32 2022
	- Picked Up Item -> Gold Coin @ position (81, 9)
Wed Nov 30 19:58:33 2022
	- Picked Up Item -> Gold Coin @ position (78, 6)
Wed Nov 30 19:58:33 2022
	- Picked Up Item -> Gold Coin @ position (78, 2)
Wed Nov 30 19:58:35 2022
	- Picked Up Weapon -> Pipe(18 damage) @ position (70, 2)
Wed Nov 30 19:58:37 2022
	- Picked Up Item -> Health Potion @ position (62, 4)

Wed Nov 30 19:58:42 2022
	- Attack Started -> Attacking Zombie (100hp) @ position (70, 5)

		- Dealt 17 damage to Zombie (83hp remaining)
		- Zombie dealt 15 damage to You (85hp remaining)
		- Dealt 17 damage to Zombie (66hp remaining)
		- Zombie dealt 15 damage to You (70hp remaining)
		- Dealt 17 damage to Zombie (49hp remaining)
		- Zombie dealt 15 damage to You (55hp remaining)
		- Dealt 17 damage to Zombie (32hp remaining)
		- Zombie dealt 15 damage to You (40hp remaining)
		- Dealt 17 damage to Zombie (15hp remaining)
		- Zombie dealt 15 damage to You (25hp remaining)
		- Dealt 17 damage to Zombie (0hp remaining)

		- Killed Monster -> Zombie(+15xp, +3 gold coins) w/ Pike(2 attacks remaining) @ position (70, 5)

Wed Nov 30 19:58:57 2022
	- Picked Up Item -> Health Potion @ position (72, 17)
Wed Nov 30 19:58:58 2022
	- Picked Up Weapon -> Pipe(19 damage) @ position (72, 19)
Wed Nov 30 19:58:59 2022
	- Picked Up Item -> Gold Coin @ position (65, 19)
Wed Nov 30 19:58:59 2022
	- Picked Up Item -> Gold Coin @ position (65, 16)
Wed Nov 30 19:59:01 2022
	- Picked Up Item -> Gold Coin @ position (79, 16)
Wed Nov 30 19:59:02 2022
	- Picked Up Item -> Gold Coin @ position (79, 19)
Wed Nov 30 19:59:18 2022
	- Dropped Weapon -> Pike
Wed Nov 30 19:59:31 2022
	- Picked Up Item -> Gold Coin @ position (43, 19)
Wed Nov 30 19:59:32 2022
	- Used Item -> Health Potion
Wed Nov 30 19:59:36 2022
	- Picked Up Item -> Health Potion @ position (28, 22)
Wed Nov 30 19:59:36 2022
	- Picked Up Item -> Gold Coin @ position (31, 19)

Wed Nov 30 19:59:39 2022
	- Attack Started -> Attacking Goblin (100hp) @ position (39, 23)

		- Dealt 19 damage to Goblin (81hp remaining)
		- Goblin dealt 10 damage to You (90hp remaining)
		- Dealt 19 damage to Goblin (62hp remaining)
		- Goblin dealt 10 damage to You (80hp remaining)
		- Dealt 19 damage to Goblin (43hp remaining)
		- Goblin dealt 10 damage to You (70hp remaining)
		- Dealt 19 damage to Goblin (24hp remaining)
		- Goblin dealt 10 damage to You (60hp remaining)
		- Dealt 19 damage to Goblin (5hp remaining)
		- Goblin dealt 10 damage to You (50hp remaining)
		- Dealt 19 damage to Goblin (0hp remaining)

		- Killed Monster -> Goblin(+10xp, +2 gold coins) w/ Pipe(2 attacks remaining) @ position (39, 23)


====================================================
Wed Nov 30 19:59:52 2022
	 Moved to Level 2
====================================================
Wed Nov 30 20:00:04 2022
	- Used Item -> Health Potion
Wed Nov 30 20:00:08 2022
	- Picked Up Item -> Gold Coin @ position (15, 8)
Wed Nov 30 20:00:10 2022
	- Picked Up Weapon -> Staff(13 damage) @ position (7, 16)
Wed Nov 30 20:00:11 2022
	- Picked Up Item -> Gold Coin @ position (1, 15)
Wed Nov 30 20:00:13 2022
	- Picked Up Item -> Gold Coin @ position (1, 17)
Wed Nov 30 20:00:15 2022
	- Picked Up Item -> Gold Coin @ position (15, 17)
Wed Nov 30 20:00:15 2022
	- Picked Up Item -> Gold Coin @ position (15, 15)
Wed Nov 30 20:00:20 2022
	- Picked Up Item -> Health Potion @ position (15, 1)
Wed Nov 30 20:00:33 2022
	- Picked Up Item -> Gold Coin @ position (45, 14)
Wed Nov 30 20:00:34 2022
	- Picked Up Item -> Gold Coin @ position (44, 17)
Wed Nov 30 20:01:00 2022
	- Picked Up Item -> Gold Coin @ position (37, 3)
Wed Nov 30 20:01:02 2022
	- Picked Up Item -> Gold Coin @ position (47, 3)
Wed Nov 30 20:01:07 2022
	- Dropped Weapon -> Staff
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:01:18 2022
	- Bought Weapon for 18 gold coins -> Karambit(36 damage)

Wed Nov 30 20:01:25 2022
	- Attack Started -> Attacking Skeleton (100hp) @ position (42, 6)

		- Dealt 36 damage to Skeleton (64hp remaining)
		- Skeleton dealt 25 damage to You (75hp remaining)
		- Dealt 36 damage to Skeleton (28hp remaining)
		- Skeleton dealt 25 damage to You (50hp remaining)
		- Dealt 36 damage to Skeleton (0hp remaining)

		- Killed Monster -> Skeleton(+20xp, +5 gold coins) w/ Karambit(2 attacks remaining) @ position (42, 6)

Wed Nov 30 20:01:37 2022
	- Used Item -> Health Potion

Wed Nov 30 20:01:42 2022
	- Attack Started -> Attacking Zombie (100hp) @ position (41, 17)

		- Dealt 36 damage to Zombie (64hp remaining)
		- Zombie dealt 20 damage to You (80hp remaining)
		- Dealt 36 damage to Zombie (28hp remaining)
		- Zombie dealt 20 damage to You (60hp remaining)
		- Dealt 36 damage to Zombie (0hp remaining)

		- Killed Monster -> Zombie(+15xp, +3 gold coins) w/ Karambit(1 attacks remaining) @ position (41, 17)

Wed Nov 30 20:02:05 2022
	- Picked Up Item -> Gold Coin @ position (7, 22)
Wed Nov 30 20:02:05 2022
	- Picked Up Item -> Gold Coin @ position (7, 24)
Wed Nov 30 20:02:08 2022
	- Picked Up Item -> Health Potion @ position (30, 24)
Wed Nov 30 20:02:14 2022
	- Picked Up Weapon -> Baton(19 damage) @ position (57, 18)
Wed Nov 30 20:02:14 2022
	- Picked Up Item -> Gold Coin @ position (54, 17)
Wed Nov 30 20:02:15 2022
	- Picked Up Item -> Health Potion @ position (60, 17)
Wed Nov 30 20:02:17 2022
	- Used Item -> Health Potion
Wed Nov 30 20:02:21 2022
	- Picked Up Item -> Gold Coin @ position (66, 23)
Wed Nov 30 20:02:26 2022
	- Picked Up Item -> Health Potion @ position (79, 24)

Wed Nov 30 20:02:28 2022
	- Attack Started -> Attacking Skeleton (100hp) @ position (77, 21)

		- Dealt 36 damage to Skeleton (64hp remaining)
		- Skeleton dealt 25 damage to You (75hp remaining)
		- Dealt 36 damage to Skeleton (28hp remaining)
		- Skeleton dealt 25 damage to You (50hp remaining)
		- Dealt 36 damage to Skeleton (0hp remaining)
Wed Nov 30 20:02:34 2022
	- Leveled Up! New Stats -> XP Level: 2, Max Health: 110, Strength: 15

		- Killed Monster -> Skeleton(+20xp, +5 gold coins) w/ Karambit(0 attacks remaining) @ position (77, 21)

Wed Nov 30 20:02:36 2022
	- Weapon broken & Removed from inventory -> Karambit
Wed Nov 30 20:02:41 2022
	- Picked Up Item -> Gold Coin @ position (75, 10)
Wed Nov 30 20:02:43 2022
	- Picked Up Item -> Gold Coin @ position (66, 10)
Wed Nov 30 20:02:43 2022
	- Picked Up Item -> Gold Coin @ position (65, 8)

====================================================
Wed Nov 30 20:02:47 2022
	 Moved to Level 3
====================================================
Wed Nov 30 20:02:56 2022
	- Picked Up Item -> Gold Coin @ position (1, 1)
Wed Nov 30 20:02:58 2022
	- Picked Up Item -> Health Potion @ position (4, 6)
Wed Nov 30 20:03:00 2022
	- Used Item -> Health Potion
Wed Nov 30 20:03:05 2022
	- Picked Up Item -> Health Potion @ position (15, 1)
Wed Nov 30 20:03:07 2022
	- Picked Up Item -> Gold Coin @ position (21, 4)
Wed Nov 30 20:03:09 2022
	- Picked Up Item -> Gold Coin @ position (31, 3)
Wed Nov 30 20:03:10 2022
	- Picked Up Item -> Gold Coin @ position (37, 3)
Wed Nov 30 20:03:10 2022
	- Picked Up Item -> Gold Coin @ position (37, 4)
Wed Nov 30 20:03:10 2022
	- Picked Up Weapon -> Baton(10 damage) @ position (37, 6)
Wed Nov 30 20:03:18 2022
	- Dropped Weapon -> Baton
Wed Nov 30 20:03:25 2022
	- Picked Up Item -> Gold Coin @ position (32, 9)
Wed Nov 30 20:04:07 2022
	- Picked Up Item -> Gold Coin @ position (25, 12)
Wed Nov 30 20:04:07 2022
	- Picked Up Item -> Gold Coin @ position (25, 14)
Wed Nov 30 20:04:09 2022
	- Picked Up Item -> Gold Coin @ position (39, 14)
Wed Nov 30 20:04:10 2022
	- Picked Up Item -> Gold Coin @ position (39, 12)
Wed Nov 30 20:04:14 2022
	- Picked Up Item -> Health Potion @ position (12, 13)
Wed Nov 30 20:04:15 2022
	- Picked Up Item -> Gold Coin @ position (12, 16)
Wed Nov 30 20:04:15 2022
	- Picked Up Item -> Gold Coin @ position (12, 18)
Wed Nov 30 20:04:17 2022
	- Picked Up Item -> Gold Coin @ position (25, 17)
Wed Nov 30 20:04:18 2022
	- Picked Up Item -> Gold Coin @ position (25, 22)
Wed Nov 30 20:04:28 2022
	- Picked Up Item -> Gold Coin @ position (39, 17)
Wed Nov 30 20:04:29 2022
	- Picked Up Item -> Gold Coin @ position (39, 22)
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:04:49 2022
	- Bought Weapon for 24 gold coins -> Balisong(47 damage)

Wed Nov 30 20:05:06 2022
	- Attack Started -> Attacking Ogre (120hp) @ position (68, 23)

		- Dealt 47 damage to Ogre (73hp remaining)
		- Ogre dealt 35 damage to You (75hp remaining)
		- Dealt 47 damage to Ogre (26hp remaining)
		- Ogre dealt 35 damage to You (40hp remaining)
		- Dealt 47 damage to Ogre (0hp remaining)

		- Killed Monster -> Ogre(+30xp, +8 gold coins) w/ Balisong(2 attacks remaining) @ position (68, 23)


====================================================
Wed Nov 30 20:05:18 2022
	 Moved to Level 4
====================================================
Wed Nov 30 20:05:29 2022
	- Used Item -> Health Potion
Wed Nov 30 20:05:30 2022
	- Picked Up Item -> Gold Coin @ position (2, 4)
Wed Nov 30 20:05:31 2022
	- Picked Up Item -> Gold Coin @ position (1, 6)

Wed Nov 30 20:05:35 2022
	- Attack Started -> Attacking Ogre (120hp) @ position (8, 3)

		- Dealt 47 damage to Ogre (73hp remaining)
		- Ogre dealt 40 damage to You (70hp remaining)
		- Dealt 47 damage to Ogre (26hp remaining)
		- Ogre dealt 40 damage to You (30hp remaining)
		- Dealt 47 damage to Ogre (0hp remaining)

		- Killed Monster -> Ogre(+30xp, +8 gold coins) w/ Balisong(1 attacks remaining) @ position (8, 3)

Wed Nov 30 20:05:47 2022
	- Picked Up Item -> Health Potion @ position (15, 1)
Wed Nov 30 20:05:48 2022
	- Picked Up Item -> Gold Coin @ position (15, 4)
Wed Nov 30 20:05:49 2022
	- Used Item -> Health Potion
Wed Nov 30 20:05:55 2022
	- Picked Up Item -> Gold Coin @ position (7, 11)
Wed Nov 30 20:05:56 2022
	- Picked Up Item -> Health Potion @ position (12, 11)

Wed Nov 30 20:06:46 2022
	- Attack Started -> Attacking Skeleton (100hp) @ position (23, 11)

		- Dealt 47 damage to Skeleton (53hp remaining)
		- Skeleton dealt 35 damage to You (75hp remaining)
		- Dealt 47 damage to Skeleton (6hp remaining)
		- Skeleton dealt 35 damage to You (40hp remaining)
		- Dealt 47 damage to Skeleton (0hp remaining)
Wed Nov 30 20:06:55 2022
	- Leveled Up! New Stats -> XP Level: 3, Max Health: 120, Strength: 20

		- Killed Monster -> Skeleton(+20xp, +5 gold coins) w/ Balisong(0 attacks remaining) @ position (23, 11)

Wed Nov 30 20:06:56 2022
	- Weapon broken & Removed from inventory -> Balisong
Wed Nov 30 20:07:10 2022
	- Used Item -> Health Potion
Wed Nov 30 20:07:14 2022
	- Picked Up Item -> Health Potion @ position (44, 4)
Wed Nov 30 20:07:19 2022
	- Picked Up Weapon -> Pipe(18 damage) @ position (70, 2)
Wed Nov 30 20:07:19 2022
	- Picked Up Item -> Gold Coin @ position (70, 4)
Wed Nov 30 20:07:20 2022
	- Picked Up Item -> Gold Coin @ position (70, 7)
Wed Nov 30 20:07:21 2022
	- Picked Up Item -> Gold Coin @ position (63, 6)
Wed Nov 30 20:07:22 2022
	- Picked Up Item -> Gold Coin @ position (58, 7)
Wed Nov 30 20:07:48 2022
	- Picked Up Item -> Health Potion @ position (54, 10)
Wed Nov 30 20:08:02 2022
	- Dropped Weapon -> Pipe
Wed Nov 30 20:08:06 2022
	- Picked Up Weapon -> Tonfa(11 damage) @ position (47, 10)
Wed Nov 30 20:08:12 2022
	- Picked Up Item -> Gold Coin @ position (40, 15)
Wed Nov 30 20:08:23 2022
	- Dropped Weapon -> Tonfa
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Used Item -> Gold Coin
Wed Nov 30 20:08:33 2022
	- Bought Weapon for 23 gold coins -> Tomahawk(51 damage)
Wed Nov 30 20:08:35 2022
	- Picked Up Item -> Gold Coin @ position (31, 19)

Wed Nov 30 20:08:46 2022
	- Attack Started -> Attacking Ogre (120hp) @ position (37, 18)

		- Dealt 51 damage to Ogre (69hp remaining)
		- Ogre dealt 40 damage to You (80hp remaining)
		- Dealt 51 damage to Ogre (18hp remaining)
		- Ogre dealt 40 damage to You (40hp remaining)
		- Dealt 51 damage to Ogre (0hp remaining)

		- Killed Monster -> Ogre(+30xp, +8 gold coins) w/ Tomahawk(1 attacks remaining) @ position (37, 18)

Wed Nov 30 20:08:55 2022
	- Picked Up Item -> Gold Coin @ position (40, 19)
Wed Nov 30 20:09:00 2022
	- Picked Up Item -> Health Potion @ position (51, 21)
Wed Nov 30 20:09:02 2022
	- Picked Up Item -> Gold Coin @ position (58, 24)
Wed Nov 30 20:09:03 2022
	- Picked Up Item -> Gold Coin @ position (60, 24)
Wed Nov 30 20:09:03 2022
	- Picked Up Item -> Gold Coin @ position (62, 24)

Wed Nov 30 20:09:18 2022
	- Attack Started -> Attacking Goblin (100hp) @ position (64, 18)

		- Dealt 51 damage to Goblin (49hp remaining)
		- Goblin dealt 25 damage to You (15hp remaining)
		- Dealt 51 damage to Goblin (0hp remaining)

		- Killed Monster -> Goblin(+10xp, +2 gold coins) w/ Tomahawk(0 attacks remaining) @ position (64, 18)

Wed Nov 30 20:09:23 2022
	- Weapon broken & Removed from inventory -> Tomahawk


Congratulations! You have beaten the game!

Game Over @ Wed Nov 30 20:09:54 2022
```

## Game Levels
There are five different levels that the player must make their way through. The levels were all designed in text files can be
found [here](https://github.com/rossliam2212/ASCIIRogueLikeGame/tree/main/Code/levels). The '=' characters that are in the
level text files represent spaces in the level. They do not appear while playing the game as they are replaced with
' ' when each level file is read in during the game.

Here is an example of how the level 1 looks when playing the game:
![1](https://user-images.githubusercontent.com/73957889/203439973-41bdd2e2-830e-4bb4-b654-c86a336b2ae8.png)

## UML Class Diagram
