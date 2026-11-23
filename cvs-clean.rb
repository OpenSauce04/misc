#!/usr/bin/env ruby
# frozen_string_literal: true

# Deletes all untracked files in a cvs repository.
# Does not ask for confirmation.

cvs_output_raw = `cvs -nq update`

if (cvs_output_raw.empty?)
  exit 1
end

cvs_output_list = cvs_output_raw.split("\n")
untracked_paths_list = []

cvs_output_list.each do |v|
  if (v.start_with?('? '))
    untracked_paths_list.append(v[2..-1])
  end
end

puts 'Cleaning up...'
untracked_paths_list.each do |path|
  puts "- #{path}"
  system("rm -rf ./#{path}")
end

puts 'Done.'
