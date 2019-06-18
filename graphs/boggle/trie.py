# from collections import defaultdict
# from nltk.corpus import words
# from nltk.corpus import stopwords
# from nltk.tokenize import word_tokenize

#english_words = words.words()

# If you wan to remove stop words
# stop_words = set(stopwords.words('english'))
# english_words = [w for w in english_words if w not in stop_words]

# Initialize trie datastructure
trie_node = {'valid': False}


def gen_trie(word, node):
    """udpates the trie datastructure using the given word"""
    if not word:
        return

    if word[0] not in node:
        node[word[0]] = {'valid': len(word) == 1}

    # recursively build trie
    gen_trie(word[1:], node[word[0]])


def build_trie(words, trie):
    """Builds trie data structure from the list of words given"""
    for word in words:
        gen_trie(word, trie)
    return trie


def main(trie_node):
    """Initiate the search for words in boggle"""
    english_words = ['apple', 'pickle', 'side', 'kick', 'sick', 'mood', 'cat',
                     'cats', 'man', 'super', 'antman', 'godzilla', 'dog', 'dot',
                     'sine', 'cos', 'signal', 'bitcoin', 'cool', 'zapper']
    trie_node = build_trie(english_words, trie_node)
    import pdb
    pdb.set_trace()


if __name__ == '__main__':
    main(trie_node)
