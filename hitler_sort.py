import random

def isprime(input):
	
	if input == 2 or input == 3:
		return True
	if input < 2 or input%2 == 0 or input%3 == 0:
		return False
	for i in range(5, int(input**0.5) +1, 6):
		if input % i == 0 and input % i+2 ==0:
			return False
	return True	 


def hitler_sort(array):
	remaining_prime = 2
	index = 0
	for element in array:
		if isprime(element) == False:
			del array[index]
			index += 1
		elif(isprime(element) and element < remaining_prime):
			del array[index]
			index += 1
		elif(isprime(element) and element > remaining_prime):
			remaining_prime = array[index]
			index += 1


if __name__ == "__main__":
	list =[]
	for i in range(int(input("how big will your hitler_sort gonna be: "))):
		list.append(random.randint(0,256))

	hitler_sort(list)
	print(list)
	print(isprime(222))