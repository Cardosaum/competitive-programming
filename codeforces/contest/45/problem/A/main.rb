# frozen_string_literal: true

months = %w[January February March April May June July August September October November
            December]
month = gets.chomp
k = gets.chomp.to_i
puts months[(months.find_index(month) + k) % months.length]
