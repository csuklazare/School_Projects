from sys import argv, exit

# provided
#
# Read integers from the given filename.
#
# Return value: list of integers
def read_array(filename):
    try:
        with open(filename) as f:
            return [int(n) for n in f.read().split()]
    except:
        exit("Couldn’t read numbers from file \""+filename+"\"")


# implement
#
# Return the number of inversions in the given list, by doing a merge
# sort and counting the inversions.
#
# Return value: number of inversions
def count_inversions(in_list):
    if len(in_list) == 1:
        return 0
    first_half = in_list[:len(in_list)//2]
    second_half = in_list[len(in_list)//2:]
    x = count_inversions(first_half)
    y = count_inversions(second_half)
    z = merge_i(first_half, second_half, in_list)
    return x+y+z


# implement
#
# Merge the left & right lists into in_list.  in_list already contains
# values--replace those with the merged values.
#
# Return value: inversion count
def merge_i(l_list, r_list, in_list):
    count = 0
    in_list.clear()
    while ((len(l_list) > 0) and (len(r_list) > 0)):
        if (l_list[0] > r_list[0]):
            in_list.append(r_list.pop(0))
            count = count + len(l_list)
        else:
            in_list.append(l_list.pop(0))
    if (len(l_list) == 0):
        in_list.extend(r_list)
    elif (len(r_list) == 0):
        in_list.extend(l_list)
    return count


# provided
if __name__ == '__main__':
    if len(argv) != 2:
        exit("usage: python3 "+argv[0]+" datafile")
    in_list = read_array(argv[1])
    print(count_inversions(in_list))
