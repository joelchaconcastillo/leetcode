class Solution:
    def compress(self, chars: List[str]) -> int:
        i,j,n = 0,0,len(chars)
        prev = chars[0]
        cont = 0
        while j < n:
            if chars[j] != prev:
                chars[i] = prev
                i+=1
                if cont > 1:
                    l = 0
                    str_cont = str(cont)
                    while l < len(str_cont):
                        chars[i] = str_cont[l]
                        i+=1
                        l+=1
                cont = 0
            prev = chars[j]
            j+=1
            cont+=1
        if cont:
            l = 0
            chars[i] = prev
            i+=1
            if cont > 1:
             str_cont = str(cont)
             while l < len(str_cont):
                 chars[i] = str_cont[l]
                 i+=1
                 l+=1
        return i

