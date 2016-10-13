require 'benchmark'

# Implementation of optimization of Kadane's algorithm for specific data.
class KadaneOptimalization
  def main
    if ARGV.size == 1
      x = []
      File.open(ARGV[0], 'r').each_line do |line|
        x = line.split(' ')
        x = x.map(&:to_i)
      end

      bm1 = Benchmark.measure do
        max = x.size - 1
        kadana_algorithm(x, 1, max)
      end

      bm2 = Benchmark.measure do
        min = find_min_positive_possition(x)
        min = 1 if min.zero?
        max = find_max_positive_possition(x)
        kadana_algorithm(x, min, max)
      end

      puts "classic: #{bm1}"
      puts "upgraded: #{bm2}"

    else
      puts 'usage: ruby problem2_i2i.rb <file_name>'
    end
  end

  def find_min_positive_possition(array)
    for i in 0..array.size - 1
      return i if array[i] > 0
    end
  end

  def find_max_positive_possition(array)
    for i in (array.size - 1).downto(0)
      return i if array[i] > 0
    end
  end

  def kadana_algorithm(array, min, max)
    max_so_far = array[0]
    max_ending_here = array[0]

    first = 0
    first_temp = 0
    last = 0

    for i in min..max
      # calculate max_ending_here
      if max_ending_here < 0
        max_ending_here = array[i]
        first_temp = i
      else
        max_ending_here += array[i]
      end
      # calculate max_so_far
      next unless max_ending_here >= max_so_far
      max_so_far = max_ending_here
      first = first_temp
      last = i

    end
    puts max_so_far
    puts first
    puts last
  end
end

solution = Kadane_optimalization.new
solution.main
