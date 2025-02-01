### Description repository
- Check file `Task.pdf`

### Описание
Тестовое задание для стажера на позицию «Программист на языке C++»
Проект состоит из трёх частей:
- Библиотека Library (реализация трёх функций)
    - Функция 1 с заменой чётных элементов трактуется в этой реализации как: замена чётных цифр.
- Программа 1. Двупоточная программа: 
    - Первый поток cin и обработка функцией 1
    - Второй поток обработка функцией 2. Отправление данных в Программу 2. Выступает как клиент для Программы 2
- Программа 2. Принимает данные от Программы 1 и обрабатывает в функции 3. Выступает в роли сервера.

### IP and port:
- Default **IP** server (*Program2*): `0.0.0.0` (INADDR_ANY) - listen all interfaces
- Default **IP** client (*Program1*): `127.0.0.1` (localhost)
- Default **port**: `8888`
- Edit **IP** and **port** in `Program2/SocketManager.cpp`

### Compile project:
```bash
cd <repository_path>
cmake -S . -B out/build_linux
cmake --build out/build_linux 
```

### Start programs:
```bash
./out/build_linux/Program1/Program1
./out/build_linux/Program2/Program2
```

### Stop programs: 
- #### Program1:
    - Press `Ctrl+C` and then put random symbol or symbols and press `Enter` to unlock program in std::cin
    - Or press a lot of `Ctrl+C` 
- #### Program2
    - Press `Ctrl+C`