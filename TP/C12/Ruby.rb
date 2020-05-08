require 'open-uri'
file = open('http://test-1430.apphb.com')
contents = file.read

puts contents
