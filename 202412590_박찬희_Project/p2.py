# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    # 입력 힌트
    for char in input:
        print(char)

    result = 0  # 초기화

    stack = 0
    add_left = 0

    for c in input:
        if c == '(':
            stack += 1
        else:  # c == ')'
            if stack > 0:
                stack -= 1
            else:
                add_left += 1

    result = add_left + stack  # 최소 추가 개수

    return result

result = problem2(input)

assert result == 3
print("정답입니다.")
