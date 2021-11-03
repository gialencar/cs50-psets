from cs50 import get_float


while True:
    owed = get_float("Change owed: ")
    if owed > 0:
        break

owed = int(owed*100)

coins = 0
for i in [25, 10, 5, 1]:
    while owed >= i:
        owed -= i
        coins += 1

print(coins)