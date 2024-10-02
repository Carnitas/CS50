from cs50 import get_string
import re


def main():
    text = get_string("Enter text: ")
    total_letters = count_letters(text)
    total_words = count_words(text)
    total_sentences = count_sentences(text)

    reading_level = reading_formula(total_letters, total_words, total_sentences)

    if reading_level < 1:
        print("Before Grade 1")
    elif reading_level > 15:
        print("Grade 16+")
    else:
        print(f"Grade {reading_level}")


def count_letters(text):
    total_letters = 0
    for i in text:
        if i.isalpha():
            total_letters += 1
    return total_letters


def count_words(text):
    return len(text.split())


def count_sentences(text):
    return len(re.findall("[.!?]", text))


def reading_formula(letter, word, sentence):
    L = letter / word * 100  # Average number of letters per 100 words
    S = sentence / word * 100  # Average number of sentences per 100 words

    return round(0.0588 * L - 0.296 * S - 15.8)


main()
