flags = [
'-Wall',
'-Wextra',
'-Werror',
'-Wc++98-compat',
'-Wno-long-long',
'-Wno-variadic-macros',
'-std=c++11',
'-isystem',
'../BoostParts',
]

def FlagsForFile( filename, **kwargs ):
    return {'flags': flags, 'do_cache': True}
