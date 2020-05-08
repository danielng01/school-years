#ТУЕС elsys-bg.org
#11Б
#11
#Даниел Николаев Георгиев
#
def process_file
	f = File.open("./csv_example.csv","r")
	content = f.read
	result = 0
	content.each_line do |line|
			array = line.split(",")
			result = result +  array[1].to_i()
	end
	p result
end

process_file
