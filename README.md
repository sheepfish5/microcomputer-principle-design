# 微机原理课程设计

## 连线

### 12864液晶

A1区(液晶屏) - A3区(系统总线)
CS    -    CS2  使得12864的地址空间为0260H~026FH
RW    -    A0   1为读，0为写
RS    -    A1   1为读写数据，0为写指令
CS1/2  -   A2  1为控制左半屏，0为控制右半屏

对应的地址已在头文件中配置好宏了

### 8255可编程并行接口

只使用方式0，PB为输出，PC0为输入，PA和PC高四位用不上，初始化为输出。

初始化字为0x81

PC0 <- KL1
PB  -> 列信号A1~A8

D3区(8255)  -  A3区(系统总线)
CS    -    CS1   使得8255地址空间为0270H~027FH
A0    -    A0
A1    -    A1

D3区(8255)  -  F5区(4x4按键)
JP24-1(PC0)  -  JP31-1(KL1)
JP20(PB0~7)  -  JP37(列信号A0~A7)

对应地址值已在头文件中配置好宏了，注意PC地址就是行信号地址，PB地址就是列信号地址

### 4x4按键

只需要和8255连接，不需要连系统总线。

------

## 设计

默认公交车路线：
(Deprecated)
神戸大橋->港口岛北公园->風見鶏の館->鱼鳞之家->山麓線&北野通り->Hotel Monterey Kobe->織田家長屋門->兵庫県立弓道場

0火车站->1文海酒店->2张家坊->3赣江大桥->4岭上村->5天际光电->6中国石化->7仁安医院

单独写好打印每个站出站和进站信息的函数。

按键：
0-上/下行
1-进一站
2-出站
4-广告
5-退一站
6-进站

初始：显示“欢迎使用报站器”

设置全局状态：station = 0~7，对应8个站

不停查询按键，当查询到有按键按下时，检测是哪个按键按下。

如果是"2"，表示出站，根据station调用对应显示出站信息的函数

如果是"6"，表示进站，根据station调用对应显示进站信息的函数，同时station++, station &= 0x7。当过完最后一站时会从第一站重新开始。

## 限制

程序假设一次只能按下一个按键
