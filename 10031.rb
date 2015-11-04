def bsearch(s, e)
	l = 0
	r = s.size
	while l + 1 < r
		m = (l + r)/2
		if s[m] < e
			l = m
		else
			r = m
		end
	end
	return l < r && (s[r] == e || s[l] == e)
end

P = gets.to_i
S = gets.split(' ').map(&:to_i).sort
Q = gets.to_i
T = gets.split(' ').map(&:to_i)

puts T.inject(0){|cnt, e| cnt + (bsearch(S, e) ? 1 : 0)}
