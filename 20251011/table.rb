# frozen_string_literal: true

require 'bundler/inline'

gemfile(true) do
  source 'https://rubygems.org'

  gem 'activerecord'
  gem 'sqlite3'
end

require 'active_record'
require 'minitest/autorun'
require 'logger'

ActiveRecord::Base.establish_connection(adapter: :sqlite3, database: ':memory:')
ActiveRecord::Base.logger = Logger.new($stdout)

ActiveRecord::Schema.define do
  create_table :companies, force: true do |t|
    t.string :code, null: false
    t.string :name, null: false
  end

  create_table :departments, force: true do |t|
    t.string :code, null: false
    t.string :name, null: false
  end

  create_table :employees, force: true do |t|
    t.references :company, null: false, foreign_key: true
    t.references :department, null: false, foreign_key: true
    t.string :code, null: false
    t.bigint :year, null: false
    t.string :full_name, null: false
  end
end

class Company < ActiveRecord::Base
  has_many :employees
end

class Department < ActiveRecord::Base
  has_many :employees
end

class Employee < ActiveRecord::Base
  belongs_to :company
  belongs_to :department
end

class Irononamae < Minitest::Test
  def test_sakura
    ActiveRecord::Base.transaction do
      company = Company.create!(code: 'C0001', name: 'A商事')
      department = Department.create!(code: 'D01', name: '開発')

      Employee.create!(company: company, department: department, code: '000A', year: 40, full_name: '加藤')
    end

    assert_equal Company.count, 1
    assert_equal Department.count, 1
    assert_equal Employee.count, 1
  end
end
