{
  'targets': [
    {
      'target_name': 'culture-native',
      'conditions': [
        ['OS=="win"', {
          'defines': [
            '_WIN32_WINNT=0x0600',
            'WINVER=0x0600',
          ],
          'sources': [ 'src/culture.cc' ],
          'include_dirs': ["<!(node -e \"require('nan')\")"],
          'cflags!': [ '-fno-exceptions' ],
          'cflags_cc!': [ '-fno-exceptions' ],
          'msvs_settings': {
            'VCCLCompilerTool': { 'ExceptionHandling': 1 },
          }
        }],
        ['OS=="mac"', {
          'defines': [
          ],
          'sources': [ 'src/culture.cc' ],
          'include_dirs': ["<!(node -e \"require('nan')\")"],
          'cflags!': [ '-fno-exceptions' ],
          'cflags_cc!': [ '-fno-exceptions' ],
          'xcode_settings': {
              'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          }
        }]
      ]
    }
  ]
}