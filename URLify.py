def URLify(string_input, trueLenght):
    count_space = 0
    for c in string_input:
        if c == ' ':
            count_space =+ 1
    index = trueLenght + count_space * 2
    if trueLenght < len(string_input):
        string_input = string_input + '\0'
    # for c in range(len())     
    print(len(string_input))
URLify("Mr John Smith     ", 13)