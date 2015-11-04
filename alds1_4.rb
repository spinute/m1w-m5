def enough?(w, k, capacity)
	res = 0
	w.each do |e|
		while res < e
			return false if k == 0
			k -= 1
			res = capacity
		end
		res -= e
	end
	true
end

n, k = gets.split(' ').map(&:to_i)

w = Array.new(n){|i| gets.to_i}

lb = 0
ub = 4000000000

while lb + 1 < ub
	mid = (lb + ub)/2
	if enough?(w, k, mid)
		ub = mid
	else
		lb = mid
	end
end

puts ub
