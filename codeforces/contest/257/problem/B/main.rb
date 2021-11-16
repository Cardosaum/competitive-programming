r, b = gets.chomp('').split.map { |i| i.to_i }
R = r
B = b
petya = true
p,v = 0, 0
l = []
(R + B).times do |_n|
  if petya && r < b && !r.zero?
    (l << R)
    r -= 1
  elsif petya && !b.zero?
    (l << B)
    b -= 1
  elsif r < b && !b.zero?
    (l << B)
    b -= 1
  elsif !r.zero?
    (l << R)
    r -= 1
  else
    puts 'DEU RUIM'
  end
  petya = !petya
end
# puts l
# puts
# puts l.zip(l[1..])
l.zip(l[1..]).each do |x, y|
  if !x || !y
    break
  end 
  if x == y
    p += 1
  else
    v += 1
  end
  puts "X:#{x} ; Y:#{y}"
end
puts
puts "#{p} #{v}"
