class CSVFile
end
arr= Array.new(31){0}

Dir.glob('./*.csv') do |item|
    puts item
   	f = File.open(item,"r")
	content = f.read
	content.each_line do |line|
	    arr[line.to_i]+=1
	end
end
for i in 1...arr.length
    puts i.to_s+" "+arr[i].to_s
end
popular = arr[1]
index=0
for i in 1...arr.length
    if arr[i]>popular
        index=i
		popular=arr[i]
    end
end
print "Number #{index} is most popular votes:#{arr[index]}\n"
unpopular = arr[1]
index=0
for i in 1...arr.length
    if arr[i]<unpopular
        index=i
		unpopular=arr[i]
    end
end
print "Number #{index} is unpopular votes:#{arr[index]}\n"