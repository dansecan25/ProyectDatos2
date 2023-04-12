cmake_minimum_required(VERSION 3.24)
project(ProyectDatos2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectDatos2 main.cpp Source/GameControls.cpp Headers/GameControls.h
        Source/GameScreen.cpp Headers/GameScreen.h
        Source/EnemyShip.cpp Headers/EnemyShip.h
        Source/Player.cpp Headers/Player.h
        Source/ApplicationManager.cpp Headers/ApplicationManager.h
        Source/SettingsScreen.cpp Headers/SettingsScreen.h
        Source/Powers.cpp Headers/Powers.h
        Source/Bullet.cpp Headers/Bullet.h
        Source/GameMechanics.cpp Headers/GameMechanics.h
        Source/Waves.cpp Headers/Waves.h
        Source/LInkedLIstFIlesSources/Node.cpp Headers/LInkedListFilesHeaders/Node.h
        Source/LInkedLIstFIlesSources/SimpleLinkedList.cpp Headers/LInkedListFilesHeaders/SimpleLinkedList.h
        Source/BulletCollector.cpp Headers/BulletCollector.h ImageLoader.cpp ImageLoader.h
        Source/SfmlButton.cpp Headers/SfmlButton.h
        Source/WindowState.cpp Headers/WindowState.h
        Source/LInkedLIstFIlesSources/WindowStatesStack.cpp Headers/LInkedListFilesHeaders/WindowStatesStack.h
        Source/LInkedLIstFIlesSources/texturesRoutes.cpp Headers/LInkedListFilesHeaders/texturesRoutes.h
        Source/Entities.cpp Headers/Entities.h
        Source/LInkedLIstFIlesSources/LinkedListStructured.cpp Headers/LInkedListFilesHeaders/LinkedListStructured.h
        Source/LInkedLIstFIlesSources/LinkedListStructured.cpp Source/MainScreen.cpp
        Headers/MainScreen.h Source/GameModeScreen.cpp Headers/GameModeScreen.h Source/EnemyManager.cpp Headers/EnemyManager.h Source/EnemyManager.cpp Source/EnemyList.cpp Headers/EnemyList.h)
target_link_libraries(ProyectDatos2 sfml-graphics sfml-window sfml-system)