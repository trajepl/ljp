static int hash(int h) { 
	h ^= (h >>> 20) ^ (h >>> 12);
	return h ^ (h >>> 7) ^ (h >>> 4);
}

/* 我们知道对于HashMap的table而言，数据分布需要均匀（最好每项都只有一个元素，这样就可以直接找到），不能太紧也不能太松，太紧会导致查询速度慢，太松则浪费空间。计算hash值后，怎么才能保证table元素分布均与呢？我们会想到取模，但是由于取模的消耗较大，HashMap是这样处理的：调用indexFor方法。
*/

static int indexFor(int h, int length) {
	return h & (length-1); 
}



