# -*- coding: utf-8 -*-
# hint: 

require "find"

class String
	def bg_green; "\033[42m#{self}\033[0m" end
end

def search(string, bool)
        if bool == false
        else
          files = []
          Find.find(".").each do |f|
              files << f 
          end

          files.each do |f|
              puts "#{f.split("/")[files.split("/")].lenght-1}"
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
		if string.split("").to_a.empty?
			#nothing
		else
                         if file == string 
			 	var = true
                         elsif file.include? (string)
			 	var2 = true
                         end
		end
		type = File.ftype(file)
		if var
			print file.bg_green
			file.length.upto(value.length + 4) do
				print " "
			end
			puts "#{type}"
                elsif var2
                        print "#{file.bg_green}" 
                        file.length.upto(value.length + 4) do
                                print " "
                        end
                        print type
                        puts "          [x]" if File.ftype(file) == "file"
                        puts "     [x]" if File.ftype(file) == "directory"
		else
			print file
			file.length.upto(value.length + 4) do
				print " "
			end
			puts "#{type}"
		end
	end
end


if ARGV[0] == "--help"
	puts "Usage: ruby list_dir.rb [<arg1> <arg2>]"
	puts "Arguments (arg1):"
	puts "--grep: Search for a file name "
        puts "        [x] near the type if the name is included!"
	puts "--dir:  Change to some directory"
	puts "Example: ruby dir.rb --dir /home/user --grep filename"
	exit
elsif ARGV[0] == "--grep" && ARGV[2] == "--dir"
	begin
		Dir.chdir(ARGV[3])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search(ARGV[1], false)
elsif ARGV[0] == "--dir" && ARGV[2] == "--grep"
	begin
		Dir.chdir(ARGV[1])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search(ARGV[3], false)
elsif ARGV[0] == "--dir"
	begin
		Dir.chdir(ARGV[1])
	rescue => error
		puts "An error occured: #{error}"
		exit
	end
	search("", false)
elsif ARGV[0] == "--grep" 
	search(ARGV[1], false)
elsif ARGV[0] == "--recursiv"
        search(ARGV[2], true)
else
	search("", false)
end

