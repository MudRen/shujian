// item.h

#include <armor.h>
#include <weapon.h>

#ifndef __ITEM__
#define __ITEM__

/*****************
   �ⲿ�ӿں�����
*****************/
// �������һ����װ���������涨��װ�ȼ�Ϊ�����װ�ȼ������涨����Ϊ�������
public varargs object create_mod_random(int level, string family);
// ����һ����װ�������������
public object create_mod(string num);
// ����һ����Ʒ���ߣ��������
public object create_obj_prime_armor(string num);
// ����һ����Ʒ�������������
public object create_obj_prime_weapon(string num);
// ����һ����Ʒ�����ݵȼ������������İٷֱ�
public varargs object create_obj(int level, int percent);
// ����һ����Ʒ����������͵ȼ�
public varargs object create_task_obj(string task, int level, string family);
// ����һ����Ʒ���������ͺ͵ȼ�
public object create_type_obj(string type, int level);
// ����һ���������������ͺ͵ȼ�
public object create_weapon(string type, int level);
// ����һ�����ߣ��������ͺ͵ȼ�
public object create_armor(string type, int level);
// ��һ��װ������ת��Ϊ�����ַ���
public string trans_eq_to_mark(object ob);
// ����һ����ʯ���������
public object create_gem(string num);
// �������һ��Ѱ��������Ʒ
public varargs object create_XB_task_ob();
// ����һ��BOSS��Ʒ������Ʒ��
public varargs object create_boss_obj(string quality);
// ����һ��BOSS������Ʒ���У����ݴ���ĵ��伸��ӳ�䡣
public varargs object *create_boss_award(mapping award_rate);
// ����һ��BOSS���䡣
public void create_boss_drop(object me, mapping award_rate);
// ����һ����Ʒ���ߣ��������
public object create_obj_prime_armor(string num);
// ����һ����Ʒ�������������
public object create_obj_prime_weapon(string num);
// �������һ����Ʒ���������涨�ȼ�Ϊ����ȼ�
public varargs object create_random_pri_weapon(int level);
// �������һ����Ʒ���ߣ����涨�ȼ�Ϊ����ȼ�
public varargs object create_random_pri_armor(int level);

/*****************
    �ڲ�������
*****************/
// ������������
private void set_weapon_name(object ob, string type, int level);
// �����������
private void set_armor_name(object ob, string type, int level);
// ������������
private void set_weapon_stats(object ob, int level);
// �����������
private void set_armor_stats(object ob, int level);
// ���type��level�Ϸ��� woa->�������Ƿ���
// type���󷵻�1 level���󷵻�2
private int do_legal(string type, int level, string woa);
// ����һ���������������
private void set_one_stats(string woa);
// �������Ե�ȫ�ּ�¼
private void save_to_stats(string type, int val);
// ���Ӽ��ܵ�ȫ�ּ�¼
private void save_to_skill_stats(string type, int val);
// ��һ�������ַ���ת��Ϊװ������
private mapping trans_mark_to_eq(string mark);
// ��һ�������ַ���ת��Ϊ��ʯ����
private mapping trans_mark_to_gem(string mark);

// ԭ���ļ�
mapping armor_dir = ([
	"CLOTH"		:	ARCHETYEP_DIR"armor/cloth",		//�·�
	"SKIRT"		:	ARCHETYEP_DIR"armor/skirt",		//��ȹ
	"HEAD"		:	ARCHETYEP_DIR"armor/head",		//ͷ��
	"NECK"		:	ARCHETYEP_DIR"armor/neck",		//����
	"ARMOR"		:	ARCHETYEP_DIR"armor/armor",		//����
	"SURCOAT"	:	ARCHETYEP_DIR"armor/surcoat",		//����
	"WAIST"		:	ARCHETYEP_DIR"armor/waist",		//����
	"WRISTS"	:	ARCHETYEP_DIR"armor/wrists",		//����
	"SHIELD"	:	ARCHETYEP_DIR"armor/shield",		//����
	"FINGER"	:	ARCHETYEP_DIR"armor/finger",		//��ָ
	"HANDS"		:	ARCHETYEP_DIR"armor/hands",		//����
	"BOOTS"		:	ARCHETYEP_DIR"armor/boots",		//Ь��
]);
mapping weapon_dir = ([
	"AXE"		:	ARCHETYEP_DIR"weapon/axe",		//����
	"BLADE"		:	ARCHETYEP_DIR"weapon/blade",		//����
	"FORK"		:	ARCHETYEP_DIR"weapon/fork",		//����
	"HAMMER"	:	ARCHETYEP_DIR"weapon/hammer",		//����
	"MACE"		:	ARCHETYEP_DIR"weapon/mace",		//���
	"RAKE"		:	ARCHETYEP_DIR"weapon/rake",		//����
	"SWORD"		:	ARCHETYEP_DIR"weapon/sword",		//����
	"STAFF"		:	ARCHETYEP_DIR"weapon/staff",		//����
	"STICK"		:	ARCHETYEP_DIR"weapon/stick",		//����
	"WHIP"		:	ARCHETYEP_DIR"weapon/whip",		//����
	"SPEAR"		:	ARCHETYEP_DIR"weapon/spear",		//ǹ��
        "ARROW"		:	ARCHETYEP_DIR"weapon/arrow",		//����
]);
// ��������
mapping armor_df_bas = ([
	"CLOTH"		:	PROP_CLOTH,		//�·�
	"SKIRT"		:	PROP_SKIRT,		//��ȹ
	"HEAD"		:	PROP_HEAD,		//ͷ��
	"NECK"		:	PROP_NECK,		//����
	"ARMOR"		:	PROP_ARMOR,		//����
	"SURCOAT"	:	PROP_SURCOAT,		//����
	"WAIST"		:	PROP_WAIST,		//����
	"WRISTS"	:	PROP_WRISTS,		//����
	"SHIELD"	:	PROP_SHIELD,		//����
	"FINGER"	:	PROP_FINGER,		//��ָ
	"HANDS"		:	PROP_HANDS,		//����
	"BOOTS"		:	PROP_BOOTS,		//Ь��
]);
// �����˺�
mapping weapon_dam_bas = ([
	"AXE"		:	DEFAULT_DAMAGE,		//����
	"BLADE"		:	DEFAULT_DAMAGE,		//����
	"FORK"		:	DEFAULT_DAMAGE,		//����
	"HAMMER"	:	DEFAULT_DAMAGE,		//����
	"MACE"		:	DEFAULT_DAMAGE,		//���
	"RAKE"		:	DEFAULT_DAMAGE,		//����
	"SWORD"		:	DEFAULT_DAMAGE,		//����
	"STAFF"		:	DEFAULT_DAMAGE,		//����
	"STICK"		:	DEFAULT_DAMAGE,		//����
	"WHIP"		:	DEFAULT_DAMAGE,		//����
	"SPEAR"		:	DEFAULT_DAMAGE,		//ǹ��
	"ARROW"		:	DEFAULT_DAMAGE,		//����
]);
// ���������͵ļ���ID
mapping short_id_weapon = ([
	"AXE"		:	"fu",		//����
	"BLADE"		:	"dao",		//����
	"FORK"		:	"cha",		//����
	"HAMMER"	:	"chui",		//����
	"MACE"		:	"jian",		//���
	"RAKE"		:	"pa",		//����
	"SWORD"		:	"jian",		//����
	"STAFF"		:	"zhang",	//����
	"STICK"		:	"gun",		//����
	"WHIP"		:	"bian",		//����
	"SPEAR"		:	"qiang",	//ǹ��
   "ARROW"		:	"gong",	//����
]);
// ���߰����͵ļ���ID
mapping short_id_armor = ([
	"CLOTH"		:	"yi",		//�·�
	"SKIRT"		:	"qun",		//��ȹ
	"HEAD"		:	"kui",		//ͷ��
	"NECK"		:	"xiangliang",	//����
	"ARMOR"		:	"jia",		//����
	"SURCOAT"	:	"pifeng",	//����
	"WAIST"		:	"yaodai",	//����
	"WRISTS"	:	"huwan",	//����
	"SHIELD"	:	"dun",		//����
	"FINGER"	:	"ring",		//��ָ
	"HANDS"		:	"glove",	//����
	"BOOTS"		:	"xue",		//Ь��
]);

// �������Դ����б�
string *public_stats_list = ({
	"str", 
	"dex", 
	"con", 
	"spi", 
	"int", 
	"cor", 
	"per", 
	"kar", 
	"attack", 
	"force", 
	"spells", 
	"dodge", 
	"RLC_force", 
	"RLC_mana", 
	"RLC_kee", 
	"RLC_sen", 
	"DF_force", 
	"DF_spells", 
	"RE_force", 
	"RE_spells", 
});
// �������Դ����б�
string *weapon_stats_list = ({
	"damage", 
	"min_damage", 
});
// �������Դ����б�
string *armor_stats_list = ({
	"armor",
});
// ȫ�����Դ��Ŷ�Ӧװ��ÿ���һ���ȼ��������ӵ�����
mapping stats_list = ([
	"damage"	:	8,
	"min_damage"	:	2, 
	"armor"		:	5,
	"str"		:	2, 
	"dex"		:	2, 
	"con"		:	2, 
	"spi"		:	2, 
	"int"		:	2, 
	"cor"		:	2, 
	"per"		:	2, 
	"kar"		:	2, 
	"attack"	:	3, 
	"force"		:	3, 
	"spells"	:	3, 
	"dodge"		:	3, 
	"RLC_force"	:	2, 
	"RLC_mana"	:	2, 
	"RLC_kee"	:	2, 
	"RLC_sen"	:	2, 
	"DF_force"	:	1, 
	"DF_spells"	:	1, 
	"RE_force"	:	1, 
	"RE_spells"	:	1, 
	"gain_gold"	:	4, 
	"gain_exp"	:	2, 
	"gain_pot"	:	2, 
	"gain_eq"	:	1, 
]);
// ���ܴ����б�
string *skill_list = ({
	"force",	"dodge",	"parry",	"spells",	"unarmed",
	"axe",		"blade",	"fork",		"hammer",	"mace",
	"rake",		"sword",	"staff",	"stick",	"whip",
	"jienan-zhi",	"lotusmove",	"buddhism",	"cibeidao",	
	"lotusforce",	"lunhui-zhang",
	"jinghun-zhang","ghost-steps",	"tonsillit",	"gouhunshu",	
	"hellfire-whip","zhuihun-sword","kusang-bang",
	"puti-zhi",	"jindouyun",	"wuxiangforce",	"dao",		
	"qianjun-bang",	"liangyi-sword",
	"baihua-zhang",	"moondance",	"moonforce",	"moonshentong",	
	"snowsword",	"jueqingbian",
	"cuixin-zhang",	"xiaoyaoyou",	"ningxie-force","dengxian-dafa",	
	"bainiao-jian",	"bingpo-blade",
	"wuxing-quan",	"baguazhen",	"zhenyuan-force","taiyi",	
	"sanqing-jian",	"yange-blade",
	"dragonfight",	"dragonstep",	"seashentong",	"dragonforce",	
	"fengbo-cha",	"huntian-hammer",
	"yinfeng-zhua",	"lingfu-steps",	"yaofa",	"huntian-qigong",	
	"qixiu-jian",	"kugu-blade",
});
// װ������
mapping name_list = ([
	"AXE"		:	
		([
			"���ְ師"	:	"chelun axe",
			"��ȸ��ɽ��"	:	"jinque axe",
			"�����師"	:	"xuanhua axe",
			"������"	:	"yueya axe",
			"����������"	:	"bagua axe",
			"��ͷ��"	:	"fengtou axe",
			"��պ��"	:	"jinzhan axe",
			"�Ӹְ師"	:	"jiagang axe",
			"������ɽ��"	:	"yueyakaishan axe",
			"��ͭ��"	:	"qingtong axe",
			"�����師"	:	"baohua axe",
			"����"	:	"shenjin axe",
			"���¼Ӹָ�"	:	"riyu axe",
			"����������"	:	"erlong axe",
			"���Կ��츫"	:	"kaitian axe",
			"��ͷ��߬��"	:	"fengtou axe",
			"�̰���ͭ��"	:	"duanba axe",
			"�̰�������"	:	"bingtie axe",
		]),
	"BLADE"		:	
		([
			"�𱳴󿳵�"	:	"jinbei blade", 
			"���ȴ�"	:	"menshan blade", 
			"��ﳯ����"	:	"chaoyang blade",  
			"��ǹ��µ�"	:	"guyue blade",  
			"��ɽ��"	:	"kanshan blade",  
			"�������е�"	:	"sanjian blade",  
			"���Ȱ��ŵ�"	:	"heshan blade", 
			"�𱳿�ɽ��"	:	"kanshan blade",  
			"���ᵶ"	:	"yanling blade",  
			"��ͭ��"	:	"qingtong blade",  
			"���ﵶ"	:	"danfeng blade",  
			"���ź�ӧ��"	:	"hongying blade",  
			"���޵�"	:	"xiurong blade",  
			"����ߡ����"	:	"qixing blade",  
			"������"	:	"huya blade", 
			"�Ŷ��˻���"	:	"bahuan blade",  
			"�����Ͻ�"	:	"yulin blade",  
			"�����ͷ��"	:	"guitou blade",  
			"������"	:	"liangyin blade",  
			"��⵶"	:	"dianguang blade",  
			"�߱����"	:	"cuojin blade",  
			"��ͭ��"	:	"chitong blade",  
			"��ˮ��"	:	"pishui blade",  
			"��ֵ�"	:	"qinggang blade", 
		]),
	"FORK"		:	
		([
			"��������"	:	"lieyan fork",  
			"�Ź������"	:	"tuotian fork",   
			"����������"	:	"liangyin fork",   
			"���������"	:	"tuotian fork",   
			"��ɸֲ�"	:	"gang fork",   
			"��������"	:	"tuotian fork",   
			"���ɸֲ�"	:	"gang fork",   
			"��������"	:	"lieyan fork",   
			"���������"	:	"lieyan fork",   
			"���������"	:	"lieyan fork",   
			"��ͭ��"	:	"qingtong fork",   
			"�Ź������"	:	"lieyan fork",   
			"�平��ɲ�"	:	"shenfei fork",   
			"�����ͭ��"	:	"qingtong fork",   
		]),
	"HAMMER"	:	
		([
			"�����Ͻ�"	:	"zijin hammer",   
			"����ƽ�"	:	"huangjin hammer",    
			"������ͭ��"	:	"shengtong hammer",    
			"����������"	:	"liangyin hammer",    
			"�������ʹ�"	:	"bingtie hammer",    
			"����������"	:	"bagua hammer",    
			"�޹��ͽ�"	:	"leigu hammer",    
			"��ͷ���Ӵ�"	:	"longtou hammer",   
			"����������"	:	"baleng hammer",    
			"����������"	:	"bagua hammer",    
			"�ڻ�ͭ��"	:	"heihu hammer",    
			"�ڽ�"	:	"wujin hammer",    
			"ѹ��������"	:	"lanlong hammer",    
			"�����ͭ��"	:	"chitong hammer",    
			"����"	:	"guasuo hammer",    
			"�˱���ⴸ"	:	"dianguang hammer",    
			"��ͭ���Ӵ�"	:	"lianzi hammer",    
			"����Ͻ�"	:	"zijin hammer",    
			"����ͭ��"	:	"baleng hammer",    
			"��Բ��"	:	"hunyuan hammer",    
			"��ͭ�ѹϴ�"	:	"wogua hammer",   
			"��ĸԧ�촸"	:	"zimu hammer",    
			"�������Ӵ�"	:	"lianzi hammer",    
			"�˽��Ͻ�"	:	"bajiao hammer",    
			"��ͭ��"	:	"hongtong hammer",    
			"�˱�������"	:	"babao hammer",    
		]),
	"MACE"		:	
		([
			"�����װ�"	:	"wamian mace",   
			"���������"	:	"bingtie mace", 
			"��������"	:	"baleng mace", 
			"�����"	:	"sileng mace", 
			"��ͭ�"	:	"shutong mace", 
			"��װ�"	:	"jinzhuang mace", 
			"������"	:	"pantong mace", 
			"�ķ������"	:	"bingtie mace", 
			"��ͭ�����"	:	"qingtong mace", 
			"��װ�"	:	"yinzhuang mace",
		]),
	"RAKE"		:	
		([
			"�̰�������"	:	"duanba rake",   
			"��������"	:	"huagan rake",   
			"�����"	:	"sancha rake",   
			"������"	:	"yinlong rake",   
			"��β��"	:	"baowei rake",   
			"��ᦰ�"	:	"huangpo rake",   
			"����"	:	"miaojin rake",   
			"˫��������"	:	"shuanger rake",  
			"��ͭ��"	:	"qingtong rake",  
		]),
	"SWORD"		:	
		([
			"���ƹŶ���"	:	"guding sword",   
			"�����̺罣"	:	"liuhong sword",    
			"������潣"	:	"qingfeng sword",    
			"͸����"	:	"toulong sword",    
			"ɥ�ű���"	:	"sanmeng sword",    
			"�ϵ���˪��"	:	"zidian sword",    
			"��˪��"	:	"zishuang sword",    
			"���齣"	:	"biling sword",    
			"���߱���"	:	"panshe sword",    
			"��������"	:	"panlong sword",    
			"���ǽ�"	:	"tianlang sword",    
			"�ڹ���"	:	"wugou sword",    
			"��ֽ�"	:	"qinggang sword",    
			"ԧ�콣"	:	"yanyang sword",    
			"��Ƽ��"	:	"qingping sword",    
			"̫�Ͻ�"	:	"taihe sword",    
			"���»�����"	:	"huolong sword",    
			"������"	:	"qinglong sword",    
			"������"	:	"zhulong sword",    
			"������"	:	"kunlong sword",    
			"���⽣"	:	"hanguang sword",    
			"��Ҷ��"	:	"liuye sword",    
			"���콣"	:	"fentian sword",    
			"��Ҷ��潣"	:	"luoye sword",   
			"������ֽ�"	:	"qinggang sword",    
			"���罣"	:	"changhong sword",   
			"ն�ɽ�"	:	"zhanxian sword",    
			"������"	:	"wulong sword",    
			"���ƽ�"	:	"qingyun sword",    
			"�滨����"	:	"lihua sword",    
			"�׹⽣"	:	"baiguang sword",    
			"���Ʊ���"	:	"caiyun sword",    
		]),
	"STAFF"		:	
		([
			"������"	:	"yinyang staff",   
			"�X����"	:	"lilai staff",  
			"ī����"	:	"mojiao staff",  
			"ţ����"	:	"niujiao staff",  
			"������"	:	"dulong staff",  
			"����������"	:	"woyu staff",  
			"����������"	:	"dingzi staff",  
			"����������"	:	"huaibao staff",  
			"��ͷ��"	:	"longtou staff",  
			"��ͷ��"	:	"hutou staff", 
			"������"	:	"qixing staff",  
			"����˫����"	:	"hushou staff",  
			"ԧ����"	:	"yanyang staff",  
			"����������"	:	"woyu staff",  
			"������"	:	"chenxiang staff",  
			"��§��ͷ��"	:	"goulou staff",  
			"����ԧ����"	:	"yanyang staff", 
		]),
	"STICK"		:	
		([
			"ˮ��������"	:	"qiulong stick",   
			"��ɽ��"	:	"kaishan stick", 
			"����������"	:	"dingding stick", 
			"������޼��"	:	"shenjin stick", 
			"�Ͻ������"	:	"zijin stick", 
			"���Ͱ�"	:	"wuyou stick", 
			"�����"	:	"baleng stick", 
			"��ͷ���"	:	"longtou stick", 
			"������"	:	"huntie stick", 
			"���"	:	"tiangang stick", 
			"���������"	:	"dulong stick", 
			"���߰�"	:	"xingzhe stick", 
			"����������"	:	"langya stick", 
			"��ͭ��޼��"	:	"qingtong stick", 
			"������˿��"	:	"luosi stick", 
			"��˿���߰�"	:	"tengshe stick", 
			"���������"	:	"jinguang stick", 
			"�ٶ�������"	:	"baiding stick", 
			"�������"	:	"ziteng stick", 
			"��ͭ���"	:	"qingtong stick", 
			"��˿���"	:	"jinsi stick",
		]),
	"WHIP"		:	
		([
			"������"	:	"liangyin whip",
			"��ڸֱ�"	:	"zhujie whip",
			"��β��"	:	"baowei whip", 
			"�򽫱�"	:	"dajiang whip", 
			"�չ������"	:	"tuogu whip", 
			"������"	:	"jinlong whip", 
			"��β�ֱ�"	:	"huwei whip", 
			"������"	:	"bingtie whip", 
			"��ͷ��β��"	:	"longtou whip", 
			"���۸ֱ�"	:	"huyan whip", 
			"��˿���"	:	"jinsi whip", 
			"��«��"	:	"hulu whip", 
			"��Ǳ�"	:	"guigu whip", 
			"��β��"	:	"yugu whip", 
			"�߹Ǳ�"	:	"shegu whip", 
			"��˿���"	:	"yinsi whip", 
			"����ɨ����"	:	"zheyun whip", 
		]),
	"SPEAR"		:	
		([
			"�����ǹ"	:	"ruyi spear",   
			"�������ǹ"	:	"diangang spear",    
			"÷������ǹ"	:	"meihua spear",    
			"����ǹ"	:	"panzhu spear",    
			"��ӧǹ"	:	"suying spear",    
			"�平���ǹ"	:	"shenfei spear",    
			"��ˮ��¬ǹ"	:	"tilu spear",    
			"����ǹ"	:	"goulian spear",    
			"����ǹ"	:	"shelian spear",    
			"����ǹ"	:	"huya spear",    
			"�ڽ�ǹ"	:	"wujin spear",    
			"����ǹ"	:	"huntie spear",    
			"��ͷ���ǹ"	:	"zuanjin spear",    
			"����˫ǹ"	:	"qilin spear",    
			"¹������ǹ"	:	"ruanteng spear",    
			"���ǹ"	:	"diangang spear",    
			"�ɰ���ìǹ"	:	"shemao spear",    
			"����ǹ"	:	"liuhe spear",    
			"�����ǹ"	:	"panlong spear",    
			"���ǹ"	:	"jinfeng spear",   
			"�滨ǹ"	:	"lihua spear",    
			"�ɰ˹���ǹ"	:	"gunyun spear",    
			"��¬ǹ"	:	"tilu spear",    
			"���ǹ"	:	"huojian spear",   
		]),
	"CLOTH"		:	
		([
			"�鲼��"	:	"mabu cloth",
			"�޲���"	:	"mianbu cloth",
			"����"	:	"choubu cloth",
			"��ѩ��"	:	"feixue cloth",
			"ҹħ��"	:	"yemo cloth",
			"��˿��"	:	"qingsi cloth",
			"������"	:	"jiutian cloth",
			"������"	:	"xuwu cloth",
			"��ڤ��"	:	"qingming cloth",
			"������"	:	"yunluo cloth",
			"˿����"	:	"silk cloth",
		]),
	"SKIRT"		:	
		([
			"ǧ��ȹ"	:	"qianze skirt",
			"��˿�˱�ȹ"	:	"babao skirt",
			"�������ȹ"	:	"wufeng skirt",
			"���̹�ȹ"	:	"gong skirt",
			"˫���Ŀȹ"	:	"bimu skirt",
			"�ƽ�ȹ"	:	"lvjin skirt",
			"�ٵ�ȹ"	:	"baidie skirt",
			"����ȹ"	:	"chuanhua skirt",
			"����ȹ"	:	"wucai skirt",
			"����ȹ"	:	"feicui skirt",
			"�����ȹ"	:	"sahua skirt",
		]),
	"HEAD"		:	
		([
			"������ͷ"	:	"naolong kui",
			"ҹ����"	:	"yeming kui",
			"�����"	:	"fengchi kui",
			"ͭ��Ҷ��"	:	"heye kui",
			"�ƽ�˧�ֿ�"	:	"huangjin kui", 
			"������"	:	"yinlian kui",
			"��ˮ��"	:	"fenshui kui",
			"��ﳯ����"	:	"chaoyang kui", 
			"���������"	:	"fengchi kui", 
			"������"	:	"langya kui", 
			"��ﻨ��"	:	"wufeng kui", 
			"̫���"	:	"taisui kui", 
			"�����"	:	"zuantian kui",
			"������ͷ��"	:	"hutou kui", 
			"���ӿ�"	:	"baozi kui", 
			"�������"	:	"hudie kui", 
			"˫���"	:	"shuangfeng guan", 
			"����"	:	"jinfeng guan",  
			"����"	:	"chijin guan",  
			"��ϼ��"	:	"jinxia guan", 
			"�Ͻ��"	:	"zijin guan",  
			"�������"	:	"shufa guan",  
			"���������"	:	"lieyan guan", 
		]),
	"NECK"		:	
		([
			"�ں�����"	:	"heihu necklace",
			"Ů����"	:	"nvshen necklace",
			"������"	:	"yin necklace",
			"ͭ����"	:	"tong necklace",
			"������"	:	"jin necklace",
			"��������"	:	"lanyu necklace",
			"��ˮ������"	:	"shuijing necklace",
			"��ͭ����"	:	"qingtong necklace",
			"��ͷ����"	:	"congtou necklace",
			"��������"	:	"kulou necklace",
			"��������"	:	"gushu necklace",
			"�������"	:	"feicui necklace",
			"��������"	:	"binglin necklace",
		]),
	"ARMOR"		:
		([
			"��Ҷ������"	:	"liuye armor",
			"��Ҷ���ۼ�"	:	"yulin armor",
			"��Ҷ���ۼ�"	:	"longlin armor",
			"������"	:	"bingtie armor", 
			"�������"	:	"chijin armor", 
			"�ƽ��"	:	"huangjin armor",
			"�걳��"	:	"guibei armor",
			"ī���"	:	"moyu armor",
			"��ͭ��Ҷ��"	:	"chitong armor",
			"��װ��"	:	"yinzhuang armor", 
			"����������"	:	"lianhuan armor",
			"������Ƽ�"	:	"yueluo armor",
			"��˿���"	:	"jinsi armor",
			"���ټ�"	:	"ziteng armor",
			"�Ͻ��ļ�"	:	"huxin armor", 
			"��Ҷ������"	:	"heye armor", 
		]),
	"SURCOAT"	:	
		([
			"ҹ������"	:	"yeguang pifeng",
			"�ƽ�����"	:	"huangjin pifeng",
			"�಼����"	:	"mianbu pifeng",
			"��Ƥ����"	:	"yangpi pifeng",
			"��ж���"	:	"chouduan pifeng",
			"��춷��"	:	"chihong pifeng",
			"�������"	:	"lingjiao pifeng",
			"ս������"	:	"zhanyue pifeng",
			"��������"	:	"yishou pifeng",
		]),
	"WAIST"		:	
		([
			"��������"	:	"fanbu waist",
			"��Ƥ����"	:	"zhenpi waist",
			"��֯����"	:	"bianzhi waist",
			"�ֲ�����"	:	"cubu waist",
			"��������"	:	"shengtie waist",
			"��������"	:	"hupo waist",
			"��������"	:	"binglin waist",
			"��������"	:	"baiying waist",
			"�������"	:	"feicui waist",
		]),
	"WRISTS"	:	
		([
			"�ֲ�����"	:	"cubu wrists",
			"������"	:	"zizhu wrists",
			"��ľ����"	:	"gumu wrists",
			"��ͭ����"	:	"qingtong wrists",
			"��������"	:	"jingtie wrists",
			"��令��"	:	"feicui wrists",
			"�ƽ���"	:	"huangjin wrists",
			"���ۻ���"	:	"bingling wrists",
		]),
	"SHIELD"	:	
		([
			"����Բ��"	:	"yuan shield",
			"�մɶ�"	:	"ci shield",
			"����֮��"	:	"huolong shield",
			"ʨ�Ӷ�"	:	"shizi shield",
			"��ͷպ���"	:	"hutou shield",
			"��Ƥ��Ƭ��"	:	"hupi shield",
			"��ľ��"	:	"tengmu shield",
			"���ֶ���"	:	"jinggang shield",
		]),
	"FINGER"	:
		([
			"�����ָ"	:	"yongheng ring",
			"����ָ"	:	"hua ring",
			"����ָ"	:	"yin ring",
			"���Ͻ�ָ"	:	"weiyan ring",
			"�����ָ"	:	"shouling ring",
			"������ָ"	:	"gushu ring",
			"��ʿ��ָ"	:	"yinshi ring",
			"ʮ�ֹǽ�"	:	"shizi ring",
			"ˮ����ָ"	:	"shuijing ring",
			"���۽�ָ"	:	"bingling ring",
			"����ָ"	:	"feicui ring",
			"��ѩ��ָ"	:	"feixue ring",
			"�����ָ"	:	"zizhu ring",
			"�޹ǽ�ָ"	:	"shougu ring",
		]),
	"HANDS"		:	
		([
			"��������"	:	"liuyun glove",
			"��������"	:	"chilian glove",
			"��������"	:	"xuwu glove",
			"�ֽ�����"	:	"liujin glove",
			"��������"	:	"bingtie glove",
		]),
	"BOOTS"		:	
		([
			"����ѥ"	:	"liuyun shoes",
			"����ѥ"	:	"chilian shoes",
			"����ѥ"	:	"xuwu shoes",
			"�ֽ�ѥ"	:	"liujin shoes",
			"����ѥ"	:	"huolong shoes",
			"��Ƥѥ"	:	"shoupi shoes",
			"ͭ��ѥ"	:	"tongya shoes",
			"����ѥ"	:	"jingtie shoes",
			"�˷�ѥ"	:	"chengfeng shoes",
			"����ѥ"	:	"huwen shoes",
			"����ѥ"	:	"polang shoes",
		]),
]);

string *item_color = ({
  	HIW, 	HIB, 	HIC, 	HIR, 	HIM, 	HIY, 	HIG,
  	WHT, 	BLU, 	CYN, 	RED, 	MAG, 	YEL, 	NOR,
});


#endif
