def solution(n):
    answer = 0

    remainder = []
    share = n
    while share >= 3:
        remainder.append(share % 3)
        share = share // 3
    remainder.append(share % 3)

    size = len(remainder)
    for i in remainder:
        answer += pow(3, size - 1) * i
        size -= 1

    return answer

n = 125
print(solution(n))