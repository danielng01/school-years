class CSVFile
end
arr= Array.new(32){0}

Dir.glob('./*.csv') do |item|
    puts item
   	f = File.open(item,"r")
	content = f.read
	content.each_line do |line|
	    arr[line.to_i]+=1
	end
end
for i in 1..32
    puts i.to_s+" "+arr[i].to_s
end
popular = 0
arr.each_index |index|
    
end

for i in 1..31
    if arr[i]>popular
        popular=i
    end
end
print i
