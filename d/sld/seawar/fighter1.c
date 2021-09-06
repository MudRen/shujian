// seawar fighter.c
// 2/1/2002  by augx@sj

#include <ansi.h>
#define	SEAWAR_D	__DIR__"seaward"
inherit NPC;

void set_party(int shen,int party);
void do_copy(object ob);

void create()
{
	set("target",0);
	set("job",0);
	set("team",0);
	set("score",10);

	set_name("սʿ", ({ "fighter" }));
	set("gender","����");
	set("long","\n");
	set("age", 27+random(30));
	set("attitude", "peaceful");
	set("combat_exp", 5000000);

        set("str", 40+random(10));
        set("int", 40+random(10));
        set("con", 40+random(10));
        set("dex", 40+random(10));

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);
	set_temp("apply/armor", 100);

	set("no_ansuan",1);
	set("no_bark", 1);
	set("no_quest", 1);
	set("no_get", 1);
	set("location", 1);

	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("stick", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("whip", 500);
	set_skill("dagger", 500);
	set_skill("hook", 500);
	set_skill("poison", 200);
	set_skill("literate", query("int") * 10);
	set("location",1);

	setup();
	if(clonep()) call_out("dest_me",5*60);
}

void dest_me()
{
	call_out("dest_me",60);
	destruct( this_object() );
}

void wieldweapon()
{
	object wp;
	string weapon = query("weapon");
	if( weapon == "null" ) return;
	wp = carry_object(BINGQI_D(weapon));
	wp->set("weapon_prop/damage", query("damage"));
	if( weapon == "falun" ) wp->set_amount(5);
	wp->wield();
}

void set_party(int shen,int party)
{
	mapping name;
	int i;
	string weapon = "null" , menpai , title;

	i = random(4);
	name = RNAME_D->get_random_name(i);
	set("gender", i?"����":"Ů��");

	if(shen>0) {
		if(party<0) party = random(26);
		set_name(name["name"], name["id"] + ({ "wu jiang" }));
		set("long","����λ����͢Ч����������ʿ�������������������á�\n");

		switch(random(6)) {
			case 0: title = "����"; break;
			case 1: title = "ǧ��"; break;
			case 2: title = "�ر�"; break;
			case 3: title = "��˾"; break;
			case 4: title = "�λ�"; break;
			case 5: title = "�ν�"; break;
		}
		set("title",HIY"����ˮʦ"+title+NOR);
	}
	else {
		if(party<0) party = 50 + random(20);
		set_name(name["name"], name["id"] + ({ "hu fa" }));
		set("long","����λ�����̸߼���ļ����������ʿ�������˰̣�һ���׺ݶ��Ե������ӡ�\n");

		switch(random(6)) {
			case 0: title = "����"; break;
			case 1: title = "�����Ż���"; break;
			case 2: title = "�����Ż���"; break;
			case 3: title = "�����Ż���"; break;
			case 4: title = "�����Ż���"; break;
			case 5: title = "�����Ż���"; break;
		}
		set("title",HIR"������"+title+NOR);
	}

	switch( party ) {
	case 0:  // wd1
		set_skill("yinyun-ziqi", 500);
		set_skill("tiyunzong", 500);
		set_skill("taiji-jian", 500);
		set_skill("taiji-quan", 500);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-quan");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 65);
		set("chat_msg_combat", ({
			(: exert_function, "taiji" :),
			(: perform_action, "cuff.zhan" :),
			(: perform_action, "cuff.ji" :),
			(: perform_action, "cuff.zhen" :),
			(: perform_action, "cuff.luanhuan" :),
		}));
		menpai = "�䵱";
		break;
	case 1:  // wd2
		set_skill("yinyun-ziqi", 500);
		set_skill("tiyunzong", 500);
		set_skill("taiji-jian", 500);
		set_skill("taiji-quan", 500);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-jian");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: perform_action, "dodge.zong" :),
			(: perform_action, "sword.chan" :),
			(: perform_action, "sword.sanhuan" :),
			(: perform_action, "sword.lian" :),
		}));
		weapon = "sword";
		menpai = "�䵱";
		break;
	case 2:  // sl1
		set_skill("yijin-jing", 500);
		set_skill("shaolin-shenfa", 500);
		set_skill("riyue-bian", 500);
		set_skill("yizhi-chan", 500);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("whip", "riyue-bian");
		map_skill("parry", "riyue-bian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "whip.chanrao" :),
			(: perform_action, "whip.fumoquan" :),
		}));
		weapon = "whip";
		menpai = "����";
		break;
	case 3:  // sl2
		set_skill("yijin-jing", 500);
		set_skill("shaolin-shenfa", 500);
		set_skill("damo-jian", 500);
		set_skill("yizhi-chan", 500);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("sword", "damo-jian");
		map_skill("parry", "damo-jian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "sword.sanjue" :),
		}));
		weapon = "sword";
		menpai = "����";
		break;
	case 4:  // sl3
		set_skill("yijin-jing", 500);
		set_skill("shaolin-shenfa", 500);
		set_skill("yizhi-chan", 500);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("parry", "yizhi-chan");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "finger.wofo" :),
			(: perform_action, "finger.qiankun" :),
		}));
		menpai = "����";
		break;
	case 5:  // hs1
		set_skill("zixia-gong", 500);
		set_skill("huashan-shenfa", 500);
		set_skill("huashan-jianfa", 500);
		set_skill("hunyuan-zhang", 500);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("sword", "huashan-jianfa");
		map_skill("parry", "huashan-jianfa");
		map_skill("strike", "hunyuan-zhang");
		prepare_skill("strike", "hunyuan-zhang");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "sword.jianzhang" :),
			(: perform_action, "sword.fengyi" :),
		}));
		weapon = "sword";
		menpai = "��ɽ";
		break;
	case 6:  // hs2
		set_skill("zixia-gong", 500);
		set_skill("huashan-shenfa", 500);
		set_skill("fanliangyi-dao", 500);
		set_skill("poyu-quan", 500);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("blade", "fanliangyi-dao");
		map_skill("parry", "fanliangyi-dao");
		map_skill("cuff", "poyu-quan");
		prepare_skill("cuff", "poyu-quan");
		set("chat_chance_combat", 75);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "blade.sanshenfeng" :),
		}));
		weapon = "blade";
		menpai = "��ɽ";
		break;
	case 7:  // gb1
		set_skill("huntian-qigong", 500);
		set_skill("bangjue", 500);
		set_skill("xiaoyaoyou", 500);
		set_skill("dagou-bang", 500);
		set_skill("xianglong-zhang", 500);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "dagou-bang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "huntian" :),
			(: perform_action, "stick.chuo" :),
			(: perform_action, "stick.chan" :),
			(: perform_action, "stick.wugou" :),
		}));
		weapon = "stick";
		menpai = "ؤ��";
		break;
	case 8:  // gb2
		set_skill("huntian-qigong", 500);
		set_skill("bangjue", 500);
		set_skill("xiaoyaoyou", 500);
		set_skill("dagou-bang", 500);
		set_skill("xianglong-zhang", 500);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "xianglong-zhang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiao" :),
//			(: perform_action, "strike.paiyun" :),
		}));
		menpai = "ؤ��";
		break;
	case 62:
	case 9:  // thd1
		set_skill("bihai-chaosheng", 500);
		set_skill("qimen-bagua", 500);
		set_skill("suibo-zhuliu", 500);
		set_skill("yuxiao-jian", 500);
		set_skill("tanzhi-shentong", 500);
		set_skill("lanhua-shou", 500);
		set_skill("luoying-zhang", 500);
		set_skill("xuanfeng-tui", 500);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "yuxiao-jian");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat",75);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "sword.feiying" :),
			(: perform_action, "sword.qimen" :),
		}));
		set("thd/perform",999);
		weapon = "xiao";
		menpai = "�һ���";
		break;
	case 63:
	case 10: // thd2
		set_skill("bihai-chaosheng", 500);
		set_skill("qimen-bagua", 500);
		set_skill("suibo-zhuliu", 500);
		set_skill("yuxiao-jian", 500);
		set_skill("tanzhi-shentong", 500);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "tanzhi-shentong");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat", 65);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "finger.huayu" :),
			(: perform_action, "finger.shentong" :),
		}));
		set("thd/perform",999);
		menpai = "�һ���";
		break;
	case 64:
	case 11: // mr1
		set_skill("shenyuan-gong", 500);
		set_skill("douzhuan-xingyi", 500);
		set_skill("yanling-shenfa", 500);
		set_skill("murong-jianfa", 500);
		set_skill("tanzhi-shentong", 500);
		map_skill("force", "shenyuan-gong");
		map_skill("dodge", "yanling-shenfa");
		map_skill("sword", "murong-jianfa");
		map_skill("parry", "douzhuan-xingyi");
		map_skill("finger", "canhe-zhi");
		prepare_skill("finger", "canhe-zhi");
		set("chat_chance_combat", 60);
		set("chat_msg_combat", ({
			(: exert_function, "shenyuan" :),
			(: perform_action, "sword.sanhua" :),
			(: perform_action, "sword.lianhuan" :),
			(: perform_action, "parry.xingyi" :),
		}));
		weapon = "sword";
		menpai = "����Ľ��";
		break;
	case 67:
	case 12: // gumu1
		set_skill("yunu-xinjing", 500);
		set_skill("yunu-shenfa", 500);
		set_skill("xuantie-jianfa", 500);
		set_skill("anran-zhang", 500);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "xuantie-jianfa");
		map_skill("parry", "xuantie-jianfa");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 52);
		set("chat_msg_combat", ({
			(: perform_action, "sword.wujian" :),
			(: perform_action, "sword.haichao" :),
		}));
		weapon = "sword";
		menpai = "��Ĺ";
		if (random(2)) set("env/��������","����");
		else set("env/��������","��ӿ");
		break;
	case 13: // emei1
		set_skill("linji-zhuang", 500);
		set_skill("anying-fuxiang", 500);
		set_skill("huifeng-jian", 500);
		set_skill("sixiang-zhang", 500);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("sword", "huifeng-jian");
		map_skill("parry", "huifeng-jian");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 65);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "sword.mie" :),
			(: perform_action, "sword.jue" :),
			(: perform_action, "sword.liaoyuan" :),
		}));
		weapon = "sword";
		menpai = "����";
		break;
	case 14: // emei2
		set_skill("linji-zhuang", 500);
		set_skill("anying-fuxiang", 500);
		set_skill("yanxing-daofa", 500);
		set_skill("sixiang-zhang", 500);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("blade", "yanxing-daofa");
		map_skill("parry", "yanxing-daofa");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 45);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "blade.huanying" :),
		}));
		weapon = "blade";
		menpai = "����";
		break;
	case 65:
	case 15: // mj1
		set_skill("shenghuo-shengong", 500);
		set_skill("qiankun-danuoyi", 500);
		set_skill("piaoyi-shenfa", 500);
		set_skill("shenghuo-lingfa", 500);
		set_skill("hanbing-mianzhang", 500);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "qiankun-danuoyi");
		map_skill("cuff", "shenghuo-lingfa");
		prepare_skill("cuff", "shenghuo-lingfa");
		set("chat_chance_combat", 75);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "dagger.ji" :),
			(: perform_action, "dagger.xinmo" :),
			(: perform_action, "dagger.tisha" :),
		}));
		weapon = "tieling";
		menpai = "����";
		break;
	case 66:
	case 16: // mj2
		set_skill("shenghuo-shengong", 500);
		set_skill("qiankun-danuoyi", 500);
		set_skill("piaoyi-shenfa", 500);
		set_skill("shenghuo-lingfa", 500);
		set_skill("hanbing-mianzhang", 500);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "hanbing-mianzhang");
		map_skill("strike", "hanbing-mianzhang");
		prepare_skill("strike", "hanbing-mianzhang");
		set("chat_chance_combat", 52);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "strike.xixue" :),
		}));
		menpai = "����";
	case 17: // dali1
		set_skill("qiantian-yiyang", 500);
		set_skill("tianlong-xiang", 500);
		set_skill("duanjia-jianfa", 500);
		set_skill("qingyan-zhang", 500);
		map_skill("force", "qiantian-yiyang");
		map_skill("dodge", "tianlong-xiang");
		map_skill("sword", "duanjia-jianfa");
		map_skill("parry", "duanjia-jianfa");
		map_skill("strike", "qingyan-zhang");
		prepare_skill("strike", "qingyan-zhang");
		set("chat_chance_combat", 75);
		set("chat_msg_combat", ({
			(: exert_function, "xinjing" :),
			(: perform_action, "sword.fenglei" :),
		}));
		weapon = "sword";
		menpai = "���ϴ���";
		break;
	case 18: // tls
		set_skill("kurong-changong", 500);
		set_skill("tianlong-xiang", 500);
		set_skill("cihang-bian", 500);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("strike", "kurong-changong");
		prepare_skill("strike","kurong-changong");
		set("chat_chance_combat", 80);
		set("chat_msg_combat", ({
			(: exert_function, "ku" :),
			(: exert_function, "jiuchong" :),
		}));
		menpai = "����������";
		break;
	case 68:
	case 19: // gumu2
		set_skill("yinsuo-jinling", 500);
		set_skill("yunu-jianfa", 500);
		set_skill("yunu-shenfa", 500);
		set_skill("meinu-quanfa", 500);
		set_skill("yunu-xinjing", 500);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "yunu-jianfa");
		map_skill("whip", "yinsuo-jinling");
		map_skill("parry", "yinsuo-jinling");
		map_skill("cuff", "meinu-quanfa");
		prepare_skill("cuff", "meinu-quanfa");
		set("yueyin", 1);
		set("gmsanwu", 1);
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: perform_action, "whip.yueyin" :),
			(: perform_action, "whip.sanwu" :),
		}));
		weapon = "whip";
		menpai = "��Ĺ��";
		break;
	case 69:
	case 20: //gumu3
		set_skill("anran-zhang", 500);
		set_skill("yunu-xinjing", 500);
		set_skill("yunu-shenfa", 500);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("parry", "anran-zhang");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 43);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiaohun" :),
//			(: perform_action, "strike.anran" :),
			(: perform_action, "strike.jishi" :),
		}));
		menpai = "��Ĺ��";
		break;
	case 21: // kl1
		set_skill("xuantian-wuji", 500);
		set_skill("taxue-wuhen", 500);
		set_skill("kunlun-zhang", 500);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "kunlun-zhang");
		map_skill("strike", "kunlun-zhang");
		prepare_skill("strike", "kunlun-zhang");
		set("chat_chance_combat", 40);
		set("chat_msg_combat", ({
			(: perform_action, "strike.diezhang" :),
		}));
		menpai = "������";
		break;
	case 22: // kl2
		set_skill("xuantian-wuji", 500);
		set_skill("taxue-wuhen", 500);
		set_skill("zhentian-quan", 500);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "zhentian-quan");
		map_skill("cuff", "zhentian-quan");
		prepare_skill("cuff", "zhentian-quan");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "cuff.kaishan" :),
		}));
		menpai = "������";
		break;
	case 23: // kl3
		set_skill("xuantian-wuji", 500);
		set_skill("taxue-wuhen", 500);
		set_skill("chuanyun-tui", 500);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "chuanyun-tui");
		map_skill("leg", "chuanyun-tui");
		prepare_skill("leg", "chuanyun-tui");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "leg.chuanyun" :),
		}));
		menpai = "������";
		break;
	case 24: // kl4
		set_skill("xuantian-wuji", 500);
		set_skill("taxue-wuhen", 500);
		set_skill("liangyi-jian", 500);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "liangyi-jian");
		map_skill("sword", "liangyi-jian");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "sword.podi" :),
		}));
		menpai = "������";
		weapon = "sword";
		break;
	case 25: // tls3
		set_skill("kurong-changong", 500);
		set_skill("tianlong-xiang", 500);
		set_skill("yiyang-zhi", 500);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("finger", "yiyang-zhi");
		prepare_skill("finger", "yiyang-zhi");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: perform_action, "finger.yizhisanmai" :),
			(: perform_action, "finger.sandie" :),
		}));
		menpai = "����������";
		break;
	}

	switch( party ) {
	case 50: // tz1
		set_skill("guiyuan-tunafa", 500);
		set_skill("shuishangpiao", 500);
		set_skill("tiezhang-zhangfa", 500);
		map_skill("force", "guiyuan-tuanfa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 52);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.heyi" :),
			(: perform_action, "strike.lianhuan" :),

		}));
		menpai = "������";
		break;
	case 51: // tz2
		set_skill("guiyuan-tunafa", 500);
		set_skill("shuishangpiao", 500);
		set_skill("tiezhang-zhangfa", 500);
		map_skill("force", "guiyuan-tunafa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 52);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.lianhuan" :),
		}));
		menpai = "������";
		break;
	case 52: // sld1
		set_skill("dulong-dafa", 500);
		set_skill("youlong-shenfa", 500);
		set_skill("huagu-mianzhang", 500);
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "huagu-mianzhang");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "strike.bujue" :),
		}));
		menpai = "������";
		break;
	case 53: // sld2
		set_skill("dulong-dafa", 500);
		set_skill("youlong-shenfa", 500);
		set_skill("huagu-mianzhang", 500);
		set_skill("tenglong-bifa", 500);
		map_skill("dagger", "tenglong-bifa");
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "tenglong-bifa");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 52);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "dagger.xiaolian" :),
			(: perform_action, "dagger.guifei" :),
			(: perform_action, "dagger.beauty" :),
			(: perform_action, "dagger.luda" :),
			(: perform_action, "dagger.diqing" :),
		}));
		menpai = "������";
		weapon = "dagger";
		break;
	case 54: // sld3
		set_skill("dulong-dafa", 500);
		set_skill("youlong-shenfa", 500);
		set_skill("canglang-goufa", 500);
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "canglang-goufa");
		map_skill("hook", "canglang-goufa");
		set("chat_chance_combat", 55);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "strike.gouhun" :),
		}));
		menpai = "������";
		weapon = "hook";
		break;
	case 55: // dls1
		set_skill("longxiang-boruo", 500);
		set_skill("yuxue-dunxing", 500);
		set_skill("xuedao-jing", 500);
		map_skill("force", "longxiang-boruo");
		map_skill("dodge", "yuxue-dunxing");
		map_skill("parry", "xuedao-jing");
		map_skill("blade", "xuedao-jing");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: exert_function, "shield" :),
			(: exert_function, "longxiang" :),
			(: perform_action, "blade.shendao" :),
			(: perform_action, "blade.jixue" :),
		}));
		menpai = "������";
		weapon = "blade";
		break;
	case 56: // dls2
		set_skill("longxiang-boruo", 500);
		set_skill("yuxue-dunxing", 500);
		set_skill("xiangfu-lun", 500);
		map_skill("force", "longxiang-boruo");
		map_skill("dodge", "yuxue-dunxing");
		map_skill("parry", "xiangfu-lun");
		map_skill("hammer", "xiangfu-lun");
		set("chat_chance_combat", 65);
		set("chat_msg_combat", ({
			(: exert_function, "shield" :),
			(: exert_function, "longxiang" :),
			(: perform_action, "hammer.wushuai" :),
			//(: perform_action, "hammer.dazhuan" :),
		}));
		menpai = "������";
		weapon = "falun";
		break;
	case 57: // dls3
		set_skill("longxiang-boruo", 500);
		set_skill("yuxue-dunxing", 500);
		set_skill("huoyan-dao", 500);
		map_skill("force", "longxiang-boruo");
		map_skill("dodge", "yuxue-dunxing");
		map_skill("parry", "huoyan-dao");
		map_skill("strike", "huoyan-dao");
		prepare_skill("strike", "huoyan-dao");
		set("chat_chance_combat", 45);
		set("chat_msg_combat", ({
			(: exert_function, "shield" :),
			(: exert_function, "longxiang" :),
			//(: perform_action, "strike.fen" :),
			(: perform_action, "strike.daoqi" :),
			(: perform_action, "strike.ran" :),
		}));
		menpai = "������";
		break;
	case 58: // xx1
		set_skill("huagong-dafa", 500);
		set_skill("zhaixingshu", 500);
		set_skill("chousui-zhang", 500);
		map_skill("force", "huagong-dafa");
		map_skill("dodge", "zhaixingshu");
		map_skill("parry", "chousui-zhang");
		map_skill("strike", "chousui-zhang");
		prepare_skill("strike", "chousui-zhang");
		set("env/������","����");
		set("chat_chance_combat", 45);
		set("chat_msg_combat", ({
			(: exert_function, "judu" :),
			(: perform_action, "strike.yinhuo" :),
			(: perform_action, "strike.huoqiang" :),
		}));
		menpai = "������";
		break;
	case 59: // xx2
		set_skill("huagong-dafa", 500);
		set_skill("zhaixingshu", 500);
		set_skill("tianshan-zhang", 500);
		map_skill("force", "huagong-dafa");
		map_skill("dodge", "zhaixingshu");
		map_skill("parry", "tianshan-zhang");
		map_skill("staff", "tianshan-zhang");
		set("env/������","����");
		set("chat_chance_combat", 40);
		set("chat_msg_combat", ({
			(: exert_function, "judu" :),
			(: perform_action, "staff.feizhi" :),
		}));
		menpai = "������";
		weapon = "staff";
		break;
	case 60: // ss1
		set_skill("hanbing-zhenqi", 500);
		set_skill("zhongyuefeng", 500);
		set_skill("songyang-shou", 500);
		map_skill("force", "hanbing-zhenqi");
		map_skill("dodge", "zhongyuefeng");
		map_skill("parry", "songyang-shou");
		map_skill("hand", "songyang-shou");
		prepare_skill("hand", "songyang-shou");
		set("chat_chance_combat", 40);
		set("chat_msg_combat", ({
			(: exert_function, "juhan" :),
			(: exert_function, "huti" :),
			//(: perform_action, "hand.junji" :),
			(: perform_action, "hand.yinyang" :),
		}));
		menpai = "��ɽ��";
		break;
	case 61: // ss2
		set_skill("hanbing-zhenqi", 500);
		set_skill("zhongyuefeng", 500);
		set_skill("songyang-shou", 500);
		set_skill("songshan-jian", 500);
		map_skill("force", "hanbing-zhenqi");
		map_skill("dodge", "zhongyuefeng");
		map_skill("parry", "songshan-jian");
		map_skill("hand", "songyang-shou");
		map_skill("sword", "songshan-jian");
		prepare_skill("hand", "songyang-shou");
		set("chat_chance_combat", 45);
		set("chat_msg_combat", ({
			(: exert_function, "juhan" :),
			(: exert_function, "huti" :),
			(: perform_action, "sword.feiwu" :),
			(: perform_action, "sword.songyang" :),
		}));
		menpai = "��ɽ��";
		weapon = "sword";
		break;
	}

	set("long",query("long")+"��λ�ƺ���"+menpai+"�ĸ��֣�\n");
	set("weapon" , weapon);
	carry_object(ARMOR_D("cloth"))->wear();
}

void do_copy(object ob)
{
	mapping skills;
	string *sk;
	int lv,exp,i;

	lv = ob->query("max_pot") - 100 + random(50);
	exp = ob->query("combat_exp");
	exp = exp / 100 * (90+random(20));

	set("max_qi", ob->query("max_qi")*5/4);
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("max_jing", ob->query("max_jing"));
	set("eff_jing", ob->query("max_jing"));
	set("jing", ob->query("max_jing"));
	set("max_neili", ob->query("max_neili"));
	set("neili", ob->query("neili"));
	if( query("neili") < query("max_neili"))
		set("neili", query("max_neili"));
	set("eff_jingli", ob->query("eff_jingli"));
	set("jingli", ob->query("jingli"));
	if( query("jingli") < query("eff_jingli"))
		set("jingli", query("eff_jingli"));
	set("combat_exp", exp);

	skills = query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
		if ( sk[i]!= "literate" && sk[i]!= "poison" )
			skills[sk[i]] = lv;
	}
	set("jiali", query_skill("force")/4);

        set("damage",80+lv/10);
	wieldweapon();
}

void checkfight()
{
	string weapon;
	object me = this_object();

	remove_call_out("checkfight");
	if( !objectp(me) || !living(me) || !me->is_fighting() ) return;
	weapon = query("weapon");
	if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") ) {
		command("emote ���ó��ѱ�����");
		wieldweapon();
	}
	call_out("checkfight", 4);
}

void check()
{
	object me = this_object();
	object target = query("target");
	remove_call_out("check");
	if( target && living(target) && !is_fighting() ) {
		if ( target && environment(target)==environment() )
			kill_ob(target);
		else {
			if (environment(me))
				message_vision("$Nһ�����˿�ս��ֻ���뿪��\n",me);
			destruct(me);
			return;
		}
	}
	call_out("check", 10);
}

void init()
{
	object target,me=this_player();
	::init();
	target = query("target");
	if ( me == target ) {
		command("emote ���˳���...");
		command("consider "+me->query("id"));
		command("say "+me->query("name")+"����������");
		kill_ob(me);
		me->fight_ob(this_object());
		call_out("check", 10);
	}
}

void kill_ob(object ob)
{
	::kill_ob(ob);
	call_out("checkfight",4);
}

int accept_fight(object ob)
{
	command("say ��û������æ������");
	return 0;
}

void die()
{
	SEAWAR_D->gain(query("job"),query("team"),query("score"));
	::die();
}
