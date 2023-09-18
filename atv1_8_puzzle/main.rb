require 'ruby2d'
require_relative 'src/board'
require_relative 'src/solver'

BG_COLOR = '#FFF5E0'.freeze
TEXT_COLOR = '#2E3840'.freeze
TILE_COLOR = '#FF6969'.freeze
BORDER_COLOR = '#BB2525'.freeze

GOAL = [0, 1, 2, 3, 4, 5, 6, 7, 8].freeze

board = Board.new
board.shuffle_board

puts 'Initial board:'
puts board

time = Time.now
result = Solver.bfs(board, GOAL)
time = Time.now - time

has_solution = !result.empty?

if has_solution
  puts "\nSolved with #{result.size} moves in #{time}s"
else
  puts "\nNo solution found"
end

puts "\nMoves: #{result}" if has_solution

set(title: '8-Puzzle', width: 400, height: 400, background: BG_COLOR)

WIDTH = Window.width
HEIGHT = Window.height
TILE_SIZE = 100

tick = 0
title = Text.new('8-Puzzle', size: 30, style: :bold, color: TEXT_COLOR)
title.x = (WIDTH - title.width) / 2
title.y = 25 - title.height / 2

author = Text.new('by Ualace (@ualacecafe)', size: 15, style: :bold, color: TEXT_COLOR)
author.x = (WIDTH - author.width) / 2
author.y = HEIGHT - 25 - author.height / 2

nosol_text = Text.new('No solution found :(', size: 40, style: :bold, color: BG_COLOR)
nosol_text.x = (WIDTH - nosol_text.width) / 2
nosol_text.y = (HEIGHT - nosol_text.height) / 2

nosol_rect = Rectangle.new(x: 0, y: 0, width: WIDTH, height: nosol_text.height + 10, color: TEXT_COLOR)
nosol_rect.y = (HEIGHT - nosol_rect.height) / 2

tiles_text = (0..8).map do |i|
  Text.new(i.to_s, size: 35, style: :bold, color: TEXT_COLOR)
end

update do
  clear

  title.add
  author.add

  board.grid.each_with_index do |tile, idx|
    x = 50 + (idx % 3) * TILE_SIZE
    y = 50 + (idx / 3) * TILE_SIZE

    if tile.zero?
      Square.new(x: x, y: y, size: TILE_SIZE, color: BORDER_COLOR)
    else
      Square.new(x: x, y: y, size: TILE_SIZE, color: BORDER_COLOR)
      Square.new(x: x + 4, y: y + 4, size: 92, color: TILE_COLOR)
      tiles_text[tile].x = x + tiles_text[tile].width / 2 + 25
      tiles_text[tile].y = y + tiles_text[tile].height / 2 + 8
      tiles_text[tile].add
    end
  end

  if has_solution && !result.empty? && (tick % 20).zero?
    board.grid = board.move(board.grid, result.shift)
  elsif !has_solution
    nosol_rect.add
    nosol_text.add
  end

  tick += 1
end

show
