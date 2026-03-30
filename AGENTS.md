# Project: C Banking System

## 1. Goal
이 프로젝트는 C 언어 기반으로 구현하는 간단한 은행 시스템 포트폴리오 프로젝트이다.

목표:
- C 언어 핵심 개념 (포인터, 구조체, 파일 I/O) 숙련
- 시스템 프로그래밍 스타일 코드 작성
- 실제 서비스 구조를 단순화하여 구현
- 유지보수 가능한 코드 구조 설계

---

## 2. Features (Planned)

다음 기능을 단계적으로 구현한다:

- 계좌 생성 (Create Account)
- 계좌 조회 (View Account)
- 입금 (Deposit)
- 출금 (Withdraw)
- 계좌 목록 출력
- 파일 저장 및 불러오기 (Persistence)

---

## 3. Directory Structure

Codex는 다음 구조를 기본으로 사용한다:

- src/        : 소스 코드 (.c)
- include/    : 헤더 파일 (.h)
- build/      : 빌드 결과물 (git ignore 대상)
- data/       : 계좌 데이터 파일
- docs/       : 문서

필요 시 Codex가 생성 가능

---

## 4. Build & Run

### Windows (gcc 기준)

```bash
gcc -Wall -Wextra -o build/main.exe src/main.c
./build/main.exe