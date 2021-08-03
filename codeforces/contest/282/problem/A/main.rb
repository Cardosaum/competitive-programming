#!/usr/bin/env ruby

# n = gets "Input something"
# x = 0
# puts ARGF.read
ARGF.each_with_index do |line, idx|
    print ARGF.filename, ":", idx, ";", line
end
