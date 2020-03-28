![8520ecba-fa49-422e-911f-42eb22554ee3](https://i.imgur.com/ueFx5Sv.jpg)
# Project Together
*You can also see process of Project at [Notion](https://www.notion.so/rukasp/Project-Together-ecc53d8874ed4d47948afb8b53c7d10e)*

1. [Game Story](#Game-Story)
2. [Game System](#Game-System)
3. [Screenshots](https://rukasp.xyz/read-me-1)


## Game Story
*In progress*

## Game System
### 상대적 소리
#### 상대적 소리 강도 측정법
- 적과의 거리를 적당히(10000) 나눈 값에, Stimulus Strength를 곱한 값을 사용
#### Stimulus Strength
|항목|Strength|
|----|--------|
|Player-Walk|0.2|
|Player-Jog|0.4|
|Player-Sprint|1|
### Doll Behavior
#### 일반적 행동
- 소리의 강도에 따라서 행동이 달라짐
- 소리의 종류를 구분할 수 있음
  - 발소리
  - 서랍을 여는 소리
  - 스위치를 켜는 소리
  - 플래시라이트를 켜는 소리
  - [문 열고 닫는 소리](#문-열고-닫는-소리-이벤트)
  - 권총을 장전하는 소리
  - 권총을 발사하는 소리
  - 아이템을 던졌을 때의 소리
- 플레이어와의 거리가 너무 멀어질 시 자동 텔레포트를 통해 조우 확률을 높임 (거리는 기숙사 끝에서 학교 끝 거리 정도를 마지노선으로)

아래는 [문 열고 닫는 소리](#문-열고-닫는-소리-이벤트) 를 제외한 모든 소리 통용임

#### 소리 강도 0
##### 일반적으로 Hall을 순찰함
- Area 단위로 움직임
  - Area 내부의 랜덤 포인트를 생성한 뒤 그곳으로 이동
- Hall Area를 원형으로 돌며 순찰함

##### 특정 확률로 다음과 같은 행동을 보임
- 원형으로 도는 방향이 바뀜(시계 -> 반시계)
- 방으로 진입하여 탐색함
  - 잠겨 있지 않은 가장 가까운 방을 찾음
  - 방 내부에 랜덤 포인트 하나를 생성한 뒤 그곳으로 이동
  - 일정 시간 대기하다가 자극이 없을 시 밖으로 나감
- 층간 이동
  - 다른 층의 Hall Area를 타깃으로 둠
- 개별 스위치 끄기
  - 가장 가까운 스위치를 찾아 끔

##### 특정 시간마다 다음과 같은 행동을 보임
- 두꺼비집 내리기
  - 플레이 한 지 일정 시간이 지난 후 발생할 수 있음
  - 지하실로 내려가는 문이 잠겨있을 경우 열고 들어감
  - 두꺼비집을 내리고 문은 열려있는 상태로 나옴

#### 소리 강도 약함 (0 ~ 1)
*소리 강도가 약해 정확한 위치는 알 수 없다고 가정*
- 소리 발생 지점 Area로 걸어감
  - 만일 같은 Area에 있으면 발생 지점 위치로 걸어감
  - 중간에 문이 있으면 천천히 열고 들어감
#### 소리 강도 중간 (1 ~ 1.5)
*소리 강도가 약해 정확한 위치는 알 수 없다고 가정*
- 소리 발생 지점 Area로 뛰어감
  - 만일 같은 Area에 있으면 [소리 강도 강함](#소리-강도-강함)으로 인식
  - 중간에 문이 있으면 강하게 열고 들어감
#### 소리 강도 강함 (1.5 ~ 2)
- 소리 발생 지점 위치로 뛰어감
  - 중간에 문이 있으면 강하게 열고 들어감

#### 문 열고 닫는 소리 이벤트
##### 소리 강도 0 ~ 1.5 (약함, 중간)
- 소리가 난 Area Hall로 걷거나 뛰어감
- 그 Hall을 순찰하면서 방을 하나씩 열고 탐색하는 것을 반복 (방법은 방 진입 탐색방법과 같음)

##### 소리 강도 1.5 ~ 2 (강함)
- 소리 발생 지점 위치로 바로 뛰어감
