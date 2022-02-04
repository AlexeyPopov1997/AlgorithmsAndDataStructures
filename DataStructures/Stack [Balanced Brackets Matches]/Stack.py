def is_balanced_brackets(input_string):
    stack = []
    brackets = {')': '(', ']': '[', '}': '{'}
    stack_top_index = 0

    for index, char in enumerate(input_string, 1):
        if char in brackets.values():
            stack.append(char)
            if stack_top_index == 0:
                stack_top_index = index

        elif char in brackets:
            if not stack or brackets[char] != stack.pop():
                return index

            if not stack:
                stack_top_index = 0

    return stack_top_index if stack else "Success"


def main():
    input_string = input()
    print(is_balanced_brackets(input_string))


if __name__ == '__main__':
    main()