import sys
import heapq
import os

# create a dictionary of each character and frequency, then return a min heap
def file_character_frequencies(file_name):
    my_dictionary = {}
    with open(file_name) as f:
        filesize = os.path.getsize(file_name)
        if filesize == 0:
            print("The file is empty. No encoding to take place.")
            exit(1)
        for line in f:
            for character in line:
                if character not in my_dictionary:
                    my_dictionary[character] = 1
                else:
                    my_dictionary[character] += 1
    my_heap = []
    for x in my_dictionary:
        heapq.heappush(my_heap, PriorityTuple((my_dictionary[x], x)))
    return my_heap


class PriorityTuple(tuple):
    """A specialization of tuple that compares only its first item when sorting.
    Create one using double parens e.g. PriorityTuple((x, (y, z))) """
    def __lt__(self, other):
        return self[0] < other[0]

    def __le__(self, other):
        return self[0] <= other[0]

    def __gt__(self, other):
        return self[0] > other[0]

    def __ge__(self, other):
        return self[0] >= other[0]

    def __eq__(self, other):
        return self[0] == other[0]

    def __ne__(self, other):
        x = self.__eq__(other)
        return not x


# create the desired huffman code
def huffman_codes_from_frequencies(frequencies):
    huffman_tree = frequencies
    length_of_heap = len(frequencies)
    codes = {}
    code = ""
    if length_of_heap == 1:
        codes[frequencies[0][1]] = "1"
        return codes
    for i in range(1,length_of_heap):
        left_value = heapq.heappop(huffman_tree)
        right_value = heapq.heappop(huffman_tree)
        new_tree = PriorityTuple((left_value[0] + right_value[0], left_value[1] +", " +  right_value[1], left_value, right_value))
        heapq.heappush(huffman_tree, new_tree)
    mega_node = heapq.heappop(huffman_tree)
    get_codes(mega_node, code, codes)
    return codes

def get_codes(curr, code, codes):
    if len(curr) == 4:
        get_codes(curr[2], code + "0", codes)
        get_codes(curr[3], code + "1", codes)
    else:
        codes[curr[1]] = code
        return

def huffman_letter_codes_from_file_contents(file_name):
    """WE WILL GRADE BASED ON THIS FUNCTION."""
    # Suggested strategy...
    freqs = file_character_frequencies(file_name)
    return huffman_codes_from_frequencies(freqs)

def encode_file_using_codes(file_name, letter_codes):
    """Provided to help you play with your code."""
    contents = ""
    with open(file_name) as f:
        contents = f.read()
    file_name_encoded = file_name + "_encoded"
    with open(file_name_encoded, 'w') as fout:
        for c in contents:
            fout.write(letter_codes[c])
    print("Wrote encoded text to {}".format(file_name_encoded))


def decode_file_using_codes(file_name_encoded, letter_codes):
    """Provided to help you play with your code."""
    contents = ""
    with open(file_name_encoded) as f:
        contents = f.read()
    file_name_encoded_decoded = file_name_encoded + "_decoded"
    codes_to_letters = {v: k for k, v in letter_codes.items()}
    with open(file_name_encoded_decoded, 'w') as fout:
        num_decoded_chars = 0
        partial_code = ""
        while num_decoded_chars < len(contents):
            partial_code += contents[num_decoded_chars]
            num_decoded_chars += 1
            letter = codes_to_letters.get(partial_code)
            if letter:
                fout.write(letter)
                partial_code = ""
    print("Wrote decoded text to {}".format(file_name_encoded_decoded))


def main():
    """Provided to help you play with your code."""
    import pprint
    frequencies = file_character_frequencies(sys.argv[1])
#    pprint.pprint(frequencies)
    codes = huffman_codes_from_frequencies(frequencies)
#    pprint.pprint(codes)
    encode_file_using_codes(sys.argv[1], codes)
    decode_file_using_codes(sys.argv[1] + "_encoded", codes)


if __name__ == '__main__':
    """We are NOT grading you based on main, this is for you to play with."""
    main()
