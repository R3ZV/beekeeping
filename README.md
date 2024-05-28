# Inspiration
This games' design / art style is inspired by [Bee Swarm Simulator](https://www.roblox.com/games/1537690962/Bee-Swarm-Simulator)
and the gameplay from [Cookie Clicker](https://orteil.dashnet.org/cookieclicker/)

# Gameplay
In this game you are beekeeper, and you go to various fields to 
collect pollen with the help of your bees in order to make honey, so
you can get more bees and upgrade your backpack and your pollen collector.

## Showcase
[![Image Alt Text Here](https://img.youtube.com/vi/15egOJGjXro/0.jpg)](https://www.youtube.com/watch?v=15egOJGjXro)

# TODOs
## Design patterns
- [ ] 3 different OOP design patterns
    * [ ] Singleton
    * [x] Template method
    * [ ] ???


## Generic programming
- [ ] 1 generic class
- [ ] Create 1 generic function (or method, the class doesn't have to be generic)
    and call it (the generic type T can be used as a return type as well)

## STD
- [x] Use 2 functions from STD (not methods) e.g. all_of/any_of/none_of, somethig
- [x] Make use of 2 different types of containers (change some vecs into array
where you don't need the container to be growable)
- [x] Use 2 different types of smart pointers

# Functionality
- Reads the player stats from JSON file
- Multiple game scenes
- Player stats debug
- Player stats window
- Loading player stats from JSON file
- Can go to a field
- Can collect pollen
- Collected pollen is based on the flowers you have on the field and your collect amount
- When you collect pollen a text shows how much pollen you have collected
- Each field has different based on the theme
- Can sell pollen for honey
- Can upgrade your collect amount (how much pollen you get when you press SPACE)
- Can upgrade your backpack capacity
- Can upgrade your honey per pollen (to get more honey)
- Counts the number of created bees in a session

# Requirements
- G++ 17
- Make
- Raylib

This project also uses [nlohmann/json](https://github.com/nlohmann/json)
for serializing / deserializing json data.

Tested on: 
1. Arch Linux:
- OS: Arch Linux x86_64
- Kernel: 6.7.9-arch1-1

2. Pop!_OS
- OS: Pop!_OS 22.04 LTS x86_64
- Kernel: 6.6.6-76060606-generic

# Refererences
Background inspired by [Patrick](https://www.artstation.com/blacklunaris)
Field flowers inspired by [brittanyyt](https://www.pinterest.com/brittanyyt/)
