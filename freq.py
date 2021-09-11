text = "oi apareceu 2x batata 1x e oi 2x"
words = text.split()
summary = {word: words.count(word) for word in set(words)}
print(summary)
