def isUniqueChars(strg):
    if len(strg) > 128:
        return false
    char_set = [False]*128
    for c in strg:
        x = ord(c)
        if char_set[x] != True:
            char_set[x] = True
        else:
            print("it's not unique chars")
            return False

isUniqueChars("DarwinEsca")