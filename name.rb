print "Type in your name: "
name = gets.chomp
greet = ["Hello", "What's up", "Hi", "Hey", "Nice to see you", "How are you", "Let's go"]

puts "#{greet[rand(greet.size)]} #{name}"
