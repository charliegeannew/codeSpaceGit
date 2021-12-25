class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        if k==1:
            return [arr[0],arr[-1]]
        else:
            res=[0,0]
            index=[len(arr)-1 for i in range(len(arr)-1)]
            arrin=[]
            for i in range(len(arr)-1):
                arrin.append(arr[i]/arr[-1])
            while k>0:
                minind=arrin.index(min(arrin))
                res=[arr[minind],arr[index[minind]]]
                k-=1
                index[minind]-=1
                if index[minind]==minind:
                    arrin[minind]=1
                else:
                    arrin[minind]=arr[minind]/arr[index[minind]]
            return res 