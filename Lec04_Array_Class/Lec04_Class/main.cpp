//include "Complex.h"
//include "Car.h"
//include "SportsCar.h"
#include "Music.h"


int main()
{
	//music streaming service를 생성
	MusicStreamingService my_service("spotify");
	my_service.addMusic("CruelSummer", "TaylorSwift", "Lover", 2019);
	my_service.addMusic("HowSweet", "NewJeans", "Double Single", 2024);
	my_service.addMusic("BubbleGum", "NewJeans", "Double Single", 2024);
	my_service.addMusic("Whiplash", "aespa", "The 5th Mini Album", 2024);
	my_service.addMusic("Supernova", "aespa", "Pre-Release Single", 2024);
	// add by user
	// music 객체 선언 --> 사용자 입력받기 (cin사용)
	// 입력받은 값을 선언한 music 객체 맴버변수에 하나씩 채우기
	// 마지막으로 music 객체 my_service의 music_list에 push_back()


	// search music bt title
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	//search music by artist
	string artist_name;
	cout << "Enter the Artist Name: ";
	cin >> artist_name;
	vector<Music*> artist_result = my_service.searchByArtist(artist_name);
	if (artist_result.size() > 0) {
		cout << "Found: " << artist_result.size() << " songs by " << artist_name << " : " << endl;
		for (int i = 0; i < artist_result.size(); i++) {
			cout << artist_result[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not found" << endl;
	}
}