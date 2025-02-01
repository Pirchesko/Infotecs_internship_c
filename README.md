### Description repository
- Check file `Task.pdf`

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