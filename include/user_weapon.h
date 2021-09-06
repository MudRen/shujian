/* 
    .H file for	user_weapond.c

	Created	by snowman@SJ 21/04/2001

   Copyright 1997-2001 ShuJian MUD Wizard Group.
   All rights reserved.

*/

#define	USER_WEAPON	BINGQI_D("user_weapon")

#define	DEFAULT_SETTINGS  ([ \
	"wield_maxneili":	500,\
	"wield_neili":		50,\
	"wield_str":		17,\
	"long":			"",\
	"material":		"steel",\
	"wield_msg":		"$N��$n�������С�\n",\
	"unwield_msg":		"$N�����е�$n���¡�\n",\
	"no_sell":		1,\
	"imbued":		1,\
])

nosave mapping	SPECIAL_B = ([ 
	"imbued":	       5,
	"material":	       "xuantie",
	"wield_maxneili":      5000 + random(5000),
	"wield_neili":	       1000 + random(1000),
	"wield_str":	       30 + random(35),
	"wield_msg":	       HIG"\n$N�����ڷ���һ�ӣ������Ļ��Ǵ��ķ���������������һ�𡫡���һ��$n"HIG"�Ѿ�������$P���У�\n"NOR,
	"unwield_msg":	       HIG"\n$N��$n"HIG"����һ�ӣ�ֻ��$n"HIG"ͻȻ��û�죬���������Ļ�����ɢƮ���ˣ�\n"NOR,
	]);
nosave mapping	SUPER_B	= ([ 
	"imbued":	       4,
	"material":	       "supersteel",
	"sharpness":	       3,
	"rigidity":	       3,
	"wield_maxneili":      4000 + random(4000),
	"wield_neili":	       800 + random(800),
	"wield_str":	       20 + random(30),
	"wield_msg":	       HIW"\n$N����һ�ӣ�һ��$n"HIW"�����ɳ������һ�����Ѿ�������$P���С�\n"NOR,
	"unwield_msg":	       HIW"\n$N�����е�$n"HIW"һ���������ҫ�У��Ѳ�����$n"HIW"���ټ���\n"NOR,
	]);
nosave mapping	GREAT_B	= ([ 
	"imbued":	       3,
	"material":	       "greatsteel",
	"sharpness":	       2,
	"rigidity":	       2,
	"wield_maxneili":      2500 + random(2500),
	"wield_neili":	       500 + random(500),
	"wield_str":	       10 + random(25),
	"wield_msg":	       "\n$N��һ��$n������������С�\n",
	"unwield_msg":	       "\n$N�����е�$n�Ż��������ҡ�\n",
	]);
nosave mapping	GOOD_B = ([ 
	"imbued":	       2,
	"material":	       "steel",
	"sharpness":	       1,
	"rigidity":	       1,
	"wield_maxneili":      1000 + random(1000),
	"wield_neili":	       100 + random(100),
	"wield_str":	       10 + random(15),
	]);	    
		       
nosave mapping	WEAPON_MAP = ([	
"sword"	: ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"jian",
	"skill_type":		"sword",
	"verbs":		({ "slash", "hack", "slice", "thrust" }),
	"unit":			"��",
	"weight":		2000 + random(3000),
	"flag":			4,]),
"xiao" : ([
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"xiao",
	"skill_type":		"sword",
	"verbs":		({ "slash", "hack", "slice", "thrust" }),
	"unit":			"ֻ",
	"weight":		1000 + random(2000),
	"flag":			8,]),
"axe" :	([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"fu",
	"skill_type":		"axe",
	"verbs":		({ "chop", "slice", "hack" }),
	"unit":			"��",
	"weight":		4000 + random(10000),
	"flag":			4,]),
"blade": ([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"dao",
	"skill_type":		"blade",
	"verbs":		({ "slash", "slice", "hack" }),
	"unit":			"��",
	"weight":		2000 + random(3000),
	"flag":			4,]),
"brush": ([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bi",
	"skill_type":		"brush",
	"verbs":		({ "pierce", "slice", "thrust" }),
	"unit":			"֧",
	"weight":		1000 + random(2000),
	"flag":			8,]),
"club":	([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"gun",
	"skill_type":		"club",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		4000 + random(9000),
	"flag":			16,]),
"dagger": ([ 
	"name":			"ذ",
	"basic_name":		"��",
	"b_id":			"bishou",
	"skill_type":		"dagger",
	"dagger_count":		5,
	"verbs":		({ "slice", "pierce", "thrust" }),
	"unit":			"��",
	"weight":		500 + random(1000),
	"flag":			4,]),
"fork":	([ 
	"name":			"��",
	"basic_name":		"��",
	"skill_type":		"fork",
	"b_id":			"cha",
	"verbs":		({ "thrust", "pierce", "impale"	}),
	"unit":			"��",
	"weight":		4000 + random(4000),
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
	"weight":		10000 +	random(18000),
	"flag":			1,]),
"hook":	([ 
	"name":			"��",
	"basic_name":		"����",
	"skill_type":		"hook",
	"b_id":			"gou",
	"verbs":		({ "impale", "slash", "hack", }),
	"unit":			"��",
	"weight":		3000 + random(4000),
	"flag":			4,]),
"spear": ([ 
	"name":			"ǹ",
	"basic_name":		"��",
	"b_id":			"qiang",
	"skill_type":		"spear",
	"verbs":		({ "thrust", "pierce", "impale"	}),
	"unit":			"��",
	"weight":		3000 + random(5000),
	"flag":			8,]),
"staff": ([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"zhang",
	"skill_type":		"staff",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		6000 + random(7000),
	"flag":			16,]),
"stick": ([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bang",
	"skill_type":		"stick",
	"rigidity":		1,
	"verbs":		({ "bash", "crush", "slam" }),
	"unit":			"��",
	"weight":		4000 + random(6000),
	"flag":			16,]),
"whip":	([ 
	"name":			"��",
	"basic_name":		"��",
	"b_id":			"bian",
	"skill_type":		"whip",
	"verbs":		({ "whip" }),
	"unit":			"��",
	"weight":		1000 + random(3000),
	"flag":			0,]),
]);


nosave mapping	Special_Class =	([
RED"�ɽ�" : ([	"id": ({ "ganjiang jian","ganjiang", "sword", "jian" }),
		"long2"	: RED"�ɽ������������ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop/damage":  350,
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"Īа" : ([	"id": ({ "moye jian","moye", "sword", "jian" }),
		"long2"	: RED"Īа�����������ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop/damage":  300,
		"sharpness":	       15,
		"rigidity":	       9,
		]),
RED"�㳦" : ([	"id": ({ "yuchang jian", "yuchang", "sword", "jian" }),
		"long2"	: RED"�㳦�����������ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop/damage":  220,
		"weapon_prop/attack":  300,
		"weapon_prop/sword":   100,
		"sharpness":	       8,
		"rigidity":	       7,
		]),
RED"̫��" : ([	"id": ({ "taie jian", "taie", "sword", "jian" }),
		"long2"	: RED"̫������������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
		"weapon_prop/damage":  150,
		"weapon_prop/qi":      4000,
		"weapon_prop/jing":    4000,
		"sharpness":	       7,
		"rigidity":	       9,
		]),
RED"����" : ([	"id": ({ "juque jian", "juque", "sword", "jian" }),
		"long2"	: RED"���ڱ�������Ӳ�ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop/damage":  270,
		"sharpness":	       7,
		"rigidity":	       20,
		]),
RED"����" : ([	"id": ({ "chunjun jian", "chunjun", "sword", "jian" }),
		"long2"	: RED"������������˧֮������֮�ܻӾ����򣬿˵���ʤ��\n"NOR,
		"weapon_prop/damage":  150,
		"weapon_prop/jingli":  4000,
		"weapon_prop/neili":   4000,
		"sharpness":	       7,
		"rigidity":	       8,
		]),
RED"տ¬" : ([	"id": ({ "zhanlu jian", "zhanlu", "sword", "jian"	}),
		"long2"	: RED"տ¬��������������������Ӳ���ھ���������ǧ�������\n"NOR,
		"weapon_prop/damage":  290,
		"sharpness":	       12,
		"rigidity":	       12,
		]),
RED"����" : ([	"id": ({ "gongbu jian", "gongbu", "sword", "jian" }),
		"long2"	: RED"�����������������죬���ܲ��̣�\n"NOR,
		"weapon_prop/damage":  150,
		"weapon_prop/attack":  200,
		"weapon_prop/parry":   200,
		"weapon_prop/dodge":   200,
		"weapon_prop/sword":   200,
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"ʤа" : ([	"id": ({ "shengxie jian", "shengxie", "sword", "jian" }),
		"long2"	: RED"ʤа�����������޴�����κ�Ҫ��\n"NOR,
		"weapon_prop/damage":  220,
		"sharpness":	       8,
		"rigidity":	       9,
		"wield_maxneili":      0,
		"wield_neili":	       0,
		"wield_str":	       0,
		]),
RED"��Ȫ" : ([	"id": ({ "longquan jian", "longquan", "sword", "jian" }),
		"long2"	: RED"��Ȫ�������˼伫Ʒ������������\n"NOR,
		"weapon_prop/damage":  190,
		"weapon_prop/dexerity":	40,
		"weapon_prop/strength":	40,
		"weapon_prop/constitution": 40,
		"weapon_prop/intelligence": 40,
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
	"�L�",	"�L��",	"���",	"���",	"��ޱ",	"ľ��",	"���F",	"̫�",
	"���Q",	"���Q",	"���Q",	"���Q",	"��ޱ",	"��ޱ",	"��ޱ",	"��ޱ",
	"��ޱ",	"���",	"���",	"���",	"���",	"���",	"��з",	"��ţ",
	"�۹�",	"����",	"����",	"����",	"����",	"����",	"����",	"��ɽ",
	"����",	"ժ��",	"̽��",	"����",	"����",	"��Ӱ",	"��ħ",	"����",
	"����",	"ǧ��",	"����",	"ǧâ",	"����",	"ħ��",	"���",
	"�Ͼ�",	"��ҳ",	"����",	"���",	"����",	"����",	"����",	"��ͼ",
	"Ѫն", "����", "����", "��â", "����", "����", "����", "����",
	"����", "Ӱ��", "���", "����", "˫��", "��ϼ", "����", "����",
	"����", "����", "�ۺ�", "��̳", "����", "����", "�ɷ�", "����",
	"��Ȫ",
});


string ask_imbue()
{
	object *obs;
	int i, pp = 0, sp = 0, gp = 0;
	string str = "������� dazao xxx �����Ҹ������������\n";

	obs = filter_array(children(USER_WEAPON), (: clonep :));
	i = sizeof(obs);
	if( i && i > 0 ){
		while(i--){
			switch(obs[i]->query("imbued")){
				case 5:	pp++; break;
				case 4:	sp++; break;
				case 3:	gp++; break;
				case 2:	
				case 1:	
				default: break;
			}
		}
	}
	if( pp > 0 ) str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(pp) +	"�Ѵ�˵�еı�����\n";
	if( sp > 0 ) str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(sp) +	"����ߵȼ���������\n";
	if( gp > 0 ) str += "		     Ŀǰ��Ϸ���Ѿ�����" + chinese_number(gp) +	"�Ѹߵȼ���������\n";
	return str;
}

string s_good(int i)
{
	switch(i){
		case 10..90:	return "�ޱ�";	
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
	if( i >= 300 )	return HIR"�������"NOR;
	if( i >= 280 )	return HIR"��Ԫ����"NOR;	
	if( i >= 250 )	return HIR"������˫"NOR;	
	if( i >= 220 )	return HIM"��������"NOR;	
	if( i >= 200 )	return HIY"������ƥ"NOR;
	if( i >= 180 )	return HIG"��������"NOR;
	if( i >= 160 )	return HIB"��������"NOR;
	if( i >= 140 )	return HIC"ն����ħ"NOR;
	if( i >= 120 )	return RED"�����ױ�"NOR;
	if( i >= 100 )	return MAG"�������"NOR;
	if( i >= 80 )	return YEL"�ܸ�"NOR;
	if( i >= 60 )	return GRN"ˮ׼����"NOR;
	if( i >= 40 )	return BLU"����"NOR;
	if( i >	20 )	return CYN"��С"NOR;
	if( i <= 0 )	return "����";
	if( i <= -20 )	return "����";
	return "һ��";
}

// Important mapping for user_weapon.
nosave mapping	mp;
nosave string *special_st = ({});
nosave string *name_st	= ({});


void special_weapon_status(int i)
{
	if( !i ) i = random(380);
	switch(i){
		case 0:	special_st += ({ HIG"����" });
			name_st	+= ({ "���Ӵ�����Ѫ" });
			mp["weapon_prop/qi"] = 1000 + random(2500);
			break;
		case 3:	special_st += ({ HIG"����" });
			name_st	+= ({ "���Ӻܶ���Ѫ" });
			mp["weapon_prop/qi"] = 700 + random(1800);
			break;
		case 6:	special_st += ({ HIG"����" });
			name_st	+= ({ "������Ѫ" });
			mp["weapon_prop/qi"] = 500 + random(1200);
			break;
		case 9:	special_st += ({ HIG"����" });
			name_st	+= ({ "����������Ѫ" });
			mp["weapon_prop/qi"] = 200 + random(700);
			break;
		case 12: special_st += ({ HIG"����" });
			name_st	+= ({ "���Ӵ�����Ѫ" });
			mp["weapon_prop/jing"] = 1000 +	random(2500);
			break;
		case 15: special_st += ({ HIG"����" });
			name_st	+= ({ "���ӺܶྫѪ" });
			mp["weapon_prop/jing"] = 700 + random(1800);
			break;
		case 18: special_st += ({ HIG"����" });
			name_st	+= ({ "���Ӿ�Ѫ" });
			mp["weapon_prop/jing"] = 500 + random(1200);
			break;
		case 21: special_st += ({ HIG"����" });
			name_st	+= ({ "����������Ѫ" });
			mp["weapon_prop/jing"] = 200 + random(700);
			break;
		case 24: special_st += ({ HIG"С����" });
			name_st	+= ({ "���Ӵ�������" });
			mp["weapon_prop/jingli"] = 1000	+ random(2500);
			break;
		case 27: special_st += ({ HIG"С����" });
			name_st	+= ({ "���Ӻܶྫ��" });
			mp["weapon_prop/jingli"] = 700 + random(1800);
			break;
		case 30: special_st += ({ HIG"С����" });
			name_st	+= ({ "���Ӿ���" });
			mp["weapon_prop/jingli"] = 500 + random(1200);
			break;
		case 33: special_st += ({ HIG"С����" });
			name_st	+= ({ "������������" });
			mp["weapon_prop/jingli"] = 200 + random(700);
			break;
		case 36: special_st += ({ HIG"������" });
			name_st	+= ({ "���Ӵ�������" });
			mp["weapon_prop/neili"]	= 1000 + random(2500);
			break;
		case 39: special_st += ({ HIG"������" });
			name_st	+= ({ "���Ӻܶ�����" });
			mp["weapon_prop/neili"]	= 700 +	random(1800);
			break;
		case 42: special_st += ({ HIG"������" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/neili"]	= 500 +	random(1200);
			break;
		case 45: special_st += ({ HIG"������" });
			name_st	+= ({ "������������" });
			mp["weapon_prop/neili"]	= 200 +	random(700);
			break;
		case 48: special_st += ({ HIR"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]) * 3;
			break;
		case 51: special_st += ({ HIR"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]) * 2;
			break;
		case 54: special_st += ({ HIW"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]);
			break;
		case 57: special_st += ({ HIW"��Ʒ" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/damage"] += mp["weapon_prop/damage"]/2;
			break;
		case 60: special_st += ({ HIC"��Ʒ" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]/2);
			break;
		case 63: special_st += ({ HIC"����" });
			name_st	+= ({ "��ǿ����" });
			mp["weapon_prop/damage"] += mp["weapon_prop/damage"]/4;
			break;
		case 66: special_st += ({ GRN"����" });
			name_st	+= ({ "���������Ҫ��" });
			mp["wield_maxneili"] = 0;
			break;
		case 69: special_st += ({ GRN"��ˮ" });
			name_st	+= ({ "�������Ҫ������" });
			mp["wield_maxneili"] /=	3;
			break;
		case 72: special_st += ({ GRN"�ᾧ" });
			name_st	+= ({ "�������Ҫ�����" });
			mp["wield_maxneili"] /=	2;
			break;
		case 75: special_st += ({ GRN"��ˮ" });
			name_st	+= ({ "�������Ҫ���С��" });
			mp["wield_maxneili"] -=	mp["wield_maxneili"]/3;
			break;
		case 78: special_st += ({ GRN"��" });
			name_st	+= ({ "������Ҫ��" });
			mp["wield_neili"] = 0;
			break;
		case 81: special_st += ({ HIW"��ˮ" });
			name_st	+= ({ "����Ҫ������" });
			mp["wield_neili"] /= 3;
			break;
		case 84: special_st += ({ HIW"����" });
			name_st	+= ({ "����Ҫ�����" });
			mp["wield_neili"] /= 2;
			break;
		case 87: special_st += ({ HIW"��ˮ" });
			name_st	+= ({ "����Ҫ���С��" });
			mp["wield_neili"] -= mp["wield_neili"]/3;
			break;
		case 90: special_st += ({ HIG"�⻪" });
			name_st	+= ({ "�������Ҫ��" });
			mp["wield_str"]	= 10;
			break;
		case 93: special_st += ({ HIG"�ʻ�" });
			name_st	+= ({ "����Ҫ������" });
			mp["wield_str"]	/= 3;
			break;
		case 96: special_st += ({ HIG"���" });
			name_st	+= ({ "����Ҫ�����" });
			mp["wield_str"]	/= 2;
			break;
		case 99: special_st += ({ HIG"����" });
			name_st	+= ({ "����Ҫ���С��" });
			mp["wield_str"]	-= mp["wield_str"]/3;
			break;
		case 102: special_st +=	({ HIW"���" });
			name_st	+= ({ "��Ʒ������" });
			mp["sharpness"]	+= 3 + random(8);
			break;
		case 105: special_st +=	({ HIW"����" });
			name_st	+= ({ "���ӷ�����" });
			mp["sharpness"]	+= 2 + random(6);
			break;
		case 108: special_st +=	({ HIW"����" });
			name_st	+= ({ "���ӷ�����" });
			mp["sharpness"]	+= 1 + random(3);
			break;
		case 112: special_st +=	({ HIW"����" });
			name_st	+= ({ "��ǿ������" });
			mp["sharpness"]	+= random(3);
			break;
		case 115: special_st +=	({ HIY"���" });
			name_st	+= ({ "��ƷӲ��" });
			mp["rigidity"] += 3 + random(8);
			break;
		case 118: special_st +=	({ HIY"����" });
			name_st	+= ({ "����Ӳ��" });
			mp["rigidity"] += 2 + random(6);
			break;
		case 121: special_st +=	({ HIY"����" });
			name_st	+= ({ "����Ӳ��" });
			mp["rigidity"] += 1 + random(3);
			break;
		case 124: special_st +=	({ HIY"����" });
			name_st	+= ({ "��ǿӲ��" });
			mp["rigidity"] += random(3);
			break;
		case 127: special_st +=	({ HIW"����" });
			name_st	+= ({ "��Ʒ����" });
			mp["weapon_prop/attack"] += (100 + random(100));
			break;
		case 130: special_st +=	({ HIB"쫵�" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/attack"] += (70	+ random(70));
			break;
		case 133: special_st +=	({ HIM"�ϵ�" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/attack"] += (40	+ random(40));
			break;
		case 136: special_st +=	({ HIW"�׵�" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/attack"] += (20	+ random(20));
			break;
		case 139: special_st +=	({ WHT"����" });
			name_st	+= ({ "��Ʒ˼ά" });
			mp["weapon_prop/intelligence"] += (5 +	random(5));
			break;
		case 142: special_st +=	({ WHT"����" });
			name_st	+= ({ "����˼ά" });
			mp["weapon_prop/intelligence"] += (3 +	random(4));
			break;
		case 145: special_st +=	({ WHT"����" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/intelligence"] += (2 + random(3));
			break;
		case 148: special_st +=	({ WHT"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/intelligence"] += (1 + random(2));
			break;
		case 151: special_st +=	({ BLU"����" });
			name_st	+= ({ "��Ʒ����" });
			mp["weapon_prop/constitution"] += (5 +	random(5));
			break;
		case 154: special_st +=	({ BLU"����" });
			name_st	+= ({ "���Ӹ���" });
			mp["weapon_prop/constitution"] += (3 +	random(4));
			break;
		case 157: special_st +=	({ BLU"����" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/constitution"] += (2 + random(3));
			break;
		case 160: special_st +=	({ BLU"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/constitution"] += (1 + random(2));
			break;
		case 163: special_st +=	({ HIM"����" });
			name_st	+= ({ "��Ʒ����" });
			mp["weapon_prop/strength"] += (5 + random(5));
			break;
		case 166: special_st +=	({ HIM"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/strength"] += (3 + random(4));
			break;
		case 169: special_st +=	({ HIM"����" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/strength"] += (2 + random(3));
			break;
		case 172: special_st +=	({ HIM"����" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/strength"] += (1 + random(2));
			break;
		case 175: special_st +=	({ MAG"��Ԩ" });
			name_st	+= ({ "��Ʒ�ٶ�" });
			mp["weapon_prop/dexerity"] += (5 + random(5));
			break;
		case 178: special_st +=	({ MAG"��Ԩ" });
			name_st	+= ({ "�����ٶ�" });
			mp["weapon_prop/dexerity"] += (3 + random(4));
			break;
		case 181: special_st +=	({ MAG"��Ԩ" });
			name_st	+= ({ "������" });
			mp["weapon_prop/dexerity"] += (2 + random(3));
			break;
		case 184: special_st +=	({ MAG"��Ԩ" });
			name_st	+= ({ "������" });
			mp["weapon_prop/dexerity"] += (1 + random(2));
			break;
		case 187: special_st +=	({ YEL"̴ľ" });
			name_st	+= ({ "ľ�ԣ�����Ҫ������" });
			mp["wield_str"]	/= 3;
			mp["material"] = "wood";
			break;
		case 190: special_st +=	({ GRN"����" });
			name_st	+= ({ "���ԣ�������Ҫ��" });
			mp["wield_str"]	= 0;
			mp["material"] = "bamboo";
			break;
		case 193: special_st +=	({ "����" });
			name_st	+= ({ "��������" });
			mp["weight"] /=	2;
			break;
		case 196: special_st +=	({ HIG"����" });
			name_st	+= ({ "�����ʲ�" });
			mp["material"] = "softsteel";
			break;
		case 199: special_st +=	({ HIB"�綾" });
			name_st	+= ({ "���Թ���" });
			mp["poisoned"] = "xx_poison";
			mp["poison_number"] = 500;
			break;
		case 202: special_st +=	({ HIB"һƷ��" });
			name_st	+= ({ "���߶�" });
			mp["poisoned"] = "bt_poison";
			mp["poison_number"] = 500;
			break;
		case 205: special_st +=	({ HIR"����" });
			name_st	+= ({ "�𶾹���" });
			mp["poisoned"] = "hot_poison";
			mp["poison_number"] = 500;
			break;
		case 208: special_st +=	({ HIG"�̲�" });
			name_st	+= ({ "�̲���¶�涾" });
			mp["poisoned"] = "lvbo_poison";
			mp["poison_number"] = 500;
			break;
		case 211: special_st +=	({ HIR"������" });
			name_st	+= ({ "�����ܶ�" });
			mp["poisoned"] = "man_poison";
			mp["poison_number"] = 500;
			break;
		case 214: special_st +=	({ HIB"ǧ��" });
			name_st	+= ({ "ǧ�붾" });
			mp["poisoned"] = "qzhu_poison";
			mp["poison_number"] = 500;
			break;
		case 217: special_st +=	({ BLU"��Ы" });
			name_st	+= ({ "��Ы��" });
			mp["poisoned"] = "scorpion_poison";
			mp["poison_number"] = 500;
			break;
		case 220: special_st +=	({ CYN"����" });
			name_st	+= ({ "���߶�" });
			mp["poisoned"] = "snake_poison";
			mp["poison_number"] = 500;
			break;
		case 223: special_st +=	({ CYN"����" });
			name_st	+= ({ "��������" });
			mp["poisoned"] = "cold_poison";
			mp["poison_number"] = 500;
			break;
		case 226: special_st +=	({ CYN"����" });
			name_st	+= ({ "��������" });
			mp["poisoned"] = "hb_poison";
			mp["poison_number"] = 500;
			break;
		case 229: special_st +=	({ BLU"��ħ" });
			name_st	+= ({ "���˹���" });
			mp["poisoned"] = "yyz_hurt";
			mp["poison_number"] = 500;
			break;
		case 232: special_st +=	({ BLU"��ʬ" });
			name_st	+= ({ "��ʬ����" });
			mp["poisoned"] = "fs_poison";
			mp["poison_number"] = 500;
			break;
		case 235: special_st +=	({ HIG"����" });
			name_st	+= ({ "���������;���" });
			mp["weapon_prop/neili"]	= 400 +	random(1100);
                        mp["weapon_prop/jingli"] = 400 + random(1100);
		case 238: special_st +=	({ HIY"��ʥ" });
			name_st	+= ({ "�����������" });
			mp["weapon_prop/dexerity"] += 8; 
			mp["weapon_prop/strength"] += 8; 
			mp["weapon_prop/constitution"] += 8; 
			mp["weapon_prop/intelligence"] += 8; 
			break;
		case 241: special_st +=	({ HIY"����" });
			name_st	+= ({ "������������" });
			mp["weapon_prop/dexerity"] += 5; 
			mp["weapon_prop/strength"] += 5; 
			mp["weapon_prop/constitution"] += 5; 
			mp["weapon_prop/intelligence"] += 5; 
			break;
		case 244: special_st +=	({ HIW"��ʯ" });
			name_st	+= ({ "���߷���" });
			mp["weapon_prop/parry"]	+= (70	+ random(70));
			break;
		case 247: special_st +=	({ HIM"��ʯ" });
			name_st	+= ({ "��߷���" });
			mp["weapon_prop/parry"]	+= (40	+ random(40));
			break;
		case 250: special_st +=	({ HIY"��ʯ" });
			name_st	+= ({ "��������" });
			mp["weapon_prop/parry"]	+= (20	+ random(20));
			break;
		case 253: special_st +=	({ BLU"��ʯ" });
			name_st	+= ({ "���߶��" });
			mp["weapon_prop/dodge"]	+= (70	+ random(70));
			break;
		case 256: special_st +=	({ HIB"��ʯ" });
			name_st	+= ({ "��߶��" });
			mp["weapon_prop/dodge"]	+= (40	+ random(40));
			break;
		case 259: special_st +=	({ HIR"��ʯ" });
			name_st	+= ({ "�������" });
			mp["weapon_prop/dodge"]	+= (20	+ random(20));
			break;
		case 262: special_st +=	({ HIY"��ľ" });
			name_st	+= ({ "��߷����Ͷ��" });
			mp["weapon_prop/dodge"]	+= (40	+ random(40));
			mp["weapon_prop/parry"]	+= (40	+ random(40));
			break;
		case 265: special_st +=	({ HIW"ˮ��" });
			name_st	+= ({ "������к�����" });
			mp["weapon_prop/attack"] += (40	+ random(40));
			mp["weapon_prop/damage"] += (20	+ random(40));
			break;
		case 268: special_st +=	({ HIR"����" });
			name_st	+= ({ "����������ڹ�����" });
			mp["weapon_prop/armor_vs_force"] += (40	+ random(40));
			mp["weapon_prop/damage"] += (20	+ random(40));
			break;
		case 271: special_st +=	({ YEL"����" });
			name_st	+= ({ "����ڹ����Ժͷ���" });
			mp["weapon_prop/parry"]	+= (40	+ random(40));
			mp["weapon_prop/armor_vs_force"] += (40	+ random(40));
			break;
		case 274: special_st +=	({ HIG"ľˮ" });
			name_st	+= ({ "��߶�ܺ�����" });
			mp["weapon_prop/attack"] += (40	+ random(40));
			mp["weapon_prop/dodge"]	+= (20	+ random(40));
			break;
		case 277: special_st +=	({ HIG"����" });
			name_st	+= ({ "������Ѫ�;�Ѫ" });
			mp["weapon_prop/qi"]	= 300 +	random(900);
			mp["weapon_prop/jing"]	= 300 +	random(900);
		default: break;
	}
	
	return;	
	
}
