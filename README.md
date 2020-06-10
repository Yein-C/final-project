 이 프로젝트는 기기가 과열될 때 자동으로 꺼질 수 있도록 하는 프로젝트입니다.

참고
----
온도 확인 방법 대표 3가지
 - temp  (#4 참고)
 - 온도 범위에 따른 소리
 - raspcontrol  (같이 쓰면 좋은 것 확인)

온도 범위
 - T > 70'C : 3초 뒤 강제종료.
 - 70'c > T >= 65'C : 1분 뒤 강제종료.
 - 65'c > T >= 60'C : 사용 중 꺼질 수 있음.
 - 60'c > T >= 55'C : 잠시 쉬었다 하는 것 추천
 - 55'c > T >= 40'C : 표준
 - 0'c >= T : 1분 뒤 강제 종료
   * 강제종료를 종료 : sudo shutdown -c

nano
 - 선택하라고 하면 'nano' 선택 (여기에서는 반복 작업 만들 때)

주의!
=====

반드시 home에 위치한 상태에서 clone하세요.

시작 전 필수
------------
 - sudo apt-get update
 - sudo apt-get upgrade

있으면 좋은 것: sudo apt-get vim


# 1. git clone

	- cd ~ 또는 cd
	- git clone https://github.com/Yein-C/final-project.git

# 2. 소리를 위해서
	
	- sudo apt-get install alsa-utils
	- sudo amixer cset numid=3 n
	 (n= 0, 1, 2 / 0: auto, 1: 아날로그-사운드 잭, 2: hdmi)

	test:
	- aplay /usr/share/sounds/alsa/Front-Right.wav

	음량조절:
	- alsamixer

# 3. 컴파일

	- cd ~/final-project
	- g++ main.cpp -o main

# 4. 어느 위치에서든지 상관없이 온도 확인하고 싶을 때

	- alias temp='~/final-project/path'
	
	temp대신 원하는 다른 것 가능

# 5. 작업 중 반복 실행(예약)
	
	- crontab -e
	 
	 crontab -e : 예약 추가
	 crontab -l : 목록 확인
	 crontab -r : 예약 삭제
	
	# 으로 시작하는 주석들 맨 밑, 새로운 내용을 추가할 수 있는 곳
	- * * * * * ~/final-project/main
	
	.
	.
	# ~~~
	# ~~~
	* * * * * ~/final-project/main

	crontab 설명
	
	.---------------- 분 (0 - 59)
	|  .------------- 시간 (0 - 23)
	|  |  .---------- 일 (1 - 31)
	|  |  |  .------- 월 (1 - 12) OR jan,feb,mar,apr ...
	|  |  |  |  .---- 요일 (0 - 6) (Sunday=0 or 7) OR sun,mon,tue,wed,thu,fri,sat
	|  |  |  |  |
	*  *  *  *  * user-name command to be executed

	자세한 설명 및 참고
	 - cat /etc/crontab
	 - https://server-talk.tistory.com/10
	 - 
	
	주기 시간 변경
	* * * * * : 매 분마다
	*/10 * * * * : 10분마다
	
# 6. 터미널 시작 전, 시작할 때, 종료한 후 등등 상관없이 프로그램 유지

	- cd /etc/profile.d
	- sudo nano bash_completion.sh

	맨 밑 # 과 그 위 # 중간에 원하는 명령어 입력
	
	.
	.
	fi
	
	#
	
	~/final-project/maine
	
	#

## 같이 쓰면 좋은 '라즈베리파이 상태 확인하는 주소'raspcontrol' '

	- sudo apt-get install apache2
	- sudo service apache2 restart
	- sudo apt-get install postfix
	postfix configuration 여기서는 상관 없습니다.
 	전  no configuration으로 했습니다.
	
	- cd /var/www

	원래 있던 파일은 새로운 directory를 만들어 그 안에 집어 넣고
	아래 실행 
	- sudo git clone https://github.com/harmon25/raspcontrol.git
	- sudo vim /etc/raspcontrol/database.aptmnt

	{
		"user": " 큰 따옴표 안에 넣으세요. "
		"password": "   "
	}

	- sudo chmod 755 /etc/raspcontrol/database.aptmnt

	들어가는 법:
	 1. 자신의 라즈베리파이 주소 입력 후 raspcontrol 들어가기
	 2. "자신의 라즈베리파이 주소"/raspcontrol  (큰 따옴표 작성X)
	 3. "자신의 라즈베리파이 주소"/index.php  (큰 따옴표 작성X)

	방금 만든 ID, PASSWORD 입력
	
	체크표시  아무거나 클릭

	새로운 내용은 새로고침을 통해 확인할 수 있습니다.

	참고 (다 같은 내용)
	 https://archmond.net/?p=5761
	 http://www.rasplay.org/?p=1935
	 https://gitlab.com/blackout314/rctrl

### 유용성
	
	기기가 과열되어 망가지는 것을 방지한다.
	 - 라즈베리파이에 전원을 연결하고 방치되어 있을 때.
	 - 오랜 사용으로 기기가 과열된지도 모르고 사용 중 일 때.

### 개선방향

	더 많은 사운드와 센서를 통해
	사용자가 정보를 더 쉽게 깨달을 수 있게 할 것.


#### 기여한 것

	다른 사람의 아이디어:
	 raspcontrol

	그 외:
	 제가 직접 블로그 및 사이트들을 뒤져가며 혼자 만들었습니다.
