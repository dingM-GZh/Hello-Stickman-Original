import copy
from pyfiglet import Figlet
import subprocess
import random


def remap_alphabet(alphabet_map, modified_list):

    for index, key in enumerate(list(alphabet_map.keys())):
        alphabet_map[key] = modified_list[index]

    return alphabet_map

def modify_and_remap(letter, alphabet_map, rotation_map):
    the_returned_letter = alphabet_map[letter]
    alpha_list = list(alphabet_map.keys())
    string = ""
    modifable_list = copy.deepcopy(alpha_list)
    remove_list = []
    for i in range(rotation_map[letter]):
        string += alpha_list[i]
        remove_list.append(alpha_list[i])

    for i in remove_list:
        modifable_list.remove(i)
        
    modifable_list = "".join(modifable_list) + string
    modifable_list = [char for char in modifable_list]


    alphabet_map = remap_alphabet(alphabet_map, modifable_list)
    

    return alphabet_map, the_returned_letter

def reset_alphabet_map(alphabet_map):
    for key in alphabet_map.keys():
        alphabet_map[key] = key

    return alphabet_map

def game_loop(rotation_map, alphabet_map):

    figlet = Figlet(font="big")
    input_list = ["1","2","3"]
    user_input = input("Please pick which difficulty you would like to play!\n"\
          "1. Easy\n2. Hard\nPlease Enter Here: ")

    if user_input not in input_list:
        print("{} is not an option please try again.\n".format(user_input))

    if user_input == "1":
        print(figlet.renderText("WELCOME TO HANGMAN CIPHER!"))
        subprocess.call("./a.out", shell=True)
        print(figlet.renderText("Congratulations! You Won!"))

    elif user_input == "2":
        
        print(figlet.renderText("WELCOME TO DYNAMIC CIPHER!"))
        print()
        print("\n\nThe goal of this game is to print hello world. Every time you enter a letter the alphabet will change.\n"\
            "If you type in a, don't expect that \'a\' will mean the character \'a\' next time around it could be \'b\'.\n"\
            "Also don't worry about spaces.  You WIN if you can spell 'helloworld'.")

        history = ""
        hello_world_list = [x for x in "helloworld"]
        player_string = ""
        best_score = len(hello_world_list)
        while player_string != "helloworld":
            print("\nWhat you have built so far with your sequence is: {}".format(player_string))
            print("The sequence that is making helloworld so far is: {}\n".format(history))
            letter = input("\nPlease enter a letter: ")
            if not letter.isalpha():
                print("{} is not a letter".format(letter))
                continue
            
            if len(letter) > 1:
                letter = letter[0]

            letter = letter.lower()
            history += letter

            alphabet_map, player_mapped_letter = modify_and_remap(letter, alphabet_map, rotation_map)
            player_string += player_mapped_letter
            

            for index, char in enumerate(player_string):
                if char != hello_world_list[index]:
                    player_string = player_string[:-1]
                    if len(player_string) > 0:
                        alphabet_map, _ = modify_and_remap(letter, alphabet_map, rotation_map)
                    else:
                        alphabet_map = reset_alphabet_map(alphabet_map)

                    
                    
            print(alphabet_map)   
        
        print(figlet.renderText("Congratulations!"))
        print("Congratulations you have completed the game!!!!!!")
        print("The best score you can get is {}".format(best_score))
        print("Your score is {}".format(len(history)))
        print("Your sequence is {}".format(history))
        


# setup
aplhabet = "abcdefghijklmnopqrstuvwxyz"

alpha_list = [char for char in aplhabet]

rotation_map = {}
alphabet_map = {}

for index, char in enumerate(aplhabet):
    rotation_map[char] = index + 1
    alphabet_map[char] = char


game_loop(rotation_map, alphabet_map)

