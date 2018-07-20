{
  'targets': [
    {
      'target_name': 'culture-native',
      'sources': [ 'src/culture.cc' ],
      'include_dirs': ["<!(node -e \"require('nan')\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'conditions': [
        ['OS=="win"', {
          'defines': [
            '_WIN32_WINNT=0x0600',
            'WINVER=0x0600',
          ],
          'msvs_settings': {
            'VCCLCompilerTool': { 'ExceptionHandling': 1 },
          }
        }],
        ['OS=="mac"', {
          'defines': [
          ],
          'xcode_settings': {
              'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          }
        }]
      ]
    }
  ]
}
