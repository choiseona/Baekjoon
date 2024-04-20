function solution(spell, dic) {
    return dic.filter((word) => spell.every((target) => word.includes(target))).length ? 1 : 2
}
