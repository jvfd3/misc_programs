
def clean_data_list(data):
    '''Removing useless info'''        
    spaces(10)
    # lines_to_remove = get_lines_to_remove()
    # lines_to_double_remove = get_lines_to_remove_twice()
    dirty = 1
    found_terminator = 0
    test_vector = [1,2,3,4,5,6,7,8,9,10]
    terminator = 6
    print (test_vector)
    tamanho = len(test_vector)
    i = 0
    while dirty:
        print(test_vector)
        if test_vector[i] == terminator:
            found_terminator = 1
            print('found terminator')
        if found_terminator and dirty:
            dirty = 0
            print('trying to erase')
            for j in range (len(test_vector)-1,i,-1):
                print('J',j)
                # print(test_vector)
                print('popped:', test_vector.pop(j))
                # print(test_vector)
                tamanho -=1
        i+=1
    print (test_vector)
