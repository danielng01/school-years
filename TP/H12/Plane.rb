class Human
	attr_accessor :name, :gender
end
class Airplane
	def initialize
		@seats =Array.new(6){Array.new(27){Human.new}}
		@c=0
	end	
	def add(rvalue, h)
		i=0
		j=0
		added=0
		for i in 0...27
			for j in 0...6				
				if (@seats[j][i] != nil)

					if(rvalue==1)
						@seats[j][i]=h[0]
						added=1
						@c+=1				
					elsif(rvalue==2)
						if(j<5)
							if(@seats[j+1][i]==0)
								if(j!=2 && j!=5)
									@seats[j][i]=h[0]
									@seats[j+1][i]=h[1]
									added=1	
									@c+=2							
								end							
							end						
						end
					elsif(rvalue==3)
						if(j<4)
							if(@seats[j+1][i]==0 && @seats[j+2][i]==0)
								if(j==0 || j==3)
									@seats[j][i]=h[0]
									@seats[j+1][i]=h[1]
									@seats[j+2][i]=h[2]
									added=1	
									@c+=3							
								end							
							end						
						end
					end
				end
				if(added==1)
					break
				end				
			end
			if(added==1)
					break
			end	
		end
	end
	def printSeats
		for i in 0...27
			for j in 0...6
				if j==3
					print "|_|"
				end
				print @seats[j][i].name			
			end
			print "\n"		
		end
	end
	def remove(h)
		done=false
		for i in 0...27
			for j in 0...6
				if @seats[j][i].name == h.name
					seats[j][i]=null
					done = true
				end
			end
		end
		puts "no human found!"
	end
	def clear()
		@seats=null
	end
	def getCapacity
		if @c<162
			return 162-@c
		else
			puts "plane is full"
			return 0
		end
	end
	def getMales()
		males=0
		for i in 0...27
			for j in 0...6
				if @seats[j][i].gender == "male"
					males+=1
				end
			end
		end
	end
	def getFemales()
		females=0
		for i in 0...27
			for j in 0...6
				if @seats[j][i].gender == "female"
					females+=1
				end
			end
		end
	end
end
plane = Airplane.new
plane.printSeats
h=Array.new(27){Human.new}
h[0].name="pesho"
h[0].gender="male"
print "###################\n"
plane.add(1,
plane.printSeats
print "###################\n"

