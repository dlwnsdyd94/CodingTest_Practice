class left_hand(object):
    def __init__(self, y, x):
        self.y = y
        self.x = x


class right_hand(object):
    def __init__(self, y, x):
        self.y = y
        self.x = x


def solution(numbers, hand):
    answer = ''

    lh = left_hand(3, 0)
    rh = right_hand(3, 2)

    for n in numbers:
        if n == 1:
            answer += 'L'
            lh.y = 0
            lh.x = 0
        elif n == 4:
            answer += 'L'
            lh.y = 1
            lh.x = 0
        elif n == 7:
            answer += 'L'
            lh.y = 2
            lh.x = 0

        elif n == 3:
            answer += 'R'
            rh.y = 0
            rh.x = 2
        elif n == 6:
            answer += 'R'
            rh.y = 1
            rh.x = 2
        elif n == 9:
            answer += 'R'
            rh.y = 2
            rh.x = 2

        else:
            if n == 2:
                y = 0
                x = 1
            elif n == 5:
                y = 1
                x = 1
            elif n == 8:
                y = 2
                x = 1
            elif n == 0:
                y = 3
                x = 1
            if hand == "right":
                right_result = abs(y - rh.y) + abs(x - rh.x)
                left_result = abs(y - lh.y) + abs(x - lh.x)
                if right_result <= left_result:
                    answer += 'R'
                    rh.y = y
                    rh.x = x
                elif right_result > left_result:
                    answer += 'L'
                    lh.y = y
                    lh.x = x
            else:
                right_result = abs(y - rh.y) + abs(x - rh.x)
                left_result = abs(y - lh.y) + abs(x - lh.x)
                if right_result < left_result:
                    answer += 'R'
                    rh.y = y
                    rh.x = x
                elif right_result >= left_result:
                    answer += 'L'
                    lh.y = y
                    lh.x = x

    return answer

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
hand = "right"
print(solution(numbers, hand))