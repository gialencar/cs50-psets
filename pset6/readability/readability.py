from cs50 import get_string


def main():
    # ask user for a text
    text = get_string("Text: ").lower()

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    L = letters / words * 100
    S = sentences / words * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index >= 16:
        print("Grade 16+")

    elif index < 1:
        print("Before Grade 1")

    else:
        print(f"Grade {round(index)}")


def count_letters(string):
    count = 0

    # count only the letters in the string
    for i in string:
        if i.isalpha():
            count += 1
    return count


def count_words(string):
    # split the string using a white space as separator, and count the items in the returned list
    return len(string.split(' '))


def count_sentences(string):
    # consider senteces as any sequence of characters ended with a ".", "1", or "?"
    count = 0
    for i in string:
        if i in ['.', '!', '?']:
            count += 1

    return count


main()
