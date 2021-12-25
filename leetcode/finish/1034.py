class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        eq=[(row,col)]#edgeQueue
        dic={}
        dic[(row,col)]=0
        rq=[]
        m=len(grid)-1
        n=len(grid[0])-1
        while len(eq)!=0:
            head=eq.pop(0)
            if head[0]==0 :
                if head[1]==0:
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))
                           dic[(head[0],head[1]+1)]=0
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))   
                           dic[(head[0]+1,head[1])]=0
                    rq.append(head)
                elif head[1]==n:
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))
                           dic[(head[0],head[1]-1)]=0
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))  
                           dic[(head[0]+1,head[1])]=0 
                    rq.append(head)
                else:
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))
                           dic[(head[0],head[1]-1)]=0
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))
                           dic[(head[0],head[1]+1)]=0
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))  
                           dic[(head[0]+1,head[1])]=0 
                    rq.append(head)
            elif head[0]==m:
                if head[1]==0:
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))
                           dic[(head[0],head[1]+1)]=0
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1]))   
                           dic[(head[0]-1,head[1])]=0
                    rq.append(head)
                elif head[1]==n:
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))
                           dic[(head[0],head[1]-1)]=0
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1])) 
                           dic[(head[0]-1,head[1])]=0  
                    rq.append(head)
                else:
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))
                           dic[(head[0],head[1]-1)]=0
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))
                           dic[(head[0],head[1]+1)]=0
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1]))   
                           dic[(head[0]-1,head[1])]=0
                    rq.append(head)
            else:
                if head[1]==0:
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1]))
                           dic[(head[0]-1,head[1])]=0
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))
                           dic[(head[0]+1,head[1])]=0
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))
                           dic[(head[0],head[1]+1)]=0   
                    rq.append(head)
                elif head[1]==n:
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1]))
                           dic[(head[0]-1,head[1])]=0
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))
                           dic[(head[0]+1,head[1])]=0
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))   
                           dic[(head[0],head[1]-1)]=0
                    rq.append(head)
                else:
                    flag=False
                    if grid[head[0]-1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]-1,head[1]) in dic:
                           eq.append((head[0]-1,head[1]))
                           dic[(head[0]-1,head[1])]=0
                    else:
                        flag=True
                    if grid[head[0]+1][head[1]]==grid[head[0]][head[1]]:
                        if not (head[0]+1,head[1]) in dic:
                           eq.append((head[0]+1,head[1]))
                           dic[(head[0]+1,head[1])]=0
                    else:
                        flag=True
                    if grid[head[0]][head[1]-1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]-1) in dic:
                           eq.append((head[0],head[1]-1))   
                           dic[(head[0],head[1]-1)]=0
                    else:
                        flag=True
                    if grid[head[0]][head[1]+1]==grid[head[0]][head[1]]:
                        if not (head[0],head[1]+1) in dic:
                           eq.append((head[0],head[1]+1))   
                           dic[(head[0],head[1]+1)]=0
                    else:
                        flag=True
                    if flag:
                        rq.append(head)
        for coord in rq:
            grid[coord[0]][coord[1]]=color
        return grid 