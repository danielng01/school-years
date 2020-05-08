# coding: utf-8
require 'csv'
f = File.open("test.txt","w")
#Dir.glob('./*.csv') do |file|
	CSV.foreach("1. Предадени входни нива - Sheet1.csv") do |row|
		p row
		row.each do |item|
			f.write(item)
			f.write("\n")
		end
	end
#end
