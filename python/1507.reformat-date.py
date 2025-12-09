class Solution:
    def reformatDate(self, date: str) -> str:
        fields = date.split(' ')
        month = {
                "Jan": "01",
                "Feb":"02",
                "Mar":"03",
                "Apr":"04",
                "May":"05",
                "Jun":"06",
                "Jul":"07",
                "Aug":"08",
                "Sep":"09",
                "Oct":"10",
                "Nov":"11",
                "Dec":"12"
                }
        day_num = int(''.join(filter(str.isdigit, fields[0])))
        str_day = f"{day_num:02d}"
        return fields[2]+"-"+month[fields[1]]+"-"+str_day
