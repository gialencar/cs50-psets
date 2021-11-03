from cs50 import get_int


def main():
    height = get_height()

    for line in range(1, height + 1):
        # first piramid
        print(' ' * (height - line), end='')
        print('#' * line, end='')

        # spacing
        print('  ', end='')

        # second piramid
        print('#' * line)


def get_height():
    # gets an integer between 1 and 8, inclusive
    while True:
        h = get_int("Height: ")
        if h in range(1, 9):
            break
    return h


main()
