m, n = gets.split(' ').map(&:to_i)

prod = 1

while n != 0
	prod *= m if n%2 == 1
	prod % 1000000007
	n = n/2
	m **= 2
	m %= 1000000007
end

puts prod % 1000000007
