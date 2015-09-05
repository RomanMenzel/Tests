# -*- coding: utf-8 -*-

# A method that accepts a start and an end value.
def range(s, e)

  if s > e
    s, e = e, s # Swap the values.
  end

  if !(s.class.superclass == Integer) || !(e.class.superclass == Integer) 
    raise "Invalid type of argument."
  end
 

  if !block_given? # If no block was given.
    return Array(s..e) # Return an array that contains the values between the start and the end point.
  end

  r = (s..e)
  r.each do |n|
    yield n+1 # Hand over n+1 to the block.
  end
  
end

print "\n"

range(1, 10) do |n|
  print n, " "
end

print "\n\n"

puts range(10, 1) 

print "\n"

