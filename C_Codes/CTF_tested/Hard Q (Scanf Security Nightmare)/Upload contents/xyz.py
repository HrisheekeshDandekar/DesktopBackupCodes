def check_null_terminations(first_in_place,second_in_place):
    
    for i in range(len(input_string)):
        if termination == input_string[i]:
            if first_in_place == False:
                if i == position1_expected_at:
                    first_in_place = True
                else:
                    break
                
            elif first_in_place == True and second_in_place == False:
                if i == position2_expected_at:
                    second_in_place = True
                else:
                    break

    if (first_in_place == True and second_in_place == True):
        return True
    return False

def match_input_and_password():
    password_matched = True
    password_size = position2_expected_at - position1_expected_at
    first_buff_i = position1_expected_at - password_size + 1
    second_buff_i = position1_expected_at + 1

    for i in range(password_size):
       # print("First buff: ", input_string[first_buff_i])
       # print("Second counter: ", second_buff_i)
       # print("Second buff: ", input_string[second_buff_i])
        if input_string[first_buff_i] != input_string[second_buff_i]:
            password_matched = False
            break

        first_buff_i += 1
        second_buff_i += 1

    return password_matched


#Checking if '\x00' (Null terminations) are in place
termination = '\x00'
position1_expected_at = 30 #Null termination after 30 chars
position2_expected_at = 41 #More of same 10 chars before null termination
input_size_expected = 42
first_in_place = False
second_in_place = False

while True:
    input_string = input()
    
    first_in_place = False
    second_in_place = False
    
    if len(input_string) < input_size_expected:
        print("Incorrect Password")
    
    elif check_null_terminations(first_in_place,second_in_place) == False:
        print("Incorrent Password")
    elif match_input_and_password() == False:
        print("Incorrect Password")
    else:
        print("Correct Password")
        print("correct password")
        print("CORRECT PASSWORD\n")
        print("Flag -> VishwaCTF{Hack3rManfrom80s}")