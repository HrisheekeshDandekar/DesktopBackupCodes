/***************************************************************
* 
* Program To Read and edit BMP files
* 
* Psudo Code
* Take input for the location of the file
* Display metadata of the file accurately
* Make provision to change meta data (some elements)
* Display the file as an image
* Make provisions to change some properties of the image 
* 
***************************************************************/
//
//#include<iostream>
//#include<string>
//#include<stdio.h>
//
//using namespace std;
//
//int main()
//{
//	string location = input_file_location();	//Take location Input
//
//	BMP test_file(location);	//Instance of a class
//
//	test_file.display_meta_data();		
//	test_file.update_meta_data();
//	test_file.display_image();
//}
//
//
//string input_file_location()
//{
//	string verified_location;
//	bool valid_location = false;
//
//	while (valid_location == false)
//	{
//		cout << "\nEnter location of the BMP file with doube forward salshes in place of forward slashes\n";
//		//getline(cin, valid_location,'\n');
//		cin >> verified_location;
//
//		//Check if path leads to a bmp file ,  set valid location to true
//	}
//}
//
//
//class BMP
//{
//public:
//
//	string path;
//	FILE* bmp_file;
//
//	BMP(string location)
//	{
//		path = location;
//	}
//		
//	void display_meta_data();
//	void update_meta_data();
//	void display_image();
//
//	~BMP()
//	{
//		fcloseall();
//	}
//};
//
//
//		/* ================== [BMP class functions] ================== */
//
//
//void BMP::display_meta_data()
//{
//	bmp_file = fopen(path.c_str(), "rb");
//
//
//	fclose(bmp_file);
//}
//
//
//void BMP::update_meta_data()
//{
//	bmp_file = fopen(path.c_str(), "wb");
//
//
//	fclose(bmp_file);
//}
//
//
//void BMP::display_image()
//{
//	bmp_file = fopen(path.c_str(), "rb");
//
//
//	fclose(bmp_file);
//}

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct BMP_reader
{
	ifstream image;

	char identification_two_b[2];
	char size_four_bytes[4];
	//int size_in_bytes;
	//uint32_t size_in_bytes;
	char reserved_one_two_b[2];
	char reserved_two_two_b[2];
	char pixal_array_start[4];

	void open_file(char* path);
	void read_header();
	void display_header();
};


int main()
{

	char file_path[] = "C:\\Users\\pc\\Desktop\\Test.bmp";

	BMP_reader reader_1;
	reader_1.open_file(file_path);
	reader_1.read_header();
	reader_1.display_header();
	return 0;

}


void BMP_reader::open_file(char* path)
{
	image.open(path, ios::in | ios::binary);
	if (!image.is_open())
	{
		cout << "\nCould not open file!";
	}
}

void BMP_reader::read_header()
{
	image.read(identification_two_b, 2);

	image.read(size_four_bytes, 4);
	//size_in_bytes = stoi(size_four_bytes, 0, 3);
	//image.read(reinterpret_cast<char*>(&size_in_bytes), 2);

	image.read(reserved_one_two_b, 2);
	image.read(reserved_two_two_b, 2);

	image.read(pixal_array_start, 4);
}

void BMP_reader::display_header()
{
	cout << "\n\t---------------- BMP header ----------------\n";
	cout << "\nFile identification : " << identification_two_b[0] << identification_two_b[1];
	//cout << "\nSize of bmp : " << size_in_bytes;
	cout << "\nSize in bytes : [" << size_four_bytes<<"]";
	cout << "\nReserved 1 : " << reserved_one_two_b;
	cout << "\nReserved 2 : " << reserved_two_two_b;
	cout << "\nPixal array starts at : " << pixal_array_start;
}



