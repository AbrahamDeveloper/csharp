using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Guess the Word Game");
        Console.WriteLine("-------------------");

        string[] words = { "apple", "banana", "cherry", "orange", "watermelon" };
        Random random = new Random();
        string wordToGuess = words[random.Next(words.Length)];
        int attempts = 5;

        char[] guessedLetters = new char[wordToGuess.Length];
        for (int i = 0; i < guessedLetters.Length; i++)
        {
            guessedLetters[i] = '_';
        }

        while (attempts > 0)
        {
            Console.WriteLine();
            Console.WriteLine("Attempts Remaining: " + attempts);
            Console.WriteLine("Word: " + new string(guessedLetters));

            Console.Write("Enter a letter: ");
            char letter = char.ToLower(Console.ReadKey().KeyChar);
            Console.WriteLine();

            bool letterFound = false;
            for (int i = 0; i < wordToGuess.Length; i++)
            {
                if (wordToGuess[i] == letter)
                {
                    guessedLetters[i] = letter;
                    letterFound = true;
                }
            }

            if (!letterFound)
            {
                attempts--;
                Console.WriteLine("Wrong letter! Try again.");
            }

            if (new string(guessedLetters) == wordToGuess)
            {
                Console.WriteLine("Congratulations! You guessed the word correctly: " + wordToGuess);
                break;
            }
        }

        if (attempts == 0)
        {
            Console.WriteLine("Sorry, you ran out of attempts. The word was: " + wordToGuess);
        }

        Console.WriteLine();
        Console.WriteLine("Thank you for playing Guess the Word!");
    }
}
