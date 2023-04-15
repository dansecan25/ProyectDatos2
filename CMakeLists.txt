cmake_minimum_required(VERSION 3.24)

project(ProyectDatos2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(ThirdPartyFolder/include)

set(serial_SRCS ThirdPartyFolder/src/serial.cc ThirdPartyFolder/include/serial/serial.h
        ThirdPartyFolder/include/serial/v8stdint.h ThirdPartyFolder/src/impl/list_ports/list_ports_linux.cc)
list(APPEND serial_SRCS ThirdPartyFolder/src/impl/unix.cc)

add_library(serial ${serial_SRCS})
target_link_libraries(serial rt)

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
        Headers/MainScreen.h Source/GameModeScreen.cpp Headers/GameModeScreen.h Source/EnemyManager.cpp Headers/EnemyManager.h Source/EnemyManager.cpp Source/EnemyList.cpp Headers/EnemyList.h Source/arduinoConnectionTest.cpp Source/ArduinoManagement.cpp Headers/ArduinoManagement.h)


target_link_libraries(ProyectDatos2 sfml-graphics sfml-window sfml-system serial)