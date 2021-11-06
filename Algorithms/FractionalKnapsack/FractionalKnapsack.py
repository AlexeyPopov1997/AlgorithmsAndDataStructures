import heapq


def get_max_knapsack_value(capacity, items):
    profit_order = [(-value / weight, weight) for value, weight in items]
    heapq.heapify(profit_order)

    acc = 0
    while profit_order and capacity: 
        profit, weight = heapq.heappop(profit_order)
        can_take = min(weight, capacity)
        acc -= profit * can_take
        capacity -= can_take

    return acc


def main():
    items_number, capacity = map(int, input().split())
    items = []
    for _ in range(items_number):
        items.append(tuple(map(int, input().split())))

    assert len(items) == items_number
    opt_value = get_max_knapsack_value(capacity, items)
    print("{:.3f}".format(opt_value))

if __name__ == "__main__":
    main()
