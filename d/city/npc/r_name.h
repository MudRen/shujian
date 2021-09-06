// named.c
// By snowman@SJ 10/06/2000
//modified by campsun 2003/09/25
//ÐÞ¸ÄÄÚÈÝ£¬ÐÞ¸Äº¯Êýget_random_name,ÏÖÔÚ¿ÉÒÔÖ¸¶¨»ñµÃÃû×ÖµÄ×Ö·ûÊýÁ¿ÁË¡£
//¿ÉÒÔÖ¸¶¨È¡³öÃû×ÖÊÇ1-4¸öÖÐÎÄ×Ö£¬µ«ÊÇÇë²»Òª³¬¹ý4¸öÒÔÉÏ

//mapping get_random_name(int,int);
//mapping random_name(int,int);

string* f_name = ({
"°®", "°²",
"°Ø", "±«", "±´", "±å", "²·",
"²Ü", "á¯", "²ý", "³£", "³Â", "³É",
"´ô", "´÷", "µË", "µÒ", "µÚ", "¶­", "ñ¼",
"¶ú",
"·®", "·¶", "·½", "·Ñ", "·ë", "·ï", "·ü", "¸£", "¸¶",
"¸ð", "çÃ", "¹Ë", "¹Ø", "¹Ü",
"¹þ", "º«", "ºÂ", "ºÍ", "ºÎ", "ºØ", "ºò", "ºó", "ºú", "»¨", "»ª", "»ª", "»Æ", "»ô",
"¼Æ", "¼Í", "½ª", "½¯", "½ð", "êÃ",
"¿µ", "¿º", "¿Â", "¿×", "Øá", "¿ö",
"ÀÉ", "À×", "Àî", "Á®", "Áº", "ÁÖ", "Áè", "Áø", "Â¬", "Â³", "ÂÀ", "ÂÞ",
"Âí", "Ã©", "Ã«", "Ã×", "Ãç", "Ã÷", "Ä«", "Ä²", "ÄÂ",
"Äß", "Äê",
"ÅË", "ÅÓ", "Åí", "Æ¤", "Æ½",
"ÆÝ", "Æë", "Æî", "Ç®", "ÚÛ", "ÇØ", "ÇÙ", "³ð", "Çü",
"ÈÎ",
"Éµ", "ÉÌ", "ÉÛ", "ÙÜ", "Éò", "Ê©", "Ê¯", "Ê±", "Ê·", "Êæ", "Ë§", "Ë®", "ËÎ", "ËÕ", "Ëï",
"Ì¸", "ÌÀ", "ÌÆ", "ÌÕ", "ÌÙ", "Ù¡",
"Íò", "Íô", "Íõ", "Î¤", "Îº", "ÎÀ", "Îâ", "Îå", "Îé", "Úù",
"ÞÉ", "Ïî", "Ð¤", "Ð»", "ÐÜ", "Ðì", "Ðí", "Ñ¦",
"ÑÏ", "ÑÔ", "Ñî", "Ñô", "Ò¦", "Òæ", "Òó", "Òü", "Ó¢", "Ó¯", "ÓÈ", "ÓÐ", "ÓÝ", "Óà", "Óí", "Ó÷", "Ôª", "Ô¬", "ÔÀ", "ÀÖ", "ÔÆ",
"²Ø", "Õ¿", "ÕÂ", "ÕÅ", "ÕÔ", "Ö£", "Ö§", "ÖÓ", "ÖÜ", "Öì", "×£", "×Ú", "×Þ", "ñÒ", "×æ",

"°ÙÀï", "°ÛÉÍ",
"³þ½ú", "´¾ÓÚ", "µ¥ÓÚ",
"¶«·½", "¶«¹ù", "¶«ÃÅ", "¶ËÄ¾", "¶ÎÇ§",
"¹«Á¼", "¹«Ëï", "¹«Î÷", "¹«Ñò", "¹«Ò±", "¹ÈÁº", "¹éº£",
"ºÕÁ¬", "ºôÑÓ", "»Ê¸¦",
"¼Ð¹È",
"ÁºÇð", "Áîºü",
"Ä½ÈÝ",
"ÄÏ¹¬", "ÄÏ¹ù",
"Å·Ñô",
"å§Ñô",
"Æáµñ",
"ÈêÛ³",
"ÉÏ¹Ù", "ÉêÍÀ", "Ê¦¿Õ", "Ë¾Âí", "Ë¾Í½",
"Ì«Êå", "å£Ì¨", "Í¿ÇÕ", "ÍØÖº",
"Î¢Éú", "ÎÅÈË", "Î×Âí",
"Î÷ÃÅ", "ÏÄºò", "æøæá", "ÐùÔ¯",
"ÑÖ·¨", "ÑòÉà", "Î¾³Ù", "ÓîÎÄ", "ÀÖÕý",
"Ô×¸¸", "³¤Ëï", "ÖÓÀë", "ÖÙËï", "Öî¸ð", "ò§¿×", "×ÚÕþ", "×óÇð",
});

string* f_id = ({
"ai", "an",
"bo", "bao", "bei", "bian", "bo",
"cao", "cen", "chang", "chang", "chen", "cheng",
"dai", "dai", "deng", "di", "di", "dong", "dou",
"er",
"fan", "fan", "fang", "fei", "feng", "feng", "fu", "fu", "fu",
"ge", "gou", "gu", "guan", "guan",
"ha", "han", "hao", "he", "he", "he", "hou", "hou", "hu", "hua", "hua", "hua", "huang", "huo",
"ji", "ji", "jiang", "jiang", "jin", "jiu",
"kang", "kang", "ke", "kong", "kuai", "kuang",
"lang", "lei", "li", "lian", "liang", "lin", "ling", "liu", "lu", "lu", "lv", "luo",
"ma", "mao", "mao", "mi", "miao", "ming", "mo", "mou", "mu",
"ni", "nian",
"pan", "pang", "peng", "pi", "ping",
"qi", "qi", "qi", "qian", "qiao", "qin", "qin", "qiu", "qu",
"ren",
"sha", "shang", "shao", "she", "shen", "shi", "shi", "shi", "shi", "shu", "shuai", "shui", "song", "su", "sun",
"tan", "tang", "tang", "tao", "teng", "tong",
"wan", "wang", "wang", "wei", "wei", "wei", "wu", "wu", "wu", "wu",
"xi", "xiang", "xiao", "xie", "xiong", "xu", "xu", "xue",
"yan", "yan", "yang", "yang", "yao", "yi", "yin", "yin", "ying", "ying", "you", "you", "yu", "yu", "yu", "yu", "yuan", "yuan", "yue", "yue", "yun",
"zang", "zhan", "zhang", "zhang", "zhao", "zheng", "zhi", "zhong", "zhou", "zhu", "zhu", "zong", "zhou", "zhu", "zu",

"baili", "baishang",
"chujin", "chunyu", "chanyu",
"dongfang", "dongguo", "dongmen", "duanmu", "duanqian",
"gongliang", "gongsun", "gongxi", "gongyang", "gongye", "guliang", "guihai",
"helian", "huyan", "huangpu",
"jiagu",
"liangqiu", "linghu",
"murong",
"nangong", "nanguo",
"ouyang",
"puyang",
"qidiao",
"ruyan",
"shangguan", "shentu", "shikong", "sima", "situ",
"taishu", "tantai", "tuqin", "tuozhi",
"weisheng", "wenren", "wuma",
"ximen", "xiahou", "xiangsi", "xuanyuan",
"yanfa", "yangshe", "yuchi", "yuwen", "yuezheng",
"zaifu", "zhangsun", "zhongli", "zhongsun", "zhuge", "zhuankong", "zongzheng", "zuoqiu",
});

string* name_m = ({
"°²",
"°Ô", "°×", "°à", "±Ì", "±ó", "±ö", "²¨",
"²Å", "²Æ", "²ý", "³¤", "³¬", "³Ï", "´¨",
"´ó", "µÂ»ª", "¶¦", "¶¨", "¶°", "¶·", "¶à",
"·¢", "·¨", "·É", "·æ", "·ç", "·ò", "¸£", "¸£", "¸»",
"¸Ö", "î¸", "¸ß", "¹«", "¹á", "¹â", "¹ú",
"º£", "ºÆ", "ºÕ", "ºê", "»¢", "»ª", "»Ô",
"¼Ã", "êª", "¼á", "¼ü", "½¡", "½£", "½­", "½Ü", "½ð", "½ð", "½ø", "¾¸", "¾þ", "¿¡",
"¿µ", "¿É", "¿Ë", "¿ï",
"ÀÅ", "Àñ", "Á¼", "Á¼", "÷ë", "Áî", "Áú", "Â¡", "Â»",
"Âú", "Ãñ", "Ã÷", "Ãù",
"Äþ",
"Åà", "Åæ",
"Ææ", "Æô", "Ç¿", "Çì",
"ÈÊ", "ÈË", "ÈÙ", "Èô",
"É½", "Ê¢", "Ê¤", "Ê±", "ÊÀ", "ÊÙ", "Êå", "Ë³",
"Ì©", "ÌÎ", "Ìí", "Ìú", "Í¦", "Í¬",
"Íò", "Îª", "Î°", "ÎÄ", "Îä",
"Îõ", "ôË", "ÏÜ", "Ïé", "Ïé", "Ïþ", "Ð¡", "Ð¢", "ÐÛ", "ÐÛ", "Ðñ", "Ñ§ÓÑ",
"Ñî", "ÒÚ", "Òã", "Òå", "Òæ", "ÓÀ", "ÓÂ", "ÓÑ", "Óî", "Óð", "è¤", "ÔÀ",
"Õñ", "á¿", "Ö®", "Ö¾", "ÖÇ", "ÖÒ", "ÖÛ", "Öæ", "×Ó", "×Ô",
});

string* id_m = ({
"an",
"ba", "bai", "ban", "bi", "bin", "bin", "bo",
"cai", "cai", "chang", "chang", "chao", "cheng", "chuan",
"da", "dehua", "ding", "ding", "dong", "dou", "duo",
"fa", "fa", "fei", "feng", "feng", "fu", "fu", "fu", "fu",
"gang", "gang", "gao", "gong", "guan", "guang", "guo",
"hai", "hao", "he", "hong", "hu", "hua", "hui",
"ji", "ji", "jian", "jian", "jian", "jian", "jiang", "jie", "jin", "jin", "jin", "jing", "jun", "jun",
"kang", "ke", "ke", "kuang",
"lang", "li", "liang", "liang", "lin", "ling", "long", "long", "lu",
"man", "min", "ming", "ming",
"ning",
"pei", "pei",
"qi", "qi", "qiang", "qing",
"ren", "ren", "rong", "ruo",
"shan", "sheng", "sheng", "shi", "shi", "shou", "shu", "shun",
"tai", "tao", "tian", "tie", "ting", "tong",
"wan", "wei", "wei", "wen", "wu",
"xi", "xi", "xian", "xiang", "xiang", "xiao", "xiao", "xiao", "xiong", "xiong", "xu", "xueyou",
"yang", "yi", "yi", "yi", "yi", "yong", "yong", "you", "yu", "yu", "yu", "yue",
"zhen", "zheng", "zhi", "zhi", "zhi", "zhong", "zhou", "zhou", "zi", "zi",
});

string* name_g = ({     //Å®ÐÔ×¨ÓÃ
"°®",
"±¦îÎ", "±Ì",
"´º", "´ä",
"÷ì", "÷ìÓñ", "µ¤",
"·¼", "·Ò", "·ï", "Ü½",
"¹Ã",
"ºç", "ºì", "»¨", "»Ý", "»Û",
"½¿", "¾§", "¾²", "¾Õ", "¾ê",
"çæ",
"À¼", "á°", "Àò", "Àö", "Á«", "ÁÕ", "Áá",
"ÃÀ", "Ãô",
"Æ¼",
"Ù»", "ÇÙ", "ÇÛ", "Çà", "óä",
"ÈØ",
"æ©", "Êç",
"æÃ",
"Íñ",
"Ï¼", "ÏÍ", "Ïã", "ÏæÔÆ",
"æÌÈ»", "ÑÞ", "Ñà", "Ó¢", "çø", "Ó«", "Ó¯", "Ó±", "Óñ", "æÂ",
"Õæ", "Õä", "Öé",
});

string* id_g = ({
"ai",
"baochai", "bi",
"chun", "cui",
"dai", "daiyu", "dan",
"fang", "fen", "feng", "fu",
"gu",
"hong", "hong", "hua", "hui", "hui",
"jiao", "jing", "jing", "ju", "juan",
"ke",
"lan", "lan", "li", "li", "lian", "lin", "ling",
"mei", "min",
"ping",
"qian", "qin", "qin", "qing", "qing",
"rong",
"shan", "shu",
"ting",
"wan",
"xia", "xian", "xiang", "xiangyun",
"yanran", "yan", "yan", "ying", "ying", "ying", "ying", "ying", "yu", "yuan",
"zhen", "zhen", "zhu",
});

void create()
{
	seteuid(getuid());
	if (sizeof(f_name) != sizeof(f_id))
		write("ÐÕÊÏÓÐ´íÎó¡£\n");
	if (sizeof(name_m) != sizeof(id_m))
		write("ÄÐÃûÓÐ´íÎó¡£\n");
	if (sizeof(name_g) != sizeof(id_g))
		write("Å®ÃûÓÐ´íÎó¡£\n");
}

mapping get_random_name(int gender)
{
	string f_n, f_i, name_1, id_1, *ids;
	int i;

	i = random(sizeof(f_name));
	f_n = f_name[i];
	f_i = f_id[i];

	if (gender) {	// male
		i = random(sizeof(name_m));
		name_1 = name_m[i];
		id_1 = id_m[i];
		if ( random(10) > 6 ){
			i = random(sizeof(name_m));
			if (strlen(name_1+name_m[i]) <= 4) {
				name_1 += name_m[i];
				id_1 += id_m[i];
			}
		}
	} else {	// female
		i = random(sizeof(name_g));
		name_1 = name_g[i];
		id_1 = id_g[i];
		if (random(10) > 6) {
			i = random(sizeof(name_g));
			if (strlen(name_1+name_g[i]) <= 4) {
				name_1 += name_g[i];
				id_1 += id_g[i];
			}
		}
	}
	if (!NAME_D->valid_name(f_n + name_1))
		return get_random_name(gender);
	ids = ({ f_i+" "+id_1, f_i, id_1 });
/*
	switch (random(4)) {
		case 0:
			ids += ({ f_i });
			break;
		case 1:
			ids += ({ id_1 });
			break;
		case 2:
			ids += ({ f_i, id_1 });
	}
*/
	return ([
		"name" : f_n + name_1,
		"id" : ids,
	]);
}
