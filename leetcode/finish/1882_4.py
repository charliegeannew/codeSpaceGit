##########################################################################
# File Name: 1882_4.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sat 06 Nov 2021 09:38:42 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        # 工作中的服务器，存储二元组 (t, idx)
        busy = list()
        
        # 空闲的服务器，存储二元组 (w, idx)
        idle = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(idle)
        
        ts = 0
        # 将优先队列 busy 中满足 t<=ts 依次取出并放入优先队列 idle
        def release():
            while busy and busy[0][0] <= ts:
                _, idx = heapq.heappop(busy)
                heapq.heappush(idle, (servers[idx], idx))
        
        ans = list()
        for i, task in enumerate(tasks):
            ts = max(ts, i)
            release()
            if not idle:
                ts = busy[0][0]
                release()
            
            _, idx = heapq.heappop(idle)
            ans.append(idx)
            heapq.heappush(busy, (ts + task, idx))
        
        return ans

# 作者：LeetCode-Solution
# 链接：https://leetcode-cn.com/problems/process-tasks-using-servers/solution/process-tasks-using-servers-by-leetcode-rot1m/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
