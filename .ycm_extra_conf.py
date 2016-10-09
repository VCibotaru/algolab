flags = [
'-Wall',
'-Wextra',
'-Werror',
'-std=c++11',
'-Wno-long-long',
'-Wno-variadic-macros',
'-std=c++11',
'-isystem',
'../BoostParts',
'-isystem',
'/usr/local/Cellar/cgal/4.7/include/CGAL'
]

def FlagsForFile( filename, **kwargs ):
    return {'flags': flags, 'do_cache': True}
