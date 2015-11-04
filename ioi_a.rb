n = gets.to_i
maximum = 0
input = gets.split(' ').map(&:to_i)
sum = input.inject(0){|a, e| maximum = [maximum, e].max; a+e}

puts n + sum + maximum
