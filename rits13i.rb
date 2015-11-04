require 'pp'

EPS = 0.000001
$w, h, n = gets.split(" ").map(&:to_i)

def calc_y(a, p, q, x)
	pp [a, p, q, x]
	a * (x-p)**2 + q
end

def add_if_in(x, list)
	list << x if 0 <= x && x <= $w
end

def calc_curves_intersection(list, ai, pi, qi, aj, pj, qj)
	a = ai - aj
	b = -2 * (ai * pi - aj * pj)
	c = ai * pi**2 + qi - aj * pj**2 - qj

	return nil if (b ** 2 - 4 * a * c < -EPS)

	xp = (-b + Math.sqrt(b**2 - 4*a*c)) / 2 / a
	add_if_in(xp, list)

	xn = (-b - Math.sqrt(b**2 - 4*a*c)) / 2 / a
	add_if_in(xn, list)
end

def calc_floor_intersection(list, a, p, q)
	b = -2*a*p
	c = a * p**2 + q

	return nil if (b ** 2 - 4 * a * c < -EPS)

	xp = (-b + Math.sqrt(b**2 - 4*a*c)) / 2 / a
	add_if_in(xp, list)

	xn = (-b - Math.sqrt(b**2 - 4*a*c)) / 2 / a
	add_if_in(xn, list)
end

def integral_f(a, b, x)
	(4 * a**2 * x + 2 * a * b) / Math.sqrt(4 * a**2 * x**2 + 4 * a * b * x + b**2 + 1)
end

def calc_length(a, p, q, from, to)
	pp [a, p, q, from, to]
	b = -2*a*p
	integral_f(a, b, to) - integral_f(a, b, from)
end

a = []
p = []
q = []
n.times do
	ai, pi, qi = gets.split(" ").map(&:to_f)
	a << ai
	p << pi
	q << qi
end

l = []

n.times do |i|
	(i+1).upto (n-1) do |j|
		calc_curves_intersection(l, a[i], p[i], q[i], a[j], p[j], q[j])
	end
	calc_floor_intersection(l, a[i], p[i], q[i])
end

pp l
l.sort!
sum = 0
for i in 0..(l.length - 2)
	mid = (l[i] + l[i+1]) / 2
	max_i = 0
	maximum = 0
	n.times do |j|
		y = calc_y(a[j], p[j], q[j], mid)
		pp y
		if y > maximum
			max_i = j
			maximum = y
		end

		if maximum != 0
			sum += calc_length(a[max_i], p[max_i], q[max_i], l[i], l[i+1])
		end
	end
end

pp calc_length(1.0, 0.0, 0.0, -1.0, 1.0)
pp 4 / Math.sqrt(5)

p sum
