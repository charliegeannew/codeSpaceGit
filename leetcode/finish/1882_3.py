##########################################################################
# File Name: 1882_3.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sat 06 Nov 2021 09:35:19 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res=[]
        import queue
        busy=queue.PriorityQueue()
        easy=queue.PriorityQueue()
        for i in range(len(servers)):
            easy.put([servers[i],i])
        tim=0
        taskPool=[]
        index=0
        while True:
            if index<len(tasks):
                taskPool.append(tasks[index])
            while not busy.empty():
                bind = busy.get()
                if bind[0]<=tim:
                    easy.put([servers[bind[1]],bind[1]])
                else:
                    busy.put(bind)
                    break
            flag=False
            while not easy.empty() and len(taskPool)>0:
                eind=easy.get()
                res.append(eind[1])
                busy.put([tim+taskPool[allFlag],eind[1]])
                taskPool.pop(0)
                flag=True
            if flag:
                tim+=1
            else:
                bind=busy.get()
                easy.put([servers[bind[1]],bind[1]])
                for i in range(1,bind[0]-tim):
                    if i+index<len(tasks):
                        taskPool.append(tasks[i+index])
                    else:
                        break
                index=bind[0]-tim+index
                tim=bind[0]
            if index>=len(tasks):
                if len(taskPool)==0:
                    break
            else:
                if flag:
                    index+=1

        return res
