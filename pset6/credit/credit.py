from cs50 import get_string


def main():
    # ask user for a credit card number
    number = get_string("Number: ")

    # check for a valid number and print the corresponding brand
    if checksum(number):
        print(check_brand(number))

    else:
        print("INVALID")


def checksum(number):
    digits = ""

    # take every other digit, starting with the second to last, and append it to the digits string
    for n in number[-2::-2]:
        digits += str(int(n) * 2)

    # sum the digits
    digits_sum = 0
    for i in digits:
        digits_sum += int(i)

    # take the remaining digits in number and add it to the sum
    for i in number[-1::-2]:
        digits_sum += int(i)

    # if the last digit of the resulting sum is 0, return true, otherwise return false
    if str(digits_sum)[-1] == '0':
        return True

    return False


def check_brand(number):
    # compare the first digits in the card number to identify the brand
    if number[0] == '4':
        return "VISA"

    elif number[0:2] in ['34', '37']:
        return "AMEX"

    elif number[0:2] in ['51', '52', '53', '54', '55']:
        return "MASTERCARD"


main()