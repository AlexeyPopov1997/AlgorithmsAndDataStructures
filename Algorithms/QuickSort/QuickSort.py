def main():
    lines_count, poins_count = [int(input_line) for input_line in input().split()]

    lines = []
    for i in range(0, lines_count):
        left, right = [int(input_line) for input_line in input().split()]
        lines.append([left, -1])
        lines.append([right, 1])

    points = [int(input_line) for input_line in input().split()]
    for i in range(poins_count):
        lines.append([points[i], 0, i])

    lines.sort()
    result = [0] * poins_count
    current = 0

    for i in range(len(lines)):
        if lines[i][1] == 1:
            current += -1
        if lines[i][1] == -1:
            current -= -1
        if lines[i][1] == 0:
            result[lines[i][2]] = current

    print(*result)


if __name__ == '__main__':
    main()
