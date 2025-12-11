背景：个人数据备份




# 准备
## 安装gtest
```sh
sudo apt-get update
sudo apt-get install libgtest-dev lcov

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
cmake .. -DCMAKE_BUILD_TYPE="Test"
cmake --build .

# Release
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE="Release"
cmake --build .

# Debug
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE="Debug"
cmake --build .
```
# 目录结构
```sh
.
├── CI             #CI的配置文件以及脚本
├── cmake           # cmake 的一些配置
├── config          # 一些项目配置
├── doc
│   ├── draw
│   ├── image
│   ├── protocol
│   └── test
├── include         # API
├── src             # 项目源代码
│   ├── client
│   ├── dtp
│   ├── lib
│   │   ├── ddm
│   │   └── net
│   ├── protocol
│   ├── server
│   └── sys
├── test            # 测试用例
└── tools           # 工具，比如说编辑发送ftp协议的工具

```
一个源文件必须对应一个头文件！！！源文件中只能存放函数或者类的实现，函数声明和类型定义都必须放在同一个目录下的头文件中。需要被其他模块引用的数据类型和函数必须放在`include`目录下