info_dict = {}
visited = [0]*4

def dfs(for_dict_info, a, cur, count):
    global info_dict
    global visited

    if a == count:
        temp_info = []

        #put in info_dict
        for j in range(4):
            if visited[j] == 1:
                temp_info.append('-')
            else:
                temp_info.append(for_dict_info[j])

        temp_info = "".join(temp_info)

        if temp_info not in info_dict:
            info_dict[temp_info] = [int(for_dict_info[4])]
        else:
            info_dict[temp_info].append(int(for_dict_info[4]))
        return

    for i in range(cur, 4):
        if visited[i] == 0:
            visited[i] = 1
            dfs(for_dict_info, a, i + 1, count + 1)
            visited[i] = 0

def info_bisect(query_join, standard):
    info_size = len(info_dict[query_join])

    start = 0
    end = info_size - 1
    while start <= end:
        midIndex = (start + end) // 2
        if info_dict[query_join][midIndex] >= standard:
            end = midIndex - 1
        else:
            start = midIndex + 1

    return info_size - start

def solution(info, query):
    global info_dict

    answer = []

    for i in info:
        for_dict_info = i.split()

        for a in range(5):
            dfs(for_dict_info, a, 0, 0)

    for key in info_dict.keys():
        info_dict[key].sort()

    for q in query:
        query_split = q.split(' and ')
        temp_query_split = query_split[3].split(' ')
        query_split[3] = temp_query_split[0]
        query_join = "".join(query_split)

        if query_join in info_dict:
            answer.append(info_bisect(query_join, int(temp_query_split[1])))
        else:
            answer.append(0)

    return answer

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
print(solution(info, query))