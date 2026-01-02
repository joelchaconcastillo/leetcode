class Solution:
    def countTime(self, time: str) -> int:
        res = 0
        for hours in range(0, 24):
            for minutes in range(0, 60):
                str_hours = str(hours)
                if hours < 10:
                    str_hours = "0"+str_hours
                str_min = str(minutes)
                if minutes < 10:
                    str_min = "0"+str(minutes)
                try_time = str_hours+":"+str_min
                same = True
                for i in range(len(time)):
                    if time[i] == '?':
                        continue;
                    if time[i] != try_time[i]:
                        same = False
                res += same
        return res

