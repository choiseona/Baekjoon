function solution(want, number, discount) {
    // 원하는 제품들 모두 할인 가능할 때 회원가입, 할인 제품 하루에 하나만 구매 가능
    // want: 원하는 제품, number: 원하는 제품 수량, discount: 할인 제품
    // 모두 할인 받을 수 있는 회원등록 날짜 일수 반환, 불가능하면 0 반환
    
    let answer = 0;
    discount.forEach((goods, index) => {
        let subDiscount;
        if(index + 10 > discount.length)  subDiscount = discount.slice(index);
        else subDiscount = discount.slice(index, index+10);
       
        let isSuccess = true;
        for(let i=0; i<want.length; i++) {
            if(subDiscount.filter((element) => element === want[i]).length < number[i]) isSuccess = false;
        }
            
        if(isSuccess) answer++;
    })
   return answer;
}