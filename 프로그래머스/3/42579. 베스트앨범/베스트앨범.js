function solution(genres, plays) {
    const answer = [];
    const genreTotalPlayCount = {};
    const genreChoiceCount = {};
    
    // 노래들 하나의 객체로 나타내기
    const songArray = genres.map((e, i) => ({genre:e, play: plays[i], index:i}));
    
    // 장르별 총 play 횟수 구하기
    songArray.forEach((e) => {
        const { genre, play } = e;
        genreTotalPlayCount[genre] = (genreTotalPlayCount[genre] || 0) + play;
    })
    
    //구한 장르별 총 play 횟수 객체에 추가하기
    const newSongArray = songArray.map((e,i) => {
        const {genre} = e;
        return {...e, genreTotal:genreTotalPlayCount[genre]};
    })
    
    // 장르별 play 수로 정렬 => 개별 play 수로 정렬 
    const sortedSongArray = newSongArray.sort((a,b) => b.genreTotal - a.genreTotal || b.play - a.play);
   
    // 장르별로 2개 선택
    sortedSongArray.forEach((e) => {
        const {genre, index} = e;
        if(genreChoiceCount[genre] > 2) return;
        answer.push(index);
        genreChoiceCount[genre] = (genreChoiceCount[genre] || 1) + 1;
    })
    
    return answer;

}
