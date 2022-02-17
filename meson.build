project('Boomerangd', 'c')

include = include_directories('include')

threads = dependency('threads')

executable( 'Boomerangd',

          ['src/util/flags.c',
           'src/util/util.c',
           'src/network/thread_start.c',
           'src/main.c'],

           dependencies: [threads],
           include_directories:[include]
)