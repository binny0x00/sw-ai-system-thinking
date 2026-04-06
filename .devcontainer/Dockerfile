# 베이스 이미지: 최신 Ubuntu 사용
FROM ubuntu:latest

# 타임존을 서울로 설정, 로케일을 한국어(UTF-8)로 설정
ENV TZ=Asia/Seoul LANG=ko_KR.UTF-8 LANGUAGE=ko_KR.UTF-8

# 패키지 목록 업데이트 후 필요한 패키지 설치
# DEBIAN_FRONTEND=noninteractive: apt 설치 중 대화형 입력 프롬프트 비활성화
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    locales tzdata build-essential sudo gdb vim curl git wget \
    # locales tzdata: 언어/타임존 설정
    # build-essential: gcc, g++, make 등 C 빌드 도구 묶음
    # gdb: GNU 디버거 (중단점, 변수 추적 등)
    # valgrind: 메모리 누수 검사 도구
    # net-tools iproute2 telnet: 네트워크 유틸리티
    python3 cmake make gcc sudo valgrind telnet net-tools iproute2\
    && locale-gen ko_KR.UTF-8 && update-locale LANG=ko_KR.UTF-8
    # locale-gen: ko_KR.UTF-8 로케일 생성
    # update-locale: 기본 로케일 적용

# 'jungle' 사용자 생성 (-m: 홈 디렉토리 생성, -s: 기본 쉘 bash)
# sudo 그룹에 추가하여 관리자 권한 부여
RUN useradd -m -s /bin/bash jungle && usermod -aG sudo jungle

# jungle 사용자의 비밀번호를 'jungle'로 설정
RUN echo 'jungle:jungle' | chpasswd

# 이후 명령은 jungle 사용자로 실행 (root 권한 최소화)
USER jungle
# 컨테이너 기본 작업 디렉토리 설정
WORKDIR /home/jungle