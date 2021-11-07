def get_different_addends_number(input_number):
    assert input_number >= 1

    addends_number = 1
    addends_sum = 0
    addends = []

    while addends_sum <= input_number:
        if input_number <= 2:
            addends.append(input_number)
            return 1, addends
        
        if addends_sum + addends_number <= input_number:
            addends.append(addends_number)
            addends_sum += addends_number
            addends_number += 1
        else:
            addends_number -= 1

            while addends_sum <= input_number:
                if input_number == addends_sum:
                    return addends_number, addends

                removed_element = addends[-1]
                addends.pop()
                addends.append(removed_element + 1)
                addends_sum += 1

            return addends_number, addends


def main():
    input_number = int(input())
    addends = []
    addends_number, addends = get_different_addends_number(input_number)
    print(addends_number)

    for idx, _ in enumerate(addends):
        if idx < len(addends) - 1:
            print(addends[idx], end=' ')
        else:
            print(addends[idx])


if __name__ == '__main__':
    main()
