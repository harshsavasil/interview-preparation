def palin_subseq(l,r):
    print word,l,r
    if r<0 or l>=len(word):
        return 0
    if word[l]==word[r]:
        return 1 + int(palin_subseq(l+1,r)) + int(palin_subseq(l,r-1))
    else:
        return int(palin_subseq(l+1,r)) + int(palin_subseq(l,r-1)) - int(palin_subseq(l+1,r-1))

if __name__ == '__main__':
    word = "dbabd"
    print palin_subseq(0,len(word)-1)
