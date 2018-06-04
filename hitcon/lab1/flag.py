key =  "where_is_the_red_bao??"
flag = "shixiongfeichangshuaia"

cipher = []
for i in range(len(key)):
    for j in range(1, 128):
        if (ord(flag[i]) + j + i) % 128 == ord(key[i]):
            print i, j
            cipher.append(j)
            break

print cipher