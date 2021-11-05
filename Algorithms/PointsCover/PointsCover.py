def get_covering_set(segments):
    points = []
    segments.sort(key=lambda value: value[1])

    for segment in segments:
        if ((not points) or (segment[0] > points[-1])):
            points.append(segment[1])

    return points


def main():
    segments_count = int(input())
    segments = []
    for _ in range(segments_count):
        first, second = input().split()
        segments.append((int(first), int(second)))
    
    points = get_covering_set(segments)
    print(len(points))

    for idx, _ in enumerate(points):
        if idx < len(points) - 1:
            print(points[idx], end=' ')
        else:
            print(points[idx])


if __name__ == '__main__':
    main()
