from nltk.corpus import wordnet as wn
word = input("Please input word: ")

length = len(wn.synsets(word))
for i in range(length):
	print(wn.synsets(word)[i].lemmas())
	print(wn.synsets(word)[i].hyponyms())
	print(wn.synsets(word)[i].hypernyms())
	print('\n')

