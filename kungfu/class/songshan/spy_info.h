// Purpose : Spy job
// Creator : Numa@Sj 2000.4.29

mapping *spy = ({
	(["family":	"��ɽ��",				  // Which Party
	"item":		HIM"��ϼ�ؼ�"NOR,			  // What Treasure
	"item_desc":	"���ǻ�ɽ����ϼ���������ؼ�����ҳ���ơ�\n", // Treasure's Description
	"generation":	"12",					  // Top Master Generation
	"canask":	"linghu chong,yue buqun,ning zhongze",]),					  // Whom Can Ask

	(["family":	"������",
	"item":		HIR"�׽�ؼ�"NOR,
	"item_desc":	"������������ѧ�����׽�������ܷ���\n",	
	"generation":	"34",
	"canask":	"xuanci dashi,xuannan dashi,xuanbei dashi,xuanji dashi,huizhen zunzhe,huixiu zunzhe,du nan,du jie",]),

	(["family":	"����",
	"item":		HIB"Ǭ����Ų���ؼ�"NOR,
	"item_desc":	"�������̽������޼����г�¼��һ��Ǭ����Ų���ķ��ؼ���\n",
	"generation":	"34",
	"canask":	"zhang wuji,yin tianzheng,fan yao,yang xiao,leng qian",]),

	(["family":	"������",
	"item":		HIC"Ѫ���ؼ�"NOR,
	"item_desc":	"����ѩɽ��Ѫ�������һ�������ؼ�����ҳ���ơ�\n",	
	"generation":	"10",
	"canask":	"jiumo zhi,xuedao laozu,lingzhi shangren,sang jie,wenwo er,mohe basi,hu bayin,",]),

	(["family":	"ؤ��",
	"item":		HIW"�򹷰��ؼ�"NOR,
	"item_desc":	"����ؤ�ﳤ�Ϻ��߹���д�Ĵ򹷰��ķ���������\n",
	"generation":	"17",
	"canask":	"hong qigong,lu youjiao,song zhanglao,jiang zhanglao,xi zhanglao,quan guanqing,chen zhanglao",]),

	(["family":	"������",
	"item":		HIG"�����񽣽���"NOR,
	"item_desc":	"���Ǵ�����Ͻ����������ػ��������񽣽��ס�\n",
	"generation":	"12",
	"canask":	"kurong zhanglao,benyin dashi,benxiang dashi,benguan dashi,duan zhengming,duan zhengchun,",]),

	(["family":	"������",
	"item":		HIM"��ľ����"NOR,
	"item_desc":	"һֻ�������ɵİ���ɫСľ��, ľ��֮������������˿�����������ͭǮ���Բ�ף�ľ���뾱����һ��ϸ�죬�ƺ����·�Ϊ���ء�",
	"generation":	"1",
	"canask":	"ding chunqiu,zhaixing zi,anran zi,tianlang zi,shihou zi,azi,",]),
/*
	(["family":	"",
	"item":		"",
	"item_desc":	"",
	"generation":	"",
	"canask":	"",]),
*/
});

mapping place = ([
	"��ɽ��":	({"/d/huashan/qinshi",
			"/d/huashan/xiaoxi",
			"/d/huashan/siguoya",
			"/d/huashan/wuqiku",
			"/d/huashan/yaofang",}),
	"������":	({"/d/shaolin/yaowang",
			"/d/shaolin/luohan9",
			"/d/shaolin/banruo1",
			"/d/shaolin/zdyuan",}),
	"����":		({"/d/mingjiao/jyt",
			"/d/mingjiao/bishui",
			"/d/mingjiao/shiwang",
			"/d/mingjiao/xting",}),
	"������":	({"/d/xueshan/dadian",
			"/d/xueshan/zhudubadian",
			"/d/xueshan/yushengdian",
			"/d/xueshan/boluomiyuan",}),
	"ؤ��":		({"/d/gb/fenduo2",
			"/d/gb/pomiao",
			"/d/gb/xinglin9",}),
	"������":	({"/d/tls/baodian",
			"/d/tls/gfd",
			"/d/tls/ta3",
			"/d/tls/ta2",}),
	"������":	({"/d/xingxiu/ryd1",
			"/d/xingxiu/ryd",
			"/d/xingxiu/shanshi",
			"/d/xingxiu/house",}),
]);