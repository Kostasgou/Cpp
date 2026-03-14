# 2D Arcade Game in C++ with SGG Graphics

A C++ arcade-style game developed with the **SGG graphics library**, featuring a complete gameplay loop with a player-controlled spaceship, moving hazards, enemy alien ships, collectible power-ups, life management, win and game over screens, and audio-visual assets.

This project demonstrates the practical use of **object-oriented programming**, **real-time game loops**, **collision detection**, **scene/state management**, and **2D game development** principles in C++.

---

## Overview

This project is a small but complete **2D arcade game** inspired by obstacle-avoidance and collection-based gameplay.

The player controls a spaceship-like character that moves horizontally across the screen while interacting with a continuously updated game world. During gameplay, the player must:

* move left and right to survive
* interact with falling or moving objects
* avoid enemy ships
* collect power-ups
* preserve remaining lives
* reach the score target in order to win

The game includes a full game flow:

* **start screen**
* **main gameplay scene**
* **game over screen**
* **win screen**

This makes the project more than a graphics demo: it is a structured game with multiple screens, gameplay logic, collision rules, HUD elements, and resource handling.

---

## Main Features

* Real-time 2D gameplay loop
* Player movement with acceleration and friction-like behavior
* Collision detection using bounding boxes
* Dynamic obstacle handling
* Enemy alien ship interactions
* Collectible power-ups
* Life system with visual HUD
* Score progression and win condition
* Dedicated start, game over, and win screens
* Background music and sound effects
* Asset-based rendering with textures and fonts

---

## Educational Goals

This project was developed as a practical exercise in C++ game programming.

It demonstrates:

* object-oriented design in game development
* entity-based architecture
* central state management
* update/draw loop separation
* collision systems in 2D games
* basic scene transitions
* interaction between gameplay systems and UI
* integration of external assets such as textures, fonts, and sounds

It is especially relevant for coursework related to:

* C++ programming
* Object-Oriented Programming
* Game Development
* Computer Graphics
* Interactive Systems

---

## Project Structure

```text
C++_Game/
├── Stage4/
│   ├── main.cpp
│   ├── gamestate.cpp
│   ├── gamestate.h
│   ├── level.cpp
│   ├── level.h
│   ├── player.cpp
│   ├── player.h
│   ├── asteroids.cpp
│   ├── asteroids.h
│   ├── alienship.cpp
│   ├── alienship.h
│   ├── powerupSp.cpp
│   ├── powerupSp.h
│   ├── powerupL.cpp
│   ├── powerupL.h
│   ├── life.cpp
│   ├── life.h
│   ├── block.cpp
│   ├── block.h
│   ├── gameobject.cpp
│   ├── gameobject.h
│   ├── box.cpp
│   ├── box.h
│   ├── gameover.cpp
│   ├── gameover.h
│   ├── win.cpp
│   ├── win.h
│   ├── Stage4.vcxproj
│   └── Stage4.vcxproj.filters
├── include/
├── lib/
├── bin/
│   └── assets/
├── Stage4.sln
├── README.md
└── .gitignore
```

---

## Technologies Used

* **C++**
* **SGG graphics library**
* **Visual Studio solution/project structure**
* 2D bitmap rendering
* Audio playback
* Font rendering
* Axis-aligned bounding box collision logic

---

## General Architecture

The game follows a clear architecture centered around a global game manager and multiple gameplay entities.

### Core Architectural Components

#### `main.cpp`

The entry point of the game.

Responsibilities:

* create the game window
* initialize the graphics context
* connect the draw callback
* connect the update callback
* set canvas parameters
* start the main loop

This file defines the basic execution structure of the application.

#### `GameState`

The central singleton that controls the overall game flow.

Responsibilities:

* initialize all major game objects
* store references to the current gameplay systems
* manage transitions between screens
* update the active game scene
* draw the currently active scene
* preload assets and setup audio

This is the most important manager class in the entire project.

#### `Level`

Represents the main gameplay scene.

Responsibilities:

* create and initialize world entities
* update moving objects
* handle collisions
* manage score progression
* trigger win or game-over transitions
* draw the active game world and HUD

#### Entity Classes

The game world contains several entity types, each with a different gameplay role:

* `Player`
* `block`
* `Asteroids`
* `AlienShip`
* `PowerUpSp`
* `PowerUpl`
* `Life`
* `Gameover`
* `win`

#### Base Infrastructure

Two utility/base classes support the entity system:

* `GameObject` for common object behavior
* `Box` for collision geometry and intersection logic

---

## Game Flow

The full game flow is organized into multiple states.

### 1. Start Screen

When the game starts, the player sees the initial start screen.

This screen acts as the game entry scene and waits for the player to begin.

### 2. Main Gameplay

After starting, the game enters the main level.

In this state, the player can:

* move horizontally
* collide with or avoid different entities
* collect points
* pick up power-ups
* lose or gain lives

### 3. Game Over

If the player’s lives reach zero, the game transitions to the game over screen.

### 4. Win Screen

If the player reaches the required point total, the game transitions to the win screen, which also displays completion information.

This multi-screen structure gives the project the feel of a complete playable game rather than a single-scene demo.

---

## State Management with `GameState`

The project uses a singleton-style `GameState` class to coordinate everything.

### Why It Matters

This central manager controls:

* initialization
* scene switching
* active object references
* global offsets/camera-like positioning
* screen-specific drawing and updating

### Stored References

`GameState` keeps references to important objects such as:

* current level
* player
* blocks
* asteroids
* life HUD
* alien ships
* speed power-up
* life power-up
* game over screen
* win screen

### Screen Switching Logic

The game uses an internal state flag to switch between screens such as:

* start scene
* gameplay scene
* game over scene
* win scene

This gives the project a simple but effective scene-management structure.

---

## Core Base Classes

## `GameObject`

This class acts as a common base for most in-game entities.

It includes:

* a pointer to `GameState`
* object naming and identification
* an active/inactive state
* common virtual methods such as:

  * `init()`
  * `update()`
  * `draw()`

This gives all game entities a shared interface and simplifies object management.

---

## `Box`

This class represents the collision box of an object.

It stores:

* position
* width
* height

It also implements bounding-box collision methods such as:

* general intersection
* downward collision checks
* sideways collision checks

This is the foundation of the game’s collision system.

---

## Main Gameplay Classes

## `Player`

The `Player` class is the main character controlled by the user.

### Responsibilities

* respond to keyboard input
* move horizontally across the screen
* maintain player life count
* render the player sprite
* interact with the rest of the game world through collisions

### Movement Model

The player uses a movement model that includes:

* acceleration
* maximum horizontal speed
* velocity damping / friction-like behavior

This makes movement feel smoother than simple instant-position changes.

### Controls

The player moves using:

* `A` for left
* `D` for right

The player sprite also visually flips depending on movement direction.

### Lives

The player begins with a maximum life value and can:

* lose life when colliding with enemies
* gain life through life power-ups

---

## `Level`

The `Level` class is the main gameplay controller.

It is responsible for:

* creating the world objects
* updating entities frame by frame
* handling collisions
* tracking points
* respawning or recycling moving entities
* triggering win and lose conditions

### Entities Managed by `Level`

The level manages collections of:

* static boundary objects
* asteroids
* alien ships
* speed power-ups
* life power-ups

It also interacts with:

* the player
* the life HUD

### Score System

The level tracks a point counter. The player gains points by interacting with specific gameplay objects, and the game ends in victory when the target score is reached.

### Win/Loss Handling

The level directly triggers:

* the game over state when life becomes zero
* the win state when the point goal is reached

This makes `Level` the gameplay core of the project.

---

## `block`

The `block` class represents static environment boundaries or obstacles.

These objects act as world limits and participate in collision handling.

They are especially important for constraining the player’s movement inside the intended playable area.

---

## `Asteroids`

The `Asteroids` class represents moving obstacles or collectible gameplay objects in the scene.

### Role in Gameplay

Asteroids are part of the main gameplay loop and contribute to score progression.

They move dynamically and are checked continuously for interaction with the player.

### Visual Role

They provide the core arcade feeling of the game, reinforcing the space-themed environment.

---

## `AlienShip`

The `AlienShip` class represents enemy entities.

### Role in Gameplay

Alien ships are dangerous objects that the player must avoid.

When the player collides with an alien ship:

* life is reduced
* the collision affects survival

### Behavior

Alien ships move dynamically and can be temporarily affected by the speed-reduction power-up.

This makes them more than simple static hazards and adds strategic value to power-up collection.

---

## `PowerUpSp`

This class represents the speed power-up.

### Gameplay Effect

When collected, it temporarily reduces the speed of alien ships.

### Importance

This power-up provides a short-term gameplay advantage and adds variation to the interaction system.

It encourages risk/reward decision-making by rewarding the player for collecting it.

---

## `PowerUpl`

This class represents the life power-up.

### Gameplay Effect

When collected, it restores one life to the player up to the allowed maximum.

### Importance

This helps balance the difficulty and gives the player recovery opportunities during gameplay.

---

## `Life`

The `Life` class acts as a visual HUD element.

### Role

It follows the player’s status and renders a life indicator depending on how many lives remain.

### Visual Feedback

Different textures are used for different life values, making the current health state immediately visible to the player.

This improves usability and gives the game a more polished presentation.

---

## End Screens

## `Gameover`

This class represents the game over screen.

Its job is to display the dedicated end-state visuals after the player loses all remaining lives.

---

## `win`

This class represents the win screen.

It displays the victory scene and also presents completion-related feedback to the player.

This creates a rewarding end-state for successful gameplay.

---

## Collision Detection System

One of the most important gameplay systems in the project is collision handling.

The project uses **axis-aligned bounding boxes (AABB)** through the `Box` class.

### Collision Types Used

The system supports:

* general overlap checks
* downward intersections
* sideways intersections

### Collision Usage in Gameplay

Collisions are used to handle:

* player interaction with boundaries
* player interaction with asteroids
* player interaction with alien ships
* player interaction with speed power-ups
* player interaction with life power-ups

### Gameplay Consequences

Depending on the object type, a collision may:

* block player movement
* increase score
* reduce life
* slow enemies
* restore life
* trigger scene transitions

This makes collision detection one of the central mechanics of the game.

---

## Rendering and Visual Assets

The game relies on external assets stored in the `assets` folder.

These include:

* player sprite
* background image
* asteroid textures
* alien ship texture
* power-up textures
* life indicator textures
* start screen image
* game over image
* win image
* font file
* audio files

The rendering system uses these resources to provide a complete game presentation with themed visuals and sound.

---

## Audio

The project includes audio support for:

* background music
* sound effects

This enhances the player experience and contributes to the arcade atmosphere of the game.

---

## Gameplay Summary

From the player’s perspective, the game plays as follows:

1. Launch the game and view the start screen.
2. Begin the game and enter the main level.
3. Move left and right to survive and interact with objects.
4. Gain points through gameplay interactions.
5. Avoid alien ships that reduce life.
6. Collect speed power-ups to slow enemies.
7. Collect life power-ups to recover health.
8. Reach the score target to win.
9. Lose all lives to trigger the game over screen.

This creates a simple but effective arcade gameplay loop with clear goals and feedback.

---

## Why This Project Is Interesting

This project stands out because it combines multiple fundamental game-development systems into one cohesive C++ application.

It is not limited to drawing a sprite or moving a character. Instead, it includes:

* a windowed real-time game loop
* entity-based object design
* collision handling
* score progression
* resource management
* multiple game states
* audio and visual feedback
* reusable class structure

As a result, it serves as a strong academic and practical example of beginner-to-intermediate 2D game development in C++.

---

## How to Build and Run

### Requirements

To run the project successfully, you typically need:

* **Visual Studio**
* the included or referenced **SGG graphics library**
* the `include/` and `lib/` folders correctly configured
* the required assets inside `bin/assets/`

### General Steps

1. Open `Stage4.sln` in Visual Studio.
2. Make sure include and library paths are correctly configured.
3. Ensure the working directory can access the `assets` folder.
4. Build the solution.
5. Run the executable.

### Important Note

If the project depends on local Visual Studio configuration or library paths, those settings may need minor adjustments depending on the machine used.

---

## Controls

The core controls of the game are:

* `SPACE` to move from the start screen into gameplay
* `A` to move left
* `D` to move right

These are the main interactions required to play the game.

---

## Learning Outcomes

By studying or extending this project, one can better understand:

* how to structure a small game in C++
* how to use object-oriented design for game entities
* how to separate update and draw logic
* how to implement collision-based interactions
* how to manage lives, score, and scene transitions
* how to integrate textures, fonts, and sound into a graphics project
* how to build a multi-screen game with a single central state manager

---

## Possible Extensions

The project already provides a strong base for future development.

Possible improvements include:

* replacing the integer-based scene flag with a proper enum-based state machine
* improving player movement with vertical motion or shooting mechanics
* adding more enemy types
* introducing levels or increasing difficulty over time
* adding menus for restart or pause
* implementing particle effects or animations
* improving score display on screen
* refactoring repeated update logic for cleaner entity management
* adding a save/high-score system

These extensions could turn the current academic project into a more advanced and polished game.

---

## Repository Goals

This repository showcases:

* a complete 2D arcade game in C++
* use of the SGG graphics framework
* object-oriented game design
* collision detection with bounding boxes
* gameplay systems such as score, lives, enemies, and power-ups
* scene transitions for start, win, and game-over states
* a strong academic project in interactive programming

---

## Authors


* Konstantinos Gougas


---

## Final Notes

This project demonstrates how core C++ programming and object-oriented design can be applied to the creation of a functional 2D arcade game. By combining gameplay logic, entity systems, collisions, UI feedback, and scene management, it provides a complete and educational example of game development with graphics libraries in C++.
