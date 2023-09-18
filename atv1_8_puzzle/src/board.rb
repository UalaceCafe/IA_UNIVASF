Node = Struct.new(:state, :parent, :op, :depth)

class Board
  attr_accessor :grid

  def initialize
    @grid = []
  end

  def shuffle_board
    @grid = (0..8).to_a.shuffle
  end

  def move(state, dir)
    new_state = state.dup
    idx = new_state.index(0)

    case dir
    when :up
      return nil if [0, 1, 2].include?(idx)

      new_state[idx], new_state[idx - 3] = new_state[idx - 3], new_state[idx]
    when :down
      return nil if [6, 7, 8].include?(idx)

      new_state[idx], new_state[idx + 3] = new_state[idx + 3], new_state[idx]
    when :left
      return nil if [0, 3, 6].include?(idx)

      new_state[idx], new_state[idx - 1] = new_state[idx - 1], new_state[idx]
    when :right
      return nil if [2, 5, 8].include?(idx)

      new_state[idx], new_state[idx + 1] = new_state[idx + 1], new_state[idx]
    else
      raise 'unreachable'
    end

    new_state
  end

  def expand_node(node)
    expanded_nodes = []
    expanded_nodes << Node.new(move(node.state, :up), node, :up, node.depth + 1)
    expanded_nodes << Node.new(move(node.state, :down), node, :down, node.depth + 1)
    expanded_nodes << Node.new(move(node.state, :left), node, :left, node.depth + 1)
    expanded_nodes << Node.new(move(node.state, :right), node, :right, node.depth + 1)

    expanded_nodes.delete_if { |n| n.state.nil? }
    expanded_nodes
  end

  def to_s
    @grid.each_slice(3).map { |row| row.join(' ') }.join("\n")
  end
end
