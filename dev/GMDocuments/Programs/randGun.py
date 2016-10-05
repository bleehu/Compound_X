import random
import argparse
import pdb

class Gun:
	
	def __init__(self):
		self.type = "Pistol"
		self.damage = 20
		self.miss_chance = 0.20
		self.cost = 200
	
	def shoot(self):
		print "Bang. Did %s damage" % self.damage

def main():
	print "beggining Random Gun generation. Version 1.0.p"
	gun_types = ["Pistol, Shotgun, Long Rifle, SMG, Automatic Rifle, Carbine"]
	fire_types = ["Single", "Full auto", ]
	
	pdb.set_trace()
main()