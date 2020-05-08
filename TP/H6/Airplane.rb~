class Airplane
	def initialize
		@seats =Array.new(6){Array.new(27){0}}
	end	
	def add(rvalue)
		i=0
		j=0
		added=0
		for i in 0...27
			for j in 0...6				
				if (@seats[j][i] == 0)
					
					if(rvalue==1)
						@seats[j][i]=1
						added=1				
					elsif(rvalue==2)
						if(j<5)
							if(@seats[j+1][i]==0)
								if(j!=2 && j!=5)
									@seats[j][i]=1
									@seats[j+1][i]=1
									added=1								
								end							
							end						
						end
					elsif(rvalue==3)
						if(j<4)
							if(@seats[j+1][i]==0 && @seats[j+2][i]==0)
								if(j==0 || j==3)
									@seats[j][i]=1
									@seats[j+1][i]=1
									@seats[j+2][i]=1
									added=1								
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
				print @seats[j][i]			
			end
			print "\n"		
		end
	end
	
end
plane = Airplane.new
plane.printSeats
print "###################\n"
plane.add(1)
plane.printSeats
print "###################\n"

plane.add(2)
plane.printSeats
print "###################\n"
plane.add(2)
plane.printSeats
print "###################\n"
plane.add(2)
plane.printSeats
print "###################\n"
plane.add(3)
plane.printSeats
print "###################\n"
plane.add(1)
plane.printSeats
print "###################\n"
