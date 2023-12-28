/*
 * Copyright (c) 2023, ke0na
 *
 * Version: 1.0.0
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <iostream>

#ifndef LG_LG_H
#define LG_LG_H

namespace lg {

struct Param {
  enum ParamType { Int, Float, Double, String, Char };
  Param(int number) {
    m_data.INT = number;
    m_type = Int;
  }
  Param(char character) {
    m_data.CHAR = character;
    m_type = Char;
  }
  Param(float number) {
    m_data.FLOAT = number;
    m_type = Float;
  }
  Param(double number) {
    m_data.DOUBLE = number;
    m_type = Double;
  }
  Param(const char *string_value) {
    m_data.STRING = string_value;
    m_type = String;
  }

  ParamType get_type() const { return m_type; }
  int get_int() const { return m_data.INT; }
  float get_float() const { return m_data.FLOAT; }
  double get_double() const { return m_data.DOUBLE; }
  const char *get_string() const { return m_data.STRING; }
  const char get_char() const { return m_data.CHAR; }

private:
  ParamType m_type;
  union {
    int INT;
    float FLOAT;
    double DOUBLE;
    const char *STRING;
    char CHAR;
  } m_data;
};

template <class... Args>
static void print_imp(const std::string message, bool newline,
                      const Args &...args) {
  std::vector<Param> params = {args...};
  auto param_position = 0;
  for (unsigned int index = 0; index < message.length(); index++) {
    auto character = message[index];
    auto next_character = message[index + 1];
    if (character == '{' && next_character == '}') {
      auto param = params.at(param_position);
      auto param_type = param.get_type();
      param_position++;
      switch (param_type) {
      case Param::Int:
        std::cout << param.get_int();
        index++;
        continue;
      case Param::Float:
        std::cout << param.get_float();
        index++;
        continue;
      case Param::Double:
        std::cout << param.get_double();
        index++;
        continue;
      case Param::String:
        std::cout << param.get_string();
        index++;
        continue;
      case Param::Char:
        std::cout << param.get_char();
        index++;
        continue;
      }
    } else {
      std::cout << character;
    }
  }

  if (newline)
    std::cout << std::endl;
}

template <class... Args> static void out(std::string message, Args... args) {
  print_imp(message, false, Param(args)...);
}

template <class... Args> static void outln(std::string message, Args... args) {
  print_imp(message, true, Param(args)...);
}

} // namespace lg

#endif // LG_LG_H
