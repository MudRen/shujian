// named.c
// By snowman@SJ 10/06/2000

string* f_name = ({
"��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "�", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "�", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "¬", "³", "��", "��", "½", "��", "��", "��", "��",
"��", "é", "ë", "��", "��", "��", "ī", "Ĳ", "��",
"��", "��", "��", "��",
"��", "��", "��", "Ƥ", "ƽ",
"��", "��", "��", "Ǯ", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��",
"��", "��", "��", "��", "ʩ", "ʯ", "ʱ", "ʷ", "��", "˧", "ˮ", "��", "��", "��", "ɣ", "��", "ɳ",
"̸", "��", "��", "��", "��", "١", "��", "̷", "ͯ",
"��", "��", "��", "Τ", "κ", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "Ф", "л", "��", "��", "��", "Ѧ", "��", "��", "��",
"��", "��", "��", "��", "Ҧ", "��", "��", "��", "Ӣ", "ӯ", "��", "��", "��", "��", "��", "��", "Ԫ", "Ԭ", "��", "��", "��", "Ҷ",
"��", "տ", "��", "��", "��", "֣", "֧", "��", "��", "��", "ף", "��", "��", "��", "��",

"����", "����",
"����", "����", "����",
"����", "����", "����", "��ľ", "��ǧ",
"����", "����", "����", "����", "��ұ", "����",
"����", "����", "�ʸ�",
"�й�",
"����", "���",
"Ľ��",
"�Ϲ�", "�Ϲ�",
"ŷ��",
"�Ϲ�", "����", "ʦ��", "˾��", "˾ͽ",
"̫��", "�̨",
"΢��", "����", "����",
"����", "�ĺ�", "����", "��ԯ",
"�ַ�", "����", "ξ��", "����", "����",
"�׸�", "����", "����", "����", "���", "��", "����", "����",
});

string* f_id = ({
"ai", "an", "ai", "ao",
"bo", "ban", "bao", "bei", "bian", "bo", "bai", "ba", "bao", "bao",
"cao", "cen", "chang", "chang", "chen", "cheng", "cai", "cui", "chi", "cheng",
"dai", "deng", "di", "di", "dong", "dou", "du", "ding",
"fan", "fan", "fang", "fei", "feng", "feng", "fu", "fu", "fu", "feng", "feng",
"ge", "gu", "guan", "guan", "guo", "gao", "guo", "gan", "gong",
"ha", "han", "hao", "he", "he", "hou","hu", "hua", "hua", "hua", "huang", "huo", "hong",
"ji", "ji", "jiang", "jiang", "jin", "jia", "jiao", "jiang",
"kang", "kang", "ke", "kong", "kuai", "kuang",
"lang", "lei", "li", "liu", "liang", "lin", "ling", "liu", "lu", "lu", "lv", "luo", "lu", "leng", "li", "long", "liao",
"ma", "mao", "mao", "mi", "miao", "ming", "mo", "mou", "mu",
"ni", "nian", "nan", "nie",
"pan", "pang", "peng", "pi", "ping",
"qi", "qi", "qi", "qian", "qiao", "qin", "qin", "qiu", "qu", "qu", "qiu", "qiu",
"ren", "ruan", "rui", "rong",
"shang", "shao", "she", "shen", "shi", "shi", "shi", "shi", "shu", "shuai", "shui", "song", "su", "sun", "sang", "shan", "sha",
"tan", "tang", "tang", "tao", "teng", "tong", "tian", "tan", "tong",
"wan", "wang", "wang", "wei", "wei", "wei", "wu", "wu", "wu", "wu", "wen", "wen",
"xi", "xiang", "xiao", "xie", "xiong", "xu", "xu", "xue", "xiao", "xia", "xu",
"yan", "yan", "yang", "yang", "yao", "yi", "yin", "yin", "ying", "ying", "you", "yu", "yu", "yu", "yu", "yu", "yuan", "yuan", "yue", "yue", "yun", "ye",
"zang", "zhan", "zhang", "zhang", "zhao", "zheng", "zhi", "zhong", "zhou", "zhu", "zhu", "zong", "zhou", "zhu", "zu",

"baili", "baishang",
"chujin", "chunyu", "chanyu",
"dongfang", "dongguo", "dongmen", "duanmu", "duanqian",
"gongliang", "gongsun", "gongxi", "gongyang", "gongye", "guliang",
"helian", "huyan", "huangpu",
"jiagu",
"liangqiu", "linghu",
"murong",
"nangong", "nanguo",
"ouyang",
"shangguan", "shentu", "shikong", "sima", "situ",
"taishu", "tantai",
"weisheng", "wenren", "wuma",
"ximen", "xiahou", "xiangsi", "xuanyuan",
"yanfa", "yangshe", "yuchi", "yuwen", "yuezheng",
"zaifu", "zhangsun", "zhongli", "zhongsun", "zhuge", "zhuankong", "zongzheng", "zuoqiu",
});

string* name_m = ({
"��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "¡", "»", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "ľ", "ı", "ï", "��", "��", "��", "��",
"��", "��", "�", "��", "��", "ũ", "��", "��", "��", "��",
"ŷ",
"��", "��", "��", "ƽ", "��", "��", "��", "��", "��", "Ʈ", "��", "�",
"��", "��", "ǿ", "��", "ǰ", "��", "Ⱥ", "Ȩ", "��", "Ǭ", "Ȫ", "��", "��", "��", "Ǳ", "ǫ", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "�", "Ȼ", "��", "��", "��", "��",
"ɽ", "ʢ", "ʤ", "ʱ", "��", "��", "��", "˳", "��", "˼", "��", "ɭ", "��", "��", "��", "˹", "��", "ʽ", "ʿ",
"̩", "��", "��", "��", "ͨ", "ͬ", "��", "ͼ", "��", "��", "��", "��", "��", "ͳ", "ͤ", "ͥ", "͢", "̹", "ͭ", "ͩ", "�", "̶", "��", "��",
"��", "Ϊ", "ΰ", "��", "��", "ά", "��", "��", "��", "ξ", "��", "Ψ", "�", "��", "��", "΢", "δ",
"��", "��", "��", "��", "��", "��", "��", "Т", "��", "��", "��", "��", "��", "��", "��", "ݷ", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "ԣ", "ԥ", "��", "��",
"��", "�", "֮", "־", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "־", "��",
// ��Цϵ��
"��ΰ",
"�»�",
"����",
"�ϴ�",
"��",
"����",
"����",
"С��",
"�ǳ�",
"ѧ��",
});

string* id_m = ({
"an", "ai", "ao", "ao", "ao",
"ba", "bai", "ban", "bi", "bin", "bin", "bo", "bu", "bu", "biao", "ben", "biao",
"cai", "cai", "chang", "chang", "chao", "cheng", "cheng", "chuan", "ce",
"da", "da", "ding", "ding", "dong", "dou", "duo", "de", "du", "du", "dang", "dai", "dong", "dong", "duan", "du", "deng", "di", "duan",
"fa", "fa", "fei", "feng", "feng", "fu", "fu", "fu", "fu", "fu", "feng", "feng", "fan", "feng",
"gang", "gang", "gao", "gong", "guan", "guang", "guo", "guo", "gong", "gang", "gen", "ge", "gui", "gui", "gong",
"hai", "hao", "he", "hong", "hu", "hua", "hui", "he", "he", "hou", "hou", "he", "han", "hua", "he", "hou", "huan", "hong", "hui", "hai",
"ji", "ji", "jian", "ji", "jian", "jian", "jiang", "jie", "jin", "jin", "jin", "jing", "jun", "jun", "jian", "jun", "jiu", "ju", "jun", "ji", "jia", "jia", "jia", "ji",
"kang", "ke", "ke", "kuang", "kai", "kong", "kuan", "kun", "kuo", "kai", "kun", "kui", "kui", "kui",
"lang", "li", "liang", "liang", "lin", "ling", "long", "long", "lu", "li", "li", "liu", "lie", "lv", "li", "lie", "lei", "liang", "lun", "lang", "lian",
"man", "min", "ming", "ming", "meng", "meng", "meng", "mu", "mou", "mao", "mai", "mu", "mie", "mai",
"ning", "nan", "nan", "nian", "neng", "nong", "nan", "nian", "na", "ni",
"ou",
"pei", "pei", "pu", "ping", "peng", "peng", "po", "po", "pei", "piao", "pi", "pu",
"qi", "qi", "qiang", "qing", "qian", "qi", "qun", "quan", "qin", "qian", "quan", "qing", "qing", "qiu", "qian", "qian", "qi", "qiong", "qi",
"ren", "ren", "rong", "ruo", "rui", "rui", "rui", "ran", "run", "ru", "ran", "rong",
"shan", "sheng", "sheng", "shi", "shi", "shou", "shu", "shun", "si", "si", "song", "sen", "shen", "sui", "sui", "si", "shi", "shi", "shi",
"tai", "tao", "tian", "tie", "tong", "tong", "tian", "tu", "tang", "teng", "tao", "tuo", "tao", "tong", "ting", "ting", "ting", "tan", "tong", "tong", "tao", "tan", "tao", "tang",
"wan", "wei", "wei", "wen", "wu", "wei", "wei", "wen", "weng", "wei", "wu", "wei", "wei", "wu", "wen", "wei", "wei",
"xi", "xi", "xian", "xiang", "xiang", "xiao", "xin", "xiao", "xiong", "xiong", "xu", "xi", "xi", "xin", "xin", "xin", "xing",
"yang", "yi", "yi", "yi", "yi", "yong", "yong", "you", "yu", "yu", "yu", "yue", "yi", "yi", "yi", "yi", "yi", "yu", "yu", "yu", "yu", "yin",
"zhen", "zheng", "zhi", "zhi", "zhi", "zhong", "zhou", "zhou", "zi", "zi", "zhong", "zuo", "zao", "zong", "zan", "zhi", "zhi", "zhi",

"chaowei",
"dehua",
"fucheng",
"mengda",
"runfa",
"tuozai",
"weijian",
"xiaochun",
"xingchi",
"xueyou",
});

string* name_g = ({     //Ů��ר��
"��",
"����", "��", "��֥",
"��", "��", "����",
"��", "����", "��",
"��", "��", "��", "ܽ",
"��",
"��", "��", "��", "��", "��",
"��", "��", "��", "��", "��",
"��",
"��", "�", "��", "��", "��", "��", "��",
"��", "��", "����",
"Ƽ", "��",
"ٻ", "��", "��", "��", "��", "��ϼ",
"��",
"�", "��",
"��",
"��",
"ϼ", "��", "��", "����", "����",
"��Ȼ", "��", "��", "Ӣ", "��", "ӫ", "ӯ", "ӱ", "��", "��",
"��", "��", "��",
});

string* id_g = ({
"ai",
"baochai", "bi", "baizhi",
"chun", "cui", "chuhong",
"dai", "daiyu", "dan",
"fang", "fen", "feng", "fu",
"gu",
"hong", "hong", "hua", "hui", "hui",
"jiao", "jing", "jing", "ju", "juan",
"ke",
"lan", "lan", "li", "li", "lian", "lin", "ling",
"mei", "min", "manyu",
"ping", "pei",
"qian", "qin", "qin", "qing", "qing", "qingxia",
"rong",
"shan", "shu",
"ting",
"wan",
"xia", "xian", "xiang", "xiangyun", "xifeng",
"yanran", "yan", "yan", "ying", "ying", "ying", "ying", "ying", "yu", "yuan",
"zhen", "zhen", "zhu",
});

void create()
{
	seteuid(getuid());
	if (sizeof(f_name) != sizeof(f_id))
		write("�����д���\n");
	if (sizeof(name_m) != sizeof(id_m))
		write("�����д���\n");
	if (sizeof(name_g) != sizeof(id_g))
		write("Ů���д���\n");
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
