import re

# Task 1: Reverse a List In-Place
def reverse_list_in_place(lst):
    left, right = 0, len(lst) - 1
    while left < right:
        lst[left], lst[right] = lst[right], lst[left]
        left += 1
        right -= 1

# Task 2: Count Characters, Alphabets, Digits, Special Symbols, and Words
text = input("Enter text: ")
total_characters = len(text)
total_alphabets = sum(c.isalpha() for c in text)
total_digits = sum(c.isdigit() for c in text)
total_special_symbols = total_characters - total_alphabets - total_digits
total_words = len(text.split())

print("Total characters:", total_characters)
print("Total alphabets:", total_alphabets)
print("Total digits:", total_digits)
print("Total special symbols:", total_special_symbols)
print("Total words:", total_words)

# Task 3: Replace Blanks with Hyphens
def replace_blanks_with_hyphens(sentence):
    modified_sentence = sentence.replace(" ", "-")
    return modified_sentence

input_sentence = input("Enter a sentence: ")
modified_sentence = replace_blanks_with_hyphens(input_sentence)
print("Modified sentence:", modified_sentence)

# Task 4: Delete a Character from a String
def deleteChar(string, char):
    new_string = string.replace(char, "")
    return new_string

input_string = input("Enter a string: ")
character_to_delete = input("Enter the character to delete: ")
new_string = deleteChar(input_string, character_to_delete)
print("New string:", new_string)

# Task 5: Title Case Conversion
def title_case(string):
    return string.title()

input_string = input("Enter a string: ")
title_case_string = title_case(input_string)
print("Title case string:", title_case_string)

# Task 6: Friends Information in a Dictionary
friends_dict = {}

def validate_mobile_number(mobile_number):
    pattern = re.compile(r'^\d{10}$')
    return bool(pattern.match(mobile_number))

while True:
    print("--------------------------------------")
    print("1. Display friends' information")
    print("2. Add a new friend")
    print("3. Delete a friend")
    print("4. Modify a friend's phone number")
    print("5. Check if a friend is present")
    print("6. Quit")
    print("--------------------------------------")
    
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        for name, phone in friends_dict.items():
            print(f"Name: {name}, Phone: {phone}")
    
    elif choice == 2:
        name = input("Enter friend's name: ")
        phone = input("Enter friend's phone number: ")
        if validate_mobile_number(phone):
            friends_dict[name] = phone
            print(f"{name} added to the dictionary.")
        else:
            print("Invalid mobile number.")
    
    elif choice == 3:
        name = input("Enter friend's name to delete: ")
        if name in friends_dict:
            del friends_dict[name]
            print(f"{name} deleted from the dictionary.")
        else:
            print(f"{name} not found in the dictionary.")
    
    elif choice == 4:
        name = input("Enter friend's name to modify: ")
        if name in friends_dict:
            new_phone = input("Enter new phone number: ")
            if validate_mobile_number(new_phone):
                friends_dict[name] = new_phone
                print(f"{name}'s phone number updated.")
            else:
                print("Invalid new phone number.")
        else:
            print(f"{name} not found in the dictionary.")
    
    elif choice == 5:
        name = input("Enter friend's name to check: ")
        if name in friends_dict:
            print(f"{name} is present in the dictionary.")
        else:
            print(f"{name} is not present in the dictionary.")
    
    elif choice == 6:
        break
    
    else:
        print("Invalid choice. Please enter a valid option.")
