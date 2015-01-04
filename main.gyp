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
			'sources': [
				'src/main.cpp',
			],
			'cflags': [
				'-Wall',
				'-std=c++11',
			],
		},
	],
}
