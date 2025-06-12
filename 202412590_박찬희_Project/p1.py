# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    # 평균 계산
    mean = sum(input) // len(input)
    
    # 중앙값 계산
    sorted_input = sorted(input)
    median = sorted_input[len(input) // 2]
    
    # 결과 리스트 구성
    result = [0, 0]
    result[0] = mean
    result[1] = median
    return result

result = problem1(input)

assert result == [34, 30]
print("정답입니다.")
