/*
.H file for	workerd.c

Created	by snowman@SJ 21/04/2001
Modified by augx@SJ 9/6/2001
Modified by Ciwei@SJ

Copyright 1997-2001 ShuJian MUD Wizard Group.
All rights reserved.

*/

#include <armor.h>

#define	USER_WEAPON	BINGQI_D("user_weapon")

#define	DEFAULT_SETTINGS  ([ \
	"wield_maxneili":	500,\
	"wield_neili":		50,\
	"wield_str":		18,\
	"long":			"",\
	"long2":		"",\
	"maker":		"",\
	"material":		"steel",\
	"wield_msg":		"$N��$n�������С�\n",\
	"unwield_msg":		"$N�����е�$n���¡�\n",\
	"utime":		0,\
	"no_sell":		1,\
	"imbued":		1,\
	"dur":			3000,\
])

nosave mapping MDESC_WEAPON = ([
	"hantie":         HIC"���꺮����"NOR,
	"xuantie":	  WHT"����"NOR,
	"shentie":        RED"��������"NOR,
	"jintie":         HIY"����"NOR,
	"ruanying":       HIW"����"NOR,
	"liuhuashi":      RED"����ʯ"NOR,
	"lushi":          HIG"��ʯ"NOR,
	"ruantie":        YEL"����"NOR,
	"shengtie":       YEL"����"NOR,
	"qingtong":       GRN"��ͭ"NOR,
	"default":        "����",
]);

nosave mapping MDESC_ARMOR = ([
	"longcansi":      HIY"�����˿"NOR,
	"tiancansi":      WHT"���˿"NOR,
	"bingcansi":      HIW"����˿"NOR,
	"yucansi":        GRN"���˿"NOR,
	"mumianhua":      HIY"ľ�޻�"NOR,
	"cansi":          HIW"��˿"NOR,
	"zhuma":          HIY"����"NOR,
	"dama":           YEL"����"NOR,
	"yama":           YEL"����"NOR,
	"mianhua":        HIW"�޻�"NOR,
	"default":        "����",
]);

nosave mapping	SPECIAL_B = ([
	"imbued":	       5,
	"material":	       "xuantie",
	"wield_maxneili":      6500,
	"wield_neili":	       1500,
	"wield_str":	       50,
	"wield_msg":	       HIG"\n$N�����ڷ���һ�ӣ������Ļ��Ǵ��ķ���������������һ�𡫡���һ��$n"HIG"�Ѿ�������$P���У�\n"NOR,
	"unwield_msg":	       HIG"\n$N��$n"HIG"����һ�ӣ�ֻ��$n"HIG"ͻȻ��û�죬���������Ļ�����ɢƮ���ˣ�\n"NOR,
	"dur":                 5000,
	]);
nosave mapping	SUPER_B	= ([
	"imbued":	       4,
	"material":	       "supersteel",
	"sharpness":	       3,
	"rigidity":	       3,
	"wield_maxneili":      4200,
	"wield_neili":	       1200,
	"wield_str":	       39,
	"wield_msg":	       HIW"\n$N����һ�ӣ�һ��$n"HIW"�����ɳ������һ�����Ѿ�������$P���С�\n"NOR,
	"unwield_msg":	       HIW"\n$N�����е�$n"HIW"һ���������ҫ�У��Ѳ�����$n"HIW"���ټ���\n"NOR,
	"dur":                 4500,
	]);
nosave mapping	GREAT_B	= ([
	"imbued":	       3,
	"material":	       "greatsteel",
	"sharpness":	       2,
	"rigidity":	       2,
	"wield_maxneili":      3300,
	"wield_neili":	       600,
	"wield_str":	       32,
	"wield_msg":	       "\n$N��һ��$n������������С�\n",
	"unwield_msg":	       "\n$N�����е�$n�Ż��������ҡ�\n",
	"dur":                 3800,
	]);
nosave mapping	GOOD_B = ([
	"imbued":	       2,
	"material":	       "steel",
	"sharpness":	       1,
	"rigidity":	       1,
	"wield_maxneili":      1500,
	"wield_neili":	       150,
	"wield_str":	       25,
	"dur":                 3350,
	]);

nosave mapping	WEAPON_MAP = ([
"sword"	: ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"jian",
	"skill_type":		"sword",
	"verbs":		({ "slash", "hack", "slice", "thrust" }),
	"unit":			"��",
	"weight":		12000,
	"flag":			4,]),
"xiao" : ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"xiao",
	"skill_type":		"sword",
	"verbs":		({ "slash", "hack", "slice", "thrust" }),
	"unit":			"ֻ",
	"weight":		5000,
	"flag":			8,]),
"axe" :	([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"fu",
	"skill_type":		"axe",
	"verbs":		({ "chop", "slice", "hack" }),
	"unit":			"��",
	"weight":		17500,
	"flag":			4,]),
"blade": ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"dao",
	"skill_type":		"blade",
	"verbs":		({ "slash", "slice", "hack" }),
	"unit":			"��",
	"weight":		15000,
	"flag":			4,]),
"brush": ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bi",
	"skill_type":		"brush",
	"verbs":		({ "pierce", "slice", "thrust" }),
	"unit":			"֧",
	"weight":		6000,
	"flag":			8,]),
"club":	([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"gun",
	"skill_type":		"club",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		17500,
	"flag":			16,]),
"dagger": ([
	"name":			"ذ",
	"basic_name":		"��",
	"b_id":			"bishou",
	"skill_type":		"dagger",
	"dagger_count":		5,
	"verbs":		({ "slice", "pierce", "thrust" }),
	"unit":			"��",
	"weight":		2000,
	"flag":			4,]),
"fork":	([
	"name":			"��",
	"basic_name":		"��",
	"skill_type":		"fork",
	"b_id":			"cha",
	"verbs":		({ "thrust", "pierce", "impale"	}),
	"unit":			"��",
	"weight":		15000,
	"flag":			8,]),
"hammer": ([
	"name":			"��",
	"basic_name":		"��ͷ",
	"b_id":			"chui",
	"skill_type":		"hammer",
	"rigidity":		1,
	"hammer_count":		5,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		26000,
	"flag":			1,]),
"hook":	([
	"name":			"��",
	"basic_name":		"����",
	"skill_type":		"hook",
	"b_id":			"gou",
	"verbs":		({ "impale", "slash", "hack", }),
	"unit":			"��",
	"weight":		15000,
	"flag":			4,]),
"spear": ([
	"name":			"ǹ",
	"basic_name":		"��",
	"b_id":			"qiang",
	"skill_type":		"spear",
	"verbs":		({ "thrust", "pierce", "impale"	}),
	"unit":			"��",
	"weight":		16000,
	"flag":			8,]),
"staff": ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"zhang",
	"skill_type":		"staff",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		22000,
	"flag":			16,]),
"stick": ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bang",
	"skill_type":		"stick",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		16000,
	"flag":			16,]),
"whip":	([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bian",
	"skill_type":		"whip",
	"verbs":		({ "whip" }),
	"unit":			"��",
	"weight":		8000,
	"flag":			0,]),
]);


nosave mapping	Special_Class =	([
RED"�ɽ�" : ([	"id": "ganjiang",
		"long2"	: RED"�ɽ������ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
                 "weapon_prop":         ([ "damage":270 ]),//180
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"Īа" : ([	"id": "moye",
		"long2"	: RED"Īа�����ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
                "weapon_prop":         ([ "damage":270 ]),//130
		"sharpness":	       15,
		"rigidity":	       9,
		]),
RED"�㳦" : ([	"id": "yuchang",
		"long2"	: RED"�㳦�����ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
                "weapon_prop":         ([ "damage":200 , "attack":150 ]),//100
		"sharpness":	       8,
		"rigidity":	       7,
		]),
RED"̫��" : ([	"id": "taie",
		"long2"	: RED"̫������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
                "weapon_prop":         ([ "damage":220 , "qi":5000 , "jing":2000 ]),//100
		"sharpness":	       7,
		"rigidity":	       9,
		]),
RED"����" : ([	"id": "juque",
		"long2"	: RED"���ڼ�Ӳ�ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
                "weapon_prop":         ([ "damage":270 ]),//120
		"sharpness":	       7,
		"rigidity":	       20,
		]),
RED"����" : ([	"id": "chungou",
		"long2"	: RED"������˧֮������֮�ܻӾ����򣬿˵���ʤ��\n"NOR,
                "weapon_prop":         ([ "damage":220 , "jingli":2000 , "neili":5000 ]),//120
		"sharpness":	       7,
		"rigidity":	       8,
		]),
RED"տ¬" : ([	"id": "zhanlu",
		"long2"	: RED"տ¬��������������Ӳ���ھ���������ǧ�������\n"NOR,
                "weapon_prop":         ([ "damage":300 ]),//160
		"sharpness":	       12,
		"rigidity":	       12,
		]),
RED"����" : ([	"id": "gongbu",
		"long2"	: RED"�����������죬���ܲ��̣�\n"NOR,
                "weapon_prop":         ([ "damage":200 , "attack":100 , "parry":175 , "dodge":175 ]),//70
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"ʤа" : ([	"id": "shengxie",
		"long2"	: RED"ʤа�����޴�����κ�Ҫ��\n"NOR,
                "weapon_prop":         ([ "damage":300 ]),//70
		"sharpness":	       8,
		"rigidity":	       9,
		"wield_maxneili":      0,
		"wield_neili":	       0,
		"wield_str":	       0,
		]),
RED"��Ȫ" : ([	"id": "longquan",
		"long2"	: RED"��Ȫ�˼伫Ʒ������������\n"NOR,
                "weapon_prop":         ([ "damage":320 , "dexerity":5 , "strength":5 , "constitution":5 , "intelligence":5 ]),
		"sharpness":	       9,
		"rigidity":	       7,
		]),
]);

nosave mapping	Super_Class = ([
	HIM"��ԯ" : ([	"id":	"xuanyuan",
			"long2": HIM"���ջƵ۳ִ�������ָ�ϳ��ϣ�������ɨ��������Ӧ�����ɣ������޶�ս��ȣ�\n"NOR,
		]),
	HIR"��ͨ" : ([	"id":	"shentong",
			"long2":	HIR"�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���\n"NOR,
		]),
	HIG"�޼�" : ([	"id":	"wuji",
			"long2": HIG"�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����\n"NOR,
		]),
	HIW"����" : ([	"id":	"bagua",
			"long2": HIW"�����С��ݡ����������ˡ����š�������������������������֮�𣬴��������򣬼����������һ��\n"NOR,
		]),
	HIB"������˹" :	([	"id":	"joeywus",
			"long2": HIB"������������ͳ�ε�ʱ��������ӵĽ�Ҳ��ֵ��ͷĸţ�ļ�Ǯ�����������Լ����ǰѴ���ʽ
�������������˹����˵�ǰ��˰���ġ�Τ�����������죬�˵����������\n"NOR,
		]),
	HIW"̫��" : ([	"id":	"taibai",
			"long2": HIW"
		�Կ��Ϻ�ӧ  �⹳˪ѩ��		�����հ���  ��������
		ʮ��ɱһ��  ǧ�ﲻ����		���˷���ȥ  ���������
		�й�������  �ѽ�ϥǰ��		���ˡ��캥  ����Ȱ����
		������Ȼŵ  ������Ϊ��		�ۻ�������  ����������
		���Իӽ��  ��������		ǧ���׳ʿ  ���մ�����
		����������  ��������Ӣ		˭�������  ����̫����\n"NOR,
		]),
	HIY"Ǭ��" : ([	"id":	"qiankun",
			"long2": HIY"�����������߷ֱ��Ժڰ����������������ɣ�һ��һ�ף��к�Ǭ������������֮������һ�����\n"NOR,
		]),
	HIY"̫��" : ([	"id":	"taiji",
			"long2": HIY"̫���ߣ��޼�����������֮ĸҲ����֮��֣���֮��ϡ��޹��������������졣
�˸�����ν֮�ߣ���˳�˱�ν֮ճ��������Ӧ���������档��仯��ˣ���
��Ϊһ�ᣡ\n"NOR,
		]),
	HIC"���" : ([	"id":	"tiandi",
			"long2": HIC"���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�\n"NOR,
		]),
	HIM"����" : ([	"id":	"fengyun",
			"long2": HIM"��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����\n"NOR,
		]),
	HIG"����" : ([	"id":	"haoqi",
			"long2": HIG"��غ���֮�����ɨħ������Ϊ��Ϊ����֮���ߣ�\n"NOR,
		]),
	HIR"����" : ([	"id":	"lianyu",
			"long2": HIR"��ʮ�������еأ������гǣ�������ǣ���С��ħ�������������ڴ��ֻ�������ν֮����������\n"NOR,
		]),
	HIC"����" : ([	"id":	"sanqing",
			"long2": HIC"����������������Σ������컯��һ�����壡����ǡ�����һ����塣��\n"NOR,
		]),
	HIC"����" : ([	"id":	"kunlun",
			"long2": HIC"	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ�
	����ʫ���ζϣ��Ϲ�����
	�ѽ���Ȼ�����޴��й��ۡ�

	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� \n"NOR,
		]),
]);

nosave mapping	Great_Class = ([
	CYN"����":	"diwang",	CYN"����":	"wangzhe",
	CYN"���":	"tianhou",	CYN"����":	"bawang",
	CYN"��ʥ":	"tiansheng",	CYN"����":	"shenwang",
	CYN"����":	"yaohou",	BLU"����":	"gonghou",
	BLU"ħ��":	"mowang",	BLU"����":	"qixing",
	BLU"���":	"egui",		GRN"����":	"yulong",
	GRN"���":	"yufeng",	GRN"�ɺ�":	"songhe",
	GRN"����":	"tianlong",	GRN"����":	"dilong",
	GRN"���":	"tianfeng",	GRN"�ط�":	"difeng",
	GRN"����":	"longxiang",	GRN"����":	"fengwu",
	HIG"��Ӱ":	"wuying",	HIG"�Ƽ�":	"pojia",
	HIG"����":	"feilong",	HIG"����":	"wuyi",
	HIG"����":	"niaoxiang",	HIG"����":	"wanpan",
	HIG"��Ƽ":	"qingping",	YEL"����":	"huanglong",
	WHT"����":	"yunti",	WHT"̫Ԩ":	"taiyuan",
	WHT"̫��":	"taifeng",	WHT"����":	"xuling",
	WHT"����":	"pili",		WHT"�׵�":	"leidian",
	WHT"����":	"fenglei",	WHT"���":	"zhendian",
	WHT"����":	"baiyu",	WHT"����":	"qingyu",
	WHT"����":	"ziyu",		WHT"����":	"lanyu",
	WHT"����":	"luyu",		WHT"����":	"huangyu",
	WHT"����":	"chiyu",	WHT"����":	"hongyu",
	CYN"���":	"qinghong",	CYN"�׺�":	"baihong",
	CYN"�Ϻ�":	"zihong",	CYN"����":	"lanhong",
	CYN"�̺�":	"luhong",	CYN"���":	"chihong",
	CYN"��Ӱ":	"huanying",	CYN"��˪":	"ningshuang",
	CYN"����":	"qingsuo",	MAG"����":	"tianlong",
	MAG"�ϵ�":	"zidian",	MAG"���":	"fenghuang",
	MAG"����":	"tianqu",	MAG"���":	"tianxuan",
	MAG"����":	"tianji",	MAG"��Ȩ":	"tianquan",
	MAG"���":	"yuheng",	MAG"����":	"kaiyang",
	MAG"ҡ��":	"yaoguang",	MAG"����":	"beidou",
	HIR"���":	"tianhuo",	HIR"����":	"qilin",
	HIR"��а":	"pixie",	YEL"���":	"hongjun",
	YEL"���":	"guangcheng",	YEL"���":	"jinguang",
	YEL"����":	"xiuluo",	YEL"ҹ��":	"yecha",
	YEL"����":	"yaochi",	YEL"���":	"leiheng",
	HIR"����":	"huolong",	HIC"����":	"binglong",
	HIB"����":	"heilong",	HIR"����":	"yanlong",
	HIC"����":	"qinglong",	HIR"��ȸ":	"zhuque",
	HIW"�׻�":	"baihu",	HIB"����":	"xuanwu",
	GRN"����":	"xuanji",	HIG"����":	"jiutian",
	HIG"����":	"jiuyou",	MAG"����":	"jiulong",
	MAG"����":	"wulong",	MAG"����":	"sanlong",
	WHT"����":	"shengsi",
]);

nosave string *G_3_class = ({
	"����",	"����",	"����",	"����",	"����",	"�ĺ�",	"���",	"��÷",
	"��Ȫ",	"��Ȫ",	"��Ȫ",	"��Ȫ",	"ŭ��",	"����",	"����",	"��ˮ",
	"��",	"��",	"С",	"��",	"��",	"��",	"��",	"��",
	"���",	"˫��",	"����",	"��ʤ",	"�⹳",	"�һ�",	"�޵�",	"˫��",
	"����",	"��Ů",	"����",	"����",	"����",	"��",	"����",	"�̹�",
	"����",	"��ˮ",	"ܽ��",	"��Ԩ",	"��ɽ",	"��",	"����",	"����",
	"����",	"��Ƥ",	"��ɽ",	"����",	"����",	"���",	"�׺�",	"����",
	"����",	"����",	"����",	"��β",	"���",	"���",	"����",	"����",
	"���",	"����",	"��ͷ",	"����",	"ţͷ",	"�л�",	"����",	"����",
	"����",	"�պ�",	"����",	"��ͷ",	"�ͻ�",	"���",	"��ˮ",	"����",
	"�޹�",	"����",	"���",	"���",	"����",	"��Ʒ",	"��ˮ",	"��ˮ",
	"���",	"�ط�",	"����",	"����",	"����",	"����",	"����",	"ħ��",
	"��ˮ",	"��ˮ",	"ħˮ",	"����",	"�岽",	"��Ҷ",	"��Ҷ",	"����",
	"����",	"����",	"ħ��",	"�˺�",	"����",	"�ͻ�",	"��ʨ",	"Х��",
	"�÷�",	"����",	"����",	"����",	"����",	"����",	"����",	"ʨ��",
	"Ұ��",	"����",	"����",	"����",	"��ʨ",	"��",	"��",	"��ӥ",
	"����",	"����",	"���",	"����",	"�ڷ�",	"����",	"����",	"����",
	"��ü",	"����",	"����",	"����",	"�촽",	"��",	"��ָ",	"�ر�",
	"����",	"����",	"ҹ��",	"��ݺ",	"����",	"����",	"����",	"����",
	"ҹ��",	"����",	"����",	"����",	"����",	"����",	"����",	"����",
	"����",	"����",	"����",	"ʨ��",	"�Ի�",	"����",	"�Ͼ�",	"��ĸ",
	"����",	"����",	"����",	"��İ",	"�ݺ�",	"����",	"����",	"���",
	"�ɰ�",	"����",	"���",	"����",	"����",	"���",	"ʥĸ",	"�Ĳ�",
	"��ʥ",	"����",	"����",	"����",	"����",	"��ѩ",	"Ʈѩ",	"��ѩ",
	"��ѩ",	"��ѩ",	"ѩ��",	"����",	"ϼε",	"��ϼ",	"����",	"嫺�",
	"ĵ��",	"�ٺ�",	"�׺�",	"����",	"����",	"���",	"��÷",	"����",
	"��˼",	"����",	"����",	"��ҩ",	"�ž�",	"õ��",	"�¼�",	"�ļ�",
	"ܽ��",	"Ǿޱ",	"����",	"��ʦ",	"ϴ��",	"����",	"����",	"��ħ",
	"����",	"����",	"����",	"����",	"��ޱ",	"ľ��",	"����",	"̫��",
	"���",	"���",	"�׺�",	"�Ϻ�",	"��ޱ",	"��ޱ",	"��ޱ",	"��ޱ",
	"��ޱ",	"����",	"����",	"����",	"����",	"���",	"��з",	"��ţ",
	"�۹�",	"����",	"����",	"����",	"����",	"����",	"����",	"��ɽ",
	"����",	"ժ��",	"̽��",	"����",	"����",	"��Ӱ",	"��ħ",	"����",
	"����",	"ǧ��",	"����",	"ǧâ",	"����",	"ħ��",	"���",
	"�Ͼ�",	"��ҳ",	"����",	"���",	"����",	"����",	"����",	"��ͼ",
	"Ѫն", "����", "����", "��â", "����", "����", "����", "����",
	"����", "Ӱ��", "���", "����", "˫��", "��ϼ", "����", "����",
	"����", "����", "�ۺ�", "��̳", "����", "����", "�ɷ�", "����",
	"��Ȫ",
});

/////////////////////////////// functions ////////////////////////
string s_good(int i)
{
	switch(i){
                case 10..99:    return "�ޱ�";
		case 9:		return "�ޱ�";
		case 8:		return "����";
		case 7:		return "����";
		case 6:		return "��Ϊ";
		case 5:		return "�൱";
		case 4:		return "ʮ��";
		case 3:		return "�ǳ�";
		case 2:		return "�Ƚ�";
		case 1:		return "����";
		case -1:	return "����ô";
		case -2:	return "�ܲ�";
		case -3:	return "����";
		default:	return "һ��";
	}
}

string s_power(int i)
{
	if( i >= 300 )	return HIW"�������"NOR;
	if( i >= 280 )	return HIW"��Ԫ����"NOR;
	if( i >= 250 )	return HIY"������˫"NOR;
	if( i >= 220 )	return HIY"��������"NOR;
	if( i >= 200 )	return HIM"������ƥ"NOR;
	if( i >= 180 )	return HIM"��������"NOR;
	if( i >= 160 )	return HIR"��������"NOR;
	if( i >= 140 )	return HIC"ն����ħ"NOR;
	if( i >= 120 )	return HIG"�����ױ�"NOR;
	if( i >= 100 )	return HIB"�������"NOR;
	if( i >= 80 )	return WHT"�ܸ�"NOR;
	if( i >= 60 )	return YEL"ˮ׼����"NOR;
	if( i >= 40 )	return MAG"����"NOR;
	if( i >	20 )	return RED"��С"NOR;
	if( i <= 0 )	return GRN"����"NOR;
	if( i <= -20 )	return BLU"����"NOR;
	return CYN"һ��"NOR;
}

// Important mapping for user_weapon.
nosave mapping	mp;
nosave string *special_st = ({});
nosave string *name_st	= ({});
/////////////////////////// armors //////////////////////////////
#define	USER_ARMOR	ARMOR_D("user_armor")

#define	ARMOR_DEFAULT_SETTINGS  ([ \
	"long":			"",\
	"long2":		"",\
	"maker":		"",\
	"material":		"mianbu",\
	"no_sell":		1,\
	"utime":		0,\
	"imbued":		1,\
	"wear_maxneili":	500,\
	"wear_con":		18,\
	"wear_str":		18,\
	"poisoned":		"",\
	"poison_number":	0,\
	"times":		100,\
	"max_dur":		2000,\
	"dur":			2000,\
])

nosave mapping	ARMOR_SPECIAL_B = ([
	"imbued":		5,
	"wear_maxneili":	6500,
	"wear_con":		50,
	"wear_str":		50,
	"max_dur":		3000,
	"times":		450,
	]);
nosave mapping	ARMOR_SUPER_B	= ([
	"imbued":		4,
	"wear_maxneili":	5000,
	"wear_con":		39,
	"wear_str":		39,
	"max_dur":		2800,
	"times":		350,
	]);
nosave mapping	ARMOR_GREAT_B	= ([
	"imbued":		3,
	"wear_maxneili":	3500,
	"wear_con":		32,
	"wear_str":		32,
	"times":		250,
	"max_dur":		2500,
	]);
nosave mapping	ARMOR_GOOD_B = ([
	"imbued":		2,
	"wear_maxneili":	1500,
	"wear_con":		26,
	"wear_str":		26,
	"times":		175,
	"max_dur":		2250,
	]);

nosave mapping	ARMOR_MAP = ([
"cap"	: ([
	"name":			"ͷ��",
	"armor_type":		TYPE_HEAD,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "armor" : 1 ]),
	"weight":		3500,]),
"glove": ([
	"name":			"����",
	"armor_type":		TYPE_HANDS,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "armor" : 1 ]),
	"weight":		1500,]),
"coat" : ([
	"name":			"����",
	"armor_type":		TYPE_COAT,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "armor" : 1 ]),
	"weight":		6000,]),
"armor": ([
	"name":			"����",
	"armor_type":		TYPE_ARMOR,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "armor" : 1 ]),
	"weight":		22000,]),
"belt": ([
	"name":			"����",
	"armor_type":		TYPE_WAIST,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "armor" : 1 ]),
	"weight":		2500,]),
"boot" : ([
	"name":			"ѥ",
	"armor_type":		TYPE_BOOTS,
	"basic_name":		"Ƥ",
	"unit":			"˫",
	"armor_prop":		([ "dodge" : 1 ]),
	"weight":		5000,]),
"mantle": ([
	"name":			"����",
	"armor_type":		TYPE_SURCOAT,
	"basic_name":		"",
	"unit":			"��",
	"armor_prop":		([ "dodge" : 1 ]),
	"weight":		10000,]),
]);

nosave mapping	Armor_Special_Class =	([
	"cap":	([
		YEL"����ͷ��"NOR : ([
			"id":		"qinglong toukui",
			"long2":	YEL"��������֮������\n"NOR,
			"armor_prop":	([ "armor":30 , "dexerity":2 ]),
			]),
		HIW"�׻�ͷ��"NOR : ([
			"id":		"qinglong toukui",
			"long2":	HIW"����ޱ�֮�Ϲű�����\n"NOR,
			"armor_prop":	([ "armor":50 ]),
			]),
		RED"Īаͷ��"NOR : ([
			"id":		"moye toukui",
			"long2":	RED"Īа����ٵأ��ٶ����֣�Ϊ�Ŵ���а֮�\n"NOR,
			"armor_prop":	([ "armor":30 , "antipoison":25 ]),
			]),
		RED"��Ȫͷ��"NOR : ([
			"id":		"longquan toukui",
			"long2":	RED"��Ȫ�˼伫Ʒ������������\n"NOR,
			"armor_prop":	([ "armor":25 , "dexerity":1 , "strength":1 , "constitution":1 , "intelligence":1 ]),
			]),
		]),
	"glove": ([
		HIB"��Ҷ����"NOR : ([
			"id":		"feiye shoutao",
			"long2":	HIB"��Ҷ����֮������\n"NOR,
			"armor_prop":	([ "armor":30 , "dexerity":2 ]),
			]),
		HIW"��ʯ����" : ([
			"id":		"wanshi shoutao",
			"long2":	HIW"����ޱ�֮�Ϲű�����\n"NOR,
			"armor_prop":	([ "armor":50 ]),
			]),
		HIR"ժ������" : ([
			"id":		"zhaihua shoutao",
			"long2":	HIR"����ժ��֮���\n"NOR,
			"armor_prop":	([ "armor":30 , "constitution":3 ]),
			]),
		RED"��Ȫ����" : ([
			"id":		"longquan toukui",
			"long2":	RED"��Ȫ�˼伫Ʒ������������\n"NOR,
			"armor_prop":	([ "armor":25 , "dexerity":1 , "strength":1 , "constitution":1 , "intelligence":1 ]),
			]),
		]),
	"boot": ([
		HIW"����ѥ"NOR : ([
			"id":		"feiyun xue",
			"long2":	HIW"�������죬�ݺ�����֮��ѥ��\n"NOR,
			"armor_prop":	([ "armor":25 , "dexerity":3 ]),
			]),
		HIY"����ѥ"NOR : ([
			"id":		"tianlong xue",
			"long2":	HIY"����ޱ�֮�Ϲű�����\n"NOR,
			"armor_prop":	([ "armor":40 ]),
			]),
		HIR"����ѥ"NOR : ([
			"id":		"gongbu xue",
			"long2":	RED"�����������죬���ܲ��̣�\n"NOR,
			"armor_prop":	([ "armor":25 , "dodge":20 , "parry":20 ]),
			]),
		RED"ʤаѥ"NOR : ([
			"id":		"shengxie xue",
			"long2":	RED"ʤа����ޱȶ����κ�Ҫ��\n"NOR,
			"armor_prop":	([ "armor":30 ]),
			"wear_maxneili": 0,
			"wear_dex":	0,
			"wear_str":	0,
			]),
		]),
	"belt": ([
		HIW"��������"NOR : ([
			"id":		"feitian yaodai",
			"long2":	HIW"�����ھ���֮��֮������\n"NOR,
			"armor_prop":	([ "armor":25 , "dexerity":2 ]),
			]),
		HIB"��а����"NOR : ([
			"id":		"pixie yaodai",
			"long2":	HIB"��а��ħ֮����������\n"NOR,
			"armor_prop":	([ "armor":25 , "constitution":2 ]),
			]),
		RED"տ¬����"NOR : ([
			"id":		"zhanlu yaodai",
			"long2":	RED"տ¬����ޱȣ���ǧ��������\n"NOR,
			"armor_prop":	([ "armor":40 ]),
			]),
		RED"ʤа����"NOR : ([
			"id":		"shengxie xue",
			"long2":	RED"ʤа����ޱȶ����κ�Ҫ��\n"NOR,
			"armor_prop":	([ "armor":30 ]),
			"wear_maxneili": 0,
			"wear_dex":	0,
			"wear_str":	0,
			]),
		]),
	"coat": ([
		RED"Īа����"NOR : ([
			"id":		"moye caiyi",
			"long2":	RED"Īа����ٵأ��ٶ����֣�Ϊ�Ŵ���а֮�\n"NOR,
			"armor_prop":	([ "armor":90 , "antipoison":60 ]),
			]),
		RED"̫������"NOR : ([
			"id":		"taie caiyi",
			"long2":	RED"̫������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
			"armor_prop":	([ "armor":90 , "qi":1000 , "jing":500 ]),
			]),
		RED"տ¬����"NOR : ([
			"id":		"zhanlu caiyi",
			"long2":	RED"տ¬����ޱȣ���ǧ�������\n"NOR,
			"armor_prop":	([ "armor":120 ]),
			]),
		RED"��������"NOR : ([
			"id":		"gongbu caiyi",
			"long2":	RED"�����������죬���ܲ��̣�\n"NOR,
			"armor_prop":	([ "armor":90 , "parry":35 , "dodge":35 ]),
			]),
		RED"ʤа����"NOR : ([
			"id":		"shengxie caiyi",
			"long2":	RED"ʤа�ޱȼ�̾޴�����κ�Ҫ��\n"NOR,
			"armor_prop":	([ "armor":90 ]),
			"wear_maxneili": 0,
			"wear_dex":	0,
			"wear_str":	0,
			]),
		RED"��Ȫ����"NOR : ([
			"id":		"longquan caiyi",
			"long2":	RED"��Ȫ�˼伫Ʒ������������\n"NOR,
			"armor_prop":	([ "armor":80 , "dexerity":1 , "strength":1 , "constitution":1 , "intelligence":1 ]),
			]),
		]),
	"armor": ([
		RED"Īа����"NOR : ([
			"id":		"moye jiazhou",
			"long2":	RED"Īа����ٵأ��ٶ����֣�Ϊ�Ŵ���а֮�\n"NOR,
			"armor_prop":	([ "armor":108 , "antipoison":50 ]),
			]),
		RED"̫������"NOR : ([
			"id":		"taie jiazhou",
			"long2":	RED"̫������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
			"armor_prop":	([ "armor":108 , "qi":600 , "jing":300 ]),
			]),
		RED"տ¬����"NOR : ([
			"id":		"zhanlu jiazhou",
			"long2":	RED"տ¬����ޱȣ���ǧ�������\n"NOR,
			"armor_prop":	([ "armor":135 ]),
			]),
		RED"��������"NOR : ([
			"id":		"gongbu jiazhou",
			"long2":	RED"�����������죬���ܲ��̣�\n"NOR,
			"armor_prop":	([ "armor":108 , "parry":30 , "dodge":30 ]),
			]),
		RED"ʤа����"NOR : ([
			"id":		"shengxie jiazhou",
			"long2":	RED"ʤа�ޱȼ�̾޴�����κ�Ҫ��\n"NOR,
			"armor_prop":	([ "armor":108 ]),
			"wear_maxneili": 0,
			"wear_dex":	0,
			"wear_str":	0,
			]),
		RED"��Ȫ����"NOR : ([
			"id":		"longquan jiazhou",
			"long2":	RED"��Ȫ�˼伫Ʒ������������\n"NOR,
			"armor_prop":	([ "armor":100 , "dexerity":1 , "strength":1 , "constitution":1 , "intelligence":1 ]),
			]),
		]),
	"mantle": ([
		RED"Īа����"NOR : ([
			"id":		"moye pifeng",
			"long2":	RED"Īа����ٵأ��ٶ����֣�Ϊ�Ŵ���а֮�\n"NOR,
			"armor_prop":	([ "armor":70 , "antipoison":75 ]),
			]),
		RED"̫������"NOR : ([
			"id":		"taie pifeng",
			"long2":	RED"̫������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
			"armor_prop":	([ "armor":70 , "qi":400 , "jing":150 ]),
			]),
		RED"տ¬����"NOR : ([
			"id":		"zhanlu pifeng",
			"long2":	RED"տ¬����ޱȣ���ǧ�������\n"NOR,
			"armor_prop":	([ "armor":85 ]),
			]),
		RED"��������"NOR : ([
			"id":		"gongbu pifeng",
			"long2":	RED"�����������죬���ܲ��̣�\n"NOR,
			"armor_prop":	([ "armor":70 , "parry":20 , "dodge":20 ]),
			]),
		RED"ʤа����"NOR : ([
			"id":		"shengxie pifeng",
			"long2":	RED"ʤа�ޱȼ�̾޴�����κ�Ҫ��\n"NOR,
			"armor_prop":	([ "armor":70 ]),
			"wear_maxneili": 0,
			"wear_dex":	0,
			"wear_str":	0,
			]),
		RED"��Ȫ����"NOR : ([
			"id":		"longquan pifeng",
			"long2":	RED"��Ȫ�˼伫Ʒ������������\n"NOR,
			"armor_prop":	([ "armor":60 , "dexerity":1 , "strength":1 , "constitution":1 , "intelligence":1 ]),
			]),
		]),
]);

nosave mapping	Armor_Super_Class = ([
	HIM"��ԯ" : ([	"id":	"xuanyuan",
			"long2": HIM"���ջƵ۳ִ�������ָ�ϳ��ϣ�������ɨ��������Ӧ�����ɣ������޶�ս��ȣ�\n"NOR,
		]),
	HIR"��ͨ" : ([	"id":	"shentong",
			"long2":	HIR"������ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���\n"NOR,
		]),
	HIG"�޼�" : ([	"id":	"wuji",
			"long2": HIG"�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����\n"NOR,
		]),
	HIW"����" : ([	"id":	"bagua",
			"long2": HIW"�����С��ݡ����������ˡ����š�������������������������֮�𣬴��������򣬼����������һ��\n"NOR,
		]),
	HIW"̫��" : ([	"id":	"taibai",
			"long2": HIW"
		�Կ��Ϻ�ӧ  �⹳˪ѩ��		�����հ���  ��������
		ʮ��ɱһ��  ǧ�ﲻ����		���˷���ȥ  ���������
		�й�������  �ѽ�ϥǰ��		���ˡ��캥  ����Ȱ����
		������Ȼŵ  ������Ϊ��		�ۻ�������  ����������
		���Իӽ��  ��������		ǧ���׳ʿ  ���մ�����
		����������  ��������Ӣ		˭�������  ����̫����\n"NOR,
		]),
	HIY"Ǭ��" : ([	"id":	"qiankun",
			"long2": HIY"�����������߷ֱ��Ժڰ����������ڻ���ɣ�һ��һ�ף��к�Ǭ������������֮������һ�����\n"NOR,
		]),
	HIY"̫��" : ([	"id":	"taiji",
			"long2": HIY"̫���ߣ��޼�����������֮ĸҲ����֮��֣���֮��ϡ��޹��������������졣
�˸�����ν֮�ߣ���˳�˱�ν֮ճ��������Ӧ���������档��仯��ˣ���
��Ϊһ�ᣡ\n"NOR,
		]),
	HIC"���" : ([	"id":	"tiandi",
			"long2": HIC"���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�\n"NOR,
		]),
	HIM"����" : ([	"id":	"fengyun",
			"long2": HIM"��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����\n"NOR,
		]),
	HIG"����" : ([	"id":	"haoqi",
			"long2": HIG"��غ���֮�����ɨħ������Ϊ��Ϊ����֮���ߣ�\n"NOR,
		]),
	HIR"����" : ([	"id":	"lianyu",
			"long2": HIR"��ʮ�������еأ������гǣ�������ǣ���С��ħ�������������ڴ��ֻ�������ν֮����������\n"NOR,
		]),
	HIC"����" : ([	"id":	"sanqing",
			"long2": HIC"����������������Σ������컯��һ�����壡����ǡ�����һ����塣��\n"NOR,
		]),
	HIC"����" : ([	"id":	"kunlun",
			"long2": HIC"	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ�
	����ʫ���ζϣ��Ϲ�����
	�ѽ���Ȼ�����޴��й��ۡ�

	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� \n"NOR,
		]),
]);

nosave mapping	Armor_Great_Class = ([
	CYN"����":	"diwang",	CYN"����":	"wangzhe",
	CYN"���":	"tianhou",	CYN"����":	"bawang",
	CYN"��ʥ":	"tiansheng",	CYN"����":	"shenwang",
	CYN"����":	"yaohou",	BLU"����":	"gonghou",
	BLU"ħ��":	"mowang",	BLU"����":	"qixing",
	BLU"���":	"egui",		GRN"����":	"yulong",
	GRN"���":	"yufeng",	GRN"�ɺ�":	"songhe",
	GRN"����":	"tianlong",	GRN"����":	"dilong",
	GRN"���":	"tianfeng",	GRN"�ط�":	"difeng",
	GRN"����":	"longxiang",	GRN"����":	"fengwu",
	HIG"��Ӱ":	"wuying",	HIG"�Ƽ�":	"pojia",
	HIG"����":	"feilong",	HIG"����":	"wuyi",
	HIG"����":	"niaoxiang",	HIG"����":	"wanpan",
	HIG"��Ƽ":	"qingping",	YEL"����":	"huanglong",
	WHT"����":	"yunti",	WHT"̫Ԩ":	"taiyuan",
	WHT"̫��":	"taifeng",	WHT"����":	"xuling",
	WHT"����":	"pili",		WHT"�׵�":	"leidian",
	WHT"����":	"fenglei",	WHT"���":	"zhendian",
	WHT"����":	"baiyu",	WHT"����":	"qingyu",
	WHT"����":	"ziyu",		WHT"����":	"lanyu",
	WHT"����":	"luyu",		WHT"����":	"huangyu",
	WHT"����":	"chiyu",	WHT"����":	"hongyu",
	CYN"���":	"qinghong",	CYN"�׺�":	"baihong",
	CYN"�Ϻ�":	"zihong",	CYN"����":	"lanhong",
	CYN"�̺�":	"luhong",	CYN"���":	"chihong",
	CYN"��Ӱ":	"huanying",	CYN"��˪":	"ningshuang",
	CYN"����":	"qingsuo",	MAG"����":	"tianlong",
	MAG"�ϵ�":	"zidian",	MAG"���":	"fenghuang",
	MAG"����":	"tianqu",	MAG"���":	"tianxuan",
	MAG"����":	"tianji",	MAG"��Ȩ":	"tianquan",
	MAG"���":	"yuheng",	MAG"����":	"kaiyang",
	MAG"ҡ��":	"yaoguang",	MAG"����":	"beidou",
	HIR"���":	"tianhuo",	HIR"����":	"qilin",
	HIR"��а":	"pixie",	YEL"���":	"hongjun",
	YEL"���":	"guangcheng",	YEL"���":	"jinguang",
	YEL"����":	"xiuluo",	YEL"ҹ��":	"yecha",
	YEL"����":	"yaochi",	YEL"���":	"leiheng",
	HIR"����":	"huolong",	HIC"����":	"binglong",
	HIB"����":	"heilong",	HIR"����":	"yanlong",
	HIC"����":	"qinglong",	HIR"��ȸ":	"zhuque",
	HIW"�׻�":	"baihu",	HIB"����":	"xuanwu",
	GRN"����":	"xuanji",	HIG"����":	"jiutian",
	HIG"����":	"jiuyou",	MAG"����":	"jiulong",
	MAG"����":	"wulong",	MAG"����":	"sanlong",
	WHT"����":	"shengsi",
]);

nosave string *Armor_G_3_class = ({
	"����",	"����",	"����",	"����",	"����",	"�ĺ�",	"���",	"��÷",
	"��Ȫ",	"��Ȫ",	"��Ȫ",	"��Ȫ",	"ŭ��",	"����",	"����",	"��ˮ",
	"��",	"��",	"С",	"��",	"��",	"��",	"��",	"��",
	"���",	"˫��",	"����",	"��ʤ",	"�⹳",	"�һ�",	"�޵�",	"˫��",
	"����",	"��Ů",	"����",	"����",	"����",	"��",	"����",	"�̹�",
	"����",	"��ˮ",	"ܽ��",	"��Ԩ",	"��ɽ",	"��",	"����",	"����",
	"����",	"��Ƥ",	"��ɽ",	"����",	"����",	"���",	"�׺�",	"����",
	"����",	"����",	"����",	"��β",	"���",	"���",	"����",	"����",
	"���",	"����",	"��ͷ",	"����",	"ţͷ",	"�л�",	"����",	"����",
	"����",	"�պ�",	"����",	"��ͷ",	"�ͻ�",	"���",	"��ˮ",	"����",
	"�޹�",	"����",	"���",	"���",	"����",	"��Ʒ",	"��ˮ",	"��ˮ",
	"���",	"�ط�",	"����",	"����",	"����",	"����",	"����",	"ħ��",
	"��ˮ",	"��ˮ",	"ħˮ",	"����",	"�岽",	"��Ҷ",	"��Ҷ",	"����",
	"����",	"����",	"ħ��",	"�˺�",	"����",	"�ͻ�",	"��ʨ",	"Х��",
	"�÷�",	"����",	"����",	"����",	"����",	"����",	"����",	"ʨ��",
	"Ұ��",	"����",	"����",	"����",	"��ʨ",	"��",	"��",	"��ӥ",
	"����",	"����",	"���",	"����",	"�ڷ�",	"����",	"����",	"����",
	"��ü",	"����",	"����",	"����",	"�촽",	"��",	"��ָ",	"�ر�",
	"����",	"����",	"ҹ��",	"��ݺ",	"����",	"����",	"����",	"����",
	"ҹ��",	"����",	"����",	"����",	"����",	"����",	"����",	"����",
	"����",	"����",	"����",	"ʨ��",	"�Ի�",	"����",	"�Ͼ�",	"��ĸ",
	"����",	"����",	"����",	"��İ",	"�ݺ�",	"����",	"����",	"���",
	"�ɰ�",	"����",	"���",	"����",	"����",	"���",	"ʥĸ",	"�Ĳ�",
	"��ʥ",	"����",	"����",	"����",	"����",	"��ѩ",	"Ʈѩ",	"��ѩ",
	"��ѩ",	"��ѩ",	"ѩ��",	"����",	"ϼε",	"��ϼ",	"����",	"嫺�",
	"ĵ��",	"�ٺ�",	"�׺�",	"����",	"����",	"���",	"��÷",	"����",
	"��˼",	"����",	"����",	"��ҩ",	"�ž�",	"õ��",	"�¼�",	"�ļ�",
	"ܽ��",	"Ǿޱ",	"����",	"��ʦ",	"ϴ��",	"����",	"����",	"��ħ",
	"����",	"����",	"����",	"����",	"��ޱ",	"ľ��",	"����",	"̫��",
	"���",	"���",	"�׺�",	"�Ϻ�",	"��ޱ",	"��ޱ",	"��ޱ",	"��ޱ",
	"��ޱ",	"����",	"����",	"����",	"����",	"���",	"��з",	"��ţ",
	"�۹�",	"����",	"����",	"����",	"����",	"����",	"����",	"��ɽ",
	"����",	"ժ��",	"̽��",	"����",	"����",	"��Ӱ",	"��ħ",	"����",
	"����",	"ǧ��",	"����",	"ǧâ",	"����",	"ħ��",	"���",
	"�Ͼ�",	"��ҳ",	"����",	"���",	"����",	"����",	"����",	"��ͼ",
	"Ѫն", "����", "����", "��â", "����", "����", "����", "����",
	"����", "Ӱ��", "���", "����", "˫��", "��ϼ", "����", "����",
	"����", "����", "�ۺ�", "��̳", "����", "����", "�ɷ�", "����",
	"��Ȫ",
});

nosave mapping armor_modify = ([
	"cap":17,
	"glove":20,
	"coat":6,
	"armor":5,
	"belt":25,
	"boot":20,
	"mantle":20,
	/*
	"cap":0.4,25
	"glove":0.3,33
	"coat":0.9,11
	"armor":1.0,10
	"belt":0.2,50
	"boot":0.5,20
	"mantle":0.4,25
	////////////	
	cap      0.6  17
	glove    0.5   20
	coat     1.6   6
	armor    1.8   5
	belt     0.4   25
	boot     0.5   20
	mantle   0.5   20
	
	cap      0.7    14
	glove    0.6    17
	coat     1.7    6
	armor    1.9    5
	belt     0.4    25
	boot     0.6    17
	mantle       0.6 17
	*/	
]);
//////////////////////// armor functions ////////////////////////////
string armor_power(mapping p,string type)
{
	int i;	
	switch (type) {
		case "head":	type = "cap";	break;
		case "hands":	type = "glove";	break;
		case "boots":	type = "boot";	break;
		case "surcoat":	type = "mantle";break;
		case "waist":	type = "belt";	break;
		case "coat":
		case "armor": break;
		default: return "����������ķ������ͣ�����";
	}
	if(type=="boot"||type=="mantle") i = p["dodge"]*8*armor_modify[type]/10;
	else i = p["armor"]*4*armor_modify[type]/10;
		
	if( i >= 600 )	return HIW"�޵�����"NOR;
	if( i >= 550 )	return HIW"������˫"NOR;
	if( i >= 500 )	return HIY"��������"NOR;
	if( i >= 450 )	return HIY"������ƥ"NOR;
	if( i >= 400 )	return HIM"�����ױ�"NOR;
	if( i >= 360 )	return HIM"�β�����"NOR;
	if( i >= 330 )	return HIR"����쳣"NOR;
	if( i >= 300 )	return HIC"����"NOR;
	if( i >= 270 )	return HIG"�ܸ�"NOR;
	if( i >= 240 )	return HIB"�ϸ�"NOR;
	if( i >= 210 )	return WHT"�ܲ���"NOR;
	if( i >= 180 )	return YEL"����"NOR;
	if( i >= 150 )	return MAG"��С"NOR;
	if( i >= 120 )	return RED"������"NOR;
	if( i <= 25  )	return BLU"����"NOR;
	if( i <= 75  )	return GRN"����"NOR;	
	return CYN"һ��"NOR;
}
///////////////////Status/////////////////////////////////////////
nosave mapping Status_list = ([
	"jingli":      5,
	"jing":        5,
	"neili":       8,	
	"qi":          8,	             
	"parry":       150,                 
	"dodge":       150,                 
	"force":       180,
	"attack":      200,		 
	"defense":     200,
	"re_qi":       400,  
	"re_neili":    400,      
	"re_jing":     400,          
	"re_jingli":   400,
	"damage":      400,
	"armor":       400,
	"strength":    1300,
	"constitution":1300,
	"dexerity":    1300,
	"intelligence":2000,
	"karma":       3000,
	"personality": 3000,
	"armor_vs_force":1000,
]);

mixed StrToFloat(string s)
{
        float i;
        
        if (sscanf(s, "%f", i) == 1)
                return i;
        return "FaileD";
}

string FloatToStr(float i)
{
        return sprintf("%f", i);
}

string ask_imbue(string type)
{
	object *obs;
	int i, pp = 0, sp = 0, gp = 0, bp = 0;
	string str = "�����뿴����������������������������������������������\n";	

	if(type=="weapon") type = USER_WEAPON;
	else if(type=="armor") type= USER_ARMOR;
	else return 0;	
	
	obs = filter_array(children(type), (: clonep :));
	i = sizeof(obs);
	if( i && i > 0 ){
		while(i--){
			switch(obs[i]->query("imbued")){
				case 5:	pp++; break;
				case 4:	sp++; break;
				case 3:	gp++; break;
				case 2: bp++; break;	
				case 1:	
				default: break;
			}
		}
	}
	if( pp > 0 ){
		str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(pp) +	"�Ѵ�˵�е�";
		str += type==USER_WEAPON?"������\n":"���ߡ�\n";
	}
	if( sp > 0 ){
		str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(sp) +	"����ߵȼ���";
		str += type==USER_WEAPON?"������\n":"���ߡ�\n";
	}
	if( gp > 0 ){
		str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(gp) +	"�Ѹߵȼ���";
		str += type==USER_WEAPON?"������\n":"���ߡ�\n";
	}
	if( bp > 0 ){
		str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(bp) +	"�ѵ͵ȼ���";
		str += type==USER_WEAPON?"������\n":"���ߡ�\n";
	}
	return str;
}

nosave string spe_name=" ";
nosave string jade_show=" ";
nosave string item_show=" ";
nosave int is_prop=0;
nosave int is_sure=0;
nosave string add_type=" ";
nosave int add_use=1;
nosave string add_numa="";
nosave float add_numb=0;
nosave string can_wield=" ";
nosave string just_for=" ";
nosave int if_next=0;
nosave int status_type=0;//���κγ�ͻ

int status_armor_lists(int i,int t)
{	
	if(i==0) i = 1+random(37);
	///init
	spe_name=" ";
	jade_show=" ";
	item_show=" ";
	is_prop=0;
	is_sure=0;
	add_type=" ";
	add_use=1;
	add_numa="";
	add_numb=0;
	can_wield=" ";
	just_for=" ";
	if_next=0;
	status_type=0;
	switch(i){
		case 1:
			spe_name = HIC"����";
			jade_show = "��������";
			item_show = "��ǿ����";
			is_prop = 1;
			is_sure = 1;
			add_type ="armor";
			add_use = 3;
			add_numa=FloatToStr(1.1);
			status_type=1;
			break;
		case 2:
			spe_name = HIC"��Ʒ";
			jade_show = "���ȵ���";
			item_show = "��Ʒ����";
			is_prop = 1;
			is_sure = 1;
			add_type ="armor";
			add_use = 3;
			add_numa=FloatToStr(1.2);
			status_type=1;
			break;	
		case 3:
			spe_name = HIW"��Ʒ";
			jade_show = "��Ʒ����";
			item_show = "��Ʒ����";			
			is_prop = 1;
			is_sure = 1;
			add_type ="armor";
			add_use = 3;
			add_numa=FloatToStr(1.3);
			status_type=1;
			break;		
		case 4:			
			spe_name = GRN"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "�������Ҫ���С��";	
			is_sure = 1;
			add_type ="wear_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=2;
			break;		
		case 5:
			spe_name = GRN"�ᾧ";
			jade_show = "�ᾧ�ʵ�";
			item_show = "�������Ҫ�����";			
			is_sure = 1;
			add_type ="wear_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=2;
			break;
		case 6:
			spe_name = GRN"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "�������Ҫ������";			
			is_sure = 1;
			add_type ="wear_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=2;
			break;
		case 7:
			spe_name = GRN"����";
			jade_show = "�����ʵ�";
			item_show = "���������Ҫ��";
			is_sure = 1;
			add_type ="wear_maxneili";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=2;
			break;
		case 8:
			spe_name = HIW"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "����Ҫ���С��";
			is_sure = 1;
			add_type ="wear_neili";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=3;
			break;
		case 9:
			spe_name = HIW"����";
			jade_show = "�����ʵ�";
			item_show = "����Ҫ�����";
			is_sure = 1;
			add_type ="wear_neili";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=3;
			break;
		case 10:
			spe_name = HIW"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "����Ҫ������";
			is_sure = 1;
			add_type ="wear_neili";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=3;
			break;
		case 11:
			spe_name = GRN"��";
			jade_show = "���ʵ�";
			item_show = "������Ҫ��";
			is_sure = 1;
			add_type ="wear_neili";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=3;
			break;		
		case 12:
			spe_name = HIG"����";
			jade_show = "ɫ�󻪲�";
			item_show = "����Ҫ���С��";
			is_sure = 1;
			add_type ="wear_str";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=4;
			break;
		case 13:
			spe_name = HIG"���";
			jade_show = "ɫ����";
			item_show = "����Ҫ�����";
			is_sure = 1;
			add_type ="wear_str";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=4;
			break;
		case 14:
			spe_name = HIG"�ʻ�";
			jade_show = "ɫ��ʻ�";
			item_show = "����Ҫ������";
			is_sure = 1;
			add_type ="wear_str";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=4;
			break;
		case 15:
			spe_name = HIG"�⻪";
			jade_show = "ɫ��⻪";
			item_show = "������Ҫ��";
			is_sure = 1;
			add_type ="wear_str";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=4;
			break;
		case 16:
			spe_name = HIG"����";
			jade_show = "ӡ������";
			item_show = "��������";
			is_sure = 1;
			add_type ="weight";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=5;
			break;
		case 17:
			spe_name = "����";
			jade_show = "ӡ������";
			item_show = "��������";
			is_sure = 1;
			add_type ="weight";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=5;
			break;		
		case 18:
			spe_name = WHT"����";
			jade_show = "����+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="intelligence";
			add_use = 1;
			break;
		case 19:
			spe_name = BLU"����";
			jade_show = "����+$x";
			item_show = "���Ӹ���";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="constitution";
			add_use = 1;	
			break;
		case 20:
			spe_name = HIM"����";
			jade_show = "����+$x";
			item_show = "���ӱ���";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="strength";
			add_use = 1;	
			break;
		case 21:
			spe_name = MAG"��Ԩ";
			jade_show = "��+$x";
			item_show = "������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="dexerity";
			add_use = 1;	
			break;
		case 22:
			spe_name = WHT"����";
			jade_show = "������������";
			item_show = "������������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_use = 1;
			switch(t){
				case 0:
					add_type ="intelligence";
					if_next=1;
					break;
				case 1:
					add_type ="constitution";
					if_next=1;
					break;
				case 2:
					add_type ="dexerity";
					if_next=1;
					break;
				case 3:
					add_type ="sharpness";					
					break;								
			}
			break;
		case 23:
			spe_name = HIG"����";
			jade_show = "������Ѫ+$x";
			item_show = "������Ѫ";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="qi";
			add_use = 1;
			break;
		case 24:
			spe_name = HIG"����";
			jade_show = "���Ӿ�Ѫ+$x";
			item_show = "���Ӿ�Ѫ";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="jing";
			add_use = 1;
			break;
		case 25:
			spe_name = HIG"С����";
			jade_show = "���Ӿ���+$x";
			item_show = "���Ӿ���";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="jingli";
			add_use = 1;
			break;
		case 26:
			spe_name = HIG"������";
			jade_show = "��������+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="neili";
			add_use = 1;
			break;						
		case 27:
			spe_name = HIW"����";
			jade_show = "��������+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(20.0);
			add_numb=100;
			add_type ="attack";
			add_use = 1;
			break;
		case 28:
			spe_name = HIG"����";
			jade_show = "��Ѫ�ָ�+$x%";
			item_show = "�����Ѫ�ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_qi";
			add_use = 1;
			break;
		case 29:
			spe_name = HIG"����";
			jade_show = "��Ѫ�ָ�+$x%";
			item_show = "��߾�Ѫ�ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_jing";
			add_use = 1;
			break;
		case 30:
			spe_name = HIG"����";
			jade_show = "�����ָ�+$x%";
			item_show = "��߾����ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_jingli";
			add_use = 1;
			break;
		case 31:
			spe_name = HIG"����";
			jade_show = "�����ָ�+$x%";
			item_show = "��������ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_neili";
			add_use = 1;
			break;
		case 32:
			spe_name = HIC"����";
			jade_show = "������ʻָ�";
			item_show = "������ʻָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_use = 1;			
			switch(t){
				case 0:
					add_type ="re_qi";
					if_next=1;
					break;
				case 1:
					add_type ="re_jing";
					if_next=1;
					break;
				case 2:
					add_type ="re_jingli";
					if_next=1;
					break;
				case 3:
					add_type ="re_neili";
					break;								
			}
			break;		
		case 33:
			spe_name = HIC"��а";
			jade_show = "����+$x%";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(10.0);
			add_numb=10;
			add_type ="antipoison";
			add_use = 1;
			status_type=87;
			break;
		case 34:
			spe_name = HIC"��а";
			jade_show = "����+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(6.0);
			add_numb=6;
			add_type ="antipoison";
			add_use = 1;
			status_type=87;
			break;
		
		case 35:
			spe_name = HIM"��ʯ";
			jade_show = "����+$x";
			item_show = "��߷���";
			is_prop=1;
			add_numa=FloatToStr(15.0);
			add_numb=15;
			add_type ="parry";
			add_use = 1;
			status_type=88;
			break;
		case 36:
			spe_name = HIW"��ʯ";
			jade_show = "���+$x";
			item_show = "��߶��";
			is_prop=1;
			add_numa=FloatToStr(15.0);
			add_numb=15;
			add_type ="dodge";
			add_use = 1;
			status_type=89;
			break;
		case 37:
			spe_name = RED"��ʯ";
			jade_show = "�ڹ�+$x";
			item_show = "����ڹ�";
			is_prop=1;
			add_numa=FloatToStr(15.0);
			add_numb=15;
			add_type ="force";
			add_use = 1;
			status_type=90;
			break;
		/*
		case 25:
			spe_name = HIB"ҹ��";
			jade_show = "ҹ������";
			item_show = "������������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_use = 1;
			switch(t){
				case 0:
					add_type ="intelligence";
					if_next=1;
					break;
				case 1:
					add_type ="constitution";
					if_next=1;
					break;
				case 2:
					add_type ="dexerity";
					if_next=1;
					break;
				case 3:
					add_type ="sharpness";					
					break;								
			}
			break;
			*/
						
	}
	return i;
}

int status_weapon_lists(int i,int t)
{	
	if(i==0) i = 1+random(37);
	///init
	spe_name=" ";
	jade_show=" ";
	item_show=" ";
	is_prop=0;
	is_sure=0;
	add_type=" ";
	add_use=1;
	add_numa="";
	add_numb=0;
	can_wield=" ";
	just_for=" ";
	if_next=0;
	status_type=0;
	switch(i){
		case 1:
			spe_name = HIC"����";
			jade_show = "��������";
			item_show = "��ǿ����";
			is_prop = 1;
			is_sure = 1;
			add_type ="damage";
			add_use = 3;
			add_numa=FloatToStr(1.1);
			status_type=1;
			break;
		case 2:
			spe_name = HIC"��Ʒ";
			jade_show = "���ȵ���";
			item_show = "��Ʒ����";
			is_prop = 1;
			is_sure = 1;
			add_type ="damage";
			add_use = 3;
			add_numa=FloatToStr(1.2);
			status_type=1;
			break;	
		case 3:
			spe_name = HIW"��Ʒ";
			jade_show = "��Ʒ����";
			item_show = "��Ʒ����";			
			is_prop = 1;
			is_sure = 1;
			add_type ="damage";
			add_use = 3;
			add_numa=FloatToStr(1.3);
			status_type=1;
			break;		
		case 4:			
			spe_name = GRN"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "�������Ҫ���С��";	
			is_sure = 1;
			add_type ="wield_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=2;
			break;		
		case 5:
			spe_name = GRN"�ᾧ";
			jade_show = "�ᾧ�ʵ�";
			item_show = "�������Ҫ�����";			
			is_sure = 1;
			add_type ="wield_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=2;
			break;
		case 6:
			spe_name = GRN"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "�������Ҫ������";			
			is_sure = 1;
			add_type ="wield_maxneili";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=2;
			break;
		case 7:
			spe_name = GRN"����";
			jade_show = "�����ʵ�";
			item_show = "���������Ҫ��";
			is_sure = 1;
			add_type ="wield_maxneili";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=2;
			break;
		case 8:
			spe_name = HIW"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "����Ҫ���С��";
			is_sure = 1;
			add_type ="wield_neili";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=3;
			break;
		case 9:
			spe_name = HIW"����";
			jade_show = "�����ʵ�";
			item_show = "����Ҫ�����";
			is_sure = 1;
			add_type ="wield_neili";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=3;
			break;
		case 10:
			spe_name = HIW"��ˮ";
			jade_show = "��ˮ�ʵ�";
			item_show = "����Ҫ������";
			is_sure = 1;
			add_type ="wield_neili";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=3;
			break;
		case 11:
			spe_name = GRN"��";
			jade_show = "���ʵ�";
			item_show = "������Ҫ��";
			is_sure = 1;
			add_type ="wield_neili";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=3;
			break;		
		case 12:
			spe_name = HIG"����";
			jade_show = "ɫ�󻪲�";
			item_show = "����Ҫ���С��";
			is_sure = 1;
			add_type ="wield_str";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=4;
			break;
		case 13:
			spe_name = HIG"���";
			jade_show = "ɫ����";
			item_show = "����Ҫ�����";
			is_sure = 1;
			add_type ="wield_str";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=4;
			break;
		case 14:
			spe_name = HIG"�ʻ�";
			jade_show = "ɫ��ʻ�";
			item_show = "����Ҫ������";
			is_sure = 1;
			add_type ="wield_str";
			add_use = 3;
			add_numa=FloatToStr(0.4);
			status_type=4;
			break;
		case 15:
			spe_name = HIG"�⻪";
			jade_show = "ɫ��⻪";
			item_show = "������Ҫ��";
			is_sure = 1;
			add_type ="wield_str";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=4;
			break;
		case 16:
			spe_name = HIG"����";
			jade_show = "ӡ������";
			item_show = "��������";
			is_sure = 1;
			add_type ="weight";
			add_use = 3;
			add_numa=FloatToStr(0.75);
			status_type=5;
			break;
		case 17:
			spe_name = "����";
			jade_show = "ӡ������";
			item_show = "��������";
			is_sure = 1;
			add_type ="weight";
			add_use = 3;
			add_numa=FloatToStr(0.5);
			status_type=5;
			break;
		case 18:
			spe_name = GRN"����";
			jade_show = "ӡ������";
			item_show = "������";
			is_sure = 1;
			add_type ="weight";
			add_use = 5;
			add_numa=FloatToStr(0.0);
			status_type=5;
			break;
		case 19:
			spe_name = HIW"����";
			jade_show = "������+$x";
			item_show = "���ӷ�����";
			add_numa=FloatToStr(1.0);
			add_numb=4;						
			add_type ="sharpness";
			add_use = 1;
			break;
		case 20:
			spe_name = HIY"����";
			jade_show = "Ӳ��+$x";
			item_show = "����Ӳ��";
			add_numa=FloatToStr(1.0);
			add_numb=4;						
			add_type ="rigidity";
			add_use = 1;
			break;
		case 21:
			spe_name = WHT"����";
			jade_show = "����+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="intelligence";
			add_use = 1;
			break;
		case 22:
			spe_name = BLU"����";
			jade_show = "����+$x";
			item_show = "���Ӹ���";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="constitution";
			add_use = 1;	
			break;
		case 23:
			spe_name = HIM"����";
			jade_show = "����+$x";
			item_show = "���ӱ���";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="strength";
			add_use = 1;	
			break;
		case 24:
			spe_name = MAG"��Ԩ";
			jade_show = "��+$x";
			item_show = "������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_type ="dexerity";
			add_use = 1;	
			break;
		case 25:
			spe_name = WHT"����";
			jade_show = "������������";
			item_show = "������������";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_use = 1;
			switch(t){
				case 0:
					add_type ="intelligence";
					if_next=1;
					break;
				case 1:
					add_type ="constitution";
					if_next=1;
					break;
				case 2:
					add_type ="dexerity";
					if_next=1;
					break;
				case 3:
					add_type ="sharpness";					
					break;								
			}
			break;	
		case 26:
			spe_name = HIG"����";
			jade_show = "������Ѫ+$x";
			item_show = "������Ѫ";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="qi";
			add_use = 1;
			break;
		case 27:
			spe_name = HIG"����";
			jade_show = "���Ӿ�Ѫ+$x";
			item_show = "���Ӿ�Ѫ";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="jing";
			add_use = 1;
			break;
		case 28:
			spe_name = HIG"С����";
			jade_show = "���Ӿ���+$x";
			item_show = "���Ӿ���";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="jingli";
			add_use = 1;
			break;
		case 29:
			spe_name = HIG"������";
			jade_show = "��������+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(200.0);
			add_numb=1000;
			add_type ="neili";
			add_use = 1;
			break;						
		case 31:
			spe_name = HIW"����";
			jade_show = "��������+$x";
			item_show = "��������";
			is_prop=1;
			add_numa=FloatToStr(20.0);
			add_numb=100;
			add_type ="attack";
			add_use = 1;
			break;
		case 32:
			spe_name = HIG"����";
			jade_show = "��Ѫ�ָ�+$x%";
			item_show = "�����Ѫ�ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_qi";
			add_use = 1;
			break;
		case 33:
			spe_name = HIG"����";
			jade_show = "��Ѫ�ָ�+$x%";
			item_show = "��߾�Ѫ�ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_jing";
			add_use = 1;
			break;
		case 34:
			spe_name = HIG"����";
			jade_show = "�����ָ�+$x%";
			item_show = "��߾����ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_jingli";
			add_use = 1;
			break;
		case 35:
			spe_name = HIG"����";
			jade_show = "�����ָ�+$x%";
			item_show = "��������ָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_type ="re_neili";
			add_use = 1;
			break;
		case 36:
			spe_name = HIC"����";
			jade_show = "������ʻָ�";
			item_show = "������ʻָ�";
			is_prop=1;
			add_numa=FloatToStr(5.0);
			add_numb=35;
			add_use = 1;			
			switch(t){
				case 0:
					add_type ="re_qi";
					if_next=1;
					break;
				case 1:
					add_type ="re_jing";
					if_next=1;
					break;
				case 2:
					add_type ="re_jingli";
					if_next=1;
					break;
				case 3:
					add_type ="re_neili";
					break;								
			}
			break;
		/*
		case 37:
			spe_name = HIB"ǧ��";
			jade_show = "ǧ�붾";
			item_show = "ǧ�붾";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="qzhu_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 38:
			spe_name = BLU"��Ы";
			jade_show = "��Ы��";
			item_show = "��Ы��";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="scorpion_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 39:
			spe_name = CYN"����";
			jade_show = "������";
			item_show = "������";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="hb_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 40:
			spe_name = HIB"һƷ��";
			jade_show = "���߶�";
			item_show = "���߶�";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="bt_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 41:
			spe_name = HIB"�綾";
			jade_show = "�綾";
			item_show = "�綾";		
			status_type=6;	
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="xx_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 42:
			spe_name = HIR"����";
			jade_show = "���涾";
			item_show = "���涾";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="hot_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 43:
			spe_name = BLU"��ʬ";
			jade_show = "��ʬ��";
			item_show = "��ʬ��";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="fs_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 44:
			spe_name = HIG"�̲�";
			jade_show = "�̲���";
			item_show = "�̲���";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="lvbo_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 45:
			spe_name = CYN"����";
			jade_show = "����";
			item_show = "����";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="cold_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 46:
			spe_name = HIR"������";
			jade_show = "�����ܶ�";
			item_show = "�����ܶ�";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="man_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 47:
			spe_name = CYN"����";
			jade_show = "���߶�";
			item_show = "���߶�";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="snake_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		*/
	}
	return i;
}
