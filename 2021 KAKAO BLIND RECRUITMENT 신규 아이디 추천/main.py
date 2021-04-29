def solution(new_id):
    answer = ''
    temp1 = ''
    temp2 = ''

    # 1단계
    for a in new_id:
        if a.isalpha():
            a = a.lower()
            temp1 += a
        else:
            temp1 += a

    # 2단계
    for a in temp1:
        if a.isalpha() or a.isdigit() or a == '-' or a == '_' or a == '.':
            temp2 += a

    temp1 = ''
    flag = False
    # 3단계
    for a in temp2:
        if a == '.' and flag == False:
            temp1 += a
            flag = True
        elif a == '.' and flag == True:
            continue
        else:
            temp1 += a
            flag = False

    # 4단계
    while len(temp1) > 0 and temp1[0] == '.':
        temp1 = temp1[1:]

    while len(temp1) > 0 and temp1[-1] == '.':
        temp1 = temp1[:-1]

    # 5단계
    if temp1 == '':
        temp1 = 'a'

    # 6단계
    if len(temp1) >= 16:
        temp1 = temp1[:15]

    while len(temp1) > 0 and temp1[-1] == '.':
        temp1 = temp1[:-1]

    # 7단계
    while len(temp1) <= 2:
        temp1 += temp1[-1]

    answer = temp1

    return answer