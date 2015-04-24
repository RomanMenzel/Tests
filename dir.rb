class String
	def bg_green; "\033[42m#{self}\033[0m" end
end

def search(string)
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
		if string.split("").to_a.empty?
			#nothing
		else
			if file == string
				var = true
			end
		end
		type = File.ftype(file)
		if var
			print file.bg_green
			file.length.upto(value.length + 4) do
				print " "
			end
			puts "#{type}"
		else
			print file
			file.length.upto(value.length + 4) do
				print " "
			end
			puts "#{type}"
		end
	end
end

string = ARGV[1]
if ARGV[0] == "--help"
	puts "Usage: ruby list_dir.rb <arg1> <arg2>"
	puts "Arguments (arg1):"
	puts "--grep: Search for a file name"
	puts "--dir:  Change to some directory"
	puts "Example: ruby list_dir.rb --dir /home/user --grep filename"
	exit
elsif ARGV[0] == "--grep" && ARGV[2] == "--dir"  
	begin
		Dir.chdir(ARGV[3])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search(ARGV[1])
elsif ARGV[0] == "--dir" && ARGV[2] == "--grep"
	begin
		Dir.chdir(ARGV[1])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search(ARGV[3])
elsif ARGV[0] == "--dir"
	begin
		Dir.chdir(ARGV[1])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search(string)
elsif ARGV[0] == "--grep"
	search(string)
else
	search(string)
end
