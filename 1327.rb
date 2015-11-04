def mul(mat, mbt, mod)
	transposed = mbt.transpose
	Array.new(mat.size) do |i|
		Array.new(transposed.size) do |j|
			mat[i].zip(transposed[j]).inject(0){|a, e| (a + e[0]*e[1]) %mod}
		end
	end
end

n, m, a, b, c, t = gets.split(' ').map(&:to_i)
while n != 0 || m != 0 || a != 0 || b != 0 || c != 0 || t != 0
	mat = Array.new(n) do |row|
		Array.new(n) do |col|
			if row == col
				b
			elsif row+1 == col
				c
			elsif row == col+1
				a
			else
				0
			end
		end
	end

	prod = Array.new(n){|i|Array.new(n){|j| i==j ? 1 : 0}}

	while t!=0
		prod = mul(mat, prod, m) if t%2 == 1
		mat_cp = Array.new(n){|i| Array.new(n){|j| mat[i][j]}}
		mat = mul(mat, mat_cp, m)
		t/=2
	end

	c = gets.split(' ').map{|e| [e.to_i]}
	ans = mul(prod, c, m)

	n.times do |i|
		print (i==0?"":" ") + "#{ans[i][0]}"
	end
	puts ""

	n, m, a, b, c, t = gets.split(' ').map(&:to_i)
end
