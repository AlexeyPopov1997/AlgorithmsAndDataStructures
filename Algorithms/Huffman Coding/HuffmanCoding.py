import heapq
from collections import Counter, namedtuple


class Node(namedtuple("Node", ["left", "right"])):
    def walk(self, code, acc):
        self.left.walk(code, acc + "0")
        self.right.walk(code, acc + "1")


class Leaf(namedtuple("Leaf", ["symbol"])):
    def walk(self, code, acc):
        code[self.symbol] = acc or "0"
        

def encode(input_code):
    huffman_encoding = []
    for symbol, frequency in Counter(input_code).items():
        huffman_encoding.append((frequency, len(huffman_encoding), Leaf(symbol)))

    heapq.heapify(huffman_encoding)
    
    count = len(huffman_encoding)
    while len(huffman_encoding) > 1:
        frequency_1, _, left = heapq.heappop(huffman_encoding)
        frequency_2, _, right = heapq.heappop(huffman_encoding)
        heapq.heappush(huffman_encoding, (frequency_1 + frequency_2, count, Node(left, right)))
        count += 1
    
    output_code = {}
    if huffman_encoding:
        [(frequency, count, root)] = huffman_encoding
        root.walk(output_code, "")

    return output_code


def decode(input_code, huffman_decoding):
    output_code = ""
    while len(input_code) > 0:
        acc = 0
        current_code = ''
        while acc < len(input_code):
            current_char = input_code[acc]
            current_code += current_char
            if current_code in huffman_decoding.values():
                new_decoding = dict(zip(huffman_decoding.values(), huffman_decoding.keys()))
                current_code = new_decoding[current_code]
                acc += 1
                break
            acc += 1
        input_code = input_code[acc:]
        output_code += current_code
    return output_code


def main():
    MODE = "ENCODING" # "ENCODING" or "DECODING"
    
    if (MODE == "ENCODING"):
        input_code = input()
        output_code = encode(input_code)
        encoded_code = "".join(output_code[symbol] for symbol in input_code)
        print(len(output_code), len(encoded_code))
        for symbol in sorted(output_code):
            print("{}: {}".format(symbol, output_code[symbol]))
        print(encoded_code)
    else:
        letters_num, line_len = map(int, input().split())
        assert line_len > 0
        huffman_decoding = {}
        for _ in range(letters_num):
            line = input()
            if (line):
                letter, code = line.split(": ")
                huffman_decoding[letter] = code
            
        input_code = input()
        print(decode(input_code, huffman_decoding))


if __name__ == '__main__':
    main()