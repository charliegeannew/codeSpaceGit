##########################################################################
# File Name: 1882.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Fri 05 Nov 2021 04:05:18 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res=[]
        import queue
        busy=queue.PriorityQueue()
        easy=queue.PriorityQueue()
        for i in range(len(servers)):
            easy.put([servers[i],i])
        tim=0
        tind=0
        for task in tasks:
            tim=max(tind,tim)
            if busy.empty():
                eind=easy.get()
                tempList=[eind[1]]
                sm=0
                while not easy.empty():
                    temp=easy.get()
                    if temp[0]==eind[0]:
                        tempList.append(temp[1])
                        if tempList[sm]>tempList[-1]:
                            sm=len(tempList)-1
                    else:
                        easy.put(temp)
                        break
                eind[1]=tempList[sm]
                for ii in range(0,len(tempList)):
                    if ii!=sm:
                        easy.put([servers[tempList[ii]],tempList[ii]]) 

                res.append(eind[1])
                busy.put([tim+task,eind[1]])
                tim+=1
            else:
                while not busy.empty():
                    bind=busy.get()
                    if bind[0]>tim:
                        busy.put(bind)
                        break
                    else:
                        easy.put([servers[bind[1]],bind[1]])
                if not easy.empty():
                    eind=easy.get()
                    tempList=[eind[1]]
                    sm=0
                    while not easy.empty():
                        temp=easy.get()
                        if temp[0]==eind[0]:
                            tempList.append(temp[1])
                            if tempList[sm]>tempList[-1]:
                                sm=len(tempList)-1
                        else:
                            easy.put(temp)
                            break
                    eind[1]=tempList[sm]
                    for ii in range(len(tempList)):
                        if ii!=sm:
                            easy.put([servers[tempList[ii]],tempList[ii]]) 

                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
                    tim+=1
                else:
                    bind=busy.get()
                    tim=bind[0]
                    easy.put([servers[bind[1]],bind[1]])
                    while not busy.empty():
                        bind=busy.get()
                        if bind[0]>tim:
                            busy.put(bind)
                            break
                        else:
                            easy.put([servers[bind[1]],bind[1]])
                    eind=easy.get()
                    tempList=[eind[1]]
                    sm=0
                    while not easy.empty():
                        temp=easy.get()
                        if temp[0]==eind[0]:
                            tempList.append(temp[1])
                            if tempList[sm]>tempList[-1]:
                                sm=len(tempList)-1
                        else:
                            easy.put(temp)
                            break
                    eind[1]=tempList[sm]
                    for ii in range(len(tempList)):
                        if ii!=sm:
                            easy.put([servers[tempList[ii]],tempList[ii]]) 

                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
                    #tim+=1
            tind+=1
        return res
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res=[]
        import queue
        busy=queue.PriorityQueue()
        easy=queue.PriorityQueue()
        for i in range(len(servers)):
            easy.put([servers[i],i])
        tim=0
        for task in tasks:
            if busy.empty():
                eind=easy.get()
                while not easy.empty():
                    temp=easy.get()
                    if temp[0]==eind[0]:
                        if temp[1]<eind[1]:
                            fort=eind[1]
                            eind[1]=temp[1]
                            temp[1]=fort
                        easy.put(temp) 
                        break
                    else:
                        easy.put(temp) 
                        break
                res.append(eind[1])
                busy.put([tim+task,eind[1]])
                tim+=1
            else:
                while not busy.empty():
                    bind=busy.get()
                    if bind[0]>tim:
                        busy.put(bind)
                        break
                    else:
                        easy.put([servers[bind[1]],bind[1]])
                if not easy.empty():
                    eind=easy.get()
                    while not easy.empty():
                        temp=easy.get()
                        if temp[0]==eind[0]:
                            if temp[1]<eind[1]:
                                fort=eind[1]
                                eind[1]=temp[1]
                                temp[1]=fort
                            easy.put(temp)
                            break
                        else:
                            easy.put(temp) 
                            break 
                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
                    tim+=1
                else:
                    bind=busy.get()
                    tim=bind[0]
                    easy.put([servers[bind[1]],bind[1]])
                    while not busy.empty():
                        bind=busy.get()
                        if bind[0]>tim:
                            busy.put(bind)
                            break
                        else:
                            easy.put([servers[bind[1]],bind[1]])
                    eind=easy.get()
                    while not easy.empty():
                        temp=easy.get()
                        if temp[0]==eind[0]:
                            if temp[1]<eind[1]:
                                fort=eind[1]
                                eind[1]=temp[1]
                                temp[1]=fort
                            easy.put(temp) 
                            break
                        else:
                            easy.put(temp) 
                            break
                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
                    tim+=1
        return res
class Solution:
    def assignTasks(self, servers, tasks):
        res=[]
        tim=[0 for i in range(len(servers))]
        for task in tasks:
            for t in range(len(tim)):
                if tim[t]!=0:
                    tim[t]-=1
            tempIndex=-1
            sm=0
            for t in range(0,len(tim)):
                if tim[t]<tim[sm]:
                    sm=t 
                elif tim[t]==tim[sm]:
                    if servers[t]<servers[sm]:
                        sm=t 
                if tim[t]==0:
                    if tempIndex==-1:
                        tempIndex=t
                    else:
                        if servers[tempIndex]>servers[t]:
                            tempIndex=t
            print(sm,tempIndex)
            print(tim)
            if tempIndex==-1:
                tempA=tim[sm]
                for t in range(0,len(tim)):
                    tim[t]=tim[t]-(tempA-1)
                tim[sm]=task+1
                res.append(sm)
            else:
                tim[tempIndex]=task
                res.append(tempIndex)
        return res
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res=[]
        import queue
        busy=queue.PriorityQueue()
        easy=queue.PriorityQueue()
        for i in range(len(servers)):
            easy.put([servers[i],i])
        tim=0
        for task in tasks:
            if busy.empty():
                eind=easy.get()
                res.append(eind[1])
                busy.put([tim+task,eind[1]])
                tim+=1
            else:
                while not busy.empty():
                    bind=busy.get()
                    if bind[0]>tim:
                        busy.put(bind)
                        break
                    else:
                        easy.put([servers[bind[1]],bind[1]])
                if not easy.empty():
                    eind=easy.get()
                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
                    tim+=1
                else:
                    bind=busy.get()
                    tim=bind[0]
                    easy.put([servers[bind[1]],bind[1]])
                    while not busy.empty():
                        bind=busy.get()
                        if bind[0]>tim:
                            busy.put(bind)
                            break
                        else:
                            easy.put([servers[bind[1]],bind[1]])
                    eind=easy.get()
                    res.append(eind[1])
                    busy.put([tim+task,eind[1]])
        return res
def main():
    print("hello world")
    sol=Solution()
    # sev=[338,890,301,532,284,930,426,616,919,267,571,140,716,859,980,469,628,490,195,664,925,652,503,301,917,563,82,947,910,451,366,190,253,516,503,721,889,964,506,914,986,718,520,328,341,765,922,139,911,578,86,435,824,321,942,215,147,985,619,865]
    # tasks=[773,537,46,317,233,34,712,625,336,221,145,227,194,693,981,861,317,308,400,2,391,12,626,265,710,792,620,416,267,611,875,361,494,128,133,157,638,632,2,158,428,284,847,431,94,782,888,44,117,489,222,932,494,948,405,44,185,587,738,164,356,783,276,547,605,609,930,847,39,579,768,59,976,790,612,196,865,149,975,28,653,417,539,131,220,325,252,160,761,226,629,317,185,42,713,142,130,695,944,40,700,122,992,33,30,136,773,124,203,384,910,214,536,767,859,478,96,172,398,146,713,80,235,176,876,983,363,646,166,928,232,699,504,612,918,406,42,931,647,795,139,933,746,51,63,359,303,752,799,836,50,854,161,87,346,507,468,651,32,717,279,139,851,178,934,233,876,797,701,505,878,731,468,884,87,921,782,788,803,994,67,905,309,2,85,200,368,672,995,128,734,157,157,814,327,31,556,394,47,53,755,721,159,843]
    sev=[318,274,325,517,437,829,86,570,311,150,277,756,710,910,750,77,801,256,894,588,748,41,681,222,463,757,703,551,99,177,788,333,937,295,101,97,989,710,549,984,492,459,38,568,382,555,984,937,945,849,489,665,426,766,988,148,920,691,486,403,996,599,703,625,236,55,457,833,409,405,782,427,342,494,217,531,874,249,770,399,983,766,682,954,786,9,760,516,862,325,661,17,78,154,352,897,27,742,864,548,570,146,501,251,623,414,631,637,852,869,527,196,173,123,238,740,291,373,675,491,97,787,635,327,501,669,674,166,394,700,415,240,96,827,396,834,760,956,208,158,818,179,420,303,169,489,362,884,310,590,981,655,629,257,749,521,525,386,371,596,263,835,86,149,446,107,435,199,367,182,74,390,348,158,711,895,662,503,436,951,26,740,42,57,459,288,32,859,591,528,422,402,353,2,849,585,62,950,817,760,268,102]
    tasks=[224,724,777,12,261,105,48,816,272,228,779,332,312,802,463,239,907,673,752,587,271,615,152,871,714,109,640,999,830,212,670,486,110,909,720,389,638,445,898,639,945,918,524,776,286,791,344,659,636,963,550,480,119,33,906,36,981,648,257,435,603,97,375,705,325,177,928,506,378,976,326,109,800,195,514,453,699,730,492,644,720,5,887,87,736,693,426,288,797,69,454,870,38,270,571,834,351,799,39,466,145,531,463,276,590,463,958,335,706,840,619,975,597,68,766,338,148,244,315,11,881,782,79,855,246,585,1000,66,414,122,423,800,895,211,168,63,592,108,862,835,892,20,798,465,213,326,703,64,839,488,772,178,628,66,94,865,326,904,844,260,134,955,691,345,677,774,885,735,162,643,910,730,648,460,444,954,241,790,280,493,848,702,445,254,156,786,923,906,900,819,848,267,858,437,883,170,209,102,428,866,188,851,993,729,120,541,614,267,449,305,195,300,154,469,68,889,465,185,351,756,705,690,198,339,789,39,301,958,519,886,548,266,626,88,254,386,18,286,874,862,348,229,34,477,714,806,408,468,573,500,902,904,973,938,533,661,591,391,589,162,264,584,26,511,355,591,12,831,962,385,349,909,171,412,44,156,848,397,754,283,117,789,406,423,873,3,955,651,606,997,657,545,822,697,364,815,59,91,792,355,231,391,418,98,197,769,382,891,948,715,265,151,113,583,480,400,379,225,955,603,17,560,135,972,216,354,466,696,230,412,370,17,138,755,612,188,901,258,508,417,173,935,84,744,464,129,591,294,480,4,222,856,925,26,729,249,490,556,797,685,820,530,316,804,892,928,334,759,249,699,315,646,996,53,403,677,272,893,438,542,207,395,91,531,552,877,881,864,219,377,622,38,352,549,438,431,157,198,581,949,823,730,978,645,551,125,172,315,93,681,149,450,425,321,88,267,806,482,855,506,73,269,213,23,264,744,360,416,142,937,553,374,385,220,587,149,433,111,794,749,131,343,281,620,967,303,369,383,763,49,17,178,648,395,680,690,214,171,792,278,746,301,42,580,112,236,904,739,412,105,34,60,301,67,607,221,782,825,961,34,556,734,766,712,942,950,636,815,428,884,179,889,36,717,874,146,585,390,469,701,523,767,34,61,399,393,198,682,628,24,634,999,268,973,488,130,390,974,950,90,213,922,385,955,400,305,953,855,18,961,323,741,5,537,993,887,729,764,565,710,972,691,911,921,64,298,531,167,880,5,229,436,831,580,413,865,269,499,843,181,246,424,893,146,549,418,742,95,766,55,699,64,107,502,842,459,967,248,933,257,143,577,969,644,164,267,104,108,661,33,826,578,138,649,189,169,72,315,176,971,319,192,349,875,743,706,77,868,142,628,267,569,356,593,754,456,272,372,193,108,466,639,404,974,74,473,876,310,329,303,822,936,892,451,341,756,827,607,447,516,690,114,816,146,165,544,719,621,891,728,394,45,823,883,344,818,343,991,360,194,913,529,643,75,604,881,890,423,793,194,1000,745,32,740,141,348,101,579,597,590,371,320,632,17,501,776,503,769,984,964,951,148,514,669,120,41,33,470,356,800,580,817,479,389,246,964,576,459,48,746,913,238,871,144,30,720,215,991,775,354,287,83,557,462,202,59,227,389,318,277,530,692,859,691,706,947,384,410,550,481,407,217,658,301,12,462,13,975,864,466,508,314,707,968,566,73,252,669,361,143,165,325,501,277,310,766,146,420,798,675,822,933,444,165,719]
    sol.assignTasks(sev,tasks)

if __name__=="__main__":
    main()

