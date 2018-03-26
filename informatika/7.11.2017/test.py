from game import Registration

# Tyto tridy implementuj:


class Player:
	#name, sledges, skis, index
	def __init__(self, name, sledges, skis, index):
		self.name = name
		self.sledges = sledges
		self.skis = skis
		self.index = index


class Team:
    def __init__(self, name, players):
    	self.name = name
    	self.players = players

    def get_players_count(self):
    	count = len(self.players)
    	return count

    def get_transport_capacity(self):
        capacity = 0
        for one in self.players:
            capacity = capacity + sum(one.sledges)
        return capacity

    def get_average_index(self):
        index = 0
        for one in self.players:
    	    index = index + one.index
        index = index / self.get_players_count()
        return index
# Testy:

registration = Registration()

print(registration.register(
    Team(
        "Zmlsani",
        [
            Player("Agata", [2, 3], [1], 5),
            Player("Rudolf", [], [], 3),
            Player("Alois", [], [], 4)
        ]
    ))
)
'''
"Tym Zmlsani zaregistrovan,
zarazen jako pojizdny s prum. hernim indexem 4.0."
'''

print(registration.register(
    Team(
        "Dupoledu",
        [
            Player("Agata", [], [1], 1),
            Player("Alois", [], [], 2)
        ]
    ))
)
'''
"Tym Dupoledu zaregistrovan,
zarazen jako nepojizdny s prum. hernim indexem 1.5."
'''

print(registration.register(
    Team(
        "(O)OP",
        [
            Player("Agata", [2], [1], 8),
            Player("Rudolf", [], [1], 7),
            Player("Alois", [3], [], 9),
            Player("Oskar", [2], [], 10),
            Player("Karlos", [10, 5], [1, 1, 1], 20)
        ]
    ))
)
''' "Tym nezaregistrovan, prekroceno povolene mnozstvi clenu." '''
