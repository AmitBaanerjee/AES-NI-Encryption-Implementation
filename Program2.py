import time
start_time = time.time()

from Crypto.Cipher import AES  
#importing AES library 
key='this is a aesenc'          
#16 byte key used for encryption
aes_object=AES.new(key,AES.MODE_ECB) 
#creating an object to use inbuilt functions of AES
plaintext='my name is amit banerjee'
 #declaring plaintext to be used in program

def padding(plaintext):            
    #this function will keep the plaintext in format of multiples of 16
        return plaintext +((16-len(plaintext)%16) * ' ')

def encryption(plaintext):
    #function returning the encrypted cipher
    return aes_object.encrypt(padding(plaintext))

def decryption(input):
    #function returning the encrypted cipher
    decode=aes_object.decrypt(input).decode('UTF-8')
    remove=decode.count('')
    return decode[:len(decode)-remove]


list=[]
i=0
while i<1000:
    list.append(encryption(plaintext))
    i=i+1
print("Output of 1000 iterations in the form of list is :-",list)
    #calling the encryption function 1000 times for question 5b
    #encrypted[i]=encryption(plaintext)
    
print("--- %s seconds ---" % (time.time() - start_time))

"""testing purposes:-"""

encrypted=encryption(plaintext)
decrypted=decryption(encrypted)
    #storing encrypted cipher in variable called encrypted
print("Plaintext message is :\n",plaintext)
print("Encrypted text is :\n",encrypted)
print("Decrypted text is :\n",decrypted)
#printing the plaintext and encrypted messages in subsequent lines
#citation links below:-
#https://stackoverflow.com/questions/1557571/how-do-i-get-time-of-a-python-programs-execution
#https://pypi.org/project/pycrypto/
