# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    #여기에서부터 코드를 작성하세요.

    from collections import deque

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def bfs(x, y, size):
        visited = [[-1]*N for _ in range(N)]
        visited[x][y] = 0
        q = deque()
        q.append((x, y))
        edible = []

        while q:
            cx, cy = q.popleft()
            for dir in range(4):
                nx = cx + dx[dir]
                ny = cy + dy[dir]
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[nx][ny] == -1 and forest[nx][ny] <= size:
                        visited[nx][ny] = visited[cx][cy] + 1
                        q.append((nx, ny))
                        if 0 < forest[nx][ny] < size:
                            edible.append((visited[nx][ny], nx, ny))
        edible.sort()
        return edible

    result = 0  # 초기화는 유지

    while True:
        edible_list = bfs(bear_x, bear_y, bear_size)
        if not edible_list:
            break
        dist, nx, ny = edible_list[0]
        time += dist
        honeycomb_count += 1
        forest[nx][ny] = 0
        bear_x, bear_y = nx, ny

        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time  # 결과에 time 할당
    return result

result = problem3(input)

assert result == 14
print("정답입니다.")
