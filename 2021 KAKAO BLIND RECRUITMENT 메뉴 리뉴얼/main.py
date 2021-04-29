# global
#  - visited
#  - orders_map

result = ""

def dfs(c, o, cur, count):
    global result

    if c == count:
        if result in orders_dict:
            orders_dict[result] += 1
        else:
            orders_dict[result] = 1
        return

    size = len(o)
    for i in range(cur, size):
        if visited[i] == 0:
            visited[i] = 1
            result += o[i]
            dfs(c, o, i + 1, count + 1)
            visited[i] = 0
            result = result[:-1]

def solution(orders, course):
    global visited
    global orders_dict
    answer = []

    temp_orders = []
    for o in orders:
        temp_orders.append("".join(sorted(list(o))))

    orders = temp_orders

    for c in course:
        orders_dict = dict()
        for o in orders:
            visited = [0]*len(o)
            dfs(c, o, 0, 0)
        max_dict = max(orders_dict.values(), default=0)
        if max_dict > 1:
            for key in orders_dict:
                if orders_dict[key] == max_dict:
                    answer.append(key)
        #print(orders_dict)

    answer = sorted(answer)

    return answer


orders = ["XYZ", "XWY", "WXA"]
course = [2,3,4]
print(solution(orders, course))