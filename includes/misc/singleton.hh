//
// Created by Pierrick on 06/10/2020.
//

#pragma once

#pragma once

#include <iostream>
#include <memory>
#include <string>

template<class T>
class Singleton {
public:
 Singleton(Singleton const&) = delete;
 Singleton& operator=(Singleton const&) = delete;

 static T& instance() {
   static T instance_;
   return instance_;
 }
protected:
 Singleton() = default;
};