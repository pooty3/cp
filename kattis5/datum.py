import datetime
from datetime import date
d,m = input().split()
print(datetime.date(2009, int(m), int(d)).strftime("%A"))
