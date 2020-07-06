# HITLER SORT BY SEKOMER

import random

def isprime(n):
	if n == 2 or n == 3:
		return True
	if n < 2 or n%2 == 0 or n%3 == 0:
		return False
	for i in range(5, int(n**0.5) +1, 6):
		if n % i == 0 or n % (i+2) ==0:
			return False
	return True	 

def hitler_sort(array):
	remaining_prime = 2
	index = 0
	filter(isprime, array)
	#array = [x for x in array if isprime(x)]
	while index < len(array):
		if isprime(array[index]) == False:
			del array[index]
			index -= 1
		elif(isprime(array[index]) and array[index] < remaining_prime):
			del array[index]
			index -= 1
		elif(isprime(array[index]) and array[index] > remaining_prime):
			remaining_prime = array[index]
		
		index += 1
	return array

if __name__ == "__main__":
	list =[]
	for i in range(int(input("how big will your hitler_sort gonna be: "))):
		list.append(random.randint(input("lower random interval: "),input("upper random interval: ")))

	list = hitler_sort(list)
	print(list)