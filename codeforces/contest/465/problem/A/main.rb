# frozen_string_literal: true

gets
number = gets.chomp
changes = 0
number.each_char do |c|
  changes += 1
  break if c == '0'
end
puts changes
