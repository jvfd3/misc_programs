"""
14. Maior prefixo comum - Escreva uma função para encontrar a string de prefixo comum mais longa entre uma matriz de strings. Se não houver um prefixo comum, retorne uma string vazia "".
Example 1:
Input: srts = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: srts = ["dog", "racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
"""

def get_examples():
    """ Returns the list of words to be testes """
    examples = [["flower","flow","flight"], ["dog", "racecar","car"]]
    return examples

def reduce_list(word_list, min_len):
    """ Reduces the length of the words of the list by a certain amount """
    new_list = []
    for elem in word_list:
        new_list.append(elem[:min_len])
    return new_list

def get_max_sufix(word_list):
    """ Returns the max prefix from the word list """
    min_len = len(min(word_list, key=len))
    reduced_list = reduce_list(word_list, min_len)
    while len(set(reduced_list)) > 1:
        reduced_list = reduce_list(reduced_list, -1)
    return reduced_list[0]


def unit_testing(examples):
    """ Tests each example for its expected output """
    assert get_max_sufix(examples[0]) == "fl", "Should be 'fl'"
    assert get_max_sufix(examples[1]) == "", "Should be ''"
    print('Everything is fine')

def main():
    """ Gets the examples and tests it """
    examples = get_examples()
    unit_testing(examples)

main()
