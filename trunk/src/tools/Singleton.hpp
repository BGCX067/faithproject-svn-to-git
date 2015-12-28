/**
 * Copyright (C) 2011 - Alexis Lucazeau
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/**
 * @file    Singleton.hpp
 * @brief   A template class defining singleton (WARNING: not thread safe (I think ...))
 * @author  Bertran Pierre - bertran.pierre@gmail.eu
 * @version 0.1
 * @date    03/07/2011 06:50:16 PM
 */

#ifndef FAITH_COMMON_UTILS_SINGLETON_HPP__
# define FAITH_COMMON_UTILS_SINGLETON_HPP__

# include <memory>

// # define SINGLETON_GIVE_RIGHTS(ClassName) friend class Faith::Common::Utils::Singleton<ClassName>;friend class std::auto_ptr<ClassName>

namespace Faith
{
    namespace Tools
    {
        template <typename T>
            class Singleton
            {
                public:
                    static T * getInstance()
                    {
                        if (!Singleton<T>::_instance.get())
                            Singleton<T>::_instance.reset(new T);
                        return Singleton<T>::_instance.get();
                    }

                    static void deleteInstance()
                    {
                        Singleton<T>::_instance.reset();
                    }

                protected:
                    // Protecting constructor and destructor
                    Singleton() {}
                    virtual ~Singleton() {}

                private:
                    // Protecting copy of singleton
                    Singleton(Singleton const &) {}

                    Singleton& operator=(Singleton const &) 
                    {
                        return (*this);
                    }

                private:
                    static std::unique_ptr<T> _instance;
            };

        // Initialise the static instance
        template <typename T>
            std::unique_ptr<T> Singleton<T>::_instance;
    }
}

#endif // FAITH_COMMON_UTILS_SINGLETON_HPP__
