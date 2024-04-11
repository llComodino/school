def reduceNum(num: str, k: int) -> str:

    stack = ''

    if k > len(num):
        print("Cannot remove more digit than the number has got")

    elif k == len(num):
        stack = '0'

    else:
        if num[k] == '0':
            while k < len(num) - 1:
                stack += num[k + 1]
                k += 1

        else:
            for d in num:
                while len(stack) >= 1 and stack[-1] > d and k > 0:
                    stack = stack[:-1]
                    k -= 1
                stack += d

            while k > 0:
                stack[-1] = ''
                k -= 1

            stack = "".join(stack).lstrip("0")

    return stack


print(reduceNum("1432219", 3))
print(reduceNum("20900", 1))
print(reduceNum("720309", 2))
print(reduceNum("10", 2))
