/*******************************************************************\

Module: Misc Utilities

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <util/array_name.h>
#include <util/irep2_expr.h>

std::string array_name(const namespacet &ns, const expr2tc &expr)
{
  if(is_index2t(expr))
  {
    return array_name(ns, to_index2t(expr).source_value) + "[]";
  }
  if(is_symbol2t(expr))
  {
    const symbolt &symbol = ns.lookup(to_symbol2t(expr).thename);
    return "array `" + id2string(symbol.base_name) + "'";
  }
  else if(is_constant_string2t(expr))
  {
    return "string";
  }

  return "array";
}
