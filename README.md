背景：个人数据备份




# 准备
## 安装gtest
```sh
sudo apt-get update
sudo apt-get install libgtest-dev

# 还需要编译 gtest
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib
```
# 编译
```sh
# Test
mkdir build
cd build
cmake .. -DBUILD_TESTING=ON
cmake --build . --config Test

# Release
mkdir build
cd build
cmake ..
cmake --build . --config Release

# Debug
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```
# TODO
- 根据构建类别分为release debug 以及test三个类别分别配置编译参数
- 