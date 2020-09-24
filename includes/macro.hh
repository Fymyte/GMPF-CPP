//
// Created by Pierrick on 22/09/2020.
//

#pragma once

#define CONNECT_SIGNAL(_type, _name, _signal, _function, _builder)                                                     \
  _type* _name;                                                                                                        \
  _builder->get_widget(#_name, _name);                                                                                 \
  _name->signal_##_signal().connect(sigc::ptr_fun(&_function));

#define GET_UI(_type, _var, _name)                                                                                     \
  _type* _var;                                                                                                         \
  GlobalData::getBuilder()->get_widget(#_name, _var);
