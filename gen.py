#!/usr/bin/env python3

import random
from sys import argv

N: int = int(argv[1])
out_str: str = ""
for _ in range(0, N):
    num: int = random.randint(-50000, 50000)
    out_str += str(num) + ' '
print(out_str)
