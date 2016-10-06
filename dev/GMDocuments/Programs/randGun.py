import random
import argparse
import pdb

args = None

class Gun:
	
	def __init__(self):
		self.type = "Pistol"
		self.range = 20 #in meters
		self.damage = 20
		self.miss_chance = 0.20
		self.cost = 200
		self.capacity = 20 # rounds
		self.fire_type = "Single"
	
	def shoot(self):
		print "Bang. Did %s damage" % self.damage
		
	def tostring(self):
		returnMe = "%s: %s at %sm %s%% %s credits" % (self.type, self.damage, self.range, self.miss_chance, self.cost)
		returnMe = "%s %s rounds %s" % (returnMe, self.capacity, self.fire_type)
		return returnMe

def make_revolver(gun, level):
	self.type = "Pistol(Revolver)"
	self.range = 30 + (random.randint(0, 5 + (level * 2)) * 5)
	self.capacity = 6
	if level > 10:
		self.capacity = 8
	self.damage = (10 * level) + 50 + random.randint(0,6) * 5
	self.fire_type = "Hammer Pull"
	self.miss_chance = random.randint(15,40)
	self.cost = (self.damage * self.capacity * self.miss_chance / 200) - 400

def make_pistol(gun, level):
	dice = random.randint(1,3)
	if dice == 2:
		make_revolver(gun, level)
	else:
		gun.range = (5 * random.randint(0,5)) + 30 + (level * 2)
		gun.damage = random.randint(0, 30 - level)
		gun.miss_chance = random.randint(0, 30 - level)
		gun.capacity = random.randint(4,30)
		gun.fire_type = "Semi"
		gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2	
def make_shotgun(gun, level):
	gun.range = 20
	gun.damage = 110
	gun.miss_chance = random.randint(15,50)
	gun.capacity = random.randint(2,6)
	gun.fire_type = "Pump Action"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2
	
def make_automatic(gun, level):
	gun.range = (5 * random.randint(0,10)) + 80 + (level * 4)
	gun.damage = random.randint(20,90)
	gun.miss_chance = random.randint(15,50)
	gun.capacity = random.randint(4,30)
	gun.fire_type = "Full Auto"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2
	
def make_heavy(gun, level):
	gun.range = 80
	gun.damage = random.randint(20,90)
	gun.miss_chance = random.randint(15,50)
	gun.capacity = random.randint(4,30)
	gun.fire_type = "Semi"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2
	#todo: make separate flamethrower, autocannon, chaingun methods
	#todo: roll a die, and call one of those methods here
	
def make_smg(gun, level):
	gun.range = (5 * random.randint(0,7)) + 45 + (level * 2)
	gun.damage = random.randint(20,90)
	gun.miss_chance = random.randint(15,50)
	gun.capacity = random.randint(4,30)
	gun.fire_type = "Full Auto"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2
	
def make_carbine(gun, level):
	gun.range = (5 * random.randint(0,15)) + 75 + (level * 4)
	gun.damage = random.randint(20,90)
	gun.miss_chance = random.randint(15,50)
	gun.capacity = random.randint(4,30)
	gun.fire_type = "Semi"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2
	
def make_long(gun, level):
	gun.range = 200
	gun.damage = random.randint(50,100) + (level * 5)
	gun.miss_chance = 15
	gun.capacity = random.randint(1,10)
	gun.fire_type = "Semi"
	gun.cost = gun.damage * gun.miss_chance * gun.capacity / 2

def make_random_gun(level):
	print "making new %s level %s %s" % ("random", level, "gun")
	gun_types = ["Pistol", "Shotgun", "Long Rifle", "SMG", "Automatic Rifle", "Carbine", "Heavy"]
	fire_types = ["Single", "Full auto", "Semi"]
	dice = random.randint(1,len(gun_types))
	newGun = Gun()
	newGun.type = gun_types[dice - 1]
	
	if newGun.type == "Pistol":
		make_pistol(newGun, level)
	elif newGun.type == "Shotgun":
		make_shotgun(newGun, level)
	elif newGun.type == "Long Rifle":
		make_long(newGun, level)
	elif newGun.type == "SMG":
		make_smg(newGun, level)
	elif newGun.type == "Carbine":
		make_carbine(newGun, level)
	elif newGun.type == "Automatic Rifle":
		make_automatic(newGun, level)
	elif newGun.type == "Heavy":
		make_heavy(newGun, level)
	else:
		print "weapon type not recognized. Add new method?"
		exit()
	return newGun
	
def display_gun(gun):
	print "Made a %s which does %s damage out to %sm" % (gun.type, gun.damage, gun.range)
	print "Has %s%% chance to miss and has fire type %s with a clip size of %s" % (gun.miss_chance, gun.fire_type, gun.capacity)
	print "Has a %s credit price tag on it." % gun.cost

def write_gun(gun):
	print "writing to file."
	with open(args.o, 'a') as outfile:
		outfile.write(gun.tostring())
		outfile.write("\n")

def main():
	print "beggining Random Gun generation. Version 1.0.p"
	#get args
	parser = argparse.ArgumentParser()
	#-db DATABSE -u USERNAME -p PASSWORD -size 20
	parser.add_argument("-n", metavar="N", help="If set, makes N number of random guns.")
	parser.add_argument("-L", metavar="Level", help="if set, makes all guns level L. Level 10 by default.")
	parser.add_argument("-o", metavar="Filename", help="if set, writes weapons to a text file named filename")
	global args
	args = parser.parse_args()
	
	if not args.o and not args.n and not args.L:
		print "You can use randGun.py like a unix command. Try '$python randGun.py --help'."
	
	level = 10
	if args.L:
		level = int(args.L)
	n = 1
	if args.n:
		n = int(args.n)
		
	for index in range(n):
		newGun = make_random_gun(level)
		display_gun(newGun)
		if args.o:
			write_gun(newGun)
	

main()