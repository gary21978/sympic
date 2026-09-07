# 1.  安装 1.1.19-1 版本虚拟环境(1.17也可用)

下载地址
http://192.10.86.29:8082/artifactory/release/driver/v1.1.19/1/ubuntu_22.04/cmodel_kmd/maps-driver-v1.1.19-1-ubuntu_22.04-cmodel_kmd.tar.gz  
**也可以使用data/share/driver的work-1.17.tar.gz**

这一步可以通过已安装的qemu进入文件夹（首先主要解压pciemu,能创建qemu虚拟机，进入qemu虚拟机后再用./mapkg install -p all来解压安装软件）  

cd /home/emu/   
chmod +x mapkg  
./mapkg install -p all  
cd driver  
./mapkg install -p all  
**如果是work-1.17.tar.gz则只需要解压即可使用。**

# 2. 安装mpicc

在每个emu环境内：  
vim /etc/apt/sources.list  
修改qemu中安装源文件/etc/apt/sources.list

deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy main restricted  
deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy-updates main restricted  
deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy universe  
deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy-updates universe  
deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy multiverse  
deb [arch=amd64] http://192.10.84.233/ubuntu/ jammy-updates multiverse  

然后apt update  
然后 apt install openmpi-bin openmpi-common libopenmpi-dev  

# 3. 拿取代码，当前版本0529

文件名picus_mapu_20260529.zip  
通过data/share/users/xinghaoyun/内部copy到自己driver目录下自行重命名  

# 4. 编译代码

编译mpu代码需要进入模拟器环境
bash build.sh mapu  

编译cuda代码不能进入模拟器环境
bash build.sh cuda



# 5. 运行算例cuda/mapu

脚本run.sh使用方法
bash ./run.sh (算例名称)
bash ./run.sh case/demo-8
bash ./run.sh case/demo-64

使用run.sh运行脚本的时候在build/test/目录中会生成结果目录test_npy/,
如果case中缺少对应的参考结果，可将cuda模式下生成的结果目录test_npy/，改名为result_npy,放到对应的case目录下面


如果case目录下面已经有了结果result_npy，可使用脚本./compare.sh，它会先调用run.sh跑出结果test_npy，然后与result_npy做数值对比，输出比对结果
bash ./compare.sh (算例名称)
bash ./compare.sh case/demo-8
bash ./compare.sh case/demo-64


