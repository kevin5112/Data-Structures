# implementing a linked list

class node(object):
	def __init__(self, next=None, data=None):
		self.next = next
		self.data = data
	
	def getNext(self):
		return self.next
	
	def setNext(self, newNext):
		self.next = newNext
		
	def getData(self):
		return self.data
		
	def setData(self, newData):
		self.data = newData
		
	def delete(self):
		del self.data
		
class list(object):
	def __init__(self):
		self.head = None
		self.size = 0
	
	def list_size(self):
		return self.size
	
	def push_front(self, newData=None):
		# testing if newData is None
		if newData is None:
			print("No data received..")
			return
		
		newNode = node(None, newData)
		if self.size == 0:
			self.head = newNode
			self.size += 1
			return
			
		newNode.setNext(self.head)
		self.head = newNode
		self.size += 1
		return
		
	def front(self):
		return self.head.getData()
		
	def push_back(self, newData):
		if self.list_size() == 0:
			self.push_front(newData)
			return
		
		newNode = node(None, newData)
		it = self.head
		while it.getNext() is not None:
			it = it.getNext()
		it.setNext(newNode)
		self.size += 1
		return
	
	def display(self):
		print("There are {} elements in this list".format(self.list_size()))
		it = self.head
		while it is not None:
			print(str(it.getData()),end=" -> ")
			it = it.getNext()
		print("null\n")
		
	# does not work yet..
'''	def clear(self):
		tracker = self.head
		trailer = None
		
		while tracker:
			trailer = tracker
			tracker = tracker.getNext()
			trailer.delete()
		self.size = 0
'''
		
def main():
	myList = list()
	
	# testing push_front
	myList.push_front(1)
	#testing display
	myList.display()
	
	# testing push_front in a loop
	for i in range(2,10):
		myList.push_front(i)
	myList.display()
	
	# testing front function
	print("The front of the list is:",myList.front(),end="/n/n")

	# testing push_back function
	myList.push_back(0)
	myList.display()

	'''
	# test clear
	myList.clear()
	myList.display()
	'''
	
	# creates a new list and tests push_back with a loop
	newList = list()
	for i in range(0,10):
		newList.push_back(i)
	newList.display()
	
	
	
main()