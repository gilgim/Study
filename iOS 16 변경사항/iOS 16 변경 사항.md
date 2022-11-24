# iOS 16 변경점 정리

## 사용자 측면
- 사용자 잠금화면 활성화되었다.
- 잠금화면에서 위젯 활성화되었다.
- 알림 시 잠금화면을 가리지 않게 하단에서 팝업된다.
- 집중모드 마다 잠금화면과 홈화면을 다르게 설정 가능하다.
- 배경을 제거한 인물, 동물 등 객체만 복사 가능해졌다.
- 사진에서의 텍스트 번역이 가능해졌다.
- 붙여넣기 시 사용자에게 허용 권한이 부여되었다.
- 건강-복용약 기록 기능이 추가되었다.
- 쌍자음 기능이 사라졌다. ㄸㄸㄸㄸㄸ -> ㄷㄷㄷㄷㄷㄷㄷㄷㄷㄷㄷㄷ
- Safari 웹사이트 번역에 한국어가 추가되었다.
- iPhone 8 부터 지원이 된다. (SE는 1세대는 제외되었다.)

## 개발자 측면
## Deprecated API
- FTP 관련 함수는 URLSession에서 제외되었다.
- UiViewController에서 shouldAutorotate가 제외되었다. (뷰를 자동 회전할 지 결정하는 값)
- attemptRotationToDeviceOrientation 가 setNeedsUpdateOfSupportedInterfaceOrientations 로 대치 되었다. (모든 창을 장치 방향으로 회전 시키는 함수)

### TextKit
- TextKit 2가 개선되었다.
- 텍스트 뷰 전환 시 코드를 사용하지 않는다. 그래서 더 빠르다.
- iOS 15에서는 일부 적용가능 했던 TextKit 2가 iOS 16에선 모든 부분이 적용되었다.
- 텍스트가 이미지를 감싸는 형태를 구현가능하다.
- 양쪽 정렬 줄 바꿈을 일정하게 설정가능하다.

<변경 전>
![이름](./iOS 16 변경사항/Pasted image 20220818091719.png)


<변경 후>
![[Pasted image 20220818091749.png]]

- NSTextList를 사용해 텍스트 목록을 나타낼 수 있다.(iOS7, 일부 iOS 16)
	- 목록은 트리구조를 이루기 때문에 NSTextElement를 이용하여 구현 할 수 있다. 
```swift
let myList = NSTextList(markerFormat: .disc, option:0)
	mitableParagraphStyle.textLists = [myList]
```

- 단일 행의 스트링만 표현 가능한 NSRange를 NSTextRange를 이용해 계층적 접근이 가능하게 만들었다. (iOS15)

**TextKit 2하위목록**
1. UITextView
2. UITextField
3. UILabel

	**UITextView, NSTextView에서 TextKit 2 사용법**
* init 시 usingTextLayoutManager 값을 true로 바꿔 사용 가능하다.
- 지원하지 않는 버전 사용 시 체크 할 점
```swift
	if let textLayoutManager = textView.textLayoutManger{
	}
	else{
		let layoutManager = textView.layoutManager
	}
```
___
### UISheetPresentationController
- 뷰를 Alert 해주는 컨트롤러
- 기존 하단에서 팝업되는 뷰의 크기를 조정할 수 있게 변경되었다.

```swift
let sheet = UISheetPresentationController()
sheet.detents = [
            .large(),
            .custom{ context in
                0.3*context.maximumDetentValus
            }
        ]
```

![[Pasted image 20220822151452.png]]

---
### UINavigationItem (iOS 16.0+)
- 브라우저 스타일 : 폴더나 탐색 뷰에 적합하다.
- 편집기 스타일 : 문서나 데이터를 편집할 때 적합하다.
___
### UICalendarView (iOS 16.0+)
- FSCalendar사용 없이 Calendar을 사용할 수 있게 되었다.
- tableView 처럼 delegate 채택 시 함수를 이용하여 각 요소의 접근 할 수 있다.
___
### PageControllerView (일부 iOS 16.0+)
- updateCurrentPageDisplay는 더 이상 사용되지 않는다.
	- 페이지 지시자를 업데이트 하는 함수인데 Deprecated 되었다. 
- 페이지 indicator의 모양을 변경 할 수 있게 되었다.(iOS 16.0+)
---
### Symbols 4 (iOS 15.0+)
- 랜더링 모드의 추가
	Monochrome : 전체 동일 색상을 적용시킨다.
	Hierarchical : 색상의 명암 적용시킨다.
	palette : 두 가지의 색상을 적용 시킨다.
	+Multicolor : 여러가지의 색상 조합을 통해서 화려한 아이콘을 나타낼 수 있다.

- 가변 색상 
	가변 색상을 통해서 볼륨에 따라 색상이 변할 수 있다.
	좀 더 정확한 표현이 가능하다. 
	
	![[Pasted image 20220818110028.png]]

### SwiftUI
- UIKit과 SwiftUI의 연동을 쉽게 만들었다. 기능은UIKit로 UI는 SwiftUI로 좀 더 쉬운 코드 작성을 할 수 있게 되었다.
```swift
	cell.contentConfiguration = UIHostingConfiguration{
		SwiftUI code
	}
```
---
### APP Intents (iOS 16.0+)
- 사용자가 단축어나 시리를 통해 앱에 접근하게 해주는 라이브러리
- ParameterSummary : UI를 정의하는 시각요소에 대한 앱 Intents의 파라미터.
- 사용자의 앱 활용성을 위해 intents API를 사용한다.

### Xcode 14 변경점
- 30% 용량 감소로 다운로드, 설치속도가 빨라졌다.
- init 자동 완성. 아래의 형태의 init를 자동 완성 시켜준다.
```swift
class TestClass{
	let value1 : Any?
	let value2 : Any?
	let value3 : Any?
	init(value1:Any?, value2:Any?, value:Any?){
		self.value1 = value1
		self.value2 = value2
		self.value3 = value3					   
	}
}
```

### Swift
- 앱을 만드는 것이 아닌, 베어메탈 환경에서의 사용까지가 목표이기 때문에 지원 라이브러리와의 연관성을 줄이고 더 빠른 기본 구현으로 대체하였다.
- Secure Enclave Processor에서도 사용할 수 있게 되었다. 
- 언랩핑 값의 대입을 지울 수 있다
```swift  
if let value = value
-> if let value
```
- 정규식을 지원해 문자열을 자를 때 긴 코드가 필요하지 않게 되었다.
- 복잡한 클로저의 리턴 타입을 수동으로 지정하지 않아도 사용하거나 호출 가능해졌다.
-  프로토콜을 제네릭 값으로 사용가능해졌다. 많은 요소에서 사용가능하게 되었다.
``` swift
typealias AnySprocket = any Sprocket
private var box: any Sprocket
```
- 프로토콜을 매개변수, 제네릭, 배열의 초기 타입 등 정해지지 않은 값에 대해 프로토콜 타입을 할당하고 싶을 때 any 키워드를 붙이는게 권장사항이 되었다.
```swift
protocol ptl{
			 
}
func test(value: any ptl){
	
}
```
### 정규식(Regex, iOS 16.0+) 
- 정규식을 다음과 같은 코드로 표현할 수 있게 되었다. 
```swift
let digits = /\d+/
```
- 정규식만 익히면 문자를 trim 하기 쉬워졌다.


## 스타벅스 앱 변경 및 개선 사항
- iOS 16.0 이상에서 지원되는 사항이 많아 변경점이 많지 않지만 Xcode 14 와 Swfit 5.7 사용 시 개선점을 작성하였다.
- Xcode에서 해당 클래스에 변수 값을 더 간편하게 확인 할 수 있게 되었다.  

 ![[Pasted image 20220825110527.png]]

- if let data = data 와 같은 스타벅스 소스 내에 많이 분포된 로직이 if let data 로 사용 가능해지면서 로직이 짧아졌다.
- init의 자동 완성으로 좀 더 빠른 로직 작성이 가능하다.
