if string=ARGV[0] == "--dir"
	begin
		Dir.chdir(ARGV[1])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
end

files = Dir.glob("**")
value = files.max_by { |var| var.length }

print "Name"
value.length.downto(0) do
	print " "
end
puts "Type"

print "===="
value.length.downto(0) do 
print " "
end
print "===="
puts

files.each do |file| 
	type = File.ftype(file)
	print "#{file}"
	file.length.upto(value.length + 4) do
		print " "
	end
	puts "#{type}"
end
