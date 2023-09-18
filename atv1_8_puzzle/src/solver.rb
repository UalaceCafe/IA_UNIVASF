require_relative 'board'

module Solver
  def self.dfs(initial_board, goal_state)
    stack = [Node.new(initial_board.grid, nil, nil, 0)]
    visited = Set.new

    goal_node = nil

    until stack.empty?
      current_node = stack.pop
      current_state = current_node.state

      if current_state == goal_state
        goal_node = current_node
        break
      end

      visited.add(current_state)

      initial_board.expand_node(current_node).each do |child_node|
        child_state = child_node.state
        unless visited.include?(child_state)
          stack.push(child_node)
        end
      end
    end

    if goal_node
      build_path(goal_node)
    else
      []
    end
  end

  def self.bfs(initial_board, goal_state)
    queue = Queue.new
    queue.enq(Node.new(initial_board.grid, nil, nil, 0))
    visited = Set.new

    goal_node = nil

    until queue.empty?
      current_node = queue.deq
      current_state = current_node.state

      if current_state == goal_state
        goal_node = current_node
        break
      end

      visited.add(current_state)

      initial_board.expand_node(current_node).each do |child_node|
        child_state = child_node.state
        unless visited.include?(child_state)
          queue.enq(child_node)
        end
      end
    end

    if goal_node
      build_path(goal_node)
    else
      []
    end
  end

  private

  def self.build_path(node)
    path = []

    while node.parent
      path.prepend(node.op)
      node = node.parent
    end

    path
  end
end
