#include<iostream>
#include<string>

using namespace std;

string reduce_file_path(string path)
{

	if (path[0] == '/' && path[1] == '.' && path[2] == '.' && path[3] == '/')
	{
		path.erase(0, 3);
	}

	if(path.length() > 4)
	{
		for (int i = 1; i < path.length()-3; i++)
		{
			if(path[i] == '/' && 
			   path[i + 1] == '.' &&
			   path[i + 2] == '.' && 
			   path[i + 3] == '/')
			{
				for (int j = i - 1 ; j > -1; j--)
				{
					if (path[j] == '/')
					{
						path.erase(j, i - j);
						break;
					}
				}
			}
		}
	}

	for(int i = 0; i < path.length(); i++)
	{
		if (path[i] == '.')
		{
			path[i] = '/';
		}
	}

	for (int i = 0; i < path.length(); i++)
	{
		while(path[i] == '/' && path[i+1] == '/')
		{
			path.erase(i, 1);
		}
	
		if(path[path.length()-1] == '/' && path.length() > 1)
		{
			path.erase(path.length() - 1, 1);
		}
	}
	return path;
}


int main()
{
	cout << reduce_file_path("/") << endl;
	cout << reduce_file_path("/srv/../")<<endl;
	cout << reduce_file_path("/srv/www/htdocs/wtf/") << endl;
	cout << reduce_file_path("/srv/www/htdocs/wtf") << endl;
	cout << reduce_file_path("/srv/./././././") << endl;
	cout << reduce_file_path("/etc//wtf/") << endl;
	cout << reduce_file_path("/etc/../etc/../etc/../") << endl;
	cout << reduce_file_path("//////////////") << endl;
	cout << reduce_file_path("/../") << endl;
	system ("pause");
	return 0;
}
