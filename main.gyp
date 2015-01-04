{
	'targets': [
		{
			'target_name': 'main_build',
			'type': 'none',
			'copies': [
				{
					'destination': '.',
					'files': [
						'out/Default/main',
					],
				},
			],
		},
		{
			'target_name': 'main',
			'type': 'executable',
			'include_dirs': [
				'.',
			],
			'sources': [
				'src/main.cpp',
				'src/test.cpp',
				'src/test.h',
				'src/stack.cpp',
				'src/stack.h',
			],
			'cflags': [
				'-Wall',
				'-std=c++11',
			],
		},
	],
}
