import cs50
import sys

def main():
    
    # Error if more or less than 1 command line argument
    if len(sys.argv) != 2:
        print("Error. Usage: python vigenere.py key")
        exit(1)
        
    m = len(sys.argv[1])
    k = sys.argv[1]
    
    # Converts key from ASCII to alphabetical indices    
    for d in k:
        if not str.isalpha(d):
            print("Error. Use a key with only alphabets.")
            exit(1)
    
    # Get plaintext from user
    print("plaintext: ", end="")
    p = cs50.get_string()

    
    if p != None:
        print("ciphertext: ", end="")
        
        j = 0
        
        for c in p:
            if j > m - 1:
                j = 0
            if str.isalpha(c):
                if str.isupper(c):
                    if str.isupper(k[j]):
                        c = (ord(c) - ord('A') + ord(k[j]) - ord('A')) % 26
                        print(chr(c + ord('A')), end="")
                        j += 1
                    else:
                        c = (ord(c) - ord('A') + ord(k[j]) - ord('a')) % 26
                        print(chr(c + ord('A')), end="")
                        j += 1
                else:
                    if str.isupper(k[j]):
                        c = (ord(c) - ord('a') + ord(k[j]) - ord('A')) % 26
                        print(chr(c + ord('a')), end="")
                        j += 1
                    else:
                        c = (ord(c) - ord('a') + ord(k[j]) - ord('a')) % 26
                        print(chr(c + ord('a')), end="")
                        j += 1
            else:
                print(c, end="")
        
        print()
    
if __name__ == "__main__":
    main()