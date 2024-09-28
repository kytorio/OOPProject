# 中山大学2024级秋季学期面向对象第一次作业仓库

## Grid类：
### 成员：
- BOX_SIZE：int类型，用于记录网格内每一分区的大小
- GRID_SIZE：int类型，用于记录网格大小，通常为BOX_SIZE的平方
- grid：二维数组，记录网格数据
### 方法：
- 构造函数：分别定义有参和无参两类构造函数
- getRow：返回一维数组，获取网格内指定行信息，采用浅复制
- getColum：返回一维数组，获取网格内指定列信息，采用浅复制
- getBox：返回一维或二维数组，获取网格内指定分区信息，采用深复制
- setValue：设置网格内指定单元格值
- getValue：返回int值，获取网格内指定单元格值
- print：打印网格
- *getBoxSize：获取成员BOX_SIZE的值，可选*
- *getGridSize：获取成员GRID_SIZE的值，可选*

## Sudoku类：继承自Grid类

### 成员：
无另外定义成员

### 方法：

- 构造函数：分别定义有参构造和无参构造
- parse：无返回值，用于解析数独字符串将其转化为Sudoku对象
- getInference：无返回值，采用回溯推理得到数独解
- isValid：返回bool类型值，用于判断当前填入值是否有效

### 序列化/反序列化函数：
- SaveSudoku：将Sudoku对象序列化
- LoadSudoku：将Sudoku对象反序列化

## C++Project（静态类型）

采用Boost库进行序列化与反序列化的操作。其中数组采用Vector进行存储。

当前所使用的Boost库版本为1.86.0，所采用的开发IDE为Visual Studio2022，**在运行本项目前请自行安装配置Boost库**

若想测试该项目代码，仅需要编译并运行main.cpp即可

**强烈建议使用Visual Studio运行该项目，因为安装Boost库依赖于VSC++运行环境，若采用Visual Studio Code等其他IDE自行导入Boost库可能会出现找不到链接库的报错**


## PythonProject （动态类型）

采用Pickle库进行序列化与反序列化的操作，本项目的运行环境为Python3.9，无额外安装库

运行main.py即可得到测试结果。


## TroubleShooting：

开发问题主要集中在C++Project项目中

1.  **error: request for member 'serialize' in 't', which is of non-class type 'int'：**
    原先采用的是使用int**这种指针方式定义Grid成员，但后来发现在序列化过程中，Boost库并不支持对指针对象的序列化，会产生如上报错，因此最终替换为使用vector动态数组进行grid成员的定义

2. **undefined reference to `boost::archive::archive_exception::~archive_exception()'**
    C++项目原先采用VSCode进行开发，通过将Boost库置于mingw32文件夹下进行编译，但在实际过程中发现进行序列化时Boost库会出现链接问题，当前通过网络搜索修改tasks.json均无解决。目前通过在Visual Studio下重新建立项目并引入Boost库开发解决。