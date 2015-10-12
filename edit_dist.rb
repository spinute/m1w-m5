s = gets.chop
r = gets.chop

sl = s.length
rl = r.length
mem = Array.new(sl+1){Array.new(rl+1, 0)}

def p_ar(ar, sl, rl)
	(sl+1).times do |i|
		(rl+1).times do |j|
			if j == rl
				puts ar[i][j]
			else
				print "#{ar[i][j]} "
			end
		end
	end
	puts ""
end

(sl+1).times do |i|
	(rl+1).times do |j|
		if i == 0
			mem[i][j] = j
		elsif j == 0
			mem[i][j] = i
		else
			if s[i-1] != r[j-1]
				mem[i][j] = [mem[i-1][j], mem[i][j-1], mem[i-1][j-1]].min + 1
			else
				mem[i][j] = mem[i-1][j-1]
			end
		end

		#p_ar(mem, sl, rl)
	end
end

puts mem[sl][rl]
