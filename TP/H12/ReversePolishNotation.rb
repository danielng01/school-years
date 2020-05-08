
def is_a_number?(s)
  s.to_s.match(/\A[+-]?\d+?(\.\d+)?\Z/) == nil ? false : true
end

STDOUT.flush
c = gets.chomp.split(" ")
stack = []
c.each do |x|
	if is_a_number?(x)
		stack.push(x.to_f)
	elsif ((x == "+" || x == "-" || x == "*" || x == "/") && stack.size >= 2)
		second = stack.pop()
		first = stack.pop()
		case x
			when "+"
				stack.push(first + second)
			when "-"
				stack.push(first - second)
			when "*"
				stack.push(first * second)
			when "/"
				stack.push(first / second)
		end
	else
		puts "Something is wrong" 
	end
end

if stack.size != 1
	puts "You've done something wrong"
else
	puts stack.pop()
end