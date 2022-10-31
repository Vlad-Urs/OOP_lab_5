# OOP Lab 5, Wrapping Up the Simulation

Simulation of a spaceship voyage.

The simulation takes some starting input parameters: crew numbers, passengers numbers and number of days that the journey will take.

The journey starts with all the ship's componentes running at 100% condition, and suffering some minor wear damage as the days go by. If the condition of any given component decreases under a certain threshold, the Engineers will take care of it and bring it up to 100% in a few days.

Additionally, through the few special events the ship will endure even more damage, and the journey will lengthen. 
If an asteroid is sighted, they will try to destroy it with the guns. If the guns fail it will impact the ship, affecting the integrity of the shield and the outer hull. If the hull endures enough damage, the engineers will take care of it.
If a Pirate Ship is encoutered, the ship will try to destroy it with the energy disruptor, but only in the case that the reactor is in very good condition, otherwise they will engage them with the guns. If the guns fail, and pirates enter the ship, a struggle with the ship security corps will take place. During this fight some crew members and passengers should die if the ship is victorious, otherwise if the pirates take over the ship, the journey and thus the simulation is over.
Through all this, if the ship runs out of provisions they will seek a near space station, where it will fill in on provisions and some crew members on the cost of some additional days to the journey.
