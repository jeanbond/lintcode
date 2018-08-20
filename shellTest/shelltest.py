import subprocess,os,datetime,copy



if __name__ == "__main__":
    #简单粗暴的直接使用subprocess来call相关的系统命令，比较容易实现，但是不是最优的做法；
    #python自带很多文件操作、字符串操作、网络操作等功能，同时有大量的运维和专用的包来解决此类的问题；
    #
    p = subprocess.Popen(args='dir', shell=True, stdout=subprocess.PIPE)
    p.wait() #get process result;

    #时间处理推荐使用datetime，而不是time和strtime等模块；
    eldestTime = datetime.datetime(year=1, month=1, day=1)
    dirs = os.listdir(os.getcwd())
    for i in dirs:
        if os.path.isfile(i):
            times = os.path.getatime(i)
            time = datetime.datetime.fromtimestamp(times)
            print(time)
            if time > eldestTime:
                eldestTime = copy.copy(time)
    print(eldestTime)